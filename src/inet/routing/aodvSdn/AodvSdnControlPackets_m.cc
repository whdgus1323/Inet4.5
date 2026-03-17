//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/routing/aodvSdn/AodvSdnControlPackets.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "AodvSdnControlPackets_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace inet {
namespace aodvSdn {

Register_Enum(inet::aodvSdn::AodvSdnControlPacketType, (inet::aodvSdn::AodvSdnControlPacketType::RREQ, inet::aodvSdn::AodvSdnControlPacketType::RREP, inet::aodvSdn::AodvSdnControlPacketType::RERR, inet::aodvSdn::AodvSdnControlPacketType::RREPACK, inet::aodvSdn::AodvSdnControlPacketType::RREQ_IPv6, inet::aodvSdn::AodvSdnControlPacketType::RREP_IPv6, inet::aodvSdn::AodvSdnControlPacketType::RERR_IPv6, inet::aodvSdn::AodvSdnControlPacketType::RREPACK_IPv6, inet::aodvSdn::AodvSdnControlPacketType::SDNADV, inet::aodvSdn::AodvSdnControlPacketType::REGREQ, inet::aodvSdn::AodvSdnControlPacketType::REGREP));

Register_Enum(inet::aodvSdn::SdnNiceType, (inet::aodvSdn::SdnNiceType::NICE_NONE_OR_LEAVE, inet::aodvSdn::SdnNiceType::NICE_BASIC_AODV, inet::aodvSdn::SdnNiceType::NICE_AODV_QOS, inet::aodvSdn::SdnNiceType::NICE_ADVANCED_SDN));

Register_Class(AodvSdnControlPacket)

AodvSdnControlPacket::AodvSdnControlPacket() : ::inet::FieldsChunk()
{
}

AodvSdnControlPacket::AodvSdnControlPacket(const AodvSdnControlPacket& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

AodvSdnControlPacket::~AodvSdnControlPacket()
{
}

AodvSdnControlPacket& AodvSdnControlPacket::operator=(const AodvSdnControlPacket& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void AodvSdnControlPacket::copy(const AodvSdnControlPacket& other)
{
    this->packetType = other.packetType;
}

void AodvSdnControlPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->packetType);
}

void AodvSdnControlPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->packetType);
}

AodvSdnControlPacketType AodvSdnControlPacket::getPacketType() const
{
    return this->packetType;
}

void AodvSdnControlPacket::setPacketType(AodvSdnControlPacketType packetType)
{
    handleChange();
    this->packetType = packetType;
}

class AodvSdnControlPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_packetType,
    };
  public:
    AodvSdnControlPacketDescriptor();
    virtual ~AodvSdnControlPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(AodvSdnControlPacketDescriptor)

AodvSdnControlPacketDescriptor::AodvSdnControlPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::aodvSdn::AodvSdnControlPacket)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

AodvSdnControlPacketDescriptor::~AodvSdnControlPacketDescriptor()
{
    delete[] propertyNames;
}

bool AodvSdnControlPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AodvSdnControlPacket *>(obj)!=nullptr;
}

const char **AodvSdnControlPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *AodvSdnControlPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int AodvSdnControlPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int AodvSdnControlPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_packetType
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *AodvSdnControlPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "packetType",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int AodvSdnControlPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "packetType") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *AodvSdnControlPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::aodvSdn::AodvSdnControlPacketType",    // FIELD_packetType
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **AodvSdnControlPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_packetType: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *AodvSdnControlPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_packetType:
            if (!strcmp(propertyName, "enum")) return "inet::aodvSdn::AodvSdnControlPacketType";
            return nullptr;
        default: return nullptr;
    }
}

int AodvSdnControlPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    AodvSdnControlPacket *pp = omnetpp::fromAnyPtr<AodvSdnControlPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void AodvSdnControlPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    AodvSdnControlPacket *pp = omnetpp::fromAnyPtr<AodvSdnControlPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'AodvSdnControlPacket'", field);
    }
}

const char *AodvSdnControlPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    AodvSdnControlPacket *pp = omnetpp::fromAnyPtr<AodvSdnControlPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AodvSdnControlPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    AodvSdnControlPacket *pp = omnetpp::fromAnyPtr<AodvSdnControlPacket>(object); (void)pp;
    switch (field) {
        case FIELD_packetType: return enum2string(pp->getPacketType(), "inet::aodvSdn::AodvSdnControlPacketType");
        default: return "";
    }
}

void AodvSdnControlPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    AodvSdnControlPacket *pp = omnetpp::fromAnyPtr<AodvSdnControlPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'AodvSdnControlPacket'", field);
    }
}

omnetpp::cValue AodvSdnControlPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    AodvSdnControlPacket *pp = omnetpp::fromAnyPtr<AodvSdnControlPacket>(object); (void)pp;
    switch (field) {
        case FIELD_packetType: return static_cast<int>(pp->getPacketType());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'AodvSdnControlPacket' as cValue -- field index out of range?", field);
    }
}

void AodvSdnControlPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    AodvSdnControlPacket *pp = omnetpp::fromAnyPtr<AodvSdnControlPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'AodvSdnControlPacket'", field);
    }
}

const char *AodvSdnControlPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr AodvSdnControlPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    AodvSdnControlPacket *pp = omnetpp::fromAnyPtr<AodvSdnControlPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void AodvSdnControlPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    AodvSdnControlPacket *pp = omnetpp::fromAnyPtr<AodvSdnControlPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'AodvSdnControlPacket'", field);
    }
}

Register_Class(Rreq)

Rreq::Rreq() : ::inet::aodvSdn::AodvSdnControlPacket()
{
}

Rreq::Rreq(const Rreq& other) : ::inet::aodvSdn::AodvSdnControlPacket(other)
{
    copy(other);
}

Rreq::~Rreq()
{
}

Rreq& Rreq::operator=(const Rreq& other)
{
    if (this == &other) return *this;
    ::inet::aodvSdn::AodvSdnControlPacket::operator=(other);
    copy(other);
    return *this;
}

void Rreq::copy(const Rreq& other)
{
    this->joinFlag = other.joinFlag;
    this->repairFlag = other.repairFlag;
    this->gratuitousRREPFlag = other.gratuitousRREPFlag;
    this->destOnlyFlag = other.destOnlyFlag;
    this->unknownSeqNumFlag = other.unknownSeqNumFlag;
    this->reserved = other.reserved;
    this->hopCount = other.hopCount;
    this->rreqId = other.rreqId;
    this->destAddr = other.destAddr;
    this->destSeqNum = other.destSeqNum;
    this->originatorAddr = other.originatorAddr;
    this->originatorSeqNum = other.originatorSeqNum;
    this->deletePeriod = other.deletePeriod;
}

void Rreq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::aodvSdn::AodvSdnControlPacket::parsimPack(b);
    doParsimPacking(b,this->joinFlag);
    doParsimPacking(b,this->repairFlag);
    doParsimPacking(b,this->gratuitousRREPFlag);
    doParsimPacking(b,this->destOnlyFlag);
    doParsimPacking(b,this->unknownSeqNumFlag);
    doParsimPacking(b,this->reserved);
    doParsimPacking(b,this->hopCount);
    doParsimPacking(b,this->rreqId);
    doParsimPacking(b,this->destAddr);
    doParsimPacking(b,this->destSeqNum);
    doParsimPacking(b,this->originatorAddr);
    doParsimPacking(b,this->originatorSeqNum);
    doParsimPacking(b,this->deletePeriod);
}

void Rreq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::aodvSdn::AodvSdnControlPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->joinFlag);
    doParsimUnpacking(b,this->repairFlag);
    doParsimUnpacking(b,this->gratuitousRREPFlag);
    doParsimUnpacking(b,this->destOnlyFlag);
    doParsimUnpacking(b,this->unknownSeqNumFlag);
    doParsimUnpacking(b,this->reserved);
    doParsimUnpacking(b,this->hopCount);
    doParsimUnpacking(b,this->rreqId);
    doParsimUnpacking(b,this->destAddr);
    doParsimUnpacking(b,this->destSeqNum);
    doParsimUnpacking(b,this->originatorAddr);
    doParsimUnpacking(b,this->originatorSeqNum);
    doParsimUnpacking(b,this->deletePeriod);
}

bool Rreq::getJoinFlag() const
{
    return this->joinFlag;
}

void Rreq::setJoinFlag(bool joinFlag)
{
    handleChange();
    this->joinFlag = joinFlag;
}

bool Rreq::getRepairFlag() const
{
    return this->repairFlag;
}

void Rreq::setRepairFlag(bool repairFlag)
{
    handleChange();
    this->repairFlag = repairFlag;
}

bool Rreq::getGratuitousRREPFlag() const
{
    return this->gratuitousRREPFlag;
}

void Rreq::setGratuitousRREPFlag(bool gratuitousRREPFlag)
{
    handleChange();
    this->gratuitousRREPFlag = gratuitousRREPFlag;
}

bool Rreq::getDestOnlyFlag() const
{
    return this->destOnlyFlag;
}

void Rreq::setDestOnlyFlag(bool destOnlyFlag)
{
    handleChange();
    this->destOnlyFlag = destOnlyFlag;
}

bool Rreq::getUnknownSeqNumFlag() const
{
    return this->unknownSeqNumFlag;
}

void Rreq::setUnknownSeqNumFlag(bool unknownSeqNumFlag)
{
    handleChange();
    this->unknownSeqNumFlag = unknownSeqNumFlag;
}

uint16_t Rreq::getReserved() const
{
    return this->reserved;
}

void Rreq::setReserved(uint16_t reserved)
{
    handleChange();
    this->reserved = reserved;
}

unsigned int Rreq::getHopCount() const
{
    return this->hopCount;
}

void Rreq::setHopCount(unsigned int hopCount)
{
    handleChange();
    this->hopCount = hopCount;
}

uint32_t Rreq::getRreqId() const
{
    return this->rreqId;
}

void Rreq::setRreqId(uint32_t rreqId)
{
    handleChange();
    this->rreqId = rreqId;
}

const ::inet::L3Address& Rreq::getDestAddr() const
{
    return this->destAddr;
}

void Rreq::setDestAddr(const ::inet::L3Address& destAddr)
{
    handleChange();
    this->destAddr = destAddr;
}

uint32_t Rreq::getDestSeqNum() const
{
    return this->destSeqNum;
}

void Rreq::setDestSeqNum(uint32_t destSeqNum)
{
    handleChange();
    this->destSeqNum = destSeqNum;
}

const ::inet::L3Address& Rreq::getOriginatorAddr() const
{
    return this->originatorAddr;
}

void Rreq::setOriginatorAddr(const ::inet::L3Address& originatorAddr)
{
    handleChange();
    this->originatorAddr = originatorAddr;
}

uint32_t Rreq::getOriginatorSeqNum() const
{
    return this->originatorSeqNum;
}

void Rreq::setOriginatorSeqNum(uint32_t originatorSeqNum)
{
    handleChange();
    this->originatorSeqNum = originatorSeqNum;
}

double Rreq::getDeletePeriod() const
{
    return this->deletePeriod;
}

void Rreq::setDeletePeriod(double deletePeriod)
{
    handleChange();
    this->deletePeriod = deletePeriod;
}

class RreqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_joinFlag,
        FIELD_repairFlag,
        FIELD_gratuitousRREPFlag,
        FIELD_destOnlyFlag,
        FIELD_unknownSeqNumFlag,
        FIELD_reserved,
        FIELD_hopCount,
        FIELD_rreqId,
        FIELD_destAddr,
        FIELD_destSeqNum,
        FIELD_originatorAddr,
        FIELD_originatorSeqNum,
        FIELD_deletePeriod,
    };
  public:
    RreqDescriptor();
    virtual ~RreqDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(RreqDescriptor)

RreqDescriptor::RreqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::aodvSdn::Rreq)), "inet::aodvSdn::AodvSdnControlPacket")
{
    propertyNames = nullptr;
}

RreqDescriptor::~RreqDescriptor()
{
    delete[] propertyNames;
}

bool RreqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Rreq *>(obj)!=nullptr;
}

const char **RreqDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *RreqDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int RreqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 13+base->getFieldCount() : 13;
}

unsigned int RreqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_joinFlag
        FD_ISEDITABLE,    // FIELD_repairFlag
        FD_ISEDITABLE,    // FIELD_gratuitousRREPFlag
        FD_ISEDITABLE,    // FIELD_destOnlyFlag
        FD_ISEDITABLE,    // FIELD_unknownSeqNumFlag
        FD_ISEDITABLE,    // FIELD_reserved
        FD_ISEDITABLE,    // FIELD_hopCount
        FD_ISEDITABLE,    // FIELD_rreqId
        0,    // FIELD_destAddr
        FD_ISEDITABLE,    // FIELD_destSeqNum
        0,    // FIELD_originatorAddr
        FD_ISEDITABLE,    // FIELD_originatorSeqNum
        FD_ISEDITABLE,    // FIELD_deletePeriod
    };
    return (field >= 0 && field < 13) ? fieldTypeFlags[field] : 0;
}

