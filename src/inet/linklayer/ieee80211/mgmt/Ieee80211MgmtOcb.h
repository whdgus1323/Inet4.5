#pragma once

#include "inet/linklayer/ieee80211/mgmt/Ieee80211MgmtAdhoc.h"

namespace inet {
namespace ieee80211 {

class INET_API Ieee80211MgmtOcb : public Ieee80211MgmtAdhoc
{
  protected:
    virtual void initialize(int stage) override;
};

} // namespace ieee80211
} // namespace inet
