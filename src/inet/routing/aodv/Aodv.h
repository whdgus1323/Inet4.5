//
// Copyright (C) 2014 OpenSim Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later
//


#ifndef __INET_AODV_H
#define __INET_AODV_H

#include <map>
#include <set>
#include <string>
#include <vector>

#include "inet/common/ModuleRefByPar.h"
#include "inet/networklayer/contract/IInterfaceTable.h"
#include "inet/networklayer/contract/IL3AddressType.h"
#include "inet/networklayer/contract/INetfilter.h"
#include "inet/networklayer/contract/IRoutingTable.h"
#include "inet/routing/aodv/AodvControlPackets_m.h"
#include "inet/routing/aodv/AodvRouteData.h"
#include "inet/routing/base/RoutingProtocolBase.h"
#include "inet/transportlayer/contract/udp/UdpSocket.h"
#include "inet/transportlayer/udp/UdpHeader_m.h"

namespace inet {
namespace aodv {

/*
 * This class implements AODV routing protocol and Netfilter hooks
 * in the IP-layer required by this protocol.
 */

class INET_API Aodv : public RoutingProtocolBase, public NetfilterBase::HookBase, public UdpSocket::ICallback, public cListener
{
  protected:
    /*
     * It implements a unique identifier for an arbitrary RREQ message
     * in the network. See: rreqsArrivalTime.
     */
    class INET_API RreqIdentifier {
      public:
        L3Address originatorAddr;
        unsigned int rreqID;
        RreqIdentifier(const L3Address& originatorAddr, unsigned int rreqID) : originatorAddr(originatorAddr), rreqID(rreqID) {};
        bool operator==(const RreqIdentifier& other) const
        {
            return this->originatorAddr == other.originatorAddr && this->rreqID == other.rreqID;
        }
    };

    class INET_API RreqIdentifierCompare {
      public:
        bool operator()(const RreqIdentifier& lhs, const RreqIdentifier& rhs) const
        {
            if (lhs.originatorAddr < rhs.originatorAddr)
                return true;
            else if (lhs.originatorAddr > rhs.originatorAddr)
                return false;
            else
                return lhs.rreqID < rhs.rreqID;
        }
    };

    // context
    const IL3AddressType *addressType = nullptr; // to support both Ipv4 and v6 addresses.

    // environment
    cModule *host = nullptr;
    ModuleRefByPar<IRoutingTable> routingTable;
    ModuleRefByPar<IInterfaceTable> interfaceTable;
    ModuleRefByPar<INetfilter> networkProtocol;
    UdpSocket socket;
    bool usingIpv6 = false;