const char *RreqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "joinFlag",
        "repairFlag",
        "gratuitousRREPFlag",
        "destOnlyFlag",
        "unknownSeqNumFlag",
        "reserved",
        "hopCount",
        "rreqId",
        "destAddr",
        "destSeqNum",
        "originatorAddr",
        "originatorSeqNum",
        "deletePeriod",
    };
    return (field >= 0 && field < 13) ? fieldNames[field] : nullptr;
}

int RreqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "joinFlag") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "repairFlag") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "gratuitousRREPFlag") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "destOnlyFlag") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "unknownSeqNumFlag") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "reserved") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "hopCount") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "rreqId") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "destAddr") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "destSeqNum") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "originatorAddr") == 0) return baseIndex + 10;
    if (strcmp(fieldName, "originatorSeqNum") == 0) return baseIndex + 11;
    if (strcmp(fieldName, "deletePeriod") == 0) return baseIndex + 12;
    return base ? base->findField(fieldName) : -1;
}

const char *RreqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_joinFlag
        "bool",    // FIELD_repairFlag
        "bool",    // FIELD_gratuitousRREPFlag
        "bool",    // FIELD_destOnlyFlag
        "bool",    // FIELD_unknownSeqNumFlag
        "uint16_t",    // FIELD_reserved
        "unsigned int",    // FIELD_hopCount
        "uint32_t",    // FIELD_rreqId
        "inet::L3Address",    // FIELD_destAddr
        "uint32_t",    // FIELD_destSeqNum
        "inet::L3Address",    // FIELD_originatorAddr
        "uint32_t",    // FIELD_originatorSeqNum
        "double",    // FIELD_deletePeriod
    };
    return (field >= 0 && field < 13) ? fieldTypeStrings[field] : nullptr;
}

const char **RreqDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *RreqDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int RreqDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    Rreq *pp = omnetpp::fromAnyPtr<Rreq>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void RreqDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    Rreq *pp = omnetpp::fromAnyPtr<Rreq>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Rreq'", field);
    }
}

const char *RreqDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    Rreq *pp = omnetpp::fromAnyPtr<Rreq>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RreqDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    Rreq *pp = omnetpp::fromAnyPtr<Rreq>(object); (void)pp;
    switch (field) {
        case FIELD_joinFlag: return bool2string(pp->getJoinFlag());
        case FIELD_repairFlag: return bool2string(pp->getRepairFlag());
        case FIELD_gratuitousRREPFlag: return bool2string(pp->getGratuitousRREPFlag());
        case FIELD_destOnlyFlag: return bool2string(pp->getDestOnlyFlag());
        case FIELD_unknownSeqNumFlag: return bool2string(pp->getUnknownSeqNumFlag());
        case FIELD_reserved: return ulong2string(pp->getReserved());
        case FIELD_hopCount: return ulong2string(pp->getHopCount());
        case FIELD_rreqId: return ulong2string(pp->getRreqId());
        case FIELD_destAddr: return pp->getDestAddr().str();
        case FIELD_destSeqNum: return ulong2string(pp->getDestSeqNum());
        case FIELD_originatorAddr: return pp->getOriginatorAddr().str();
        case FIELD_originatorSeqNum: return ulong2string(pp->getOriginatorSeqNum());
        case FIELD_deletePeriod: return double2string(pp->getDeletePeriod());
        default: return "";
    }
}

void RreqDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Rreq *pp = omnetpp::fromAnyPtr<Rreq>(object); (void)pp;
    switch (field) {
        case FIELD_joinFlag: pp->setJoinFlag(string2bool(value)); break;
        case FIELD_repairFlag: pp->setRepairFlag(string2bool(value)); break;
        case FIELD_gratuitousRREPFlag: pp->setGratuitousRREPFlag(string2bool(value)); break;
        case FIELD_destOnlyFlag: pp->setDestOnlyFlag(string2bool(value)); break;
        case FIELD_unknownSeqNumFlag: pp->setUnknownSeqNumFlag(string2bool(value)); break;
        case FIELD_reserved: pp->setReserved(string2ulong(value)); break;
        case FIELD_hopCount: pp->setHopCount(string2ulong(value)); break;
        case FIELD_rreqId: pp->setRreqId(string2ulong(value)); break;
        case FIELD_destSeqNum: pp->setDestSeqNum(string2ulong(value)); break;
        case FIELD_originatorSeqNum: pp->setOriginatorSeqNum(string2ulong(value)); break;
        case FIELD_deletePeriod: pp->setDeletePeriod(string2double(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Rreq'", field);
    }
}

omnetpp::cValue RreqDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    Rreq *pp = omnetpp::fromAnyPtr<Rreq>(object); (void)pp;
    switch (field) {
        case FIELD_joinFlag: return pp->getJoinFlag();
        case FIELD_repairFlag: return pp->getRepairFlag();
        case FIELD_gratuitousRREPFlag: return pp->getGratuitousRREPFlag();
        case FIELD_destOnlyFlag: return pp->getDestOnlyFlag();
        case FIELD_unknownSeqNumFlag: return pp->getUnknownSeqNumFlag();
        case FIELD_reserved: return (omnetpp::intval_t)(pp->getReserved());
        case FIELD_hopCount: return (omnetpp::intval_t)(pp->getHopCount());
        case FIELD_rreqId: return (omnetpp::intval_t)(pp->getRreqId());
        case FIELD_destAddr: return omnetpp::toAnyPtr(&pp->getDestAddr()); break;
        case FIELD_destSeqNum: return (omnetpp::intval_t)(pp->getDestSeqNum());
        case FIELD_originatorAddr: return omnetpp::toAnyPtr(&pp->getOriginatorAddr()); break;
        case FIELD_originatorSeqNum: return (omnetpp::intval_t)(pp->getOriginatorSeqNum());
        case FIELD_deletePeriod: return pp->getDeletePeriod();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'Rreq' as cValue -- field index out of range?", field);
    }
}

void RreqDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Rreq *pp = omnetpp::fromAnyPtr<Rreq>(object); (void)pp;
    switch (field) {
        case FIELD_joinFlag: pp->setJoinFlag(value.boolValue()); break;
        case FIELD_repairFlag: pp->setRepairFlag(value.boolValue()); break;
        case FIELD_gratuitousRREPFlag: pp->setGratuitousRREPFlag(value.boolValue()); break;
        case FIELD_destOnlyFlag: pp->setDestOnlyFlag(value.boolValue()); break;
        case FIELD_unknownSeqNumFlag: pp->setUnknownSeqNumFlag(value.boolValue()); break;
        case FIELD_reserved: pp->setReserved(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_hopCount: pp->setHopCount(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_rreqId: pp->setRreqId(omnetpp::checked_int_cast<uint32_t>(value.intValue())); break;
        case FIELD_destSeqNum: pp->setDestSeqNum(omnetpp::checked_int_cast<uint32_t>(value.intValue())); break;
        case FIELD_originatorSeqNum: pp->setOriginatorSeqNum(omnetpp::checked_int_cast<uint32_t>(value.intValue())); break;
        case FIELD_deletePeriod: pp->setDeletePeriod(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Rreq'", field);
    }
}

const char *RreqDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr RreqDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    Rreq *pp = omnetpp::fromAnyPtr<Rreq>(object); (void)pp;
    switch (field) {
        case FIELD_destAddr: return omnetpp::toAnyPtr(&pp->getDestAddr()); break;
        case FIELD_originatorAddr: return omnetpp::toAnyPtr(&pp->getOriginatorAddr()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void RreqDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    Rreq *pp = omnetpp::fromAnyPtr<Rreq>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Rreq'", field);
    }
}

Register_Class(Rrep)

Rrep::Rrep() : ::inet::aodvSdn::AodvSdnControlPacket()
{
}

Rrep::Rrep(const Rrep& other) : ::inet::aodvSdn::AodvSdnControlPacket(other)
{
    copy(other);
}

Rrep::~Rrep()
{
}

Rrep& Rrep::operator=(const Rrep& other)
{
    if (this == &other) return *this;
    ::inet::aodvSdn::AodvSdnControlPacket::operator=(other);
    copy(other);
    return *this;
}

void Rrep::copy(const Rrep& other)
{
    this->repairFlag = other.repairFlag;
    this->ackRequiredFlag = other.ackRequiredFlag;
    this->reserved = other.reserved;
    this->prefixSize = other.prefixSize;
    this->hopCount = other.hopCount;
    this->destAddr = other.destAddr;
    this->destSeqNum = other.destSeqNum;
    this->originatorAddr = other.originatorAddr;
    this->lifeTime = other.lifeTime;
}

void Rrep::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::aodvSdn::AodvSdnControlPacket::parsimPack(b);
    doParsimPacking(b,this->repairFlag);
    doParsimPacking(b,this->ackRequiredFlag);
    doParsimPacking(b,this->reserved);
    doParsimPacking(b,this->prefixSize);
    doParsimPacking(b,this->hopCount);
    doParsimPacking(b,this->destAddr);
    doParsimPacking(b,this->destSeqNum);
    doParsimPacking(b,this->originatorAddr);
    doParsimPacking(b,this->lifeTime);
}

void Rrep::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::aodvSdn::AodvSdnControlPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->repairFlag);
    doParsimUnpacking(b,this->ackRequiredFlag);
    doParsimUnpacking(b,this->reserved);
    doParsimUnpacking(b,this->prefixSize);
    doParsimUnpacking(b,this->hopCount);
    doParsimUnpacking(b,this->destAddr);
    doParsimUnpacking(b,this->destSeqNum);
    doParsimUnpacking(b,this->originatorAddr);
    doParsimUnpacking(b,this->lifeTime);
}

bool Rrep::getRepairFlag() const
{
    return this->repairFlag;
}

void Rrep::setRepairFlag(bool repairFlag)
{
    handleChange();
    this->repairFlag = repairFlag;
}

bool Rrep::getAckRequiredFlag() const
{
    return this->ackRequiredFlag;
}

void Rrep::setAckRequiredFlag(bool ackRequiredFlag)
{
    handleChange();
    this->ackRequiredFlag = ackRequiredFlag;
}

uint16_t Rrep::getReserved() const
{
    return this->reserved;
}

void Rrep::setReserved(uint16_t reserved)
{
    handleChange();
    this->reserved = reserved;
}

unsigned int Rrep::getPrefixSize() const
{
    return this->prefixSize;
}

void Rrep::setPrefixSize(unsigned int prefixSize)
{
    handleChange();
    this->prefixSize = prefixSize;
}

unsigned int Rrep::getHopCount() const
{
    return this->hopCount;
}

void Rrep::setHopCount(unsigned int hopCount)
{
    handleChange();
    this->hopCount = hopCount;
}

const ::inet::L3Address& Rrep::getDestAddr() const
{
    return this->destAddr;
}

void Rrep::setDestAddr(const ::inet::L3Address& destAddr)
{
    handleChange();
    this->destAddr = destAddr;
}

uint32_t Rrep::getDestSeqNum() const
{
    return this->destSeqNum;
}

void Rrep::setDestSeqNum(uint32_t destSeqNum)
{
    handleChange();
    this->destSeqNum = destSeqNum;
}

const ::inet::L3Address& Rrep::getOriginatorAddr() const
{
    return this->originatorAddr;
}

void Rrep::setOriginatorAddr(const ::inet::L3Address& originatorAddr)
{
    handleChange();
    this->originatorAddr = originatorAddr;
}

::omnetpp::simtime_t Rrep::getLifeTime() const
{
    return this->lifeTime;
}

void Rrep::setLifeTime(::omnetpp::simtime_t lifeTime)
{
    handleChange();
    this->lifeTime = lifeTime;
}

class RrepDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_repairFlag,
        FIELD_ackRequiredFlag,
        FIELD_reserved,
        FIELD_prefixSize,
        FIELD_hopCount,
        FIELD_destAddr,
        FIELD_destSeqNum,
        FIELD_originatorAddr,
        FIELD_lifeTime,
    };
  public:
    RrepDescriptor();
    virtual ~RrepDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(RrepDescriptor)

RrepDescriptor::RrepDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::aodvSdn::Rrep)), "inet::aodvSdn::AodvSdnControlPacket")
{
    propertyNames = nullptr;
}

RrepDescriptor::~RrepDescriptor()
{
    delete[] propertyNames;
}

