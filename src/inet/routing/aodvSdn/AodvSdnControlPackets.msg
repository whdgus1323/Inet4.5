//
// Copyright (C) 2014 OpenSim Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later
//

import inet.common.INETDefs;
import inet.common.packet.chunk.Chunk;
import inet.common.packet.Packet;
import inet.networklayer.common.L3Address;

namespace inet::aodvSdn;

enum AodvSdnControlPacketType
{
    RREQ = 1;
    RREP = 2;
    RERR = 3;
    RREPACK = 4;
    RREQ_IPv6 = 16;
    RREP_IPv6 = 17;
    RERR_IPv6 = 18;
    RREPACK_IPv6 = 19;

    SDNADV = 32;
    REGREQ = 33;
    REGREP = 34;
};

enum SdnNiceType
{
    NICE_NONE_OR_LEAVE = 1;
    NICE_BASIC_AODV = 2;
    NICE_AODV_QOS = 3;
    NICE_ADVANCED_SDN = 4;
};

class AodvSdnControlPacket extends FieldsChunk
{
    AodvSdnControlPacketType packetType = static_cast<AodvSdnControlPacketType>(-1);
}

class Rreq extends AodvSdnControlPacket
{
    bool joinFlag;
    bool repairFlag;
    bool gratuitousRREPFlag;
    bool destOnlyFlag;
    bool unknownSeqNumFlag;
    uint16_t reserved = 0;
    unsigned int hopCount;
    uint32_t rreqId;
    L3Address destAddr;
    uint32_t destSeqNum;
    L3Address originatorAddr;
    uint32_t originatorSeqNum;

    double deletePeriod;
}

class Rrep extends AodvSdnControlPacket
{
    bool repairFlag;
    bool ackRequiredFlag;
    uint16_t reserved = 0;
    unsigned int prefixSize;
    unsigned int hopCount;
    L3Address destAddr;
    uint32_t destSeqNum;
    L3Address originatorAddr;
    simtime_t lifeTime;
}

struct UnreachableNode
{
    @packetData;
    L3Address addr;
    uint32_t seqNum;
};

class Rerr extends AodvSdnControlPacket
{
    bool noDeleteFlag;
    uint16_t reserved = 0;
    UnreachableNode unreachableNodes[];
}

class RrepAck extends AodvSdnControlPacket
{
    chunkLength = B(2);
    uint8_t reserved = 0;
}

message WaitForRrep
{
    L3Address destAddr;
    unsigned int lastTTL;
    bool fromInvalidEntry;
}

message PacketHolderMessage
{
    Packet *ownedPacket @owned;
}

struct SdnControllerEntry
{
    @packetData;
    L3Address controllerAddr;
    string controllerInfo;
};

class Sdnadv extends AodvSdnControlPacket
{
    uint8_t noOfControllers = 0;
    unsigned int hopCount = 1;
    SdnControllerEntry controllers[];
}

struct NeighborQosEntry
{
    @packetData;
    L3Address neighborAddr;
    uint8_t qosType = 0;
    uint8_t qosValue = 0;
};

class Regreq extends AodvSdnControlPacket
{
    SdnNiceType nice = NICE_BASIC_AODV;
    unsigned int hopCount = 0;

    L3Address sourceAddr;

    uint16_t noOfNeighbors = 0;
    uint16_t noOfQos = 0;
    uint8_t typeOfQos = 0;

    NeighborQosEntry neighbors[];
}

struct OfpHeader
{
    @packetData;
    uint8_t version = 0;
    uint8_t type = 0;
    uint16_t length = 0;
    uint32_t xid = 0;
};

class Regrep extends AodvSdnControlPacket
{
    SdnNiceType nice = NICE_BASIC_AODV;
    unsigned int hopCount = 0;

    OfpHeader ofpHeader;
    uint8_t ofpData[]; 
}
