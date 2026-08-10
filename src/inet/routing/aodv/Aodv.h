//
// Copyright (C) 2014 OpenSim Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later
//


#ifndef __INET_AODV_H
#define __INET_AODV_H

#include <array>
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

    class INET_API AcceptedRreqRecord {
      public:
        L3Address destinationAddr;
        L3Address peerAddr;
        unsigned int hopCount = 0;
        simtime_t acceptedTime = SIMTIME_ZERO;
    };

    class INET_API SourceDiscoveryRecord {
      public:
        unsigned int rreqId = 0;
        simtime_t startTime = SIMTIME_ZERO;
        L3Address packetSourceAddr;
        L3Address packetDestinationAddr;
        bool isSelfOriginatedDatagram = false;
        bool hasDatagramContext = false;
    };

    class INET_API RouteHistoryKey {
      public:
        L3Address destinationAddr;
        L3Address nextHopAddr;
        RouteHistoryKey(const L3Address& destinationAddr, const L3Address& nextHopAddr) :
            destinationAddr(destinationAddr), nextHopAddr(nextHopAddr) {}
    };

    class INET_API RouteHistoryKeyCompare {
      public:
        bool operator()(const RouteHistoryKey& lhs, const RouteHistoryKey& rhs) const
        {
            if (lhs.destinationAddr < rhs.destinationAddr)
                return true;
            else if (lhs.destinationAddr > rhs.destinationAddr)
                return false;
            else
                return lhs.nextHopAddr < rhs.nextHopAddr;
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
        bool cbrBasedRreqRangeEnabled = false;
        bool cbrBasedRrepRangeFollowupRreqSuppressionEnabled = false;
        bool cbrBasedRrepDirectDestinationOnlyEnabled = false;
        int cbrBasedRrepLowThreshold = 0;
        int cbrBasedRrepHighThresholdForRange = 0;
      bool cbrBasedRandomThresholdEnabled = false;
      simtime_t cbrBasedRandomThresholdUpdateInterval;
      double cbrBasedRandomLowMin = 0;
      double cbrBasedRandomLowMax = 0;
      double cbrBasedRandomHighMin = 0;
      double cbrBasedRandomHighMax = 0;
      double cbrBasedRandomMinGap = 0;
      bool cbrBasedRrepDirectRouteBypassEnabled = false;
      bool dlBasedRrepEnabled = false;
      double dlBasedRrepScoreThreshold = 0;
      std::string dlBasedRrepCompareMode;
      std::string dlBasedRrepFeatureSet;
      int dlBasedRrepNeighborNorm = 0;
    int dlBasedRrepHopNorm = 0;
    double dlBasedRrepThresholdMin = 0;
    double dlBasedRrepThresholdMax = 100;
    double dlBasedRrepMinThresholdGap = 0;
    bool dlBasedRrepDirectThresholdOutputEnabled = false;
    bool dlBasedRrepCustomArchitectureEnabled = false;
    int dlBasedRrepHidden1Size = 32;
    int dlBasedRrepHidden2Size = 16;
    int dlBasedRrepHidden3Size = 128;
    std::vector<double> dlBasedRrepHiddenWeights;
    std::vector<double> dlBasedRrepHiddenBiases;
    std::vector<double> dlBasedRrepHidden2Weights;
    std::vector<double> dlBasedRrepHidden2Biases;
    std::vector<double> dlBasedRrepHidden3Weights;
    std::vector<double> dlBasedRrepHidden3Biases;
    std::vector<double> dlBasedRrepOutputWeights;
    std::vector<double> dlBasedRrepOutputBiases;
    bool dlDirectThresholdRrepEnabled = false;
    std::string dlDirectThresholdRrepFeatureSet;
    int dlDirectThresholdRrepNeighborNorm = 0;
    int dlDirectThresholdRrepHopNorm = 0;
    double dlDirectThresholdRrepThresholdMin = 0;
    double dlDirectThresholdRrepThresholdMax = 100;
    double dlDirectThresholdRrepMinThresholdGap = 0;
    bool dlDirectThresholdRrepInputStandardizationEnabled = false;
    bool dlDirectThresholdRrepOutputStandardizationEnabled = false;
    int dlDirectThresholdRrepHidden1Size = 256;
    int dlDirectThresholdRrepHidden2Size = 256;
    int dlDirectThresholdRrepHidden3Size = 128;
    std::vector<double> dlDirectThresholdRrepInputMeans;
    std::vector<double> dlDirectThresholdRrepInputScales;
    std::vector<double> dlDirectThresholdRrepOutputMeans;
    std::vector<double> dlDirectThresholdRrepOutputScales;
    std::vector<double> dlDirectThresholdRrepHiddenWeights;
    std::vector<double> dlDirectThresholdRrepHiddenBiases;
    std::vector<double> dlDirectThresholdRrepHidden2Weights;
    std::vector<double> dlDirectThresholdRrepHidden2Biases;
    std::vector<double> dlDirectThresholdRrepHidden3Weights;
    std::vector<double> dlDirectThresholdRrepHidden3Biases;
    std::vector<double> dlDirectThresholdRrepOutputWeights;
    std::vector<double> dlDirectThresholdRrepOutputBiases;
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
    bool stateLookupBasedRrepEnabled = false;
    bool stateLookupBasedRrepNearestFallbackEnabled = true;
    int stateLookupBasedRrepCbrBinSize = 5;
    int stateLookupBasedRrepNeighborBinSize = 5;
    int stateLookupBasedRrepHopMax = 6;
    std::string stateLookupBasedRrepPolicyCsvPath;
    struct StateLookupBasedRrepEntry {
        std::string key;
        int stateCbrBin = 0;
        int stateNeighborBin = 0;
        int stateHopBin = 0;
        int stateDirectBin = 0;
        double lowThreshold = 0;
        double highThreshold = 0;
    };
    std::map<std::string, StateLookupBasedRrepEntry> stateLookupBasedRrepEntriesByKey;
    std::vector<StateLookupBasedRrepEntry> stateLookupBasedRrepEntries;
    struct TreeBasedRrepNode {
        bool isLeaf = false;
        int featureIndex = -1;
        double threshold = 0;
        int leftIndex = -1;
        int rightIndex = -1;
        double value = 0;
    };
    using TreeBasedRrepTree = std::vector<TreeBasedRrepNode>;
    using TreeBasedRrepEnsemble = std::vector<TreeBasedRrepTree>;
    bool treeBasedRrepEnabled = false;
    std::string treeBasedRrepFeatureSet;
    int treeBasedRrepNeighborNorm = 0;
    int treeBasedRrepHopNorm = 0;
    double treeBasedRrepThresholdMin = 0;
    double treeBasedRrepThresholdMax = 100;
    double treeBasedRrepMinThresholdGap = 0;
    std::string treeBasedRrepModel;
    std::string treeBasedRrepLowModel;
    std::string treeBasedRrepHighModel;
    TreeBasedRrepEnsemble treeBasedRrepLowEnsemble;
    TreeBasedRrepEnsemble treeBasedRrepHighEnsemble;
    bool cbrBasedRrepDelayEnabled = false;
    int cbrBasedRrepModerateThreshold = 0;
    int cbrBasedRrepHighThreshold = 0;
    simtime_t cbrBasedRrepModerateDelay;
    simtime_t cbrBasedRrepHighDelay;
    bool cbrRrepMetricsEnabled = false;
    bool cbrRrepDecisionLogEnabled = false;
    bool aodvControlLogEnabled = false;
    bool dlDirectThresholdRrepDebugLogEnabled = false;
    bool cbrRouteCauseLogEnabled = false;
    bool transmissionFailureDiagnosisLogEnabled = false;
    bool radioStateDiagnosisLogEnabled = false;
    // Ground-truth raw dataset logging switch.
    bool groundTruthDatasetLogEnabled = false;
    bool inputDatasetLogEnabled = false;
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
    unsigned int inputRreqReceivedCount = 0;
    unsigned int inputRrepReceivedCount = 0;
    unsigned int inputRerrReceivedCount = 0;
    unsigned int inputMacAckReceivedCount = 0;
    unsigned int inputRrepAckReceivedCount = 0;
    unsigned int inputDataRouteUseCount = 0;
    unsigned int inputDataRouteMissCount = 0;
    std::vector<double> inputRreqReceiveSpeedSamplesKmh;
    unsigned int diagnosisNoRouteToForwardCount = 0;
    unsigned int diagnosisNoActiveRouteToForwardCount = 0;
    unsigned int diagnosisRouteInvalidateCount = 0;
    unsigned int diagnosisRouteExpireInactiveCount = 0;
    unsigned int diagnosisRouteDeleteCount = 0;
    unsigned int diagnosisRerrOriginatedCount = 0;
    int cbrBasedRandomThresholdEpoch = -1;
    double cbrBasedRandomActiveLowThreshold = 0;
    double cbrBasedRandomActiveHighThreshold = 0;

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
    std::map<RreqIdentifier, AcceptedRreqRecord, RreqIdentifierCompare> acceptedRreqRecords;
    std::map<L3Address, SourceDiscoveryRecord> sourceDiscoveryRecords;
    std::map<L3Address, SourceDiscoveryRecord> pendingSourceDiscoveryRecords;
    std::map<L3Address, simtime_t> cbrRangeBlockedFollowupRreqSuppressionExpirations;
    std::map<RouteHistoryKey, simtime_t, RouteHistoryKeyCompare> routeFirstFormedTimes;

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
    void logRadioStateDiagnosis1s();
    void logInputDataset1s();
    int countCurrentNeighbors() const;
    int getBdStationCount() const;
    double getCurrentNodeSpeed() const;
    void ensureAodvControlLogFile() const;
    void logAodvControlEvent(const std::string& event, const std::string& source, const std::string& target, const std::string& originator, const std::string& destination, const std::string& rreqId, const std::string& hopCount, const std::string& ttl, const std::string& retryCount, const std::string& jitter, const std::string& replyType = "", const std::string& localCbr = "", const std::string& appliedLowThreshold = "", const std::string& appliedHighThreshold = "", const std::string& destRouteNextHop = "", const std::string& reverseRouteNextHop = "", const std::string& packetSource = "", const std::string& packetDestination = "", const std::string& rawOriginatorIp = "", const std::string& rawDestinationIp = "", const std::string& resolvedOriginatorNode = "", const std::string& resolvedDestinationNode = "", const std::string& isSelfOriginatedDatagram = "") const;
    void ensureCbrRrepDecisionLogFile() const;
    std::string addressToNodeName(const L3Address& address) const;
    void logCbrRrepDecision(const Ptr<Rreq>& rreq, const L3Address& sourceAddr, double localCbr, const char *decision, double appliedLowThreshold, double appliedHighThreshold) const;
    void ensureDlDirectThresholdRrepDebugLogFile() const;
    void logDlDirectThresholdRrepDebug(const Ptr<Rreq>& rreq, const L3Address& sourceAddr, double localCbr, int neighborCount, unsigned int hopCount, bool isDirectRouteToDestination, const std::vector<double>& inputs, const std::array<double, 2>& rawOutputs, double predictedLow, double predictedHigh, const char *decision) const;
    void logRouteCauseEvent(const char *event, const L3Address& routeDest, const L3Address& nextHop, unsigned int hopCount, bool isActive, simtime_t lifeTime, const char *reason) const;
    // Ground-truth raw dataset logging helpers.
    void ensureGroundTruthDiscoveryLogFile() const;
    void ensureGroundTruthMaintenanceLogFile() const;
    void logGroundTruthDiscoveryEvent(const char *event, const L3Address& originator, const L3Address& destination, unsigned int rreqId,
            const L3Address& peer, unsigned int hopCount, int labelHint, const char *note,
            unsigned int matchedRreqId = 0, simtime_t pairedAcceptedTime = SIMTIME_ZERO,
            simtime_t sourceDiscoveryStartTime = SIMTIME_ZERO, simtime_t elapsedSincePaired = SIMTIME_ZERO,
            unsigned int sourceRetryCount = 0) const;
    void logGroundTruthMaintenanceEvent(const char *event, const L3Address& routeDest, const L3Address& nextHop, unsigned int hopCount,
            bool isActive, simtime_t lifeTime, const char *reason, const char *note,
            simtime_t routeFormedTime = SIMTIME_ZERO, simtime_t elapsedSinceRouteFormed = SIMTIME_ZERO,
            simtime_t remainingLifetime = SIMTIME_ZERO, simtime_t referenceLifetime = SIMTIME_ZERO,
            unsigned int precursorCount = 0, unsigned int unreachableCount = 0) const;
    int countAodvCapableNodes() const;
    bool findAcceptedRreqForRrep(const L3Address& originator, const L3Address& destination, unsigned int& matchedRreqId, simtime_t& acceptedTime) const;
    void rememberRouteFormation(const L3Address& routeDest, const L3Address& nextHop, simtime_t formedTime);
    simtime_t findRouteFormationTime(const L3Address& routeDest, const L3Address& nextHop) const;
    void eraseRouteFormation(const L3Address& routeDest, const L3Address& nextHop);

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
      std::pair<double, double> getActiveCbrThresholdRange();
      bool isOutsideConfiguredCbrRange(double localCbr, double& activeLowThreshold, double& activeHighThreshold);
      size_t getRrepFeatureInputSize(const std::string& featureSet) const;
      std::vector<double> buildRrepFeatureInputs(const std::string& featureSet, int neighborNormDiv, int hopNormDiv, double localCbr, int neighborCount, unsigned int hopCount, bool isDirectRouteToDestination) const;
      size_t getDlBasedRrepInputSize() const;
      std::vector<double> buildDlBasedRrepInputs(double localCbr, int neighborCount, unsigned int hopCount, bool isDirectRouteToDestination) const;
      TreeBasedRrepEnsemble parseTreeBasedRrepEnsemble(const std::string& text, size_t inputSize, const char *fieldName) const;
      double evaluateTreeBasedRrepEnsemble(const TreeBasedRrepEnsemble& ensemble, const std::vector<double>& inputs, const char *fieldName) const;
      void loadDlBasedRrepParameters();
      void loadDlDirectThresholdRrepParameters();
      void loadDlBucketBasedRrepParameters();
      void loadStateLookupBasedRrepParameters();
      void loadTreeBasedRrepParameters();
      std::pair<double, double> inferDlBasedRrepThresholdRange(double localCbr, int neighborCount, unsigned int hopCount, bool isDirectRouteToDestination) const;
      std::pair<double, double> inferDlDirectThresholdRrepThresholdRange(double localCbr, int neighborCount, unsigned int hopCount, bool isDirectRouteToDestination, std::vector<double> *debugInputs = nullptr, std::array<double, 2> *debugRawOutputs = nullptr) const;
      std::pair<double, double> inferDlBucketBasedRrepThresholdRange(double localCbr, int neighborCount, unsigned int rreqHopCount) const;
      std::pair<double, double> inferStateLookupBasedRrepThresholdRange(double localCbr, int neighborCount, unsigned int hopCount, bool isDirectRouteToDestination) const;
      std::pair<double, double> inferTreeBasedRrepThresholdRange(double localCbr, int neighborCount, unsigned int hopCount, bool isDirectRouteToDestination) const;
      std::string buildDlBucketBasedStateKey(double localCbrNorm, double neighborNorm, double hopNorm, double isOriginatorNear) const;
      std::string buildStateLookupBasedRrepStateKey(double localCbr, int neighborCount, unsigned int hopCount, bool isDirectRouteToDestination) const;

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