bool RrepDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Rrep *>(obj)!=nullptr;
}

const char **RrepDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *RrepDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int RrepDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 9+base->getFieldCount() : 9;
}

unsigned int RrepDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_repairFlag
        FD_ISEDITABLE,    // FIELD_ackRequiredFlag
        FD_ISEDITABLE,    // FIELD_reserved
        FD_ISEDITABLE,    // FIELD_prefixSize
        FD_ISEDITABLE,    // FIELD_hopCount
        0,    // FIELD_destAddr
        FD_ISEDITABLE,    // FIELD_destSeqNum
        0,    // FIELD_originatorAddr
        FD_ISEDITABLE,    // FIELD_lifeTime
    };
    return (field >= 0 && field < 9) ? fieldTypeFlags[field] : 0;
}

const char *RrepDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "repairFlag",
        "ackRequiredFlag",
        "reserved",
        "prefixSize",
        "hopCount",
        "destAddr",
        "destSeqNum",
        "originatorAddr",
        "lifeTime",
    };
    return (field >= 0 && field < 9) ? fieldNames[field] : nullptr;
}

int RrepDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "repairFlag") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "ackRequiredFlag") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "reserved") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "prefixSize") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "hopCount") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "destAddr") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "destSeqNum") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "originatorAddr") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "lifeTime") == 0) return baseIndex + 8;
    return base ? base->findField(fieldName) : -1;
}

const char *RrepDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_repairFlag
        "bool",    // FIELD_ackRequiredFlag
        "uint16_t",    // FIELD_reserved
        "unsigned int",    // FIELD_prefixSize
        "unsigned int",    // FIELD_hopCount
        "inet::L3Address",    // FIELD_destAddr
        "uint32_t",    // FIELD_destSeqNum
        "inet::L3Address",    // FIELD_originatorAddr
        "omnetpp::simtime_t",    // FIELD_lifeTime
    };
    return (field >= 0 && field < 9) ? fieldTypeStrings[field] : nullptr;
}

const char **RrepDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *RrepDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int RrepDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    Rrep *pp = omnetpp::fromAnyPtr<Rrep>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void RrepDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    Rrep *pp = omnetpp::fromAnyPtr<Rrep>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Rrep'", field);
    }
}

const char *RrepDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    Rrep *pp = omnetpp::fromAnyPtr<Rrep>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RrepDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    Rrep *pp = omnetpp::fromAnyPtr<Rrep>(object); (void)pp;
    switch (field) {
        case FIELD_repairFlag: return bool2string(pp->getRepairFlag());
        case FIELD_ackRequiredFlag: return bool2string(pp->getAckRequiredFlag());
        case FIELD_reserved: return ulong2string(pp->getReserved());
        case FIELD_prefixSize: return ulong2string(pp->getPrefixSize());
        case FIELD_hopCount: return ulong2string(pp->getHopCount());
        case FIELD_destAddr: return pp->getDestAddr().str();
        case FIELD_destSeqNum: return ulong2string(pp->getDestSeqNum());
        case FIELD_originatorAddr: return pp->getOriginatorAddr().str();
        case FIELD_lifeTime: return simtime2string(pp->getLifeTime());
        default: return "";
    }
}

void RrepDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Rrep *pp = omnetpp::fromAnyPtr<Rrep>(object); (void)pp;
    switch (field) {
        case FIELD_repairFlag: pp->setRepairFlag(string2bool(value)); break;
        case FIELD_ackRequiredFlag: pp->setAckRequiredFlag(string2bool(value)); break;
        case FIELD_reserved: pp->setReserved(string2ulong(value)); break;
        case FIELD_prefixSize: pp->setPrefixSize(string2ulong(value)); break;
        case FIELD_hopCount: pp->setHopCount(string2ulong(value)); break;
        case FIELD_destSeqNum: pp->setDestSeqNum(string2ulong(value)); break;
        case FIELD_lifeTime: pp->setLifeTime(string2simtime(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Rrep'", field);
    }
}

omnetpp::cValue RrepDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    Rrep *pp = omnetpp::fromAnyPtr<Rrep>(object); (void)pp;
    switch (field) {
        case FIELD_repairFlag: return pp->getRepairFlag();
        case FIELD_ackRequiredFlag: return pp->getAckRequiredFlag();
        case FIELD_reserved: return (omnetpp::intval_t)(pp->getReserved());
        case FIELD_prefixSize: return (omnetpp::intval_t)(pp->getPrefixSize());
        case FIELD_hopCount: return (omnetpp::intval_t)(pp->getHopCount());
        case FIELD_destAddr: return omnetpp::toAnyPtr(&pp->getDestAddr()); break;
        case FIELD_destSeqNum: return (omnetpp::intval_t)(pp->getDestSeqNum());
        case FIELD_originatorAddr: return omnetpp::toAnyPtr(&pp->getOriginatorAddr()); break;
        case FIELD_lifeTime: return pp->getLifeTime().dbl();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'Rrep' as cValue -- field index out of range?", field);
    }
}

void RrepDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Rrep *pp = omnetpp::fromAnyPtr<Rrep>(object); (void)pp;
    switch (field) {
        case FIELD_repairFlag: pp->setRepairFlag(value.boolValue()); break;
        case FIELD_ackRequiredFlag: pp->setAckRequiredFlag(value.boolValue()); break;
        case FIELD_reserved: pp->setReserved(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_prefixSize: pp->setPrefixSize(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_hopCount: pp->setHopCount(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_destSeqNum: pp->setDestSeqNum(omnetpp::checked_int_cast<uint32_t>(value.intValue())); break;
        case FIELD_lifeTime: pp->setLifeTime(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Rrep'", field);
    }
}

const char *RrepDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr RrepDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    Rrep *pp = omnetpp::fromAnyPtr<Rrep>(object); (void)pp;
    switch (field) {
        case FIELD_destAddr: return omnetpp::toAnyPtr(&pp->getDestAddr()); break;
        case FIELD_originatorAddr: return omnetpp::toAnyPtr(&pp->getOriginatorAddr()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void RrepDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    Rrep *pp = omnetpp::fromAnyPtr<Rrep>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Rrep'", field);
    }
}

UnreachableNode::UnreachableNode()
{
}

void __doPacking(omnetpp::cCommBuffer *b, const UnreachableNode& a)
{
    doParsimPacking(b,a.addr);
    doParsimPacking(b,a.seqNum);
}

void __doUnpacking(omnetpp::cCommBuffer *b, UnreachableNode& a)
{
    doParsimUnpacking(b,a.addr);
    doParsimUnpacking(b,a.seqNum);
}

class UnreachableNodeDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_addr,
        FIELD_seqNum,
    };
  public:
    UnreachableNodeDescriptor();
    virtual ~UnreachableNodeDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(UnreachableNodeDescriptor)

UnreachableNodeDescriptor::UnreachableNodeDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::aodvSdn::UnreachableNode)), "")
{
    propertyNames = nullptr;
}

UnreachableNodeDescriptor::~UnreachableNodeDescriptor()
{
    delete[] propertyNames;
}

bool UnreachableNodeDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UnreachableNode *>(obj)!=nullptr;
}

const char **UnreachableNodeDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = { "packetData",  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *UnreachableNodeDescriptor::getProperty(const char *propertyName) const
{
    if (!strcmp(propertyName, "packetData")) return "";
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int UnreachableNodeDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int UnreachableNodeDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_addr
        FD_ISEDITABLE,    // FIELD_seqNum
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *UnreachableNodeDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "addr",
        "seqNum",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int UnreachableNodeDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "addr") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "seqNum") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *UnreachableNodeDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::L3Address",    // FIELD_addr
        "uint32_t",    // FIELD_seqNum
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **UnreachableNodeDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *UnreachableNodeDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int UnreachableNodeDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    UnreachableNode *pp = omnetpp::fromAnyPtr<UnreachableNode>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void UnreachableNodeDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    UnreachableNode *pp = omnetpp::fromAnyPtr<UnreachableNode>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'UnreachableNode'", field);
    }
}

const char *UnreachableNodeDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    UnreachableNode *pp = omnetpp::fromAnyPtr<UnreachableNode>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UnreachableNodeDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    UnreachableNode *pp = omnetpp::fromAnyPtr<UnreachableNode>(object); (void)pp;
    switch (field) {
        case FIELD_addr: return pp->addr.str();
        case FIELD_seqNum: return ulong2string(pp->seqNum);
        default: return "";
    }
}

void UnreachableNodeDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    UnreachableNode *pp = omnetpp::fromAnyPtr<UnreachableNode>(object); (void)pp;
    switch (field) {
        case FIELD_seqNum: pp->seqNum = string2ulong(value); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UnreachableNode'", field);
    }
}

omnetpp::cValue UnreachableNodeDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    UnreachableNode *pp = omnetpp::fromAnyPtr<UnreachableNode>(object); (void)pp;
    switch (field) {
        case FIELD_addr: return omnetpp::toAnyPtr(&pp->addr); break;
        case FIELD_seqNum: return (omnetpp::intval_t)(pp->seqNum);
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'UnreachableNode' as cValue -- field index out of range?", field);
    }
}

void UnreachableNodeDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    UnreachableNode *pp = omnetpp::fromAnyPtr<UnreachableNode>(object); (void)pp;
    switch (field) {
        case FIELD_seqNum: pp->seqNum = omnetpp::checked_int_cast<uint32_t>(value.intValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UnreachableNode'", field);
    }
}

const char *UnreachableNodeDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr UnreachableNodeDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    UnreachableNode *pp = omnetpp::fromAnyPtr<UnreachableNode>(object); (void)pp;
    switch (field) {
        case FIELD_addr: return omnetpp::toAnyPtr(&pp->addr); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void UnreachableNodeDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    UnreachableNode *pp = omnetpp::fromAnyPtr<UnreachableNode>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UnreachableNode'", field);
    }
}

Register_Class(Rerr)

Rerr::Rerr() : ::inet::aodvSdn::AodvSdnControlPacket()
{
}

Rerr::Rerr(const Rerr& other) : ::inet::aodvSdn::AodvSdnControlPacket(other)
{
    copy(other);
}

Rerr::~Rerr()
{
    delete [] this->unreachableNodes;
}

Rerr& Rerr::operator=(const Rerr& other)
{
    if (this == &other) return *this;
    ::inet::aodvSdn::AodvSdnControlPacket::operator=(other);
    copy(other);
    return *this;
}

void Rerr::copy(const Rerr& other)
{
    this->noDeleteFlag = other.noDeleteFlag;
    this->reserved = other.reserved;
    delete [] this->unreachableNodes;
    this->unreachableNodes = (other.unreachableNodes_arraysize==0) ? nullptr : new UnreachableNode[other.unreachableNodes_arraysize];
    unreachableNodes_arraysize = other.unreachableNodes_arraysize;
    for (size_t i = 0; i < unreachableNodes_arraysize; i++) {
        this->unreachableNodes[i] = other.unreachableNodes[i];
    }
}

void Rerr::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::aodvSdn::AodvSdnControlPacket::parsimPack(b);
    doParsimPacking(b,this->noDeleteFlag);
    doParsimPacking(b,this->reserved);
    b->pack(unreachableNodes_arraysize);
    doParsimArrayPacking(b,this->unreachableNodes,unreachableNodes_arraysize);
}

void Rerr::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::aodvSdn::AodvSdnControlPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->noDeleteFlag);
    doParsimUnpacking(b,this->reserved);
    delete [] this->unreachableNodes;
    b->unpack(unreachableNodes_arraysize);
    if (unreachableNodes_arraysize == 0) {
        this->unreachableNodes = nullptr;
    } else {
        this->unreachableNodes = new UnreachableNode[unreachableNodes_arraysize];
        doParsimArrayUnpacking(b,this->unreachableNodes,unreachableNodes_arraysize);
    }
}

bool Rerr::getNoDeleteFlag() const
{
    return this->noDeleteFlag;
}

void Rerr::setNoDeleteFlag(bool noDeleteFlag)
{
    handleChange();
    this->noDeleteFlag = noDeleteFlag;
}

uint16_t Rerr::getReserved() const
{
    return this->reserved;
}

void Rerr::setReserved(uint16_t reserved)
{
    handleChange();
    this->reserved = reserved;
}

size_t Rerr::getUnreachableNodesArraySize() const
{
    return unreachableNodes_arraysize;
}

const UnreachableNode& Rerr::getUnreachableNodes(size_t k) const
{
    if (k >= unreachableNodes_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)unreachableNodes_arraysize, (unsigned long)k);
    return this->unreachableNodes[k];
}