    // AODV parameters: the following parameters are configurable, see the NED file for more info.
    unsigned int rerrRatelimit = 0;
    unsigned int aodvUDPPort = 0;
    bool askGratuitousRREP = false;
    bool useHelloMessages = false;
    bool destinationOnlyFlag = false;
    simtime_t maxJitter;
    simtime_t activeRouteTimeout;
    simtime_t helloInterval;
    unsigned int netDiameter = 0;
    unsigned int rreqRetries = 0;
    unsigned int rreqRatelimit = 0;
    unsigned int timeoutBuffer = 0;
    unsigned int ttlStart = 0;
    unsigned int ttlIncrement = 0;
    unsigned int ttlThreshold = 0;
    unsigned int localAddTTL = 0;
    unsigned int allowedHelloLoss = 0;
    simtime_t nodeTraversalTime;
    cPar *jitterPar = nullptr;
    cPar *periodicJitter = nullptr;
    std::string pwd;
    bool enableRreqGraphLog = false;
    bool enableRouteGraphLog = false;
    bool enablePrecursorLog = false;
    bool enableRerrFanoutLog = false;
    bool enableRoutingTableSnapshotLog = false;
      bool enableSummary1sLog = false;
      bool cbrBasedRrepEnabled = false;
      int cbrBasedRrepThreshold = 0;
      std::string cbrBasedRrepCompareMode;
      bool cbrBasedRrepRangeEnabled = false;
      int cbrBasedRrepLowThreshold = 0;
      int cbrBasedRrepHighThresholdForRange = 0;
      bool cbrBasedRrepDirectRouteBypassEnabled = false;
      bool dlBasedRrepEnabled = false;
      double dlBasedRrepScoreThreshold = 0;
      std::string dlBasedRrepCompareMode;
      int dlBasedRrepNeighborNorm = 0;
    int dlBasedRrepHopNorm = 0;
    double dlBasedRrepThresholdMin = 0;
    double dlBasedRrepThresholdMax = 100;
    double dlBasedRrepMinThresholdGap = 0;
    bool dlBasedRrepCustomArchitectureEnabled = false;
    int dlBasedRrepHidden1Size = 32;
    int dlBasedRrepHidden2Size = 16;
    std::vector<double> dlBasedRrepHiddenWeights;
    std::vector<double> dlBasedRrepHiddenBiases;
    std::vector<double> dlBasedRrepHidden2Weights;
    std::vector<double> dlBasedRrepHidden2Biases;
    std::vector<double> dlBasedRrepOutputWeights;
    std::vector<double> dlBasedRrepOutputBiases;
    bool dlBucketBasedRrepEnabled = false;
    int dlBucketBasedRrepNeighborNorm = 0;
    int dlBucketBasedRrepHopNorm = 0;
    int dlBucketBasedRrepBucketRoundDigits = 2;
    bool dlBucketBasedRrepNearestFallbackEnabled = true;
    std::string dlBucketBasedRrepLookupTable;
    struct DlBucketBasedRrepEntry {
        std::string key;
        double localCbrNorm = 0;
        double neighborNorm = 0;
        double hopNorm = 0;
        double isOriginatorNear = 0;
        double lowThreshold = 0;
        double highThreshold = 0;
    };
    std::map<std::string, DlBucketBasedRrepEntry> dlBucketBasedRrepEntriesByKey;
    std::vector<DlBucketBasedRrepEntry> dlBucketBasedRrepEntries;
    bool cbrBasedRrepDelayEnabled = false;
    int cbrBasedRrepModerateThreshold = 0;
    int cbrBasedRrepHighThreshold = 0;
    simtime_t cbrBasedRrepModerateDelay;
    simtime_t cbrBasedRrepHighDelay;
    bool cbrRrepMetricsEnabled = false;
    bool cbrRrepDecisionLogEnabled = false;
    bool cbrRouteCauseLogEnabled = false;
    bool transmissionFailureDiagnosisLogEnabled = false;
    bool useBdStationCount = false;

    // the following parameters are calculated from the parameters defined above
    // see the NED file for more info
    simtime_t deletePeriod;
    simtime_t myRouteTimeout;
    simtime_t blacklistTimeout;
    simtime_t netTraversalTime;
    simtime_t nextHopWait;
    simtime_t pathDiscoveryTime;

    // state
    unsigned int rreqId = 0; // when sending a new RREQ packet, rreqID incremented by one from the last id used by this node
    unsigned int sequenceNum = 0; // it helps to prevent loops in the routes (RFC 3561 6.1 p11.)
    std::map<L3Address, WaitForRrep *> waitForRREPTimers; // timeout for Route Replies
    std::map<RreqIdentifier, simtime_t, RreqIdentifierCompare> rreqsArrivalTime; // maps RREQ id to its arriving time
    L3Address failedNextHop; // next hop to the destination who failed to send us RREP-ACK
    std::map<L3Address, simtime_t> blacklist; // we don't accept RREQs from blacklisted nodes
    unsigned int rerrCount = 0; // num of originated RERR in the last second
    unsigned int rreqCount = 0; // num of originated RREQ in the last second
    unsigned long totalOriginatedRerrCount = 0; // cumulative number of locally originated RERR messages
    simtime_t lastBroadcastTime; // the last time when any control packet was broadcasted
    simtime_t nextRoutingTableSnapshotTime; // throttle full routing table snapshots
    unsigned int summaryRreqAcceptCount = 0;
    unsigned int summaryRerrGeneratedCount = 0;
    unsigned int summaryRerrUnreachableSum = 0;
    unsigned int summaryRerrPrecursorSum = 0;
    std::map<L3Address, unsigned int> addressToRreqRetries; // number of re-discovery attempts per address
    unsigned int metricsRreqReceivedCount = 0;
    unsigned int metricsRrepCandidateCount = 0;
    unsigned int metricsRrepAllowedCount = 0;
    unsigned int metricsRrepBlockedCount = 0;
    unsigned int metricsRouteDiscoveryStartedCount = 0;
    unsigned int metricsRouteDiscoverySucceededCount = 0;
    unsigned int metricsRouteDiscoveryFailedCount = 0;
    unsigned int metricsRrepReceivedCount = 0;
    unsigned int metricsRelayParticipationCount = 0;
    unsigned int metricsRouteCandidateCountSum = 0;
    unsigned int metricsRouteCandidateCountCount = 0;
    unsigned int metricsSelectedRouteHopCountSum = 0;
    unsigned int metricsSelectedRouteHopCountCount = 0;
    simtime_t metricsRouteDiscoveryDelaySum = SIMTIME_ZERO;
    unsigned int metricsRouteDiscoveryDelayCount = 0;
    std::map<L3Address, simtime_t> metricsRouteDiscoveryStartTimes;
    std::map<L3Address, unsigned int> metricsRouteDiscoveryCandidateCounts;
    unsigned int diagnosisNoRouteToForwardCount = 0;
    unsigned int diagnosisNoActiveRouteToForwardCount = 0;
    unsigned int diagnosisRouteInvalidateCount = 0;
    unsigned int diagnosisRouteExpireInactiveCount = 0;
    unsigned int diagnosisRouteDeleteCount = 0;
    unsigned int diagnosisRerrOriginatedCount = 0;

