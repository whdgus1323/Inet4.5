
#include "inet/routing/aodvSdn/AodvSdn.h"

#include "inet/common/IProtocolRegistrationListener.h"
#include "inet/common/ModuleAccess.h"
#include "inet/common/ProtocolTag_m.h"
#include "inet/common/packet/Packet.h"
#include "inet/common/stlutils.h"
#include "inet/linklayer/common/InterfaceTag_m.h"
#include "inet/networklayer/common/HopLimitTag_m.h"
#include "inet/networklayer/common/L3AddressResolver.h"
#include "inet/networklayer/common/L3AddressTag_m.h"
#include "inet/networklayer/common/L3Tools.h"
#include "inet/networklayer/ipv4/IcmpHeader.h"
#include "inet/networklayer/ipv4/Ipv4Header_m.h"
#include "inet/networklayer/ipv4/Ipv4Route.h"
#include "inet/transportlayer/common/L4PortTag_m.h"
#include "inet/transportlayer/contract/udp/UdpControlInfo.h"

#include <cmath>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "inet/mobility/contract/IMobility.h"
#include <unordered_map>
#include <string>

namespace inet {
namespace aodvSdn {

Define_Module(AodvSdn); // @suppress("Abstract class cannot be instantiated")

const int KIND_DELAYEDSEND = 100;

std::unordered_map<IRoute*, std::string> routeIdMap;
std::unordered_map<cModule*, double> nodeDpc;
std::unordered_map<cModule*, double> nodeArt;

std::unordered_map<cModule*, double> nodeLifeTime;
std::unordered_map<cModule*, double> nodeLifeTimeStart;

struct SpeedSample { SimTime t; double v_ms; };
std::unordered_map<cModule*, SpeedSample> nodeSpeeds;


double prevSpeed;
static double totalSpeed = 0.0;
static int speedCount = 0;
static double totalDensity = 0.0;
static int densityCount = 0;

double dpc_base = 160;
double art_base = 60.0;

void AodvSdn::initialize(int stage) {
    if (stage == INITSTAGE_ROUTING_PROTOCOLS)
        addressType = getSelfIPAddress().getAddressType();

    RoutingProtocolBase::initialize(stage);

    if (stage == INITSTAGE_LOCAL) {
        logRoutingTableTimer = new cMessage("logRoutingTableTimer");
        scheduleAt(simTime() + 10, logRoutingTableTimer);

        lastBroadcastTime = SIMTIME_ZERO;
        rebootTime = SIMTIME_ZERO;
        rreqId = sequenceNum = 0;
        rreqCount = rerrCount = 0;
        host = getContainingNode(this);
        routingTable.reference(this, "routingTableModule", true);
        interfaceTable.reference(this, "interfaceTableModule", true);
        networkProtocol.reference(this, "networkProtocolModule", true);

        aodvUDPPort = par("udpPort");
        askGratuitousRREP = par("askGratuitousRREP");

        if (hasPar("pwd"))   pwd   = par("pwd").stdstringValue();
        if (hasPar("pFlag")) pFlag = par("pFlag").boolValue();

        destinationOnlyFlag = par("destinationOnlyFlag");
        activeRouteTimeout = par("activeRouteTimeout");
        if (pFlag) {
            if (simTime() < SimTime(100)) {
                useHelloMessages = true;
            } else {
                useHelloMessages = true;
            }
        } else {
            useHelloMessages = true;
        }

        helloInterval = par("helloInterval");
        allowedHelloLoss = par("allowedHelloLoss");
        netDiameter = par("netDiameter");
        nodeTraversalTime = par("nodeTraversalTime");
        rerrRatelimit = par("rerrRatelimit");
        rreqRetries = par("rreqRetries");
        rreqRatelimit = par("rreqRatelimit");
        timeoutBuffer = par("timeoutBuffer");
        ttlStart = par("ttlStart");
        ttlIncrement = par("ttlIncrement");
        ttlThreshold = par("ttlThreshold");
        localAddTTL = par("localAddTTL");
        jitterPar = &par("jitter");
        periodicJitter = &par("periodicJitter");

        myRouteTimeout = par("myRouteTimeout");

        deletePeriod = par("deletePeriod");

        blacklistTimeout = par("blacklistTimeout");
        netTraversalTime = par("netTraversalTime");
        nextHopWait = par("nextHopWait");
        pathDiscoveryTime = par("pathDiscoveryTime");
        expungeTimer = new cMessage("ExpungeTimer");
        counterTimer = new cMessage("CounterTimer");
        rrepAckTimer = new cMessage("RrepAckTimer");
        blacklistTimer = new cMessage("BlackListTimer");
        if (useHelloMessages)
            helloMsgTimer = new cMessage("HelloMsgTimer");
    } else if (stage == INITSTAGE_ROUTING_PROTOCOLS) {
        networkProtocol->registerHook(0, this);
        host->subscribe(linkBrokenSignal, this);
        usingIpv6 = (routingTable->getRouterIdAsGeneric().getType()
                == L3Address::IPv6);
    }


}

void AodvSdn::handleMessageWhenUp(cMessage *msg) {
    if (msg->isSelfMessage()) {
        if (auto waitForRrep = dynamic_cast<WaitForRrep*>(msg))
            handleWaitForRREP(waitForRrep);
        else if (msg == helloMsgTimer)
            sendHelloMessagesIfNeeded();
        else if (msg == expungeTimer)
            expungeRoutes();
        else if (msg == counterTimer) {
            rreqCount = rerrCount = 0;
            scheduleAfter(1, counterTimer);
        } else if (msg == rrepAckTimer)
            handleRREPACKTimer();
        else if (msg == blacklistTimer)
            handleBlackListTimer();
        else if (msg->getKind() == KIND_DELAYEDSEND) {
            auto timer = check_and_cast<PacketHolderMessage*>(msg);
            socket.send(timer->removeOwnedPacket());
            delete timer;
        }
        else if (msg == logRoutingTableTimer) {
            std::ofstream rtLog(pwd + "/routing_table_log.csv", std::ios::app);
            static bool firstWrite = true;
            if (firstWrite) {
                rtLog << "Time,Node,Destination,NextHop,Metric,Lifetime,DestSeq,Active\n";
                firstWrite = false;
            }


            std::ofstream posLog(pwd + "/position.csv", std::ios::app);
            static bool posHeaderWritten = false;
            if (!posHeaderWritten && posLog.tellp() == 0) {
                posLog << "Time,Node,NodeX,NodeY,NodeZ,NextHop,NextHopX,NextHopY,NextHopZ,Active\n";
                posHeaderWritten = true;
            }

            auto getNodePosition = [](cModule* node) -> inet::Coord {
                if (!node) return inet::Coord(-1, -1, -1);
                cModule* mob = node->getSubmodule("mobility");
                if (!mob) return inet::Coord(-1, -1, -1);
                if (auto* mobility = dynamic_cast<inet::IMobility*>(mob))
                    return mobility->getCurrentPosition();
                return inet::Coord(-1, -1, -1);
            };

            inet::Coord nodePos(-1, -1, -1);
            {
                cModule* selfMob = getParentModule()->getSubmodule("mobility");
                if (auto* mobility = dynamic_cast<inet::IMobility*>(selfMob))
                    nodePos = mobility->getCurrentPosition();
                else
                    std::cerr << simTime() << " : ERRER!" << std::endl;
            }

            for (int i = 0; i < routingTable->getNumRoutes(); i++) {
                IRoute *route = routingTable->getRoute(i);
                auto *aodvData = dynamic_cast<AodvSdnRouteData *>(route->getProtocolData());
                if (!aodvData){
                    continue;
                }


                L3Address destAddr = route->getDestinationAsGeneric();
                L3Address nextHopAddr = route->getNextHopAsGeneric();

                cModule *destNode = L3AddressResolver().findHostWithAddress(destAddr);
                cModule *nextHopNode = L3AddressResolver().findHostWithAddress(nextHopAddr);

                std::string destName = destNode ? destNode->getFullName() : destAddr.str();
                std::string nextHopName = nextHopNode ? nextHopNode->getFullName() : nextHopAddr.str();

                if (nextHopNode) {
                    inet::Coord nextHopPos = getNodePosition(nextHopNode);
                    posLog << simTime() << ","
                            << getParentModule()->getFullName() << ","
                            << nodePos.x << "," << nodePos.y << "," << nodePos.z << ","
                            << nextHopName << ","
                            << nextHopPos.x << "," << nextHopPos.y << "," << nextHopPos.z << ","
                            << (aodvData->isActive() ? "true" : "false") << "\n";
                }


                const char *className = aodvData->getClassName();
                const char *packetName = (!strncmp("inet::", className, 6)) ? className + 6 : className;
                if (strlen(packetName) == 0)
                    packetName = "AODV_Packet";

                Packet *packet = new Packet(packetName);

                rtLog << simTime() << ","
                        << getParentModule()->getFullName() << ","
                        << destName << "," << nextHopName << ","
                        << route->getMetric() << "," << aodvData->getLifeTime() << ","
                        << aodvData->getDestSeqNum() << "," << (aodvData->isActive() ? "true" : "false") << "\n";

                delete packet;
            }

            rtLog.close();
            posLog.close();
            scheduleAt(simTime() + 1, logRoutingTableTimer);
        }

        else
            throw cRuntimeError("Unknown self message");
    } else
        socket.processMessage(msg);
}

void AodvSdn::checkIpVersionAndPacketTypeCompatibility(AodvSdnControlPacketType packetType) {
    switch (packetType) {
    case RREQ:
    case RREP:
    case RERR:
    case RREPACK:
        if (usingIpv6)
            throw cRuntimeError(
                    "AODV Control Packet arrived with non-IPv6 packet type %d, but AODV configured for IPv6 routing",
                    packetType);
        break;

    case RREQ_IPv6:
    case RREP_IPv6:
    case RERR_IPv6:
    case RREPACK_IPv6:
        if (!usingIpv6)
            throw cRuntimeError(
                    "AODV Control Packet arrived with IPv6 packet type %d, but AODV configured for non-IPv6 routing",
                    packetType);
        break;

    default:
        throw cRuntimeError(
                "AODV Control Packet arrived with undefined packet type: %d",
                packetType);
    }
}

void AodvSdn::processPacket(Packet *packet) {
    L3Address sourceAddr = packet->getTag<L3AddressInd>()->getSrcAddress();
    unsigned int arrivalPacketTTL = packet->getTag<HopLimitInd>()->getHopLimit()
                                                    - 1;
    const auto &aodvPacket = packet->popAtFront<AodvSdnControlPacket>();

    auto packetType = aodvPacket->getPacketType();
    switch (packetType) {
    case RREQ:
    case RREQ_IPv6:
        checkIpVersionAndPacketTypeCompatibility(packetType);
        handleRREQ(CHK(dynamicPtrCast<Rreq>(aodvPacket->dupShared())),
                sourceAddr, arrivalPacketTTL);
        delete packet;
        return;

    case RREP:
    case RREP_IPv6:
        checkIpVersionAndPacketTypeCompatibility(packetType);
        handleRREP(CHK(dynamicPtrCast<Rrep>(aodvPacket->dupShared())),
                sourceAddr);
        delete packet;
        return;

    case RERR:
    case RERR_IPv6:
        checkIpVersionAndPacketTypeCompatibility(packetType);
        handleRERR(CHK(dynamicPtrCast<const Rerr>(aodvPacket)), sourceAddr);
        delete packet;
        return;

    case RREPACK:
    case RREPACK_IPv6:
        checkIpVersionAndPacketTypeCompatibility(packetType);
        handleRREPACK(CHK(dynamicPtrCast<const RrepAck>(aodvPacket)),
                sourceAddr);
        delete packet;
        return;

    default:
        throw cRuntimeError(
                "AODV Control Packet arrived with undefined packet type: %d",
                packetType);
    }
}

INetfilter::IHook::Result AodvSdn::ensureRouteForDatagram(Packet *datagram) {
    const auto &networkHeader = getNetworkProtocolHeader(datagram);
    const L3Address &destAddr = networkHeader->getDestinationAddress();
    const L3Address &sourceAddr = networkHeader->getSourceAddress();

    if (destAddr.isBroadcast() || routingTable->isLocalAddress(destAddr)
            || destAddr.isMulticast())
        return ACCEPT;
    else {
        EV_INFO << "Finding route for source " << sourceAddr
                << " with destination " << destAddr << endl;
        IRoute *route = routingTable->findBestMatchingRoute(destAddr);
        AodvSdnRouteData *routeData =
                route ? dynamic_cast<AodvSdnRouteData*>(route->getProtocolData()) : nullptr;
        bool isActive = routeData && routeData->isActive();
        if (isActive && !route->getNextHopAsGeneric().isUnspecified()) {
            EV_INFO << "Active route found: " << route << endl;

            if (pFlag) {
                if (nodeArt[getParentModule()] == 0) {
                    nodeArt[getParentModule()] = 3;
                }
                updateValidRouteLifeTime(destAddr,
                        simTime() + simtime_t(nodeArt[getParentModule()]));
                nodeLifeTimeStart[getParentModule()] =
                        nodeArt[getParentModule()];
                updateValidRouteLifeTime(route->getNextHopAsGeneric(),
                        simTime() + simtime_t(nodeArt[getParentModule()]));
            } else {
                updateValidRouteLifeTime(destAddr,
                        simTime() + simtime_t(activeRouteTimeout));
                updateValidRouteLifeTime(route->getNextHopAsGeneric(),
                        simTime() + simtime_t(activeRouteTimeout));
            }

            return ACCEPT;
        } else {
            bool isInactive = routeData && !routeData->isActive();

            EV_INFO << (isInactive ? "Inactive" : "Missing")
                                                                   << " route for destination " << destAddr << endl;

            delayDatagram(datagram);

            if (!hasOngoingRouteDiscovery(destAddr)) {
                if (isInactive)
                    startRouteDiscovery(destAddr,
                            route->getMetric() + ttlIncrement);
                else
                    startRouteDiscovery(destAddr);
            } else
                EV_DETAIL << "Route discovery is in progress, originator "
                << getSelfIPAddress() << " target " << destAddr
                << endl;

            return QUEUE;
        }
    }
}

AodvSdn::AodvSdn() {
}

bool AodvSdn::hasOngoingRouteDiscovery(const L3Address &target) {
    return containsKey(waitForRREPTimers, target);
}

void AodvSdn::startRouteDiscovery(const L3Address &target, unsigned timeToLive) {
    EV_INFO << "Starting route discovery with originator " << getSelfIPAddress()
                                                           << " and destination " << target << endl;
    ASSERT(!hasOngoingRouteDiscovery(target));
    auto rreq = createRREQ(target);
    addressToRreqRetries[target] = 0;
    sendRREQ(rreq, addressType->getBroadcastAddress(), timeToLive);
}

L3Address AodvSdn::getSelfIPAddress() const {
    return routingTable->getRouterIdAsGeneric();
}

void AodvSdn::delayDatagram(Packet *datagram) {
    const auto &networkHeader = getNetworkProtocolHeader(datagram);
    EV_DETAIL << "Queuing datagram, source "
            << networkHeader->getSourceAddress() << ", destination "
            << networkHeader->getDestinationAddress() << endl;
    const L3Address &target = networkHeader->getDestinationAddress();
    targetAddressToDelayedPackets.insert(
            std::pair<L3Address, Packet*>(target, datagram));
}

void AodvSdn::sendRREQ(const Ptr<Rreq> &rreq, const L3Address &destAddr,
        unsigned int timeToLive) {

    std::ofstream recoveryLog(pwd + "/recovery_log.csv", std::ios::app);
    recoveryLog << simTime() << "," << getParentModule()->getFullName() << ","
            << rreq->getDestAddr() << ",RREQ_SENT\n";
    recoveryLog.close();

    if (rreqCount >= rreqRatelimit) {
        EV_WARN
        << "A node should not originate more than RREQ_RATELIMIT RREQ messages per second. Canceling sending RREQ"
        << endl;
        return;
    }

    auto rrepTimer = waitForRREPTimers.find(rreq->getDestAddr());
    WaitForRrep *rrepTimerMsg = nullptr;
    if (rrepTimer != waitForRREPTimers.end()) {
        rrepTimerMsg = rrepTimer->second;
        unsigned int lastTTL = rrepTimerMsg->getLastTTL();
        rrepTimerMsg->setDestAddr(rreq->getDestAddr());

        if (timeToLive != 0) {
            rrepTimerMsg->setLastTTL(timeToLive);
            rrepTimerMsg->setFromInvalidEntry(true);
            cancelEvent(rrepTimerMsg);
        } else if (lastTTL + ttlIncrement < ttlThreshold) {
            ASSERT(!rrepTimerMsg->isScheduled());
            timeToLive = lastTTL + ttlIncrement;
            rrepTimerMsg->setLastTTL(lastTTL + ttlIncrement);
        } else {
            ASSERT(!rrepTimerMsg->isScheduled());
            timeToLive = netDiameter;
            rrepTimerMsg->setLastTTL(netDiameter);
        }
    } else {
        rrepTimerMsg = new WaitForRrep();
        waitForRREPTimers[rreq->getDestAddr()] = rrepTimerMsg;
        ASSERT(hasOngoingRouteDiscovery(rreq->getDestAddr()));

        timeToLive = ttlStart;
        rrepTimerMsg->setLastTTL(ttlStart);
        rrepTimerMsg->setFromInvalidEntry(false);
        rrepTimerMsg->setDestAddr(rreq->getDestAddr());
    }

    simtime_t ringTraversalTime = 2.0 * nodeTraversalTime
            * (timeToLive + timeoutBuffer);
    scheduleAfter(ringTraversalTime, rrepTimerMsg);

    EV_INFO << "Sending a Route Request with target " << rreq->getDestAddr()
                                                           << " and TTL= " << timeToLive << endl;
    sendAODVPacket(rreq, destAddr, timeToLive, *jitterPar);
    rreqCount++;
}

void AodvSdn::sendRREP(const Ptr<Rrep> &rrep, const L3Address &destAddr,
        unsigned int timeToLive) {

    if (destAddr.isBroadcast() || destAddr.isUnspecified()) {
        std::cerr << "WARNING: RREP destination address is invalid: "
                << destAddr << endl;
    }

    EV_INFO << "Sending Route Reply to " << destAddr << endl;
    IRoute *destRoute = routingTable->findBestMatchingRoute(destAddr);
    const L3Address &nextHop = destRoute->getNextHopAsGeneric();
    AodvSdnRouteData *destRouteData = check_and_cast<AodvSdnRouteData*>(
            destRoute->getProtocolData());
    destRouteData->addPrecursor(nextHop);

    if (destRoute->getMetric() == 1) {
        rrep->setAckRequiredFlag(true);
        failedNextHop = nextHop;
        rescheduleAfter(nextHopWait, rrepAckTimer);
    }
    sendAODVPacket(rrep, nextHop, timeToLive, 0);
}

const Ptr<Rreq> AodvSdn::createRREQ(const L3Address &destAddr) {
    auto rreqPacket = makeShared<Rreq>();
    rreqPacket->setPacketType(usingIpv6 ? RREQ_IPv6 : RREQ);
    rreqPacket->setChunkLength(usingIpv6 ? B(48) : B(24));

    rreqPacket->setGratuitousRREPFlag(askGratuitousRREP);
    IRoute *lastKnownRoute = routingTable->findBestMatchingRoute(destAddr);

    sequenceNum++;

    rreqPacket->setOriginatorSeqNum(sequenceNum);

    if (lastKnownRoute && lastKnownRoute->getSource() == this) {
        AodvSdnRouteData *routeData = check_and_cast<AodvSdnRouteData*>(
                lastKnownRoute->getProtocolData());
        if (routeData && routeData->hasValidDestNum()) {
            rreqPacket->setDestSeqNum(routeData->getDestSeqNum());
            rreqPacket->setUnknownSeqNumFlag(false);
        } else
            rreqPacket->setUnknownSeqNumFlag(true);
    } else
        rreqPacket->setUnknownSeqNumFlag(true);
    rreqPacket->setOriginatorAddr(getSelfIPAddress());
    rreqPacket->setDestAddr(destAddr);

    rreqId++;
    rreqPacket->setRreqId(rreqId);
    rreqPacket->setHopCount(0);
    rreqPacket->setDestOnlyFlag(destinationOnlyFlag);

    RreqIdentifier rreqIdentifier(getSelfIPAddress(), rreqId);
    rreqsArrivalTime[rreqIdentifier] = simTime();
    return rreqPacket;
}

const Ptr<Rrep> AodvSdn::createRREP(const Ptr<Rreq> &rreq, IRoute *destRoute,
        IRoute *originatorRoute, const L3Address &lastHopAddr) {
    auto rrep = makeShared<Rrep>();
    rrep->setPacketType(usingIpv6 ? RREP_IPv6 : RREP);
    rrep->setChunkLength(usingIpv6 ? B(44) : B(20));
    rrep->setDestAddr(rreq->getDestAddr());
    rrep->setOriginatorAddr(rreq->getOriginatorAddr());
    //std::cerr << "Ceate RREP" << std::endl;

    if (rreq->getDestAddr() == getSelfIPAddress()) {
        if (!rreq->getUnknownSeqNumFlag()
                && sequenceNum + 1 == rreq->getDestSeqNum())
            sequenceNum++;

        rrep->setDestSeqNum(sequenceNum);
        rrep->setHopCount(0);
        //rrep->setLifeTime(SimTime(myRouteTimeout, SIMTIME_MS));


        if (pFlag) myRouteTimeout = 3 * (simTime() + simtime_t(nodeArt[getParentModule()]));

        //std::cout << activeRouteTimeout << " : "  << deletePeriod << " : "<< myRouteTimeout << std::endl;
        rrep->setLifeTime(myRouteTimeout.trunc(SIMTIME_MS));
        nodeLifeTimeStart[getParentModule()] = nodeArt[getParentModule()];
        //std::cerr << rrep->getLifeTime() - simTime() << std::endl;
    } else {
        AodvSdnRouteData *destRouteData = check_and_cast<AodvSdnRouteData*>(
                destRoute->getProtocolData());
        AodvSdnRouteData *originatorRouteData = check_and_cast<AodvSdnRouteData*>(
                originatorRoute->getProtocolData());
        rrep->setDestSeqNum(destRouteData->getDestSeqNum());
        destRouteData->addPrecursor(lastHopAddr);
        originatorRouteData->addPrecursor(destRoute->getNextHopAsGeneric());
        rrep->setHopCount(destRoute->getMetric());
        rrep->setLifeTime(
                (destRouteData->getLifeTime() - simTime()).trunc(SIMTIME_MS));
        //std::cerr << destRouteData->getLifeTime() - simTime() << std::endl;
    }

    return rrep;
}

const Ptr<Rrep> AodvSdn::createGratuitousRREP(const Ptr<Rreq> &rreq,
        IRoute *originatorRoute) {
    ASSERT(originatorRoute != nullptr);
    auto grrep = makeShared<Rrep>();
    grrep->setPacketType(usingIpv6 ? RREP_IPv6 : RREP);
    grrep->setChunkLength(usingIpv6 ? B(44) : B(20));

    AodvSdnRouteData *routeData = check_and_cast<AodvSdnRouteData*>(
            originatorRoute->getProtocolData());
    grrep->setHopCount(originatorRoute->getMetric());
    grrep->setDestAddr(rreq->getOriginatorAddr());
    grrep->setDestSeqNum(rreq->getOriginatorSeqNum());
    grrep->setOriginatorAddr(rreq->getDestAddr());
    grrep->setLifeTime(routeData->getLifeTime());
    return grrep;
}

void AodvSdn::handleRREP(const Ptr<Rrep> &rrep, const L3Address &sourceAddr) {
    EV_INFO << "AODV Route Reply arrived with source addr: " << sourceAddr
            << " originator addr: " << rrep->getOriginatorAddr()
            << " destination addr: " << rrep->getDestAddr() << endl;

    if (rrep->getOriginatorAddr().isUnspecified()) {
        EV_INFO << "This Route Reply is a Hello Message" << endl;
        handleHelloMessage(rrep);
        return;
    } else {
        /*        std::ofstream rrepCnt("data/rrepCnt.txt", std::ios::app);
         //rrepCnt << getParentModule()->getFullName() << std::endl;
         rrepCnt << "AODV Route Reply arrived with source addr: " << sourceAddr << " originator addr: " << rrep->getOriginatorAddr() << " destination addr: " << rrep->getDestAddr() << endl;
         rrepCnt.close();*/

        std::ofstream recoveryLog(pwd + "/recovery_log.csv", std::ios::app);
        recoveryLog << simTime() << "," << getParentModule()->getFullName()
                                                            << "," << rrep->getDestAddr() << ",RREP_RECV\n";
        recoveryLog.close();

    }

    IRoute *previousHopRoute = routingTable->findBestMatchingRoute(sourceAddr);

    if (pFlag) {
        if (nodeArt[getParentModule()] == 0) {
            nodeArt[getParentModule()] = 3;
        }
        if (!previousHopRoute || previousHopRoute->getSource() != this) {
            previousHopRoute = createRoute(sourceAddr, sourceAddr, 1, false,
                    rrep->getDestSeqNum(), true,
                    simTime() + simtime_t(nodeArt[getParentModule()]));
        } else
            updateRoutingTable(previousHopRoute, sourceAddr, 1, false,
                    rrep->getDestSeqNum(), true,
                    simTime() + simtime_t(nodeArt[getParentModule()]));
    } else {
        if (!previousHopRoute || previousHopRoute->getSource() != this) {
            previousHopRoute = createRoute(sourceAddr, sourceAddr, 1, false,
                    rrep->getDestSeqNum(), true,
                    simTime() + simtime_t(activeRouteTimeout));
        } else
            updateRoutingTable(previousHopRoute, sourceAddr, 1, false,
                    rrep->getDestSeqNum(), true,
                    simTime() + simtime_t(activeRouteTimeout));
    }

    unsigned int newHopCount = rrep->getHopCount() + 1;
    rrep->setHopCount(newHopCount);
    IRoute *destRoute = routingTable->findBestMatchingRoute(
            rrep->getDestAddr());
    AodvSdnRouteData *destRouteData = nullptr;
    simtime_t lifeTime = rrep->getLifeTime();
    unsigned int destSeqNum = rrep->getDestSeqNum();

    if (destRoute && destRoute->getSource() == this) {
        destRouteData = check_and_cast<AodvSdnRouteData*>(
                destRoute->getProtocolData());

        if (!destRouteData->hasValidDestNum()) {
            updateRoutingTable(destRoute, sourceAddr, newHopCount, true,
                    destSeqNum, true, simTime() + lifeTime);
        } else if (destSeqNum > destRouteData->getDestSeqNum()) {
            updateRoutingTable(destRoute, sourceAddr, newHopCount, true,
                    destSeqNum, true, simTime() + lifeTime);
        } else {
            if (destSeqNum == destRouteData->getDestSeqNum()
                    && !destRouteData->isActive()) {
                updateRoutingTable(destRoute, sourceAddr, newHopCount, true,
                        destSeqNum, true, simTime() + lifeTime);
            } else if (destSeqNum == destRouteData->getDestSeqNum()
                    && newHopCount < (unsigned int) destRoute->getMetric()) {
                updateRoutingTable(destRoute, sourceAddr, newHopCount, true,
                        destSeqNum, true, simTime() + lifeTime);
            }
        }
    } else {
        destRoute = createRoute(rrep->getDestAddr(), sourceAddr, newHopCount,
                true, destSeqNum, true, simTime() + lifeTime);
        destRouteData = check_and_cast<AodvSdnRouteData*>(
                destRoute->getProtocolData());
    }

    IRoute *originatorRoute = routingTable->findBestMatchingRoute(
            rrep->getOriginatorAddr());
    if (getSelfIPAddress() != rrep->getOriginatorAddr()) {
        if (originatorRoute && originatorRoute->getSource() == this) {
            AodvSdnRouteData *originatorRouteData = check_and_cast<AodvSdnRouteData*>(
                    originatorRoute->getProtocolData());
            simtime_t existingLifeTime = originatorRouteData->getLifeTime();
            if (pFlag) {
                if (nodeArt[getParentModule()] == 0) {
                    nodeArt[getParentModule()] = 3;
                }
                originatorRouteData->setLifeTime(
                        std::max(
                                simTime()
                                + simtime_t(nodeArt[getParentModule()]),
                                existingLifeTime));
            } else {
                originatorRouteData->setLifeTime(
                        std::max(simTime() + simtime_t(activeRouteTimeout),
                                existingLifeTime));
            }

            if (pFlag) {
                if (nodeDpc[getParentModule()] == 0)
                    nodeDpc[getParentModule()] = 15;
                if (simTime()
                        > rebootTime + simtime_t(nodeDpc[getParentModule()])
                        || rebootTime == 0) {

                    if (rrep->getAckRequiredFlag()) {
                        auto rrepACK = createRREPACK();
                        sendRREPACK(rrepACK, sourceAddr);
                        rrep->setAckRequiredFlag(false);
                    }
                    destRouteData->addPrecursor(
                            originatorRoute->getNextHopAsGeneric());
                    IRoute *nextHopToDestRoute =
                            routingTable->findBestMatchingRoute(
                                    destRoute->getNextHopAsGeneric());
                    if (nextHopToDestRoute
                            && nextHopToDestRoute->getSource() == this) {
                        AodvSdnRouteData *nextHopToDestRouteData = check_and_cast<
                                AodvSdnRouteData*>(
                                        nextHopToDestRoute->getProtocolData());
                        nextHopToDestRouteData->addPrecursor(
                                originatorRoute->getNextHopAsGeneric());
                    }
                    auto outgoingRREP = dynamicPtrCast<Rrep>(rrep->dupShared());
                    forwardRREP(outgoingRREP,
                            originatorRoute->getNextHopAsGeneric(), 100);
                }
            } else {
                if (simTime() > rebootTime + simtime_t(deletePeriod)
                        || rebootTime == 0) {

                    if (rrep->getAckRequiredFlag()) {
                        auto rrepACK = createRREPACK();
                        sendRREPACK(rrepACK, sourceAddr);
                        rrep->setAckRequiredFlag(false);
                    }
                    destRouteData->addPrecursor(
                            originatorRoute->getNextHopAsGeneric());
                    IRoute *nextHopToDestRoute =
                            routingTable->findBestMatchingRoute(
                                    destRoute->getNextHopAsGeneric());
                    if (nextHopToDestRoute
                            && nextHopToDestRoute->getSource() == this) {
                        AodvSdnRouteData *nextHopToDestRouteData = check_and_cast<
                                AodvSdnRouteData*>(
                                        nextHopToDestRoute->getProtocolData());
                        nextHopToDestRouteData->addPrecursor(
                                originatorRoute->getNextHopAsGeneric());
                    }
                    auto outgoingRREP = dynamicPtrCast<Rrep>(rrep->dupShared());
                    forwardRREP(outgoingRREP,
                            originatorRoute->getNextHopAsGeneric(), 100);
                }
            }
        }

        else
            EV_ERROR << "Reverse route doesn't exist. Dropping the RREP message"
            << endl;
    } else {
        if (hasOngoingRouteDiscovery(rrep->getDestAddr())) {
            EV_INFO
            << "The Route Reply has arrived for our Route Request to node "
            << rrep->getDestAddr() << endl;
            updateRoutingTable(destRoute, sourceAddr, newHopCount, true,
                    destSeqNum, true, simTime() + lifeTime);
            completeRouteDiscovery(rrep->getDestAddr());
        }
    }
}

void AodvSdn::updateRoutingTable(IRoute *route, const L3Address &nextHop,
        unsigned int hopCount, bool hasValidDestNum, unsigned int destSeqNum,
        bool isActive, simtime_t lifeTime) {


    EV << "[AODV] Updating existing route: " << route->getDestinationAsGeneric()
                                                      << std::endl;

    L3Address prevNextHop = route->getNextHopAsGeneric();
    unsigned int prevHopCount = route->getMetric();

    AodvSdnRouteData *routingData = check_and_cast<AodvSdnRouteData*>(
            route->getProtocolData());
    ASSERT(routingData != nullptr);

    simtime_t prevLifeTime = routingData->getLifeTime();
    unsigned int prevDestSeqNum = routingData->getDestSeqNum();
    bool prevIsActive = routingData->isActive();
    bool prevHasValidDestNum = routingData->hasValidDestNum();

    route->setNextHop(nextHop);
    route->setMetric(hopCount);
    routingData->setLifeTime(lifeTime);
    routingData->setDestSeqNum(destSeqNum);
    routingData->setIsActive(isActive);
    routingData->setHasValidDestNum(hasValidDestNum);

    scheduleExpungeRoutes();
}


void AodvSdn::sendAODVPacket(const Ptr<AodvSdnControlPacket> &aodvPacket,
        const L3Address &destAddr, unsigned int timeToLive, double delay) {
    ASSERT(timeToLive != 0);

    const char *className = aodvPacket->getClassName();
    const char *packetName = (
            !strncmp("inet::", className, 6) ? className + 6 : className);
    if (strlen(packetName) == 0)
        packetName = "AODV_Packet";

    Packet *packet = new Packet(packetName, aodvPacket);

    L3Address srcAddr;
    if (packet->findTag<L3AddressInd>())
        srcAddr = packet->getTag<L3AddressInd>()->getSrcAddress();
    else
        srcAddr = L3Address();
    const char *nodeName = getContainingNode(this)->getFullName();

    bool isHello = false;
    if (auto rrep = dynamicPtrCast<Rrep>(aodvPacket)) {
        if (rrep->getHopCount() == 0 && destAddr.isBroadcast()) {
            isHello = true;
        }
    }

    int interfaceId =
            CHK(interfaceTable->findInterfaceByName(par("interface")))->getInterfaceId();
    packet->addTag<InterfaceReq>()->setInterfaceId(interfaceId);
    packet->addTag<HopLimitReq>()->setHopLimit(timeToLive);
    packet->addTag<L3AddressReq>()->setDestAddress(destAddr);
    packet->addTag<L4PortReq>()->setDestPort(aodvUDPPort);

    if (destAddr.isBroadcast())
        lastBroadcastTime = simTime();

    if (delay == 0)
        socket.send(packet);
    else {
        auto *timer = new PacketHolderMessage("aodv-send-jitter",
                KIND_DELAYEDSEND);
        timer->setOwnedPacket(packet);
        scheduleAfter(delay, timer);
    }
}

void AodvSdn::socketDataArrived(UdpSocket *socket, Packet *packet) {
    processPacket(packet);
}

void AodvSdn::socketErrorArrived(UdpSocket *socket, Indication *indication) {
    EV_WARN << "Ignoring UDP error report " << indication->getName() << endl;
    delete indication;
}

void AodvSdn::socketClosed(UdpSocket *socket) {
    if (operationalState == State::STOPPING_OPERATION)
        startActiveOperationExtraTimeOrFinish(par("stopOperationExtraTime"));
}

void AodvSdn::handleRREQ(const Ptr<Rreq> &rreq, const L3Address &sourceAddr,
        unsigned int timeToLive) {
    EV_INFO << "AODV Route Request arrived with source addr: " << sourceAddr
            << " originator addr: " << rreq->getOriginatorAddr()
            << " destination addr: " << rreq->getDestAddr() << endl;

    double currentTime = simTime().dbl();
    int    nodeIndex   = -1;
    int    neighborCount = 0;
    double vehicleSpeed  = 0.0;

    do {
        cModule *host = getParentModule();
        if (!host) break;
        nodeIndex = host->getIndex();

        cModule *mobilityModule = host->getSubmodule("mobility");
        if (!mobilityModule) break;

        inet::IMobility *mobility = check_and_cast<inet::IMobility*>(mobilityModule);
        vehicleSpeed = mobility->getCurrentVelocity().length();

        const double radius = 110.0;
        inet::Coord myPosition = mobility->getCurrentPosition();
        cModule *network = host->getParentModule();
        if (!network) break;

        for (cModule::SubmoduleIterator it(network); !it.end(); ++it) {
            cModule *other = *it;
            if (other == host) continue;
            if (strncmp(other->getFullName(), "node[", 5) != 0) continue;

            cModule *otherMobilityModule = other->getSubmodule("mobility");
            if (!otherMobilityModule) continue;

            inet::IMobility *otherMobility = check_and_cast<inet::IMobility*>(otherMobilityModule);
            double distance = myPosition.distance(otherMobility->getCurrentPosition());
            if (distance <= radius) neighborCount++;
        }
    } while (false);

    if (containsKey(blacklist, sourceAddr)) {
        EV << "The sender node " << sourceAddr
           << " is in our blacklist. Ignoring the Route Request" << endl;
        return;
    }

    IRoute *previousHopRoute = routingTable->findBestMatchingRoute(sourceAddr);
    if (!previousHopRoute || previousHopRoute->getSource() != this) {
        previousHopRoute = createRoute(sourceAddr, sourceAddr, /*hopCount*/ 1,
                /*hasValidDestNum*/ false, rreq->getOriginatorSeqNum(),
                /*isActive*/ true,
                /*lifeTime*/ simTime() + simtime_t(activeRouteTimeout));
    } else {
        updateRoutingTable(previousHopRoute, sourceAddr, /*hopCount*/ 1,
                /*hasValidDestNum*/ false, rreq->getOriginatorSeqNum(),
                /*isActive*/ true,
                /*lifeTime*/ simTime() + simtime_t(activeRouteTimeout));
    }

    RreqIdentifier rreqIdentifier(rreq->getOriginatorAddr(), rreq->getRreqId());
    auto itArrival = rreqsArrivalTime.find(rreqIdentifier);
    if (itArrival != rreqsArrivalTime.end()
            && simTime() - itArrival->second <= pathDiscoveryTime) {
        EV << "The same packet has arrived within PATH_DISCOVERY_TIME= "
           << pathDiscoveryTime << ". Discarding it" << endl;
        return;
    }
    rreqsArrivalTime[rreqIdentifier] = simTime();

    rreq->setHopCount(rreq->getHopCount() + 1);
    IRoute *reverseRoute = routingTable->findBestMatchingRoute(
            rreq->getOriginatorAddr());

    unsigned int hopCount = rreq->getHopCount();
    simtime_t minimalLifeTime = simTime() + 2 * netTraversalTime
            - 2 * hopCount * nodeTraversalTime;
    simtime_t newLifeTime = std::max(simTime(), minimalLifeTime);

    int rreqSeqNum = rreq->getOriginatorSeqNum();
    if (!reverseRoute || reverseRoute->getSource() != this) {
        reverseRoute = createRoute(rreq->getOriginatorAddr(), sourceAddr,
                hopCount, /*hasValidDestNum*/ true, rreqSeqNum,
                /*isActive*/ true, newLifeTime);
    } else {
        AodvSdnRouteData *routeData = check_and_cast<AodvSdnRouteData*>(
                reverseRoute->getProtocolData());
        int routeSeqNum = routeData->getDestSeqNum();
        int newSeqNum = std::max(routeSeqNum, rreqSeqNum);
        int newHopCount = rreq->getHopCount();
        int routeHopCount = reverseRoute->getMetric();

        if (rreqSeqNum > routeSeqNum
                || (rreqSeqNum == routeSeqNum && newHopCount < routeHopCount)
                || rreq->getUnknownSeqNumFlag()) {
            updateRoutingTable(reverseRoute, sourceAddr, hopCount,
                    /*hasValidDestNum*/ true, newSeqNum,
                    /*isActive*/ true, newLifeTime);
        }
    }

    IRoute *destRoute = routingTable->findBestMatchingRoute(
            rreq->getDestAddr());
    AodvSdnRouteData *destRouteData =
        destRoute ? dynamic_cast<AodvSdnRouteData*>(destRoute->getProtocolData()) : nullptr;

    if (rreq->getDestAddr() == getSelfIPAddress()) {
        EV << "I am the destination node for which the route was requested" << endl;

        simtime_t reverseLifetime = -1;
        if (reverseRoute) {
            if (auto *rd = dynamic_cast<AodvSdnRouteData*>(reverseRoute->getProtocolData()))
                reverseLifetime = rd->getLifeTime();
        }
        {
            std::string rrepPath = pwd + std::string("/rreq_art_dpc_log.csv");
            std::ifstream chk(rrepPath);
            bool exists = chk.good();
            chk.close();

            std::ofstream out(rrepPath, std::ios::app);
            if (out.is_open()) {
                if (!exists) out << "Time,NodeID,N_t,Speed,ART,DPC,Lifetime" << std::endl;
                out << currentTime << ","
                    << nodeIndex << ","
                    << neighborCount << ","
                    << vehicleSpeed << ","
                    << activeRouteTimeout << ","
                    << deletePeriod << ","
                    << reverseLifetime << std::endl;
            } else {
                EV_ERROR << "Cannot open rrep_art_dpc_log.csv for writing!" << endl;
            }
        }

        auto rrep = createRREP(rreq, destRoute, reverseRoute, sourceAddr);
        sendRREP(rrep, rreq->getOriginatorAddr(), /*TTL*/ 255);
        return;
    }

    if (destRouteData && destRouteData->isActive()
            && destRouteData->hasValidDestNum()
            && destRouteData->getDestSeqNum() >= rreq->getDestSeqNum()) {
        EV << "I am an intermediate node who has information about a route to "
           << rreq->getDestAddr() << endl;

        if (destRoute->getNextHopAsGeneric() == sourceAddr) {
            EV << "This RREP would make a loop. Dropping it" << endl;
            return;
        }

        if (!rreq->getDestOnlyFlag()) {

            simtime_t reverseLifetime = -1;
            if (reverseRoute) {
                if (auto *rd = dynamic_cast<AodvSdnRouteData*>(reverseRoute->getProtocolData()))
                    reverseLifetime = rd->getLifeTime();
            }
            {
                std::string rrepPath = pwd + std::string("/rrep_art_dpc_log.csv");
                std::ifstream chk(rrepPath);
                bool exists = chk.good();
                chk.close();

                std::ofstream out(rrepPath, std::ios::app);
                if (out.is_open()) {
                    if (!exists) out << "Time,NodeID,N_t,Speed,ART,DPC,Lifetime" << std::endl;
                    out << currentTime << ","
                        << nodeIndex << ","
                        << neighborCount << ","
                        << vehicleSpeed << ","
                        << activeRouteTimeout << ","
                        << deletePeriod << ","
                        << reverseLifetime << std::endl;
                } else {
                    EV_ERROR << "Cannot open rrep_art_dpc_log.csv for writing!" << endl;
                }
            }
            // === [추가 끝] ===

            auto rrep = createRREP(rreq, destRoute, reverseRoute, sourceAddr);
            sendRREP(rrep, rreq->getOriginatorAddr(), /*TTL*/ 255);

            // Gratuitous RREP 옵션 처리
            if (rreq->getGratuitousRREPFlag()) {
                IRoute *originatorRoute = routingTable->findBestMatchingRoute(
                        rreq->getOriginatorAddr());
                auto grrep = createGratuitousRREP(rreq, originatorRoute);
                sendGRREP(grrep, rreq->getDestAddr(), /*TTL*/ 100);
            }
            return;
        }
        else {
            EV << "The originator indicated that only the destination may respond (D flag). Forwarding ..." << endl;
        }
    }

    // RREQ 포워딩 (확산검색 규칙/리붓타임 고려)
    if (timeToLive > 0
            && (simTime() > rebootTime + simtime_t(deletePeriod)
                || rebootTime == 0)) {
        if (destRouteData) {
            rreq->setDestSeqNum(std::max(destRouteData->getDestSeqNum(),
                                         rreq->getDestSeqNum()));
        }
        rreq->setUnknownSeqNumFlag(false);

        auto outgoingRREQ = dynamicPtrCast<Rreq>(rreq->dupShared());
        forwardRREQ(outgoingRREQ, timeToLive);
    }
    else {
        EV << "Can't forward the RREQ because of its small (<= 1) TTL: "
           << timeToLive << " or the AODV reboot has not completed yet" << endl;
    }
}



IRoute* AodvSdn::createRoute(const L3Address &destAddr, const L3Address &nextHop,
        unsigned int hopCount, bool hasValidDestNum, unsigned int destSeqNum,
        bool isActive, simtime_t lifeTime) {
    IRoute *newRoute = routingTable->createRoute();

    newRoute->setDestination(destAddr);
    newRoute->setNextHop(nextHop);
    newRoute->setPrefixLength(addressType->getMaxPrefixLength());
    newRoute->setMetric(hopCount);
    NetworkInterface *ifEntry = interfaceTable->findInterfaceByName(
            par("interface"));
    if (ifEntry)
        newRoute->setInterface(ifEntry);
    newRoute->setSourceType(IRoute::AODV);
    newRoute->setSource(this);

    AodvSdnRouteData *newProtocolData = new AodvSdnRouteData();
    newProtocolData->setIsActive(isActive);
    newProtocolData->setHasValidDestNum(hasValidDestNum);
    newProtocolData->setDestSeqNum(destSeqNum);
    newProtocolData->setLifeTime(lifeTime);
    newRoute->setProtocolData(newProtocolData);

    routingTable->addRoute(newRoute);
    scheduleExpungeRoutes();
    return newRoute;
}

void AodvSdn::receiveSignal(cComponent *source, simsignal_t signalID, cObject *obj,
        cObject *details) {
    Enter_Method("%s", cComponent::getSignalName(signalID));

    if (signalID == linkBrokenSignal) {
        EV_DETAIL << "Received link break signal" << endl;
        Packet *datagram = check_and_cast<Packet*>(obj);
        const auto &networkHeader = findNetworkProtocolHeader(datagram);
        if (networkHeader != nullptr) {
            L3Address unreachableAddr = networkHeader->getDestinationAddress();
            if (unreachableAddr.getAddressType() == addressType) {
                IRoute *route = routingTable->findBestMatchingRoute(
                        unreachableAddr);

                if (route && route->getSource() == this)
                    handleLinkBreakSendRERR(route->getNextHopAsGeneric());
            }
        }
    }
}

void AodvSdn::handleLinkBreakSendRERR(const L3Address &unreachableAddr) {
    IRoute *unreachableRoute = routingTable->findBestMatchingRoute(
            unreachableAddr);

    if (!unreachableRoute || unreachableRoute->getSource() != this)
        return;

    std::vector<UnreachableNode> unreachableNodes;
    AodvSdnRouteData *unreachableRouteData = check_and_cast<AodvSdnRouteData*>(
            unreachableRoute->getProtocolData());

    if (unreachableRouteData->isActive()) {
        UnreachableNode node;
        node.addr = unreachableAddr;
        node.seqNum = unreachableRouteData->getDestSeqNum();
        unreachableNodes.push_back(node);
    }

    for (int i = 0; i < routingTable->getNumRoutes(); i++) {
        IRoute *route = routingTable->getRoute(i);

        AodvSdnRouteData *routeData =
                dynamic_cast<AodvSdnRouteData*>(route->getProtocolData());
        if (routeData && routeData->isActive()
                && route->getNextHopAsGeneric() == unreachableAddr) {
            if (routeData->hasValidDestNum())
                routeData->setDestSeqNum(routeData->getDestSeqNum() + 1);

            EV_DETAIL << "Marking route to " << route->getDestinationAsGeneric()
                                                                     << " as inactive" << endl;

            routeData->setIsActive(false);

            // 수정 - 2
            if (pFlag) {
                if (nodeDpc[getParentModule()] == 0)
                    nodeDpc[getParentModule()] = 15;
                routeData->setLifeTime(
                        simTime() + simtime_t(nodeDpc[getParentModule()]));
                nodeLifeTime[getParentModule()] = nodeDpc[getParentModule()];
            } else {
                routeData->setLifeTime(simTime() + simtime_t(deletePeriod));
            }
            scheduleExpungeRoutes();

            UnreachableNode node;
            node.addr = route->getDestinationAsGeneric();
            node.seqNum = routeData->getDestSeqNum();
            unreachableNodes.push_back(node);
        }
    }

    if (rerrCount >= rerrRatelimit) {
        EV_WARN
        << "A node should not generate more than RERR_RATELIMIT RERR messages per second. Canceling sending RERR"
        << endl;
        return;
    }

    if (unreachableNodes.empty())
        return;

    std::ofstream recoveryLog(pwd + "/recovery_log.csv", std::ios::app);
    recoveryLog << simTime() << "," << getParentModule()->getFullName() << ","
            << unreachableAddr << ",RERR_SENT\n";
    recoveryLog.close();
    auto rerr = createRERR(unreachableNodes);
    rerrCount++;

    EV_INFO << "Broadcasting Route Error message with TTL=1" << endl;
    sendAODVPacket(rerr, addressType->getBroadcastAddress(), 1, *jitterPar);
}

const Ptr<Rerr> AodvSdn::createRERR(
        const std::vector<UnreachableNode> &unreachableNodes) {
    auto rerr = makeShared<Rerr>();
    rerr->setPacketType(usingIpv6 ? RERR_IPv6 : RERR);

    unsigned int destCount = unreachableNodes.size();
    rerr->setUnreachableNodesArraySize(destCount);

    for (unsigned int i = 0; i < destCount; i++) {
        UnreachableNode node;
        node.addr = unreachableNodes[i].addr;
        node.seqNum = unreachableNodes[i].seqNum;
        rerr->setUnreachableNodes(i, node);
    }

    rerr->setChunkLength(B(4 + destCount * (usingIpv6 ? (4 + 16) : (4 + 4))));

    cModule *host = getParentModule();
    cModule *mobilityModule = host->getSubmodule("mobility");
    const char *currentNodeName = host->getFullName();

    std::ofstream logFileR(pwd + "/rerr_debug.txt", std::ios::app);
    logFileR << "[RERR 생성] 시간: " << simTime()
                    << ", 노드: " << getParentModule()->getFullName()
                    << ", 목적지 수: " << unreachableNodes.size() << std::endl;

    for (const auto& u : unreachableNodes) {
        logFileR << "  - 대상: " << u.addr << ", SeqNum: " << u.seqNum << std::endl;
    }
    logFileR.close();

    std::set<L3Address> uniquePrecursors;

    for (const auto& u : unreachableNodes) {
        const IRoute* route = routingTable->findBestMatchingRoute(u.addr);
        if (route) {
            const AodvSdnRouteData* routeData = dynamic_cast<const AodvSdnRouteData*>(route->getProtocolData());
            if (routeData) {
                const auto& precursors = routeData->getPrecursorList();
                for (const auto& p : precursors)
                    uniquePrecursors.insert(p);
            }
        }
    }

    std::ofstream logFileP(pwd + "/rerr_precursor_log.txt", std::ios::app);
    logFileP << "[RERR 생성] 시간: " << simTime()
                     << ", 노드: " << getParentModule()->getFullName()
                     << ", Precursor 수: " << uniquePrecursors.size() << std::endl;

    for (const auto& p : uniquePrecursors)
        logFileP << "  - Precursor: " << p << std::endl;
    logFileP.close();



    return rerr;
}

void AodvSdn::handleRERR(const Ptr<const Rerr> &rerr,
        const L3Address &sourceAddr) {
    EV_INFO << "AODV Route Error arrived with source addr: " << sourceAddr
            << endl;
    unsigned int unreachableArraySize = rerr->getUnreachableNodesArraySize();
    std::vector<UnreachableNode> unreachableNeighbors;

    for (int i = 0; i < routingTable->getNumRoutes(); i++) {
        IRoute *route = routingTable->getRoute(i);
        AodvSdnRouteData *routeData =
                route ? dynamic_cast<AodvSdnRouteData*>(route->getProtocolData()) : nullptr;

        if (!routeData)
            continue;

        if (routeData->isActive()
                && route->getNextHopAsGeneric() == sourceAddr) {
            for (unsigned int j = 0; j < unreachableArraySize; j++) {
                if (route->getDestinationAsGeneric()
                        == rerr->getUnreachableNodes(j).addr) {
                    routeData->setDestSeqNum(
                            rerr->getUnreachableNodes(j).seqNum);
                    routeData->setIsActive(false);
                    if (routeData->getPrecursorList().size() > 0) {
                        UnreachableNode node;
                        node.addr = route->getDestinationAsGeneric();
                        node.seqNum = routeData->getDestSeqNum();
                        unreachableNeighbors.push_back(node);
                    }
                    scheduleExpungeRoutes();
                }
            }
        }
    }

    if (rerrCount >= rerrRatelimit) {
        EV_WARN
        << "A node should not generate more than RERR_RATELIMIT RERR messages per second. Canceling sending RERR"
        << endl;
        return;
    }

    if (pFlag) {
        if (nodeDpc[getParentModule()] == 0)
            nodeDpc[getParentModule()] = 15;
        if (unreachableNeighbors.size() > 0
                && (simTime()
                        > rebootTime + simtime_t(nodeDpc[getParentModule()])
                        || rebootTime == 0)) {
            EV_INFO << "Sending RERR to inform our neighbors about link breaks."
                    << endl;
            auto newRERR = createRERR(unreachableNeighbors);
            sendAODVPacket(newRERR, addressType->getBroadcastAddress(), 1, 0);
            rerrCount++;
        }
    } else {
        if (unreachableNeighbors.size() > 0
                && (simTime() > rebootTime + simtime_t(deletePeriod)
                        || rebootTime == 0)) {
            EV_INFO << "Sending RERR to inform our neighbors about link breaks."
                    << endl;
            auto newRERR = createRERR(unreachableNeighbors);
            sendAODVPacket(newRERR, addressType->getBroadcastAddress(), 1, 0);
            rerrCount++;
        }
    }
}

void AodvSdn::handleStartOperation(LifecycleOperation *operation) {
    rebootTime = simTime();

    socket.setOutputGate(gate("socketOut"));
    socket.setCallback(this);
    socket.bind(L3Address(), aodvUDPPort);
    socket.setBroadcast(true);

    if (useHelloMessages) {
        scheduleAfter(helloInterval - *periodicJitter, helloMsgTimer);
    }

    scheduleAfter(1, counterTimer);
}

void AodvSdn::handleStopOperation(LifecycleOperation *operation) {
    socket.close();
    clearState();
}

void AodvSdn::handleCrashOperation(LifecycleOperation *operation) {
    socket.destroy();
    clearState();
}

void AodvSdn::clearState() {
    rerrCount = rreqCount = rreqId = sequenceNum = 0;
    addressToRreqRetries.clear();
    for (auto &elem : waitForRREPTimers)
        cancelAndDelete(elem.second);

    targetAddressToDelayedPackets.clear();

    waitForRREPTimers.clear();
    rreqsArrivalTime.clear();

    if (useHelloMessages)
        cancelEvent(helloMsgTimer);
    if (expungeTimer)
        cancelEvent(expungeTimer);
    if (counterTimer)
        cancelEvent(counterTimer);
    if (blacklistTimer)
        cancelEvent(blacklistTimer);
    if (rrepAckTimer)
        cancelEvent(rrepAckTimer);
}

void AodvSdn::handleWaitForRREP(WaitForRrep *rrepTimer) {
    EV_INFO << "We didn't get any Route Reply within RREP timeout" << endl;
    L3Address destAddr = rrepTimer->getDestAddr();

    ASSERT(containsKey(addressToRreqRetries, destAddr));
    if (addressToRreqRetries[destAddr] == rreqRetries) {
        cancelRouteDiscovery(destAddr);
        EV_WARN << "Re-discovery attempts for node " << destAddr
                << " reached RREQ_RETRIES= " << rreqRetries
                << " limit. Stop sending RREQ." << endl;
        return;
    }

    auto rreq = createRREQ(destAddr);

    if (rrepTimer->getLastTTL() == netDiameter)
        addressToRreqRetries[destAddr]++;

    sendRREQ(rreq, addressType->getBroadcastAddress(), 0);
}

void AodvSdn::forwardRREP(const Ptr<Rrep> &rrep, const L3Address &destAddr,
        unsigned int timeToLive) {
    EV_INFO << "Forwarding the Route Reply to the node "
            << rrep->getOriginatorAddr()
            << " which originated the Route Request" << endl;
    sendAODVPacket(rrep, destAddr, 100, *jitterPar);
}

void AodvSdn::forwardRREQ(const Ptr<Rreq> &rreq, unsigned int timeToLive) {
    EV_INFO << "Forwarding the Route Request message with TTL= " << timeToLive
            << endl;
    sendAODVPacket(rreq, addressType->getBroadcastAddress(), timeToLive,
            *jitterPar);
}

void AodvSdn::completeRouteDiscovery(const L3Address &target) {
    EV_DETAIL << "Completing route discovery, originator " << getSelfIPAddress()
                                                             << ", target " << target << endl;
    ASSERT(hasOngoingRouteDiscovery(target));

    auto lt = targetAddressToDelayedPackets.lower_bound(target);
    auto ut = targetAddressToDelayedPackets.upper_bound(target);

    for (auto it = lt; it != ut; it++) {
        Packet *datagram = it->second;
        const auto &networkHeader = getNetworkProtocolHeader(datagram);
        EV_DETAIL << "Sending queued datagram: source "
                << networkHeader->getSourceAddress()
                << ", destination "
                << networkHeader->getDestinationAddress() << endl;
        networkProtocol->reinjectQueuedDatagram(datagram);
    }

    targetAddressToDelayedPackets.erase(lt, ut);
    auto waitRREPIter = waitForRREPTimers.find(target);
    ASSERT(waitRREPIter != waitForRREPTimers.end());
    cancelAndDelete(waitRREPIter->second);
    waitForRREPTimers.erase(waitRREPIter);
}

void AodvSdn::sendGRREP(const Ptr<Rrep> &grrep, const L3Address &destAddr,
        unsigned int timeToLive) {
    EV_INFO << "Sending gratuitous Route Reply to " << destAddr << endl;

    IRoute *destRoute = routingTable->findBestMatchingRoute(destAddr);
    const L3Address &nextHop = destRoute->getNextHopAsGeneric();

    sendAODVPacket(grrep, nextHop, timeToLive, 0);
}

const Ptr<Rrep> AodvSdn::createHelloMessage() {
    auto helloMessage = makeShared<Rrep>();
    helloMessage->setPacketType(usingIpv6 ? RREP_IPv6 : RREP);
    helloMessage->setChunkLength(usingIpv6 ? B(44) : B(20));

    helloMessage->setDestAddr(getSelfIPAddress());
    helloMessage->setDestSeqNum(sequenceNum);
    helloMessage->setHopCount(0);
    helloMessage->setLifeTime(allowedHelloLoss * helloInterval);

    return helloMessage;
}

void AodvSdn::sendHelloMessagesIfNeeded() {
    ASSERT(useHelloMessages);
    bool hasActiveRoute = false;

    for (int i = 0; i < routingTable->getNumRoutes(); i++) {
        IRoute *route = routingTable->getRoute(i);
        if (route->getSource() == this) {
            AodvSdnRouteData *routeData = check_and_cast<AodvSdnRouteData*>(
                    route->getProtocolData());
            if (routeData->isActive()) {
                hasActiveRoute = true;
                break;
            }
        }
    }

    if (hasActiveRoute
            && (lastBroadcastTime == 0
                    || simTime() - lastBroadcastTime > helloInterval)) {
        EV_INFO << "It is hello time, broadcasting Hello Messages with TTL=1"
                << endl;
        auto helloMessage = createHelloMessage();
        sendAODVPacket(helloMessage, addressType->getBroadcastAddress(), 1, 0);
    }

    scheduleAfter(helloInterval - *periodicJitter, helloMsgTimer);
}



void AodvSdn::handleHelloMessage(const Ptr<Rrep> &helloMessage)
{
    double receiverSpeed = 0.0;
    if (simTime() <= SimTime(130)) {
        if (cModule *mobilityModule = getParentModule()->getSubmodule("mobility")) {
            inet::IMobility *mobility = check_and_cast<inet::IMobility*>(mobilityModule);
            receiverSpeed = mobility->getCurrentVelocity().length();
        }
        //nodeSpeeds[getParentModule()] = receiverSpeed;
        nodeSpeeds[getParentModule()] = { simTime(), receiverSpeed };
    }

    const L3Address &helloOriginatorAddr = helloMessage->getDestAddr();
    IRoute *routeHelloOriginator = routingTable->findBestMatchingRoute(helloOriginatorAddr);
    unsigned int latestDestSeqNum = helloMessage->getDestSeqNum();
    simtime_t newLifeTime = simTime() + allowedHelloLoss * helloInterval;

    if (!routeHelloOriginator || routeHelloOriginator->getSource() != this) {
        createRoute(helloOriginatorAddr, helloOriginatorAddr,
                    /*hop=*/1, /*isActive=*/true,
                    latestDestSeqNum, /*hasValidDestSeqNum=*/true,
                    newLifeTime);
    }
    else {
        AodvSdnRouteData *routeData = check_and_cast<AodvSdnRouteData*>(routeHelloOriginator->getProtocolData());
        simtime_t lifeTime = routeData->getLifeTime();
        updateRoutingTable(routeHelloOriginator, helloOriginatorAddr,
                           /*hop=*/1, /*isActive=*/true,
                           latestDestSeqNum, /*hasValidDestSeqNum=*/true,
                           std::max(lifeTime, newLifeTime));
    }


    if (pFlag) {
        cModule *host = getParentModule();
        const char *currentNodeName = host->getFullName();

        double radius = 110.0;
        int    N_t = 0;

        double S_cur = 0.0, S_prev = 0.0, deltaS = 0.0;

        inet::Coord myPosition;
        if (cModule *mobilityModule = host->getSubmodule("mobility")) {
            inet::IMobility *mobility = check_and_cast<inet::IMobility*>(mobilityModule);
            S_cur = mobility->getCurrentVelocity().length();
            myPosition = mobility->getCurrentPosition();
        }

        auto it = nodeSpeeds.find(host);
        if (it != nodeSpeeds.end()) {
            S_prev = it->second.v_ms;
        } else {
            S_prev = S_cur;
            nodeSpeeds[host] = { simTime(), S_cur };
        }

        deltaS = (S_cur - S_prev) * 3.6;
        nodeSpeeds[host] = { simTime(), S_cur };

        cModule *network = host->getParentModule();
        for (cModule::SubmoduleIterator iter(network); !iter.end(); ++iter) {
            cModule *otherVehicle = *iter;
            if (otherVehicle == host) continue;
            if (strncmp(otherVehicle->getFullName(), "node[", 5) != 0) continue;

            cModule *otherMobilityModule = otherVehicle->getSubmodule("mobility");
            if (!otherMobilityModule) continue;

            inet::IMobility *otherMobility = check_and_cast<inet::IMobility*>(otherMobilityModule);
            inet::Coord otherPosition = otherMobility->getCurrentPosition();

            if (myPosition.distance(otherPosition) <= radius) N_t++;
        }

        try {
            std::ofstream ntlog(pwd + "/hello_nt_probe.csv", std::ios::app);
            if (ntlog.is_open()) {
                std::string nodeName = host->getFullName();
                int nodeIndex = -1;
                size_t lb = nodeName.find('['), rb = nodeName.find(']');
                if (lb != std::string::npos && rb != std::string::npos && rb > lb)
                    nodeIndex = std::stoi(nodeName.substr(lb + 1, rb - lb - 1));
                ntlog << simTime().dbl() << "," << nodeIndex << "," << N_t << "\n";
                ntlog.close();
            }
        } catch (...) {
            EV_WARN << "Failed to append NT probe record" << endl;
        }

        double rho_t = (N_t / (M_PI * radius * radius)) * 10.0;

        totalDensity += rho_t;  densityCount++;
        double rho_t_avg = totalDensity / std::max(1, densityCount);
        totalSpeed   += S_cur;  speedCount++;
        double S_avg   = totalSpeed / std::max(1, speedCount);

        auto clip = [](double x, double lo, double hi){ return std::max(lo, std::min(x, hi)); };

        const double W_base_rho  = 0.027;
        const double W_base_S    = 0.037;
        const double S_change    = -0.003;
        const double F_change    = -0.03;
        const double F_rho       = 10.0;
        const double W_rho_min   = 0.022, W_rho_max = 0.22;
        const double W_min       = 0.022, W_max     = 0.22;
        const double inter_scale = 0.5;

        double S_cur_safe = (S_cur <= 1e-9 ? 1e-3 : S_cur);



        double W_S = clip(
            W_base_S +
            (clip(std::sqrt(std::abs(S_cur - S_avg)) * S_change, -0.03, 0.03)
             + clip(deltaS * F_change, -0.02, 0.02)) * 2.2,
            W_min, W_max
        );


        double W_rho_t = clip((W_base_rho + clip((rho_t - rho_t_avg) * F_rho, -0.5, 0.5)) * 2.2, W_rho_min, W_rho_max);
        double F_rho_t = clip(rho_t / 0.05, 0.08, 10.2);
        double F_S     = clip(35.0 / S_cur_safe, 0.9, 1.1);
        double F_adjust = (W_S * F_S + W_rho_t * F_rho_t);

        double art_base_eff;
        double dpc_base_eff;
        {
            const double ntLow  = 15.0;
            const double ntHigh = 20.0;

            double t;
            if (N_t <= ntLow)       t = 0.0;
            else if (N_t >= ntHigh) t = 1.0;
            else                    t = (static_cast<double>(N_t) - ntLow) / (ntHigh - ntLow);
            if (t < 0.0) t = 0.0; else if (t > 1.0) t = 1.0;

            art_base_eff = 60.0 * (1.0 - t) + 40.0 * t;
            dpc_base_eff = 160.0 * (1.0 - t) + 140.0 * t;
        }

        double art = clip((art_base_eff * F_adjust), 2.0, 100.0);
        double dpc = clip((dpc_base_eff * F_adjust), 5.0, 500.0) * art;


        std::cout << "Art, Dpc : " << art << ", " << dpc << std::endl;

        activeRouteTimeout = art;
        deletePeriod       = dpc;
        nodeArt[host] = art;
        nodeDpc[host] = dpc;

        try {
            std::ofstream lg(pwd + "/hello_log.csv", std::ios::app);
            if (lg.is_open()) {
                std::string nodeName = host->getFullName();
                int nodeIndex = -1;
                size_t lb = nodeName.find('['), rb = nodeName.find(']');
                if (lb != std::string::npos && rb != std::string::npos && rb > lb)
                    nodeIndex = std::stoi(nodeName.substr(lb + 1, rb - lb - 1));

                lg << simTime().dbl() << ","    // Time
                   << nodeIndex << ","          // Node
                   << N_t << ","                // N_t
                   << rho_t << ","              // rho_t
                   << S_cur << ","              // S_cur
                   << S_avg << ","              // S_avg
                   << rho_t_avg << ","          // rho_avg
                   << deltaS << ","             // deltaS
                   << art << ","                // ART
                   << dpc                      // DPC
                   << std::endl;
                lg.close();
            }
        }
        catch (...) {
            EV_WARN << "Failed to append HELLO record to rrep_art_dpc_log.csv" << endl;
        }
    } else {
        cModule *host = getParentModule();
        const char *currentNodeName = host->getFullName();

        double radius = 60.0;
        int    N_t = 0;


        double S_cur = 0.0, S_prev = 0.0, deltaS = 0.0;

        inet::Coord myPosition;
        if (cModule *mobilityModule = host->getSubmodule("mobility")) {
            inet::IMobility *mobility = check_and_cast<inet::IMobility*>(mobilityModule);
            S_cur = mobility->getCurrentVelocity().length();
            myPosition = mobility->getCurrentPosition();
        }

        SimTime now = simTime();


        auto it = nodeSpeeds.find(host);
        if (it == nodeSpeeds.end()) {
            nodeSpeeds[host] = { now, S_cur };
            std::cerr << "[INIT] node=" << host->getFullName()
                      << " time=" << now << " S_cur=" << S_cur << std::endl;
        } else {
            SimTime prevT = it->second.t;
            S_prev = it->second.v_ms;
            SimTime dt = now - prevT;

            if (dt > SimTime(1)) {
                deltaS = (S_cur - S_prev) * 3.6;
                nodeSpeeds[host] = { now, S_cur };

                std::cerr << "[UPDATE] node=" << host->getFullName()
                          << " now=" << now
                          << " dt=" << dt
                          << " S_cur=" << S_cur
                          << " S_prev=" << S_prev
                          << " deltaS=" << deltaS << " (>1s)" << std::endl;
            } else {
                deltaS = 0.0;

            }
        }

        cModule *network = host->getParentModule();
        for (cModule::SubmoduleIterator iter(network); !iter.end(); ++iter) {
            cModule *otherVehicle = *iter;
            if (otherVehicle == host) continue;
            if (strncmp(otherVehicle->getFullName(), "node[", 5) != 0) continue;

            cModule *otherMobilityModule = otherVehicle->getSubmodule("mobility");
            if (!otherMobilityModule) continue;

            inet::IMobility *otherMobility = check_and_cast<inet::IMobility*>(otherMobilityModule);
            inet::Coord otherPosition = otherMobility->getCurrentPosition();

            if (myPosition.distance(otherPosition) <= radius) N_t++;
        }
        try {
            std::string logPath = pwd + "/hello_log.csv";

            bool writeHeader = false;
            {
                std::ifstream checkFile(logPath);
                if (!checkFile.good() || checkFile.peek() == std::ifstream::traits_type::eof())
                    writeHeader = true;
            }

            std::ofstream lg(logPath, std::ios::app);
            if (lg.is_open()) {
                std::string nodeName = host->getFullName();
                int nodeIndex = -1;
                size_t lb = nodeName.find('['), rb = nodeName.find(']');
                if (lb != std::string::npos && rb != std::string::npos && rb > lb)
                    nodeIndex = std::stoi(nodeName.substr(lb + 1, rb - lb - 1));

                if (writeHeader) {
                    lg << "Time,Node,N_t,S_cur,deltaS" << std::endl;
                }

                lg << simTime().dbl() << ","    // Time
                   << nodeIndex << ","          // Node
                   << N_t << ","                // N_t
                   << S_cur * 3.6
                   << std::endl;

                lg.close();
            }
        }
        catch (...) {
            EV_WARN << "Failed to append HELLO record to hello_log.csv" << endl;
        }

    }
}



void AodvSdn::expungeRoutes() {
    for (int i = 0; i < routingTable->getNumRoutes(); i++) {
        IRoute *route = routingTable->getRoute(i);
        if (route->getSource() == this) {
            AodvSdnRouteData *routeData = check_and_cast<AodvSdnRouteData*>(
                    route->getProtocolData());
            ASSERT(routeData != nullptr);
            if (routeData->getLifeTime() <= simTime()) {
                std::ofstream log(pwd + "/lifetime_expired_log.csv", std::ios::app);
                log << getParentModule()->getFullName() << ","
                        << route->getDestinationAsGeneric() << ","
                        << simTime().dbl() << std::endl;
                log.close();
                if (routeData->isActive()) {
                    std::ofstream log(pwd + "/inactive_transition_log.csv", std::ios::app);
                    log << getParentModule()->getFullName() << ","
                            << route->getDestinationAsGeneric() << ","
                            << simTime().dbl() << std::endl;
                    log.close();
                    EV << "Route to " << route->getDestinationAsGeneric()
                                                                      << " expired and set to inactive. It will be deleted after DELETE_PERIOD time : "
                                                                      << routeData->getLifeTime() << endl;
                    routeData->setIsActive(false);

                    if (pFlag) {
                        if (nodeDpc[getParentModule()] == 0)
                            nodeDpc[getParentModule()] = 15;
                        routeData->setLifeTime(
                                simTime()
                                + simtime_t(
                                        nodeDpc[getParentModule()]));
                        nodeLifeTime[getParentModule()] =
                                nodeDpc[getParentModule()];

                    } else {
                        routeData->setLifeTime(
                                simTime() + simtime_t(deletePeriod));
                    }
                } else {
                    if (hasOngoingRouteDiscovery(

                            route->getDestinationAsGeneric())) {
                        EV << "Route to " << route->getDestinationAsGeneric()
                                                                          << " expired and is inactive, but we are waiting for a RREP to this destination, so we extend its lifetime with 2 * NET_TRAVERSAL_TIME"
                                                                          << endl;
                        routeData->setLifeTime(
                                simTime() + 2 * netTraversalTime);
                    } else {
                        EV << "Route to " << route->getDestinationAsGeneric()
                                                                          << " expired and is inactive and we are not expecting any RREP to this destination, so we delete this route : "
                                                                          << routeData->getLifeTime() << endl;

                        routingTable->deleteRoute(route);
                    }
                }
            }
        }
    }
    scheduleExpungeRoutes();
}

void AodvSdn::scheduleExpungeRoutes() {
    simtime_t nextExpungeTime = SimTime::getMaxTime();
    for (int i = 0; i < routingTable->getNumRoutes(); i++) {
        IRoute *route = routingTable->getRoute(i);

        if (route->getSource() == this) {
            AodvSdnRouteData *routeData = check_and_cast<AodvSdnRouteData*>(
                    route->getProtocolData());
            ASSERT(routeData != nullptr);

            if (routeData->getLifeTime() < nextExpungeTime)
                nextExpungeTime = routeData->getLifeTime();
        }
    }
    if (nextExpungeTime == SimTime::getMaxTime()) {
        if (expungeTimer->isScheduled())
            cancelEvent(expungeTimer);
    } else {
        if (!expungeTimer->isScheduled())
            scheduleAt(nextExpungeTime, expungeTimer);
        else {
            if (expungeTimer->getArrivalTime() != nextExpungeTime) {
                rescheduleAt(nextExpungeTime, expungeTimer);
            }
        }
    }
}

INetfilter::IHook::Result AodvSdn::datagramForwardHook(Packet *datagram) {
    Enter_Method("datagramForwardHook");
    const auto &networkHeader = getNetworkProtocolHeader(datagram);
    const L3Address &destAddr = networkHeader->getDestinationAddress();
    const L3Address &sourceAddr = networkHeader->getSourceAddress();
    IRoute *ipSource = routingTable->findBestMatchingRoute(sourceAddr);

    if (destAddr.isBroadcast() || routingTable->isLocalAddress(destAddr)
            || destAddr.isMulticast()) {
        if (routingTable->isLocalAddress(destAddr) && ipSource
                && ipSource->getSource() == this) {

            if (pFlag) {
                if (nodeArt[getParentModule()] == 0) {
                    nodeArt[getParentModule()] = 3;
                }
                updateValidRouteLifeTime(ipSource->getNextHopAsGeneric(),
                        simTime() + simtime_t(nodeArt[getParentModule()]));
            } else {
                updateValidRouteLifeTime(ipSource->getNextHopAsGeneric(),
                        simTime() + simtime_t(activeRouteTimeout));
            }
        }

        return ACCEPT;
    }

    IRoute *routeDest = routingTable->findBestMatchingRoute(destAddr);
    AodvSdnRouteData *routeDestData =
            routeDest ?
                    dynamic_cast<AodvSdnRouteData*>(routeDest->getProtocolData()) :
                    nullptr;
    if (pFlag) {
        if (nodeArt[getParentModule()] == 0) {
            nodeArt[getParentModule()] = 3;
        }
        updateValidRouteLifeTime(sourceAddr,
                simTime() + simtime_t(nodeArt[getParentModule()]));
        updateValidRouteLifeTime(destAddr,
                simTime() + simtime_t(nodeArt[getParentModule()]));

        if (routeDest && routeDest->getSource() == this)
            updateValidRouteLifeTime(routeDest->getNextHopAsGeneric(),
                    simTime() + simtime_t(nodeArt[getParentModule()]));
        if (ipSource && ipSource->getSource() == this)
            updateValidRouteLifeTime(ipSource->getNextHopAsGeneric(),
                    simTime() + simtime_t(nodeArt[getParentModule()]));
    } else {
        updateValidRouteLifeTime(sourceAddr,
                simTime() + simtime_t(activeRouteTimeout));
        updateValidRouteLifeTime(destAddr,
                simTime() + simtime_t(activeRouteTimeout));

        if (routeDest && routeDest->getSource() == this)
            updateValidRouteLifeTime(routeDest->getNextHopAsGeneric(),
                    simTime() + simtime_t(activeRouteTimeout));
        if (ipSource && ipSource->getSource() == this)
            updateValidRouteLifeTime(ipSource->getNextHopAsGeneric(),
                    simTime() + simtime_t(activeRouteTimeout));
    }

    EV_INFO << "We can't forward datagram because we have no active route for "
            << destAddr << endl;
    if (routeDest && routeDestData && !routeDestData->isActive()) {
        if (routeDestData->hasValidDestNum())
            routeDestData->setDestSeqNum(routeDestData->getDestSeqNum() + 1);

        if (pFlag) {
            if (nodeDpc[getParentModule()] == 0)
                nodeDpc[getParentModule()] = 15;
            routeDestData->setLifeTime(
                    simTime() + simtime_t(nodeDpc[getParentModule()]));
        } else {
            routeDestData->setLifeTime(simTime() + simtime_t(deletePeriod));
        }

        sendRERRWhenNoRouteToForward(destAddr);
    } else if (!routeDest || routeDest->getSource() != this)
        sendRERRWhenNoRouteToForward(destAddr);

    return ACCEPT;
}

void AodvSdn::sendRERRWhenNoRouteToForward(const L3Address &unreachableAddr) {
    if (rerrCount >= rerrRatelimit) {
        EV_WARN
        << "A node should not generate more than RERR_RATELIMIT RERR messages per second. Canceling sending RERR"
        << endl;
        return;
    }
    std::vector<UnreachableNode> unreachableNodes;
    UnreachableNode node;
    node.addr = unreachableAddr;

    IRoute *unreachableRoute = routingTable->findBestMatchingRoute(
            unreachableAddr);
    AodvSdnRouteData *unreachableRouteData =
            unreachableRoute ?
                    dynamic_cast<AodvSdnRouteData*>(unreachableRoute->getProtocolData()) :
                    nullptr;

    if (unreachableRouteData && unreachableRouteData->hasValidDestNum())
        node.seqNum = unreachableRouteData->getDestSeqNum();
    else
        node.seqNum = 0;

    unreachableNodes.push_back(node);
    auto rerr = createRERR(unreachableNodes);

    rerrCount++;
    EV_INFO << "Broadcasting Route Error message with TTL=1" << endl;
    sendAODVPacket(rerr, addressType->getBroadcastAddress(), 1, *jitterPar); // TODO unicast if there exists a route to the source
}

void AodvSdn::cancelRouteDiscovery(const L3Address &destAddr) {
    ASSERT(hasOngoingRouteDiscovery(destAddr));
    auto lt = targetAddressToDelayedPackets.lower_bound(destAddr);
    auto ut = targetAddressToDelayedPackets.upper_bound(destAddr);
    for (auto it = lt; it != ut; it++)
        networkProtocol->dropQueuedDatagram(it->second);

    targetAddressToDelayedPackets.erase(lt, ut);

    auto waitRREPIter = waitForRREPTimers.find(destAddr);
    ASSERT(waitRREPIter != waitForRREPTimers.end());
    cancelAndDelete(waitRREPIter->second);
    waitForRREPTimers.erase(waitRREPIter);
}

bool AodvSdn::updateValidRouteLifeTime(const L3Address &destAddr, simtime_t lifetime) {
    IRoute *route = routingTable->findBestMatchingRoute(destAddr);

    if (route && route->getSource() == this) {
        AodvSdnRouteData *routeData = check_and_cast<AodvSdnRouteData*>(route->getProtocolData());

        if (routeData->isActive()) {
            simtime_t newLifeTime = std::max(routeData->getLifeTime(), lifetime);
            EV_DETAIL << "Updating " << route << " lifetime to " << newLifeTime << endl;
            routeData->setLifeTime(newLifeTime);

            return true;
        }
    }
    return false;
}


const Ptr<RrepAck> AodvSdn::createRREPACK() {
    auto rrepAck = makeShared<RrepAck>(); // TODO "AODV-RREPACK");
    rrepAck->setPacketType(usingIpv6 ? RREPACK_IPv6 : RREPACK);
    return rrepAck;
}

void AodvSdn::sendRREPACK(const Ptr<RrepAck> &rrepACK, const L3Address &destAddr) {
    EV_INFO << "Sending Route Reply ACK to " << destAddr << endl;
    sendAODVPacket(rrepACK, destAddr, 100, 0);
}

void AodvSdn::handleRREPACK(const Ptr<const RrepAck> &rrepACK,
        const L3Address &neighborAddr) {
    if (rrepAckTimer->isScheduled()) {
        EV_INFO << "RREP-ACK arrived from " << neighborAddr << endl;

        IRoute *route = routingTable->findBestMatchingRoute(neighborAddr);
        if (route && route->getSource() == this) {
            EV_DETAIL << "Marking route " << route << " as active" << endl;

            AodvSdnRouteData *routeData = check_and_cast<AodvSdnRouteData*>(
                    route->getProtocolData());
            routeData->setIsActive(true);
            cancelEvent(rrepAckTimer);
        }
    }
}

void AodvSdn::handleRREPACKTimer() {
    EV_INFO << "RREP-ACK didn't arrived within timeout. Adding "
            << failedNextHop << " to the blacklist" << endl;

    blacklist[failedNextHop] = simTime() + blacklistTimeout;

    if (!blacklistTimer->isScheduled())
        scheduleAfter(blacklistTimeout, blacklistTimer);
}

void AodvSdn::handleBlackListTimer() {
    simtime_t nextTime = SimTime::getMaxTime();

    for (auto it = blacklist.begin(); it != blacklist.end();) {
        auto current = it++;

        if (current->second <= simTime()) {
            EV_DETAIL << "Blacklist lifetime has expired for " << current->first
                    << " removing it from the blacklisted addresses"
                    << endl;
            blacklist.erase(current);
        } else if (nextTime > current->second)
            nextTime = current->second;
    }

    if (nextTime != SimTime::getMaxTime())
        scheduleAt(nextTime, blacklistTimer);
}

AodvSdn::~AodvSdn() {
    clearState();
    delete helloMsgTimer;
    delete expungeTimer;
    delete counterTimer;
    delete rrepAckTimer;
    delete blacklistTimer;
}

}
}