void Rerr::setUnreachableNodesArraySize(size_t newSize)
{
    handleChange();
    UnreachableNode *unreachableNodes2 = (newSize==0) ? nullptr : new UnreachableNode[newSize];
    size_t minSize = unreachableNodes_arraysize < newSize ? unreachableNodes_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        unreachableNodes2[i] = this->unreachableNodes[i];
    delete [] this->unreachableNodes;
    this->unreachableNodes = unreachableNodes2;
    unreachableNodes_arraysize = newSize;
}

void Rerr::setUnreachableNodes(size_t k, const UnreachableNode& unreachableNodes)
{
    if (k >= unreachableNodes_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)unreachableNodes_arraysize, (unsigned long)k);
    handleChange();
    this->unreachableNodes[k] = unreachableNodes;
}

void Rerr::insertUnreachableNodes(size_t k, const UnreachableNode& unreachableNodes)
{
    if (k > unreachableNodes_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)unreachableNodes_arraysize, (unsigned long)k);
    handleChange();
    size_t newSize = unreachableNodes_arraysize + 1;
    UnreachableNode *unreachableNodes2 = new UnreachableNode[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        unreachableNodes2[i] = this->unreachableNodes[i];
    unreachableNodes2[k] = unreachableNodes;
    for (i = k + 1; i < newSize; i++)
        unreachableNodes2[i] = this->unreachableNodes[i-1];
    delete [] this->unreachableNodes;
    this->unreachableNodes = unreachableNodes2;
    unreachableNodes_arraysize = newSize;
}

void Rerr::appendUnreachableNodes(const UnreachableNode& unreachableNodes)
{
    insertUnreachableNodes(unreachableNodes_arraysize, unreachableNodes);
}

void Rerr::eraseUnreachableNodes(size_t k)
{
    if (k >= unreachableNodes_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)unreachableNodes_arraysize, (unsigned long)k);
    handleChange();
    size_t newSize = unreachableNodes_arraysize - 1;
    UnreachableNode *unreachableNodes2 = (newSize == 0) ? nullptr : new UnreachableNode[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        unreachableNodes2[i] = this->unreachableNodes[i];
    for (i = k; i < newSize; i++)
        unreachableNodes2[i] = this->unreachableNodes[i+1];
    delete [] this->unreachableNodes;
    this->unreachableNodes = unreachableNodes2;
    unreachableNodes_arraysize = newSize;
}

class RerrDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_noDeleteFlag,
        FIELD_reserved,
        FIELD_unreachableNodes,
    };
  public:
    RerrDescriptor();
    virtual ~RerrDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(RerrDescriptor)

RerrDescriptor::RerrDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::aodvSdn::Rerr)), "inet::aodvSdn::AodvSdnControlPacket")
{
    propertyNames = nullptr;
}

RerrDescriptor::~RerrDescriptor()
{
    delete[] propertyNames;
}

bool RerrDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Rerr *>(obj)!=nullptr;
}

const char **RerrDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *RerrDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int RerrDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int RerrDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_noDeleteFlag
        FD_ISEDITABLE,    // FIELD_reserved
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISRESIZABLE,    // FIELD_unreachableNodes
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *RerrDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "noDeleteFlag",
        "reserved",
        "unreachableNodes",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int RerrDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "noDeleteFlag") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "reserved") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "unreachableNodes") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *RerrDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_noDeleteFlag
        "uint16_t",    // FIELD_reserved
        "inet::aodvSdn::UnreachableNode",    // FIELD_unreachableNodes
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **RerrDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *RerrDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int RerrDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    Rerr *pp = omnetpp::fromAnyPtr<Rerr>(object); (void)pp;
    switch (field) {
        case FIELD_unreachableNodes: return pp->getUnreachableNodesArraySize();
        default: return 0;
    }
}

void RerrDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    Rerr *pp = omnetpp::fromAnyPtr<Rerr>(object); (void)pp;
    switch (field) {
        case FIELD_unreachableNodes: pp->setUnreachableNodesArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Rerr'", field);
    }
}

const char *RerrDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    Rerr *pp = omnetpp::fromAnyPtr<Rerr>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RerrDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    Rerr *pp = omnetpp::fromAnyPtr<Rerr>(object); (void)pp;
    switch (field) {
        case FIELD_noDeleteFlag: return bool2string(pp->getNoDeleteFlag());
        case FIELD_reserved: return ulong2string(pp->getReserved());
        case FIELD_unreachableNodes: return "";
        default: return "";
    }
}

void RerrDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Rerr *pp = omnetpp::fromAnyPtr<Rerr>(object); (void)pp;
    switch (field) {
        case FIELD_noDeleteFlag: pp->setNoDeleteFlag(string2bool(value)); break;
        case FIELD_reserved: pp->setReserved(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Rerr'", field);
    }
}

omnetpp::cValue RerrDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    Rerr *pp = omnetpp::fromAnyPtr<Rerr>(object); (void)pp;
    switch (field) {
        case FIELD_noDeleteFlag: return pp->getNoDeleteFlag();
        case FIELD_reserved: return (omnetpp::intval_t)(pp->getReserved());
        case FIELD_unreachableNodes: return omnetpp::toAnyPtr(&pp->getUnreachableNodes(i)); break;
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'Rerr' as cValue -- field index out of range?", field);
    }
}

void RerrDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Rerr *pp = omnetpp::fromAnyPtr<Rerr>(object); (void)pp;
    switch (field) {
        case FIELD_noDeleteFlag: pp->setNoDeleteFlag(value.boolValue()); break;
        case FIELD_reserved: pp->setReserved(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Rerr'", field);
    }
}

const char *RerrDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_unreachableNodes: return omnetpp::opp_typename(typeid(UnreachableNode));
        default: return nullptr;
    };
}

omnetpp::any_ptr RerrDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    Rerr *pp = omnetpp::fromAnyPtr<Rerr>(object); (void)pp;
    switch (field) {
        case FIELD_unreachableNodes: return omnetpp::toAnyPtr(&pp->getUnreachableNodes(i)); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void RerrDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    Rerr *pp = omnetpp::fromAnyPtr<Rerr>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Rerr'", field);
    }
}

Register_Class(RrepAck)

RrepAck::RrepAck() : ::inet::aodvSdn::AodvSdnControlPacket()
{
    this->setChunkLength(B(2));

}

RrepAck::RrepAck(const RrepAck& other) : ::inet::aodvSdn::AodvSdnControlPacket(other)
{
    copy(other);
}

RrepAck::~RrepAck()
{
}

RrepAck& RrepAck::operator=(const RrepAck& other)
{
    if (this == &other) return *this;
    ::inet::aodvSdn::AodvSdnControlPacket::operator=(other);
    copy(other);
    return *this;
}

void RrepAck::copy(const RrepAck& other)
{
    this->reserved = other.reserved;
}

void RrepAck::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::aodvSdn::AodvSdnControlPacket::parsimPack(b);
    doParsimPacking(b,this->reserved);
}

void RrepAck::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::aodvSdn::AodvSdnControlPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->reserved);
}

uint8_t RrepAck::getReserved() const
{
    return this->reserved;
}

void RrepAck::setReserved(uint8_t reserved)
{
    handleChange();
    this->reserved = reserved;
}

class RrepAckDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_reserved,
    };
  public:
    RrepAckDescriptor();
    virtual ~RrepAckDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(RrepAckDescriptor)

RrepAckDescriptor::RrepAckDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::aodvSdn::RrepAck)), "inet::aodvSdn::AodvSdnControlPacket")
{
    propertyNames = nullptr;
}

RrepAckDescriptor::~RrepAckDescriptor()
{
    delete[] propertyNames;
}

bool RrepAckDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RrepAck *>(obj)!=nullptr;
}

const char **RrepAckDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *RrepAckDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int RrepAckDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int RrepAckDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_reserved
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *RrepAckDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "reserved",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int RrepAckDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "reserved") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *RrepAckDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",    // FIELD_reserved
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **RrepAckDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *RrepAckDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int RrepAckDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    RrepAck *pp = omnetpp::fromAnyPtr<RrepAck>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void RrepAckDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    RrepAck *pp = omnetpp::fromAnyPtr<RrepAck>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'RrepAck'", field);
    }
}

const char *RrepAckDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    RrepAck *pp = omnetpp::fromAnyPtr<RrepAck>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RrepAckDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    RrepAck *pp = omnetpp::fromAnyPtr<RrepAck>(object); (void)pp;
    switch (field) {
        case FIELD_reserved: return ulong2string(pp->getReserved());
        default: return "";
    }
}

void RrepAckDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    RrepAck *pp = omnetpp::fromAnyPtr<RrepAck>(object); (void)pp;
    switch (field) {
        case FIELD_reserved: pp->setReserved(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'RrepAck'", field);
    }
}

omnetpp::cValue RrepAckDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    RrepAck *pp = omnetpp::fromAnyPtr<RrepAck>(object); (void)pp;
    switch (field) {
        case FIELD_reserved: return (omnetpp::intval_t)(pp->getReserved());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'RrepAck' as cValue -- field index out of range?", field);
    }
}

void RrepAckDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    RrepAck *pp = omnetpp::fromAnyPtr<RrepAck>(object); (void)pp;
    switch (field) {
        case FIELD_reserved: pp->setReserved(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'RrepAck'", field);
    }
}

const char *RrepAckDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr RrepAckDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    RrepAck *pp = omnetpp::fromAnyPtr<RrepAck>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void RrepAckDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    RrepAck *pp = omnetpp::fromAnyPtr<RrepAck>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'RrepAck'", field);
    }
}

Register_Class(WaitForRrep)

WaitForRrep::WaitForRrep(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

WaitForRrep::WaitForRrep(const WaitForRrep& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

WaitForRrep::~WaitForRrep()
{
}

WaitForRrep& WaitForRrep::operator=(const WaitForRrep& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void WaitForRrep::copy(const WaitForRrep& other)
{
    this->destAddr = other.destAddr;
    this->lastTTL = other.lastTTL;
    this->fromInvalidEntry = other.fromInvalidEntry;
}

void WaitForRrep::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->destAddr);
    doParsimPacking(b,this->lastTTL);
    doParsimPacking(b,this->fromInvalidEntry);
}

void WaitForRrep::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->destAddr);
    doParsimUnpacking(b,this->lastTTL);
    doParsimUnpacking(b,this->fromInvalidEntry);
}

const ::inet::L3Address& WaitForRrep::getDestAddr() const
{
    return this->destAddr;
}

void WaitForRrep::setDestAddr(const ::inet::L3Address& destAddr)
{
    this->destAddr = destAddr;
}

unsigned int WaitForRrep::getLastTTL() const
{
    return this->lastTTL;
}

void WaitForRrep::setLastTTL(unsigned int lastTTL)
{
    this->lastTTL = lastTTL;
}

bool WaitForRrep::getFromInvalidEntry() const
{
    return this->fromInvalidEntry;
}

void WaitForRrep::setFromInvalidEntry(bool fromInvalidEntry)
{
    this->fromInvalidEntry = fromInvalidEntry;
}

class WaitForRrepDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_destAddr,
        FIELD_lastTTL,
        FIELD_fromInvalidEntry,
    };
  public:
    WaitForRrepDescriptor();
    virtual ~WaitForRrepDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(WaitForRrepDescriptor)

WaitForRrepDescriptor::WaitForRrepDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::aodvSdn::WaitForRrep)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

WaitForRrepDescriptor::~WaitForRrepDescriptor()
{
    delete[] propertyNames;
}

bool WaitForRrepDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<WaitForRrep *>(obj)!=nullptr;
}

const char **WaitForRrepDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *WaitForRrepDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int WaitForRrepDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int WaitForRrepDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_destAddr
        FD_ISEDITABLE,    // FIELD_lastTTL
        FD_ISEDITABLE,    // FIELD_fromInvalidEntry
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *WaitForRrepDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "destAddr",
        "lastTTL",
        "fromInvalidEntry",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int WaitForRrepDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "destAddr") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "lastTTL") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "fromInvalidEntry") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *WaitForRrepDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::L3Address",    // FIELD_destAddr
        "unsigned int",    // FIELD_lastTTL
        "bool",    // FIELD_fromInvalidEntry
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **WaitForRrepDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *WaitForRrepDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int WaitForRrepDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    WaitForRrep *pp = omnetpp::fromAnyPtr<WaitForRrep>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void WaitForRrepDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    WaitForRrep *pp = omnetpp::fromAnyPtr<WaitForRrep>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'WaitForRrep'", field);
    }
}