    // self messages
    cMessage *helloMsgTimer = nullptr; // timer to send hello messages (only if the feature is enabled)
    cMessage *expungeTimer = nullptr; // timer to clean the routing table out
    cMessage *counterTimer = nullptr; // timer to set rrerCount = rreqCount = 0 in each second
    cMessage *rrepAckTimer = nullptr; // timer to wait for RREP-ACKs (RREP-ACK timeout)
    cMessage *blacklistTimer = nullptr; // timer to clean the blacklist out

    // lifecycle
    simtime_t rebootTime; // the last time when the node rebooted

    // internal
    std::multimap<L3Address, Packet *> targetAddressToDelayedPackets; // queue for the datagrams we have no route for

  protected:
    void handleMessageWhenUp(cMessage *msg) override;
    void initialize(int stage) override;
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }

    /* Route Discovery */
    void startRouteDiscovery(const L3Address& target, unsigned int timeToLive = 0);
    void completeRouteDiscovery(const L3Address& target);
    bool hasOngoingRouteDiscovery(const L3Address& destAddr);
    void cancelRouteDiscovery(const L3Address& destAddr);

    /* Routing Table management */
    void updateRoutingTable(IRoute *route, const L3Address& nextHop, unsigned int hopCount, bool hasValidDestNum, unsigned int destSeqNum, bool isActive, simtime_t lifeTime);
    IRoute *createRoute(const L3Address& destAddr, const L3Address& nextHop, unsigned int hopCount, bool hasValidDestNum, unsigned int destSeqNum, bool isActive, simtime_t lifeTime);
    bool updateValidRouteLifeTime(const L3Address& destAddr, simtime_t lifetime);
    void scheduleExpungeRoutes();
    void expungeRoutes();

    /* Control packet creators */
    const Ptr<RrepAck> createRREPACK();
    const Ptr<Rrep> createHelloMessage();
    const Ptr<Rreq> createRREQ(const L3Address& destAddr);
    const Ptr<Rrep> createRREP(const Ptr<Rreq>& rreq, IRoute *destRoute, IRoute *originatorRoute, const L3Address& sourceAddr);
    const Ptr<Rrep> createGratuitousRREP(const Ptr<Rreq>& rreq, IRoute *originatorRoute);
    const Ptr<Rerr> createRERR(const std::vector<UnreachableNode>& unreachableNodes);
    void logOriginatedRerr(const char *reason, const std::vector<UnreachableNode>& unreachableNodes, const std::set<L3Address>& precursorNodes);
    void logPrecursorAddition(const char *reason, const L3Address& routeDest, const L3Address& precursor, const std::set<L3Address>& precursorList) const;
    void logRouteGraphEvent(const char *event, const L3Address& routeDest, const L3Address& nextHop, unsigned int hopCount, bool isActive, simtime_t lifeTime) const;
    void logRoutingTableSnapshot(const char *reason);
    void appendAodvMetric(const std::string& fileName, const std::string& line) const;
    void logSummary1s();
    void logCbrRrepMetrics1s();
    void logTransmissionFailureDiagnosis1s();
    int countCurrentNeighbors() const;
    int getBdStationCount() const;
    void ensureCbrRrepDecisionLogFile() const;
    void logCbrRrepDecision(const Ptr<Rreq>& rreq, const L3Address& sourceAddr, double localCbr, const char *decision) const;
    void logRouteCauseEvent(const char *event, const L3Address& routeDest, const L3Address& nextHop, unsigned int hopCount, bool isActive, simtime_t lifeTime, const char *reason) const;

