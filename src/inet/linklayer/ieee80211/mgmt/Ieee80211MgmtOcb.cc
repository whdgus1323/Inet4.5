#include "inet/linklayer/ieee80211/mgmt/Ieee80211MgmtOcb.h"
#include "inet/linklayer/common/MacAddress.h"
#include "inet/common/ModuleAccess.h"
#include "inet/linklayer/ieee80211/mib/Ieee80211Mib.h"

namespace inet {
namespace ieee80211 {

Define_Module(Ieee80211MgmtOcb);

void Ieee80211MgmtOcb::initialize(int stage)
{
    Ieee80211MgmtAdhoc::initialize(stage);

    std::cout << "[OCB] init stage=" << stage << " module=" << getFullPath() << std::endl;
    std::cout.flush();
    std::fflush(stdout);

    if (stage == INITSTAGE_LINK_LAYER) {
        auto *m = getParentModule()->getSubmodule("mib");
        auto *mib = check_and_cast<Ieee80211Mib *>(m);

        mib->mode = Ieee80211Mib::OCB;
        mib->bssData.bssid = MacAddress::BROADCAST_ADDRESS;

        std::cout << "[OCB] set mode=OCB at " << mib->getFullPath() << std::endl;
        std::cout.flush();
        std::fflush(stdout);
    }
}


} // namespace ieee80211
} // namespace inet