const char *WaitForRrepDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    WaitForRrep *pp = omnetpp::fromAnyPtr<WaitForRrep>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string WaitForRrepDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    WaitForRrep *pp = omnetpp::fromAnyPtr<WaitForRrep>(object); (void)pp;
    switch (field) {
        case FIELD_destAddr: return pp->getDestAddr().str();
        case FIELD_lastTTL: return ulong2string(pp->getLastTTL());
        case FIELD_fromInvalidEntry: return bool2string(pp->getFromInvalidEntry());
        default: return "";
    }
}

void WaitForRrepDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    WaitForRrep *pp = omnetpp::fromAnyPtr<WaitForRrep>(object); (void)pp;
    switch (field) {
        case FIELD_lastTTL: pp->setLastTTL(string2ulong(value)); break;
        case FIELD_fromInvalidEntry: pp->setFromInvalidEntry(string2bool(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'WaitForRrep'", field);
    }
}

omnetpp::cValue WaitForRrepDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    WaitForRrep *pp = omnetpp::fromAnyPtr<WaitForRrep>(object); (void)pp;
    switch (field) {
        case FIELD_destAddr: return omnetpp::toAnyPtr(&pp->getDestAddr()); break;
        case FIELD_lastTTL: return (omnetpp::intval_t)(pp->getLastTTL());
        case FIELD_fromInvalidEntry: return pp->getFromInvalidEntry();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'WaitForRrep' as cValue -- field index out of range?", field);
    }
}

void WaitForRrepDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    WaitForRrep *pp = omnetpp::fromAnyPtr<WaitForRrep>(object); (void)pp;
    switch (field) {
        case FIELD_lastTTL: pp->setLastTTL(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_fromInvalidEntry: pp->setFromInvalidEntry(value.boolValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'WaitForRrep'", field);
    }
}

const char *WaitForRrepDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr WaitForRrepDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    WaitForRrep *pp = omnetpp::fromAnyPtr<WaitForRrep>(object); (void)pp;
    switch (field) {
        case FIELD_destAddr: return omnetpp::toAnyPtr(&pp->getDestAddr()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void WaitForRrepDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    WaitForRrep *pp = omnetpp::fromAnyPtr<WaitForRrep>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'WaitForRrep'", field);
    }
}

Register_Class(PacketHolderMessage)

PacketHolderMessage::PacketHolderMessage(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
    if (this->ownedPacket != nullptr) take(this->ownedPacket);
}

PacketHolderMessage::PacketHolderMessage(const PacketHolderMessage& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

PacketHolderMessage::~PacketHolderMessage()
{
    dropAndDelete(this->ownedPacket);
}

PacketHolderMessage& PacketHolderMessage::operator=(const PacketHolderMessage& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void PacketHolderMessage::copy(const PacketHolderMessage& other)
{
    dropAndDelete(this->ownedPacket);
    this->ownedPacket = other.ownedPacket;
    if (this->ownedPacket != nullptr) {
        this->ownedPacket = this->ownedPacket->dup();
        take(this->ownedPacket);
        this->ownedPacket->setName(other.ownedPacket->getName());
    }
}

void PacketHolderMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->ownedPacket);
}

void PacketHolderMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->ownedPacket);
}

const ::inet::Packet * PacketHolderMessage::getOwnedPacket() const
{
    return this->ownedPacket;
}

void PacketHolderMessage::setOwnedPacket(::inet::Packet * ownedPacket)
{
    if (this->ownedPacket != nullptr) throw omnetpp::cRuntimeError("setOwnedPacket(): a value is already set, remove it first with removeOwnedPacket()");
    this->ownedPacket = ownedPacket;
    if (this->ownedPacket != nullptr) take(this->ownedPacket);
}

::inet::Packet * PacketHolderMessage::removeOwnedPacket()
{
    ::inet::Packet * retval = this->ownedPacket;
    if (retval != nullptr) drop(retval);
    this->ownedPacket = nullptr;
    return retval;
}

class PacketHolderMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_ownedPacket,
    };
  public:
    PacketHolderMessageDescriptor();
    virtual ~PacketHolderMessageDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(PacketHolderMessageDescriptor)

PacketHolderMessageDescriptor::PacketHolderMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::aodvSdn::PacketHolderMessage)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

PacketHolderMessageDescriptor::~PacketHolderMessageDescriptor()
{
    delete[] propertyNames;
}

bool PacketHolderMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PacketHolderMessage *>(obj)!=nullptr;
}

const char **PacketHolderMessageDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *PacketHolderMessageDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int PacketHolderMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int PacketHolderMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT | FD_ISREPLACEABLE,    // FIELD_ownedPacket
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *PacketHolderMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ownedPacket",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int PacketHolderMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "ownedPacket") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *PacketHolderMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Packet",    // FIELD_ownedPacket
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **PacketHolderMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_ownedPacket: {
            static const char *names[] = { "owned",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *PacketHolderMessageDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_ownedPacket:
            if (!strcmp(propertyName, "owned")) return "";
            return nullptr;
        default: return nullptr;
    }
}

int PacketHolderMessageDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    PacketHolderMessage *pp = omnetpp::fromAnyPtr<PacketHolderMessage>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void PacketHolderMessageDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    PacketHolderMessage *pp = omnetpp::fromAnyPtr<PacketHolderMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'PacketHolderMessage'", field);
    }
}

const char *PacketHolderMessageDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    PacketHolderMessage *pp = omnetpp::fromAnyPtr<PacketHolderMessage>(object); (void)pp;
    switch (field) {
        case FIELD_ownedPacket: { const ::inet::Packet * value = pp->getOwnedPacket(); return omnetpp::opp_typename(typeid(*value)); }
        default: return nullptr;
    }
}

std::string PacketHolderMessageDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    PacketHolderMessage *pp = omnetpp::fromAnyPtr<PacketHolderMessage>(object); (void)pp;
    switch (field) {
        case FIELD_ownedPacket: { auto obj = pp->getOwnedPacket(); return obj == nullptr ? "" : obj->str(); }
        default: return "";
    }
}

void PacketHolderMessageDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PacketHolderMessage *pp = omnetpp::fromAnyPtr<PacketHolderMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PacketHolderMessage'", field);
    }
}

omnetpp::cValue PacketHolderMessageDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    PacketHolderMessage *pp = omnetpp::fromAnyPtr<PacketHolderMessage>(object); (void)pp;
    switch (field) {
        case FIELD_ownedPacket: return omnetpp::toAnyPtr(pp->getOwnedPacket()); break;
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'PacketHolderMessage' as cValue -- field index out of range?", field);
    }
}

void PacketHolderMessageDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PacketHolderMessage *pp = omnetpp::fromAnyPtr<PacketHolderMessage>(object); (void)pp;
    switch (field) {
        case FIELD_ownedPacket: pp->setOwnedPacket(omnetpp::fromAnyPtr<::inet::Packet>(value.pointerValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PacketHolderMessage'", field);
    }
}

const char *PacketHolderMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_ownedPacket: return omnetpp::opp_typename(typeid(::inet::Packet));
        default: return nullptr;
    };
}

omnetpp::any_ptr PacketHolderMessageDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    PacketHolderMessage *pp = omnetpp::fromAnyPtr<PacketHolderMessage>(object); (void)pp;
    switch (field) {
        case FIELD_ownedPacket: return omnetpp::toAnyPtr(pp->getOwnedPacket()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void PacketHolderMessageDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    PacketHolderMessage *pp = omnetpp::fromAnyPtr<PacketHolderMessage>(object); (void)pp;
    switch (field) {
        case FIELD_ownedPacket: pp->setOwnedPacket(omnetpp::fromAnyPtr<::inet::Packet>(ptr)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PacketHolderMessage'", field);
    }
}

SdnControllerEntry::SdnControllerEntry()
{
}

void __doPacking(omnetpp::cCommBuffer *b, const SdnControllerEntry& a)
{
    doParsimPacking(b,a.controllerAddr);
    doParsimPacking(b,a.controllerInfo);
}

void __doUnpacking(omnetpp::cCommBuffer *b, SdnControllerEntry& a)
{
    doParsimUnpacking(b,a.controllerAddr);
    doParsimUnpacking(b,a.controllerInfo);
}

class SdnControllerEntryDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_controllerAddr,
        FIELD_controllerInfo,
    };
  public:
    SdnControllerEntryDescriptor();
    virtual ~SdnControllerEntryDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(SdnControllerEntryDescriptor)

SdnControllerEntryDescriptor::SdnControllerEntryDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::aodvSdn::SdnControllerEntry)), "")
{
    propertyNames = nullptr;
}

SdnControllerEntryDescriptor::~SdnControllerEntryDescriptor()
{
    delete[] propertyNames;
}

bool SdnControllerEntryDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SdnControllerEntry *>(obj)!=nullptr;
}

const char **SdnControllerEntryDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = { "packetData",  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *SdnControllerEntryDescriptor::getProperty(const char *propertyName) const
{
    if (!strcmp(propertyName, "packetData")) return "";
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int SdnControllerEntryDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int SdnControllerEntryDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_controllerAddr
        FD_ISEDITABLE,    // FIELD_controllerInfo
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *SdnControllerEntryDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "controllerAddr",
        "controllerInfo",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int SdnControllerEntryDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "controllerAddr") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "controllerInfo") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *SdnControllerEntryDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::L3Address",    // FIELD_controllerAddr
        "string",    // FIELD_controllerInfo
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **SdnControllerEntryDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *SdnControllerEntryDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int SdnControllerEntryDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    SdnControllerEntry *pp = omnetpp::fromAnyPtr<SdnControllerEntry>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void SdnControllerEntryDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    SdnControllerEntry *pp = omnetpp::fromAnyPtr<SdnControllerEntry>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'SdnControllerEntry'", field);
    }
}

const char *SdnControllerEntryDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    SdnControllerEntry *pp = omnetpp::fromAnyPtr<SdnControllerEntry>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SdnControllerEntryDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    SdnControllerEntry *pp = omnetpp::fromAnyPtr<SdnControllerEntry>(object); (void)pp;
    switch (field) {
        case FIELD_controllerAddr: return pp->controllerAddr.str();
        case FIELD_controllerInfo: return oppstring2string(pp->controllerInfo);
        default: return "";
    }
}

void SdnControllerEntryDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    SdnControllerEntry *pp = omnetpp::fromAnyPtr<SdnControllerEntry>(object); (void)pp;
    switch (field) {
        case FIELD_controllerInfo: pp->controllerInfo = (value); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'SdnControllerEntry'", field);
    }
}

omnetpp::cValue SdnControllerEntryDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    SdnControllerEntry *pp = omnetpp::fromAnyPtr<SdnControllerEntry>(object); (void)pp;
    switch (field) {
        case FIELD_controllerAddr: return omnetpp::toAnyPtr(&pp->controllerAddr); break;
        case FIELD_controllerInfo: return pp->controllerInfo;
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'SdnControllerEntry' as cValue -- field index out of range?", field);
    }
}

void SdnControllerEntryDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    SdnControllerEntry *pp = omnetpp::fromAnyPtr<SdnControllerEntry>(object); (void)pp;
    switch (field) {
        case FIELD_controllerInfo: pp->controllerInfo = value.stringValue(); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'SdnControllerEntry'", field);
    }
}

const char *SdnControllerEntryDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr SdnControllerEntryDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    SdnControllerEntry *pp = omnetpp::fromAnyPtr<SdnControllerEntry>(object); (void)pp;
    switch (field) {
        case FIELD_controllerAddr: return omnetpp::toAnyPtr(&pp->controllerAddr); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void SdnControllerEntryDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    SdnControllerEntry *pp = omnetpp::fromAnyPtr<SdnControllerEntry>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'SdnControllerEntry'", field);
    }
}

Register_Class(Sdnadv)

Sdnadv::Sdnadv() : ::inet::aodvSdn::AodvSdnControlPacket()
{
}

Sdnadv::Sdnadv(const Sdnadv& other) : ::inet::aodvSdn::AodvSdnControlPacket(other)
{
    copy(other);
}

Sdnadv::~Sdnadv()
{
    delete [] this->controllers;
}

Sdnadv& Sdnadv::operator=(const Sdnadv& other)
{
    if (this == &other) return *this;
    ::inet::aodvSdn::AodvSdnControlPacket::operator=(other);
    copy(other);
    return *this;
}

void Sdnadv::copy(const Sdnadv& other)
{
    this->noOfControllers = other.noOfControllers;
    this->hopCount = other.hopCount;
    delete [] this->controllers;
    this->controllers = (other.controllers_arraysize==0) ? nullptr : new SdnControllerEntry[other.controllers_arraysize];
    controllers_arraysize = other.controllers_arraysize;
    for (size_t i = 0; i < controllers_arraysize; i++) {
        this->controllers[i] = other.controllers[i];
    }
}