    /* Control Packet handlers */
    void handleRREP(const Ptr<Rrep>& rrep, const L3Address& sourceAddr);
    void handleRREQ(const Ptr<Rreq>& rreq, const L3Address& sourceAddr, unsigned int timeToLive);
    void handleRERR(const Ptr<const Rerr>& rerr, const L3Address& sourceAddr);
      void handleHelloMessage(const Ptr<Rrep>& helloMessage);
      void handleRREPACK(const Ptr<const RrepAck>& rrepACK, const L3Address& neighborAddr);
      simtime_t computeIntermediateRrepDelay(double localCbr, bool isDirectRouteToDestination) const;
      std::vector<double> parseDoubleList(const char *text) const;
      bool shouldBlockByMode(double value, double threshold, const std::string& mode) const;
      const char *describeModeRelation(const std::string& mode) const;
      bool isOutsideConfiguredCbrRange(double localCbr) const;
      void loadDlBasedRrepParameters();
      void loadDlBucketBasedRrepParameters();
      std::pair<double, double> inferDlBasedRrepThresholdRange(double localCbr, int neighborCount, unsigned int hopCount, bool isDirectRouteToDestination) const;
      std::pair<double, double> inferDlBucketBasedRrepThresholdRange(double localCbr, int neighborCount, unsigned int rreqHopCount) const;
      std::string buildDlBucketBasedStateKey(double localCbrNorm, double neighborNorm, double hopNorm, double isOriginatorNear) const;

    /* Control Packet sender methods */
    void sendRREQ(const Ptr<Rreq>& rreq, const L3Address& destAddr, unsigned int timeToLive);
    void sendRREPACK(const Ptr<RrepAck>& rrepACK, const L3Address& destAddr);
    void sendRREP(const Ptr<Rrep>& rrep, const L3Address& destAddr, unsigned int timeToLive, simtime_t delay = SIMTIME_ZERO);
    void sendGRREP(const Ptr<Rrep>& grrep, const L3Address& destAddr, unsigned int timeToLive);

    /* Control Packet forwarders */
    void forwardRREP(const Ptr<Rrep>& rrep, const L3Address& destAddr, unsigned int timeToLive);
    void forwardRREQ(const Ptr<Rreq>& rreq, unsigned int timeToLive);

    /* Self message handlers */
    void handleRREPACKTimer();
    void handleBlackListTimer();
    void sendHelloMessagesIfNeeded();
    void handleWaitForRREP(WaitForRrep *rrepTimer);

    /* General functions to handle route errors */
    void sendRERRWhenNoRouteToForward(const L3Address& unreachableAddr);
    void handleLinkBreakSendRERR(const L3Address& unreachableAddr);
    virtual void receiveSignal(cComponent *source, simsignal_t signalID, cObject *obj, cObject *details) override;

    /* Netfilter hooks */
    Result ensureRouteForDatagram(Packet *datagram);
    virtual Result datagramPreRoutingHook(Packet *datagram) override { Enter_Method("datagramPreRoutingHook"); return ensureRouteForDatagram(datagram); }
    virtual Result datagramForwardHook(Packet *datagram) override;
    virtual Result datagramPostRoutingHook(Packet *datagram) override { return ACCEPT; }
    virtual Result datagramLocalInHook(Packet *datagram) override { return ACCEPT; }
    virtual Result datagramLocalOutHook(Packet *datagram) override { Enter_Method("datagramLocalOutHook"); return ensureRouteForDatagram(datagram); }
    void delayDatagram(Packet *datagram);

    /* Helper functions */
    L3Address getSelfIPAddress() const;
    void sendAODVPacket(const Ptr<AodvControlPacket>& packet, const L3Address& destAddr, unsigned int timeToLive, double delay);
    void processPacket(Packet *pk);
    void clearState();
    void checkIpVersionAndPacketTypeCompatibility(AodvControlPacketType packetType);

    /* UDP callback interface */
    virtual void socketDataArrived(UdpSocket *socket, Packet *packet) override;
    virtual void socketErrorArrived(UdpSocket *socket, Indication *indication) override;
    virtual void socketClosed(UdpSocket *socket) override;
    double getLocalCbr() const;

    /* Lifecycle */
    virtual void handleStartOperation(LifecycleOperation *operation) override;
    virtual void handleStopOperation(LifecycleOperation *operation) override;
    virtual void handleCrashOperation(LifecycleOperation *operation) override;

  public:
    Aodv();
    virtual ~Aodv();
};

} // namespace aodv
} // namespace inet

#endif
