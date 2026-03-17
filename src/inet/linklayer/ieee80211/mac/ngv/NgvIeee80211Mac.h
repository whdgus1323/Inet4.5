#ifndef __INET_NGVIEEE80211MAC_H
#define __INET_NGVIEEE80211MAC_H

#include "inet/linklayer/ieee80211/mac/Ieee80211Mac.h"
#include "omnetpp/cmessage.h"

namespace inet {
namespace ieee80211 {
namespace ngv {

class NgvIeee80211Mac : public inet::ieee80211::Ieee80211Mac
{
  protected:
    bool print;
    long expirySaved = 0;
    long expiryCheckedAtTx = 0;
    long expiryDroppedAtTx = 0;

    omnetpp::cMessage *ngvRepEvent = nullptr;
    inet::Packet *ngvRepTemplate = nullptr;
    int ngvRepRemaining = 0;

    virtual void initialize(int stage) override;
    virtual bool isModuleStartStage(int stage) const override;
    virtual bool isModuleStopStage(int stage) const override;

    virtual void handleUpperPacket(inet::Packet *packet) override;
    virtual void sendDownFrame(inet::Packet *frame) override;

    virtual void handleSelfMessage(omnetpp::cMessage *message) override;

    virtual void finish() override;

    void clearNgvRepState();

  public:
    NgvIeee80211Mac() = default;
    //virtual ~NgvIeee80211Mac() = default;
    virtual ~NgvIeee80211Mac() override { clearNgvRepState(); }
};

} // namespace ngv
} // namespace ieee80211
} // namespace inet

#endif