void Sdnadv::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::aodvSdn::AodvSdnControlPacket::parsimPack(b);
    doParsimPacking(b,this->noOfControllers);
    doParsimPacking(b,this->hopCount);
    b->pack(controllers_arraysize);
    doParsimArrayPacking(b,this->controllers,controllers_arraysize);
}

void Sdnadv::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::aodvSdn::AodvSdnControlPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->noOfControllers);
    doParsimUnpacking(b,this->hopCount);
    delete [] this->controllers;
    b->unpack(controllers_arraysize);
    if (controllers_arraysize == 0) {
        this->controllers = nullptr;
    } else {
        this->controllers = new SdnControllerEntry[controllers_arraysize];
        doParsimArrayUnpacking(b,this->controllers,controllers_arraysize);
    }
}

uint8_t Sdnadv::getNoOfControllers() const
{
    return this->noOfControllers;
}

void Sdnadv::setNoOfControllers(uint8_t noOfControllers)
{
    handleChange();
    this->noOfControllers = noOfControllers;
}

unsigned int Sdnadv::getHopCount() const
{
    return this->hopCount;
}

void Sdnadv::setHopCount(unsigned int hopCount)
{
    handleChange();
    this->hopCount = hopCount;
}

size_t Sdnadv::getControllersArraySize() const
{
    return controllers_arraysize;
}

const SdnControllerEntry& Sdnadv::getControllers(size_t k) const
{
    if (k >= controllers_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)controllers_arraysize, (unsigned long)k);
    return this->controllers[k];
}

void Sdnadv::setControllersArraySize(size_t newSize)
{
    handleChange();
    SdnControllerEntry *controllers2 = (newSize==0) ? nullptr : new SdnControllerEntry[newSize];
    size_t minSize = controllers_arraysize < newSize ? controllers_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        controllers2[i] = this->controllers[i];
    delete [] this->controllers;
    this->controllers = controllers2;
    controllers_arraysize = newSize;
}

void Sdnadv::setControllers(size_t k, const SdnControllerEntry& controllers)
{
    if (k >= controllers_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)controllers_arraysize, (unsigned long)k);
    handleChange();
    this->controllers[k] = controllers;
}

void Sdnadv::insertControllers(size_t k, const SdnControllerEntry& controllers)
{
    if (k > controllers_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)controllers_arraysize, (unsigned long)k);
    handleChange();
    size_t newSize = controllers_arraysize + 1;
    SdnControllerEntry *controllers2 = new SdnControllerEntry[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        controllers2[i] = this->controllers[i];
    controllers2[k] = controllers;
    for (i = k + 1; i < newSize; i++)
        controllers2[i] = this->controllers[i-1];
    delete [] this->controllers;
    this->controllers = controllers2;
    controllers_arraysize = newSize;
}

void Sdnadv::appendControllers(const SdnControllerEntry& controllers)
{
    insertControllers(controllers_arraysize, controllers);
}

void Sdnadv::eraseControllers(size_t k)
{
    if (k >= controllers_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)controllers_arraysize, (unsigned long)k);
    handleChange();
    size_t newSize = controllers_arraysize - 1;
    SdnControllerEntry *controllers2 = (newSize == 0) ? nullptr : new SdnControllerEntry[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        controllers2[i] = this->controllers[i];
    for (i = k; i < newSize; i++)
        controllers2[i] = this->controllers[i+1];
    delete [] this->controllers;
    this->controllers = controllers2;
    controllers_arraysize = newSize;
}

class SdnadvDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_noOfControllers,
        FIELD_hopCount,
        FIELD_controllers,
    };
  public:
    SdnadvDescriptor();
    virtual ~SdnadvDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(SdnadvDescriptor)

SdnadvDescriptor::SdnadvDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::aodvSdn::Sdnadv)), "inet::aodvSdn::AodvSdnControlPacket")
{
    propertyNames = nullptr;
}

SdnadvDescriptor::~SdnadvDescriptor()
{
    delete[] propertyNames;
}

bool SdnadvDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Sdnadv *>(obj)!=nullptr;
}

const char **SdnadvDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *SdnadvDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int SdnadvDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int SdnadvDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_noOfControllers
        FD_ISEDITABLE,    // FIELD_hopCount
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISRESIZABLE,    // FIELD_controllers
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *SdnadvDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "noOfControllers",
        "hopCount",
        "controllers",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int SdnadvDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "noOfControllers") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "hopCount") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "controllers") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *SdnadvDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",    // FIELD_noOfControllers
        "unsigned int",    // FIELD_hopCount
        "inet::aodvSdn::SdnControllerEntry",    // FIELD_controllers
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **SdnadvDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *SdnadvDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int SdnadvDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    Sdnadv *pp = omnetpp::fromAnyPtr<Sdnadv>(object); (void)pp;
    switch (field) {
        case FIELD_controllers: return pp->getControllersArraySize();
        default: return 0;
    }
}

void SdnadvDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    Sdnadv *pp = omnetpp::fromAnyPtr<Sdnadv>(object); (void)pp;
    switch (field) {
        case FIELD_controllers: pp->setControllersArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Sdnadv'", field);
    }
}

const char *SdnadvDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    Sdnadv *pp = omnetpp::fromAnyPtr<Sdnadv>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SdnadvDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    Sdnadv *pp = omnetpp::fromAnyPtr<Sdnadv>(object); (void)pp;
    switch (field) {
        case FIELD_noOfControllers: return ulong2string(pp->getNoOfControllers());
        case FIELD_hopCount: return ulong2string(pp->getHopCount());
        case FIELD_controllers: return "";
        default: return "";
    }
}

void SdnadvDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Sdnadv *pp = omnetpp::fromAnyPtr<Sdnadv>(object); (void)pp;
    switch (field) {
        case FIELD_noOfControllers: pp->setNoOfControllers(string2ulong(value)); break;
        case FIELD_hopCount: pp->setHopCount(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Sdnadv'", field);
    }
}

omnetpp::cValue SdnadvDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    Sdnadv *pp = omnetpp::fromAnyPtr<Sdnadv>(object); (void)pp;
    switch (field) {
        case FIELD_noOfControllers: return (omnetpp::intval_t)(pp->getNoOfControllers());
        case FIELD_hopCount: return (omnetpp::intval_t)(pp->getHopCount());
        case FIELD_controllers: return omnetpp::toAnyPtr(&pp->getControllers(i)); break;
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'Sdnadv' as cValue -- field index out of range?", field);
    }
}

void SdnadvDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Sdnadv *pp = omnetpp::fromAnyPtr<Sdnadv>(object); (void)pp;
    switch (field) {
        case FIELD_noOfControllers: pp->setNoOfControllers(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_hopCount: pp->setHopCount(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Sdnadv'", field);
    }
}

const char *SdnadvDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_controllers: return omnetpp::opp_typename(typeid(SdnControllerEntry));
        default: return nullptr;
    };
}

omnetpp::any_ptr SdnadvDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    Sdnadv *pp = omnetpp::fromAnyPtr<Sdnadv>(object); (void)pp;
    switch (field) {
        case FIELD_controllers: return omnetpp::toAnyPtr(&pp->getControllers(i)); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void SdnadvDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    Sdnadv *pp = omnetpp::fromAnyPtr<Sdnadv>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Sdnadv'", field);
    }
}

NeighborQosEntry::NeighborQosEntry()
{
}

void __doPacking(omnetpp::cCommBuffer *b, const NeighborQosEntry& a)
{
    doParsimPacking(b,a.neighborAddr);
    doParsimPacking(b,a.qosType);
    doParsimPacking(b,a.qosValue);
}

void __doUnpacking(omnetpp::cCommBuffer *b, NeighborQosEntry& a)
{
    doParsimUnpacking(b,a.neighborAddr);
    doParsimUnpacking(b,a.qosType);
    doParsimUnpacking(b,a.qosValue);
}

class NeighborQosEntryDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_neighborAddr,
        FIELD_qosType,
        FIELD_qosValue,
    };
  public:
    NeighborQosEntryDescriptor();
    virtual ~NeighborQosEntryDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(NeighborQosEntryDescriptor)

NeighborQosEntryDescriptor::NeighborQosEntryDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::aodvSdn::NeighborQosEntry)), "")
{
    propertyNames = nullptr;
}

NeighborQosEntryDescriptor::~NeighborQosEntryDescriptor()
{
    delete[] propertyNames;
}

bool NeighborQosEntryDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NeighborQosEntry *>(obj)!=nullptr;
}

const char **NeighborQosEntryDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = { "packetData",  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *NeighborQosEntryDescriptor::getProperty(const char *propertyName) const
{
    if (!strcmp(propertyName, "packetData")) return "";
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int NeighborQosEntryDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int NeighborQosEntryDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_neighborAddr
        FD_ISEDITABLE,    // FIELD_qosType
        FD_ISEDITABLE,    // FIELD_qosValue
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *NeighborQosEntryDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "neighborAddr",
        "qosType",
        "qosValue",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int NeighborQosEntryDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "neighborAddr") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "qosType") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "qosValue") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *NeighborQosEntryDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::L3Address",    // FIELD_neighborAddr
        "uint8_t",    // FIELD_qosType
        "uint8_t",    // FIELD_qosValue
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **NeighborQosEntryDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *NeighborQosEntryDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int NeighborQosEntryDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    NeighborQosEntry *pp = omnetpp::fromAnyPtr<NeighborQosEntry>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void NeighborQosEntryDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    NeighborQosEntry *pp = omnetpp::fromAnyPtr<NeighborQosEntry>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'NeighborQosEntry'", field);
    }
}

const char *NeighborQosEntryDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    NeighborQosEntry *pp = omnetpp::fromAnyPtr<NeighborQosEntry>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NeighborQosEntryDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    NeighborQosEntry *pp = omnetpp::fromAnyPtr<NeighborQosEntry>(object); (void)pp;
    switch (field) {
        case FIELD_neighborAddr: return pp->neighborAddr.str();
        case FIELD_qosType: return ulong2string(pp->qosType);
        case FIELD_qosValue: return ulong2string(pp->qosValue);
        default: return "";
    }
}

void NeighborQosEntryDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    NeighborQosEntry *pp = omnetpp::fromAnyPtr<NeighborQosEntry>(object); (void)pp;
    switch (field) {
        case FIELD_qosType: pp->qosType = string2ulong(value); break;
        case FIELD_qosValue: pp->qosValue = string2ulong(value); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'NeighborQosEntry'", field);
    }
}

omnetpp::cValue NeighborQosEntryDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    NeighborQosEntry *pp = omnetpp::fromAnyPtr<NeighborQosEntry>(object); (void)pp;
    switch (field) {
        case FIELD_neighborAddr: return omnetpp::toAnyPtr(&pp->neighborAddr); break;
        case FIELD_qosType: return (omnetpp::intval_t)(pp->qosType);
        case FIELD_qosValue: return (omnetpp::intval_t)(pp->qosValue);
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'NeighborQosEntry' as cValue -- field index out of range?", field);
    }
}

void NeighborQosEntryDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    NeighborQosEntry *pp = omnetpp::fromAnyPtr<NeighborQosEntry>(object); (void)pp;
    switch (field) {
        case FIELD_qosType: pp->qosType = omnetpp::checked_int_cast<uint8_t>(value.intValue()); break;
        case FIELD_qosValue: pp->qosValue = omnetpp::checked_int_cast<uint8_t>(value.intValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'NeighborQosEntry'", field);
    }
}

const char *NeighborQosEntryDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr NeighborQosEntryDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    NeighborQosEntry *pp = omnetpp::fromAnyPtr<NeighborQosEntry>(object); (void)pp;
    switch (field) {
        case FIELD_neighborAddr: return omnetpp::toAnyPtr(&pp->neighborAddr); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void NeighborQosEntryDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    NeighborQosEntry *pp = omnetpp::fromAnyPtr<NeighborQosEntry>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'NeighborQosEntry'", field);
    }
}

Register_Class(Regreq)

Regreq::Regreq() : ::inet::aodvSdn::AodvSdnControlPacket()
{
}

Regreq::Regreq(const Regreq& other) : ::inet::aodvSdn::AodvSdnControlPacket(other)
{
    copy(other);
}

Regreq::~Regreq()
{
    delete [] this->neighbors;
}

Regreq& Regreq::operator=(const Regreq& other)
{
    if (this == &other) return *this;
    ::inet::aodvSdn::AodvSdnControlPacket::operator=(other);
    copy(other);
    return *this;
}

