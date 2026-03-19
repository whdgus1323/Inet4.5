//
// Copyright (C) 2016 OpenSim Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later
//


#include "inet/linklayer/ieee80211/mac/framesequence/DcfFs.h"

#include <algorithm>
#include <cctype>
#include <cstring>

#include "inet/linklayer/ieee80211/mac/framesequence/PrimitiveFrameSequences.h"

namespace inet {
namespace ieee80211 {

namespace {

cModule *findBdParameterModule()
{
    cModule *module = getSimulation()->getContextModule();
    while (module != nullptr) {
        if (module->hasPar("bdRepetitionTarget"))
            return module;
        module = module->getParentModule();
    }
    return nullptr;
}

std::string getConfiguredBdRepetitionTarget()
{
    cModule *module = findBdParameterModule();
    std::string target = module != nullptr && module->hasPar("bdRepetitionTarget") ? module->par("bdRepetitionTarget").stdstringValue() : "rreq";
    std::transform(target.begin(), target.end(), target.begin(),
            [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return target;
}

} // namespace

DcfFs::DcfFs() :
    // Excerpt from G.2 Basic sequences (p. 2309)
    // frame-sequence =
    //   ( [ CTS ] ( Management + broadcast | Data + group ) ) |
    //   ( [ CTS | RTS CTS] {frag-frame ACK } last-frame ACK )
    //
    // frag-frame = ( Data | Management ) + individual + frag;
    // last-frame = ( Data | Management ) + individual + last;
    //
    AlternativesFs({new SequentialFs({new OptionalFs(new SelfCtsFs(), OPTIONALFS_PREDICATE(isSelfCtsNeeded)),
                                      new AlternativesFs({new ManagementFs(), new BroadcastRreqFs(), new DataFs()}, ALTERNATIVESFS_SELECTOR(selectMulticastDataOrMgmt))}),
                    new SequentialFs({new OptionalFs(new AlternativesFs({new SelfCtsFs(), new SequentialFs({new RtsFs(), new CtsFs()})},
                                                                        ALTERNATIVESFS_SELECTOR(selectSelfCtsOrRtsCts)),
                                                     OPTIONALFS_PREDICATE(isCtsOrRtsCtsNeeded)),
                                      new RepeatingFs(new FragFrameAckFs(), REPEATINGFS_PREDICATE(hasMoreFragments)),
                                      new LastFrameAckFs()})},
                   ALTERNATIVESFS_SELECTOR(selectDcfSequence))
{
}

int DcfFs::selectDcfSequence(AlternativesFs *frameSequence, FrameSequenceContext *context)
{
    bool multicastMgmtOrDataSequence = isBroadcastManagementOrGroupDataSequenceNeeded(frameSequence, context);
    bool fragFrameSequence = isFragFrameSequenceNeeded(frameSequence, context);
    if (multicastMgmtOrDataSequence) return 0;
    else if (fragFrameSequence) return 1;
    else throw cRuntimeError("One alternative must be chosen");
}

int DcfFs::selectSelfCtsOrRtsCts(AlternativesFs *frameSequence, FrameSequenceContext *context)
{
    bool selfCts = isSelfCtsNeeded(nullptr, context); // TODO
    bool rtsCts = isRtsCtsNeeded(nullptr, context); // TODO
    if (selfCts) return 0;
    else if (rtsCts) return 1;
    else throw cRuntimeError("One alternative must be chosen");
}

bool DcfFs::hasMoreFragments(RepeatingFs *frameSequence, FrameSequenceContext *context)
{
    return context->getInProgressFrames()->hasInProgressFrames() && context->getInProgressFrames()->getFrameToTransmit()->peekAtFront<Ieee80211MacHeader>()->getMoreFragments();
}

bool DcfFs::isSelfCtsNeeded(OptionalFs *frameSequence, FrameSequenceContext *context)
{
    return false; // TODO Implement
}

bool DcfFs::isRtsCtsNeeded(OptionalFs *frameSequence, FrameSequenceContext *context)
{
    auto protectedFrame = context->getInProgressFrames()->getFrameToTransmit();
    return context->getRtsPolicy()->isRtsNeeded(protectedFrame, protectedFrame->peekAtFront<Ieee80211MacHeader>());
}

bool DcfFs::isCtsOrRtsCtsNeeded(OptionalFs *frameSequence, FrameSequenceContext *context)
{
    bool selfCts = isSelfCtsNeeded(frameSequence, context);
    bool rtsCts = isRtsCtsNeeded(frameSequence, context);
    return selfCts || rtsCts;
}

bool DcfFs::isBroadcastManagementOrGroupDataSequenceNeeded(AlternativesFs *frameSequence, FrameSequenceContext *context)
{
    if (context->getInProgressFrames()->hasInProgressFrames()) {
        auto frameToTransmit = context->getInProgressFrames()->getFrameToTransmit();
        return frameToTransmit->peekAtFront<Ieee80211MacHeader>()->getReceiverAddress().isMulticast();
    }
    else
        return false;
}

int DcfFs::selectMulticastDataOrMgmt(AlternativesFs *frameSequence, FrameSequenceContext *context)
{
    auto frameToTransmit = context->getInProgressFrames()->getFrameToTransmit();
    if (dynamicPtrCast<const Ieee80211MgmtHeader>(frameToTransmit->peekAtFront<Ieee80211MacHeader>()))
        return 0;
    else if (isBroadcastAodvRepetitionNeeded(frameSequence, context))
        return 1;
    else
        return 2;
}

bool DcfFs::matchesBdRepetitionTarget(Packet *frameToTransmit, FrameSequenceContext *context)
{
    const auto target = getConfiguredBdRepetitionTarget();
    const char *packetName = frameToTransmit->getName();
    if (target == "rreq")
        return std::strcmp(packetName, "aodv::Rreq") == 0;
    else if (target == "rerr")
        return std::strcmp(packetName, "aodv::Rerr") == 0;
    else if (target == "hello")
        return std::strcmp(packetName, "aodv::Hello") == 0;
    else
        return false;
}

bool DcfFs::isBroadcastAodvRepetitionNeeded(AlternativesFs *frameSequence, FrameSequenceContext *context)
{
    auto frameToTransmit = context->getInProgressFrames()->getFrameToTransmit();
    auto header = frameToTransmit->peekAtFront<Ieee80211MacHeader>();

    // Apply the custom 802.11bd-style static repetition only to the selected broadcast AODV control frame kind.
    return header->getReceiverAddress().isMulticast() && matchesBdRepetitionTarget(frameToTransmit, context);
}

bool DcfFs::isFragFrameSequenceNeeded(AlternativesFs *frameSequence, FrameSequenceContext *context)
{
    return context->getInProgressFrames()->hasInProgressFrames() && dynamicPtrCast<const Ieee80211DataOrMgmtHeader>(context->getInProgressFrames()->getFrameToTransmit()->peekAtFront<Ieee80211MacHeader>());
}

} // namespace ieee80211
} // namespace inet

