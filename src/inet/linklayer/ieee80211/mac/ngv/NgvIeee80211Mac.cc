#include <iostream>
#include <string>

#include "inet/linklayer/ieee80211/mac/Ieee80211Frame_m.h"
#include "inet/linklayer/ieee80211/mac/ngv/NgvIeee80211Mac.h"

#include "inet/common/InitStages.h"
#include "inet/common/packet/Packet.h"

#include "inet/linklayer/ieee80211/mac/ngv/NgvExpiryDeadlineTag_m.h"
#include "inet/linklayer/ieee80211/mac/ngv/NgvRadioEnvironmentReqTag_m.h"


#include "inet/common/ProtocolTag_m.h"
#include "inet/common/Protocol.h"

namespace inet {
namespace ieee80211 {
namespace ngv {

Define_Module(NgvIeee80211Mac);

void NgvIeee80211Mac::initialize(int stage)
{
    inet::ieee80211::Ieee80211Mac::initialize(stage);
    if (stage == INITSTAGE_LOCAL) {
        print = par("print");
        if (ngvRepEvent == nullptr)
            ngvRepEvent = new omnetpp::cMessage("ngvRepEvent");
    }
}

bool NgvIeee80211Mac::isModuleStartStage(int stage) const
{
    return stage == INITSTAGE_LINK_LAYER;
}

bool NgvIeee80211Mac::isModuleStopStage(int stage) const
{
    return stage == INITSTAGE_LINK_LAYER;
}

void NgvIeee80211Mac::handleUpperPacket(inet::Packet *packet)
{
    const auto req = packet->findTag<inet::NgvRadioEnvironmentReqTag>();

    if (req == nullptr) {
        if(print) std::cout << "[NGV-EXP] now=" << simTime() << " req=null (no tag)" << std::endl;
        inet::ieee80211::Ieee80211Mac::handleUpperPacket(packet);
        return;
    }

    if(print) {
        std::cout << "[NGV-EXP] now=" << simTime()
                  << " expiryPresent=" << req->getExpiryPresent()
                  << " expiryTime(ms)=" << req->getExpiryTime()
                  << std::endl;
    }

    if (!req->getExpiryPresent()) {
        if(print) std::cout << "[NGV-EXP] expiryPresent=false -> skip expiry handling" << std::endl;
        inet::ieee80211::Ieee80211Mac::handleUpperPacket(packet);
        return;
    }

    double expiryMs = req->getExpiryTime();

    if (!(expiryMs > 0.0)) {
        if(print) std::cout << "[NGV-EXP] expiryMs<=0 -> skip expiry handling" << std::endl;
        inet::ieee80211::Ieee80211Mac::handleUpperPacket(packet);
        return;
    }

    if (expiryMs < 1.0)
        expiryMs = 1.0;

    const simtime_t expiryDuration = SimTime(expiryMs, SIMTIME_MS);
    const simtime_t deadline = simTime() + expiryDuration;

    auto dl = packet->addTagIfAbsent<inet::NgvExpiryDeadlineTag>();
    dl->setDeadline(deadline);

    expirySaved++;

    if(print) {
        std::cout << "[NGV-EXP] expiryMs(clamped)=" << expiryMs
                  << " expiryDuration=" << expiryDuration
                  << " deadline=" << deadline
                  << " (saved on packet)" << std::endl;
    }

    inet::ieee80211::Ieee80211Mac::handleUpperPacket(packet);
}

void NgvIeee80211Mac::sendDownFrame(inet::Packet *frame)
{
    /*
    std::cout << "[NGV-TXHOOK] frame=" << frame->getName()
              << " hasDeadline=" << (frame->findTag<inet::NgvExpiryDeadlineTag>() != nullptr)
              << std::endl;

    std::cout << "[NGV-TXHOOK] sendDownFrame called: now=" << simTime()
              << " frame=" << frame->getName() << std::endl;
    */

    const bool isPing = (std::string(frame->getName()).rfind("ping", 0) == 0);
    if(print) std::cout << "[NGV-TXHOOK] isPing=" << isPing << std::endl;

    const auto dl = frame->findTag<inet::NgvExpiryDeadlineTag>();
    if (dl != nullptr) {
        if(print) {
            std::cout << "[NGV-TXHOOK] deadlineTag=1 frame=" << frame->getName()
                      << " deadline=" << dl->getDeadline() << std::endl;
        }
    }

    if (dl != nullptr && isPing) {
        expiryCheckedAtTx++;

        if (simTime() >= dl->getDeadline()) {
            expiryDroppedAtTx++;

            if(print) {
                std::cout << "[NGV] DROP expired at TX: now=" << simTime()
                          << " deadline=" << dl->getDeadline()
                          << " frame=" << frame->getName() << std::endl;
            }

            delete frame;
            return;
        }
    }

    int numReps = 1;
    const auto req = frame->findTag<inet::NgvRadioEnvironmentReqTag>();
    if (req != nullptr && req->getRepetitionPresent()) {
        numReps = req->getNumRepetitions();
        if (numReps < 1)
            numReps = 1;
    }

    bool isGroup = false;
    try {
        const auto& hdr = frame->peekAtFront<inet::ieee80211::Ieee80211MacHeader>();
        isGroup = hdr->getReceiverAddress().isMulticast();
    }
    catch (...) {
        isGroup = false;
    }

    if(print) {
        std::cout << "[NGV-REP] frame=" << frame->getName()
                  << " numReps=" << numReps
                  << " isGroup=" << isGroup
                  << std::endl;
    }

    if (isGroup && numReps > 1) {
        if (ngvRepEvent != nullptr && ngvRepEvent->isScheduled())
            cancelEvent(ngvRepEvent);
        if (ngvRepTemplate != nullptr) {
            delete ngvRepTemplate;
            ngvRepTemplate = nullptr;
        }

        ngvRepTemplate = frame->dup();
        ngvRepRemaining = numReps - 1;

        inet::ieee80211::Ieee80211Mac::sendDownFrame(frame);

        scheduleAt(simTime() + modeSet->getSifsTime(), ngvRepEvent);

        return;
    }

    inet::ieee80211::Ieee80211Mac::sendDownFrame(frame);
}


void NgvIeee80211Mac::clearNgvRepState()
{
    if (ngvRepEvent != nullptr) {
        cancelAndDelete(ngvRepEvent);
        ngvRepEvent = nullptr;
    }
    if (ngvRepTemplate != nullptr) {
        delete ngvRepTemplate;
        ngvRepTemplate = nullptr;
    }
    ngvRepRemaining = 0;
}


void NgvIeee80211Mac::handleSelfMessage(omnetpp::cMessage *message)
{
    if (message == ngvRepEvent) {
        if (ngvRepRemaining > 0 && ngvRepTemplate != nullptr) {

            std::cout << "[NGV-REP-TX] now=" << simTime()
                      << " remaining=" << ngvRepRemaining
                      << " template=" << ngvRepTemplate->getName()
                      << std::endl;


            auto copy = ngvRepTemplate->dup();
            inet::ieee80211::Ieee80211Mac::sendDownFrame(copy);

            ngvRepRemaining--;

            if (ngvRepRemaining > 0)
                scheduleAt(simTime() + modeSet->getSifsTime(), ngvRepEvent);

            else {
                delete ngvRepTemplate;
                ngvRepTemplate = nullptr;
            }
        }
        else {
            if (ngvRepTemplate != nullptr) {
                delete ngvRepTemplate;
                ngvRepTemplate = nullptr;
            }
            ngvRepRemaining = 0;
        }
        return;
    }

    inet::ieee80211::Ieee80211Mac::handleSelfMessage(message);

}

void NgvIeee80211Mac::finish()
{
    clearNgvRepState();

    omnetpp::cSimpleModule::finish();
    if (expirySaved > 0 || expiryCheckedAtTx > 0 || expiryDroppedAtTx > 0) {
        EV_INFO << "[NGV-STATS] host=" << getContainingNode(this)->getFullPath()
                << " expirySaved=" << expirySaved
                << " expiryCheckedAtTx=" << expiryCheckedAtTx
                << " expiryDroppedAtTx=" << expiryDroppedAtTx << endl;
    }
}



} // namespace ngv
} // namespace ieee80211
} // namespace inet