void Regreq::copy(const Regreq& other)
{
    this->nice = other.nice;
    this->hopCount = other.hopCount;
    this->sourceAddr = other.sourceAddr;
    this->noOfNeighbors = other.noOfNeighbors;
    this->noOfQos = other.noOfQos;
    this->typeOfQos = other.typeOfQos;
    delete [] this->neighbors;
    this->neighbors = (other.neighbors_arraysize==0) ? nullptr : new NeighborQosEntry[other.neighbors_arraysize];
    neighbors_arraysize = other.neighbors_arraysize;
    for (size_t i = 0; i < neighbors_arraysize; i++) {
        this->neighbors[i] = other.neighbors[i];
    }
}

void Regreq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::aodvSdn::AodvSdnControlPacket::parsimPack(b);
    doParsimPacking(b,this->nice);
    doParsimPacking(b,this->hopCount);
    doParsimPacking(b,this->sourceAddr);
    doParsimPacking(b,this->noOfNeighbors);
    doParsimPacking(b,this->noOfQos);
    doParsimPacking(b,this->typeOfQos);
    b->pack(neighbors_arraysize);
    doParsimArrayPacking(b,this->neighbors,neighbors_arraysize);
}

void Regreq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::aodvSdn::AodvSdnControlPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->nice);
    doParsimUnpacking(b,this->hopCount);
    doParsimUnpacking(b,this->sourceAddr);
    doParsimUnpacking(b,this->noOfNeighbors);
    doParsimUnpacking(b,this->noOfQos);
    doParsimUnpacking(b,this->typeOfQos);
    delete [] this->neighbors;
    b->unpack(neighbors_arraysize);
    if (neighbors_arraysize == 0) {
        this->neighbors = nullptr;
    } else {
        this->neighbors = new NeighborQosEntry[neighbors_arraysize];
        doParsimArrayUnpacking(b,this->neighbors,neighbors_arraysize);
    }
}

SdnNiceType Regreq::getNice() const
{
    return this->nice;
}

void Regreq::setNice(SdnNiceType nice)
{
    handleChange();
    this->nice = nice;
}

unsigned int Regreq::getHopCount() const
{
    return this->hopCount;
}

void Regreq::setHopCount(unsigned int hopCount)
{
    handleChange();
    this->hopCount = hopCount;
}

const ::inet::L3Address& Regreq::getSourceAddr() const
{
    return this->sourceAddr;
}

void Regreq::setSourceAddr(const ::inet::L3Address& sourceAddr)
{
    handleChange();
    this->sourceAddr = sourceAddr;
}

uint16_t Regreq::getNoOfNeighbors() const
{
    return this->noOfNeighbors;
}

void Regreq::setNoOfNeighbors(uint16_t noOfNeighbors)
{
    handleChange();
    this->noOfNeighbors = noOfNeighbors;
}

uint16_t Regreq::getNoOfQos() const
{
    return this->noOfQos;
}

void Regreq::setNoOfQos(uint16_t noOfQos)
{
    handleChange();
    this->noOfQos = noOfQos;
}

uint8_t Regreq::getTypeOfQos() const
{
    return this->typeOfQos;
}

void Regreq::setTypeOfQos(uint8_t typeOfQos)
{
    handleChange();
    this->typeOfQos = typeOfQos;
}

size_t Regreq::getNeighborsArraySize() const
{
    return neighbors_arraysize;
}

const NeighborQosEntry& Regreq::getNeighbors(size_t k) const
{
    if (k >= neighbors_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)neighbors_arraysize, (unsigned long)k);
    return this->neighbors[k];
}

void Regreq::setNeighborsArraySize(size_t newSize)
{
    handleChange();
    NeighborQosEntry *neighbors2 = (newSize==0) ? nullptr : new NeighborQosEntry[newSize];
    size_t minSize = neighbors_arraysize < newSize ? neighbors_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        neighbors2[i] = this->neighbors[i];
    delete [] this->neighbors;
    this->neighbors = neighbors2;
    neighbors_arraysize = newSize;
}

void Regreq::setNeighbors(size_t k, const NeighborQosEntry& neighbors)
{
    if (k >= neighbors_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)neighbors_arraysize, (unsigned long)k);
    handleChange();
    this->neighbors[k] = neighbors;
}

void Regreq::insertNeighbors(size_t k, const NeighborQosEntry& neighbors)
{
    if (k > neighbors_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)neighbors_arraysize, (unsigned long)k);
    handleChange();
    size_t newSize = neighbors_arraysize + 1;
    NeighborQosEntry *neighbors2 = new NeighborQosEntry[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        neighbors2[i] = this->neighbors[i];
    neighbors2[k] = neighbors;
    for (i = k + 1; i < newSize; i++)
        neighbors2[i] = this->neighbors[i-1];
    delete [] this->neighbors;
    this->neighbors = neighbors2;
    neighbors_arraysize = newSize;
}

void Regreq::appendNeighbors(const NeighborQosEntry& neighbors)
{
    insertNeighbors(neighbors_arraysize, neighbors);
}

void Regreq::eraseNeighbors(size_t k)
{
    if (k >= neighbors_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)neighbors_arraysize, (unsigned long)k);
    handleChange();
    size_t newSize = neighbors_arraysize - 1;
    NeighborQosEntry *neighbors2 = (newSize == 0) ? nullptr : new NeighborQosEntry[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        neighbors2[i] = this->neighbors[i];
    for (i = k; i < newSize; i++)
        neighbors2[i] = this->neighbors[i+1];
    delete [] this->neighbors;
    this->neighbors = neighbors2;
    neighbors_arraysize = newSize;
}

class RegreqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_nice,
        FIELD_hopCount,
        FIELD_sourceAddr,
        FIELD_noOfNeighbors,
        FIELD_noOfQos,
        FIELD_typeOfQos,
        FIELD_neighbors,
    };
  public:
    RegreqDescriptor();
    virtual ~RegreqDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(RegreqDescriptor)

RegreqDescriptor::RegreqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::aodvSdn::Regreq)), "inet::aodvSdn::AodvSdnControlPacket")
{
    propertyNames = nullptr;
}

RegreqDescriptor::~RegreqDescriptor()
{
    delete[] propertyNames;
}

bool RegreqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Regreq *>(obj)!=nullptr;
}

const char **RegreqDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *RegreqDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int RegreqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 7+base->getFieldCount() : 7;
}

unsigned int RegreqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_nice
        FD_ISEDITABLE,    // FIELD_hopCount
        0,    // FIELD_sourceAddr
        FD_ISEDITABLE,    // FIELD_noOfNeighbors
        FD_ISEDITABLE,    // FIELD_noOfQos
        FD_ISEDITABLE,    // FIELD_typeOfQos
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISRESIZABLE,    // FIELD_neighbors
    };
    return (field >= 0 && field < 7) ? fieldTypeFlags[field] : 0;
}

const char *RegreqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "nice",
        "hopCount",
        "sourceAddr",
        "noOfNeighbors",
        "noOfQos",
        "typeOfQos",
        "neighbors",
    };
    return (field >= 0 && field < 7) ? fieldNames[field] : nullptr;
}

int RegreqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "nice") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "hopCount") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "sourceAddr") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "noOfNeighbors") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "noOfQos") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "typeOfQos") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "neighbors") == 0) return baseIndex + 6;
    return base ? base->findField(fieldName) : -1;
}

const char *RegreqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::aodvSdn::SdnNiceType",    // FIELD_nice
        "unsigned int",    // FIELD_hopCount
        "inet::L3Address",    // FIELD_sourceAddr
        "uint16_t",    // FIELD_noOfNeighbors
        "uint16_t",    // FIELD_noOfQos
        "uint8_t",    // FIELD_typeOfQos
        "inet::aodvSdn::NeighborQosEntry",    // FIELD_neighbors
    };
    return (field >= 0 && field < 7) ? fieldTypeStrings[field] : nullptr;
}

const char **RegreqDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_nice: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *RegreqDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_nice:
            if (!strcmp(propertyName, "enum")) return "inet::aodvSdn::SdnNiceType";
            return nullptr;
        default: return nullptr;
    }
}

int RegreqDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    Regreq *pp = omnetpp::fromAnyPtr<Regreq>(object); (void)pp;
    switch (field) {
        case FIELD_neighbors: return pp->getNeighborsArraySize();
        default: return 0;
    }
}

void RegreqDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    Regreq *pp = omnetpp::fromAnyPtr<Regreq>(object); (void)pp;
    switch (field) {
        case FIELD_neighbors: pp->setNeighborsArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Regreq'", field);
    }
}

const char *RegreqDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    Regreq *pp = omnetpp::fromAnyPtr<Regreq>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RegreqDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    Regreq *pp = omnetpp::fromAnyPtr<Regreq>(object); (void)pp;
    switch (field) {
        case FIELD_nice: return enum2string(pp->getNice(), "inet::aodvSdn::SdnNiceType");
        case FIELD_hopCount: return ulong2string(pp->getHopCount());
        case FIELD_sourceAddr: return pp->getSourceAddr().str();
        case FIELD_noOfNeighbors: return ulong2string(pp->getNoOfNeighbors());
        case FIELD_noOfQos: return ulong2string(pp->getNoOfQos());
        case FIELD_typeOfQos: return ulong2string(pp->getTypeOfQos());
        case FIELD_neighbors: return "";
        default: return "";
    }
}

void RegreqDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Regreq *pp = omnetpp::fromAnyPtr<Regreq>(object); (void)pp;
    switch (field) {
        case FIELD_hopCount: pp->setHopCount(string2ulong(value)); break;
        case FIELD_noOfNeighbors: pp->setNoOfNeighbors(string2ulong(value)); break;
        case FIELD_noOfQos: pp->setNoOfQos(string2ulong(value)); break;
        case FIELD_typeOfQos: pp->setTypeOfQos(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Regreq'", field);
    }
}

omnetpp::cValue RegreqDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    Regreq *pp = omnetpp::fromAnyPtr<Regreq>(object); (void)pp;
    switch (field) {
        case FIELD_nice: return static_cast<int>(pp->getNice());
        case FIELD_hopCount: return (omnetpp::intval_t)(pp->getHopCount());
        case FIELD_sourceAddr: return omnetpp::toAnyPtr(&pp->getSourceAddr()); break;
        case FIELD_noOfNeighbors: return (omnetpp::intval_t)(pp->getNoOfNeighbors());
        case FIELD_noOfQos: return (omnetpp::intval_t)(pp->getNoOfQos());
        case FIELD_typeOfQos: return (omnetpp::intval_t)(pp->getTypeOfQos());
        case FIELD_neighbors: return omnetpp::toAnyPtr(&pp->getNeighbors(i)); break;
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'Regreq' as cValue -- field index out of range?", field);
    }
}

void RegreqDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Regreq *pp = omnetpp::fromAnyPtr<Regreq>(object); (void)pp;
    switch (field) {
        case FIELD_hopCount: pp->setHopCount(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_noOfNeighbors: pp->setNoOfNeighbors(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_noOfQos: pp->setNoOfQos(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_typeOfQos: pp->setTypeOfQos(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Regreq'", field);
    }
}

const char *RegreqDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_neighbors: return omnetpp::opp_typename(typeid(NeighborQosEntry));
        default: return nullptr;
    };
}

omnetpp::any_ptr RegreqDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    Regreq *pp = omnetpp::fromAnyPtr<Regreq>(object); (void)pp;
    switch (field) {
        case FIELD_sourceAddr: return omnetpp::toAnyPtr(&pp->getSourceAddr()); break;
        case FIELD_neighbors: return omnetpp::toAnyPtr(&pp->getNeighbors(i)); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void RegreqDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    Regreq *pp = omnetpp::fromAnyPtr<Regreq>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Regreq'", field);
    }
}

OfpHeader::OfpHeader()
{
}

void __doPacking(omnetpp::cCommBuffer *b, const OfpHeader& a)
{
    doParsimPacking(b,a.version);
    doParsimPacking(b,a.type);
    doParsimPacking(b,a.length);
    doParsimPacking(b,a.xid);
}

void __doUnpacking(omnetpp::cCommBuffer *b, OfpHeader& a)
{
    doParsimUnpacking(b,a.version);
    doParsimUnpacking(b,a.type);
    doParsimUnpacking(b,a.length);
    doParsimUnpacking(b,a.xid);
}

class OfpHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_version,
        FIELD_type,
        FIELD_length,
        FIELD_xid,
    };
  public:
    OfpHeaderDescriptor();
    virtual ~OfpHeaderDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(OfpHeaderDescriptor)

OfpHeaderDescriptor::OfpHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::aodvSdn::OfpHeader)), "")
{
    propertyNames = nullptr;
}

OfpHeaderDescriptor::~OfpHeaderDescriptor()
{
    delete[] propertyNames;
}

bool OfpHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OfpHeader *>(obj)!=nullptr;
}

const char **OfpHeaderDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = { "packetData",  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *OfpHeaderDescriptor::getProperty(const char *propertyName) const
{
    if (!strcmp(propertyName, "packetData")) return "";
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int OfpHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 4+base->getFieldCount() : 4;
}

unsigned int OfpHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_version
        FD_ISEDITABLE,    // FIELD_type
        FD_ISEDITABLE,    // FIELD_length
        FD_ISEDITABLE,    // FIELD_xid
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *OfpHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "version",
        "type",
        "length",
        "xid",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int OfpHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "version") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "type") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "length") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "xid") == 0) return baseIndex + 3;
    return base ? base->findField(fieldName) : -1;
}

const char *OfpHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",    // FIELD_version
        "uint8_t",    // FIELD_type
        "uint16_t",    // FIELD_length
        "uint32_t",    // FIELD_xid
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **OfpHeaderDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OfpHeaderDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OfpHeaderDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    OfpHeader *pp = omnetpp::fromAnyPtr<OfpHeader>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void OfpHeaderDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    OfpHeader *pp = omnetpp::fromAnyPtr<OfpHeader>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'OfpHeader'", field);
    }
}

const char *OfpHeaderDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    OfpHeader *pp = omnetpp::fromAnyPtr<OfpHeader>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OfpHeaderDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    OfpHeader *pp = omnetpp::fromAnyPtr<OfpHeader>(object); (void)pp;
    switch (field) {
        case FIELD_version: return ulong2string(pp->version);
        case FIELD_type: return ulong2string(pp->type);
        case FIELD_length: return ulong2string(pp->length);
        case FIELD_xid: return ulong2string(pp->xid);
        default: return "";
    }
}

void OfpHeaderDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    OfpHeader *pp = omnetpp::fromAnyPtr<OfpHeader>(object); (void)pp;
    switch (field) {
        case FIELD_version: pp->version = string2ulong(value); break;
        case FIELD_type: pp->type = string2ulong(value); break;
        case FIELD_length: pp->length = string2ulong(value); break;
        case FIELD_xid: pp->xid = string2ulong(value); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'OfpHeader'", field);
    }
}

omnetpp::cValue OfpHeaderDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    OfpHeader *pp = omnetpp::fromAnyPtr<OfpHeader>(object); (void)pp;
    switch (field) {
        case FIELD_version: return (omnetpp::intval_t)(pp->version);
        case FIELD_type: return (omnetpp::intval_t)(pp->type);
        case FIELD_length: return (omnetpp::intval_t)(pp->length);
        case FIELD_xid: return (omnetpp::intval_t)(pp->xid);
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'OfpHeader' as cValue -- field index out of range?", field);
    }
}

void OfpHeaderDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    OfpHeader *pp = omnetpp::fromAnyPtr<OfpHeader>(object); (void)pp;
    switch (field) {
        case FIELD_version: pp->version = omnetpp::checked_int_cast<uint8_t>(value.intValue()); break;
        case FIELD_type: pp->type = omnetpp::checked_int_cast<uint8_t>(value.intValue()); break;
        case FIELD_length: pp->length = omnetpp::checked_int_cast<uint16_t>(value.intValue()); break;
        case FIELD_xid: pp->xid = omnetpp::checked_int_cast<uint32_t>(value.intValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'OfpHeader'", field);
    }
}

const char *OfpHeaderDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr OfpHeaderDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    OfpHeader *pp = omnetpp::fromAnyPtr<OfpHeader>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void OfpHeaderDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    OfpHeader *pp = omnetpp::fromAnyPtr<OfpHeader>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'OfpHeader'", field);
    }
}

Register_Class(Regrep)

Regrep::Regrep() : ::inet::aodvSdn::AodvSdnControlPacket()
{
}

Regrep::Regrep(const Regrep& other) : ::inet::aodvSdn::AodvSdnControlPacket(other)
{
    copy(other);
}

Regrep::~Regrep()
{
    delete [] this->ofpData;
}

Regrep& Regrep::operator=(const Regrep& other)
{
    if (this == &other) return *this;
    ::inet::aodvSdn::AodvSdnControlPacket::operator=(other);
    copy(other);
    return *this;
}

void Regrep::copy(const Regrep& other)
{
    this->nice = other.nice;
    this->hopCount = other.hopCount;
    this->ofpHeader = other.ofpHeader;
    delete [] this->ofpData;
    this->ofpData = (other.ofpData_arraysize==0) ? nullptr : new uint8_t[other.ofpData_arraysize];
    ofpData_arraysize = other.ofpData_arraysize;
    for (size_t i = 0; i < ofpData_arraysize; i++) {
        this->ofpData[i] = other.ofpData[i];
    }
}

void Regrep::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::aodvSdn::AodvSdnControlPacket::parsimPack(b);
    doParsimPacking(b,this->nice);
    doParsimPacking(b,this->hopCount);
    doParsimPacking(b,this->ofpHeader);
    b->pack(ofpData_arraysize);
    doParsimArrayPacking(b,this->ofpData,ofpData_arraysize);
}

void Regrep::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::aodvSdn::AodvSdnControlPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->nice);
    doParsimUnpacking(b,this->hopCount);
    doParsimUnpacking(b,this->ofpHeader);
    delete [] this->ofpData;
    b->unpack(ofpData_arraysize);
    if (ofpData_arraysize == 0) {
        this->ofpData = nullptr;
    } else {
        this->ofpData = new uint8_t[ofpData_arraysize];
        doParsimArrayUnpacking(b,this->ofpData,ofpData_arraysize);
    }
}

SdnNiceType Regrep::getNice() const
{
    return this->nice;
}

void Regrep::setNice(SdnNiceType nice)
{
    handleChange();
    this->nice = nice;
}

unsigned int Regrep::getHopCount() const
{
    return this->hopCount;
}

void Regrep::setHopCount(unsigned int hopCount)
{
    handleChange();
    this->hopCount = hopCount;
}

const OfpHeader& Regrep::getOfpHeader() const
{
    return this->ofpHeader;
}

void Regrep::setOfpHeader(const OfpHeader& ofpHeader)
{
    handleChange();
    this->ofpHeader = ofpHeader;
}

size_t Regrep::getOfpDataArraySize() const
{
    return ofpData_arraysize;
}

uint8_t Regrep::getOfpData(size_t k) const
{
    if (k >= ofpData_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)ofpData_arraysize, (unsigned long)k);
    return this->ofpData[k];
}

void Regrep::setOfpDataArraySize(size_t newSize)
{
    handleChange();
    uint8_t *ofpData2 = (newSize==0) ? nullptr : new uint8_t[newSize];
    size_t minSize = ofpData_arraysize < newSize ? ofpData_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        ofpData2[i] = this->ofpData[i];
    for (size_t i = minSize; i < newSize; i++)
        ofpData2[i] = 0;
    delete [] this->ofpData;
    this->ofpData = ofpData2;
    ofpData_arraysize = newSize;
}

void Regrep::setOfpData(size_t k, uint8_t ofpData)
{
    if (k >= ofpData_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)ofpData_arraysize, (unsigned long)k);
    handleChange();
    this->ofpData[k] = ofpData;
}

void Regrep::insertOfpData(size_t k, uint8_t ofpData)
{
    if (k > ofpData_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)ofpData_arraysize, (unsigned long)k);
    handleChange();
    size_t newSize = ofpData_arraysize + 1;
    uint8_t *ofpData2 = new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        ofpData2[i] = this->ofpData[i];
    ofpData2[k] = ofpData;
    for (i = k + 1; i < newSize; i++)
        ofpData2[i] = this->ofpData[i-1];
    delete [] this->ofpData;
    this->ofpData = ofpData2;
    ofpData_arraysize = newSize;
}

void Regrep::appendOfpData(uint8_t ofpData)
{
    insertOfpData(ofpData_arraysize, ofpData);
}

void Regrep::eraseOfpData(size_t k)
{
    if (k >= ofpData_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)ofpData_arraysize, (unsigned long)k);
    handleChange();
    size_t newSize = ofpData_arraysize - 1;
    uint8_t *ofpData2 = (newSize == 0) ? nullptr : new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        ofpData2[i] = this->ofpData[i];
    for (i = k; i < newSize; i++)
        ofpData2[i] = this->ofpData[i+1];
    delete [] this->ofpData;
    this->ofpData = ofpData2;
    ofpData_arraysize = newSize;
}

class RegrepDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_nice,
        FIELD_hopCount,
        FIELD_ofpHeader,
        FIELD_ofpData,
    };
  public:
    RegrepDescriptor();
    virtual ~RegrepDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(RegrepDescriptor)

RegrepDescriptor::RegrepDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::aodvSdn::Regrep)), "inet::aodvSdn::AodvSdnControlPacket")
{
    propertyNames = nullptr;
}

RegrepDescriptor::~RegrepDescriptor()
{
    delete[] propertyNames;
}

bool RegrepDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Regrep *>(obj)!=nullptr;
}

const char **RegrepDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *RegrepDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int RegrepDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 4+base->getFieldCount() : 4;
}

unsigned int RegrepDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_nice
        FD_ISEDITABLE,    // FIELD_hopCount
        FD_ISCOMPOUND,    // FIELD_ofpHeader
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_ofpData
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *RegrepDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "nice",
        "hopCount",
        "ofpHeader",
        "ofpData",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int RegrepDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "nice") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "hopCount") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "ofpHeader") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "ofpData") == 0) return baseIndex + 3;
    return base ? base->findField(fieldName) : -1;
}

const char *RegrepDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::aodvSdn::SdnNiceType",    // FIELD_nice
        "unsigned int",    // FIELD_hopCount
        "inet::aodvSdn::OfpHeader",    // FIELD_ofpHeader
        "uint8_t",    // FIELD_ofpData
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **RegrepDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_nice: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *RegrepDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_nice:
            if (!strcmp(propertyName, "enum")) return "inet::aodvSdn::SdnNiceType";
            return nullptr;
        default: return nullptr;
    }
}

int RegrepDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    Regrep *pp = omnetpp::fromAnyPtr<Regrep>(object); (void)pp;
    switch (field) {
        case FIELD_ofpData: return pp->getOfpDataArraySize();
        default: return 0;
    }
}

void RegrepDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    Regrep *pp = omnetpp::fromAnyPtr<Regrep>(object); (void)pp;
    switch (field) {
        case FIELD_ofpData: pp->setOfpDataArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Regrep'", field);
    }
}

const char *RegrepDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    Regrep *pp = omnetpp::fromAnyPtr<Regrep>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RegrepDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    Regrep *pp = omnetpp::fromAnyPtr<Regrep>(object); (void)pp;
    switch (field) {
        case FIELD_nice: return enum2string(pp->getNice(), "inet::aodvSdn::SdnNiceType");
        case FIELD_hopCount: return ulong2string(pp->getHopCount());
        case FIELD_ofpHeader: return "";
        case FIELD_ofpData: return ulong2string(pp->getOfpData(i));
        default: return "";
    }
}

void RegrepDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Regrep *pp = omnetpp::fromAnyPtr<Regrep>(object); (void)pp;
    switch (field) {
        case FIELD_hopCount: pp->setHopCount(string2ulong(value)); break;
        case FIELD_ofpData: pp->setOfpData(i,string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Regrep'", field);
    }
}

omnetpp::cValue RegrepDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    Regrep *pp = omnetpp::fromAnyPtr<Regrep>(object); (void)pp;
    switch (field) {
        case FIELD_nice: return static_cast<int>(pp->getNice());
        case FIELD_hopCount: return (omnetpp::intval_t)(pp->getHopCount());
        case FIELD_ofpHeader: return omnetpp::toAnyPtr(&pp->getOfpHeader()); break;
        case FIELD_ofpData: return (omnetpp::intval_t)(pp->getOfpData(i));
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'Regrep' as cValue -- field index out of range?", field);
    }
}

void RegrepDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Regrep *pp = omnetpp::fromAnyPtr<Regrep>(object); (void)pp;
    switch (field) {
        case FIELD_hopCount: pp->setHopCount(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_ofpData: pp->setOfpData(i,omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Regrep'", field);
    }
}

const char *RegrepDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_ofpHeader: return omnetpp::opp_typename(typeid(OfpHeader));
        default: return nullptr;
    };
}

omnetpp::any_ptr RegrepDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    Regrep *pp = omnetpp::fromAnyPtr<Regrep>(object); (void)pp;
    switch (field) {
        case FIELD_ofpHeader: return omnetpp::toAnyPtr(&pp->getOfpHeader()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void RegrepDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    Regrep *pp = omnetpp::fromAnyPtr<Regrep>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Regrep'", field);
    }
}

}  // namespace aodvSdn
}  // namespace inet

namespace omnetpp {

}  // namespace omnetpp

