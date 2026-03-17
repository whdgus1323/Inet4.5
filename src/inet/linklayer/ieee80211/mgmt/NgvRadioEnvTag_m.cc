//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/linklayer/ieee80211/mgmt/NgvRadioEnvTag.msg.
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
#include "NgvRadioEnvTag_m.h"

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
namespace ieee80211 {

Register_Class(NgvRadioEnvTag)

NgvRadioEnvTag::NgvRadioEnvTag() : ::omnetpp::cObject()
{
}

NgvRadioEnvTag::NgvRadioEnvTag(const NgvRadioEnvTag& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

NgvRadioEnvTag::~NgvRadioEnvTag()
{
}

NgvRadioEnvTag& NgvRadioEnvTag::operator=(const NgvRadioEnvTag& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void NgvRadioEnvTag::copy(const NgvRadioEnvTag& other)
{
    this->ngvMcs = other.ngvMcs;
    this->numSpatialStreams = other.numSpatialStreams;
    this->permittedAggregation = other.permittedAggregation;
    this->numRepetitions = other.numRepetitions;
    this->expiryTime = other.expiryTime;
    this->channelNumber = other.channelNumber;
    this->primaryChannelNumber = other.primaryChannelNumber;
    this->channelWidth = other.channelWidth;
    this->txPowerSpectralDensity = other.txPowerSpectralDensity;
}

void NgvRadioEnvTag::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->ngvMcs);
    doParsimPacking(b,this->numSpatialStreams);
    doParsimPacking(b,this->permittedAggregation);
    doParsimPacking(b,this->numRepetitions);
    doParsimPacking(b,this->expiryTime);
    doParsimPacking(b,this->channelNumber);
    doParsimPacking(b,this->primaryChannelNumber);
    doParsimPacking(b,this->channelWidth);
    doParsimPacking(b,this->txPowerSpectralDensity);
}

void NgvRadioEnvTag::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->ngvMcs);
    doParsimUnpacking(b,this->numSpatialStreams);
    doParsimUnpacking(b,this->permittedAggregation);
    doParsimUnpacking(b,this->numRepetitions);
    doParsimUnpacking(b,this->expiryTime);
    doParsimUnpacking(b,this->channelNumber);
    doParsimUnpacking(b,this->primaryChannelNumber);
    doParsimUnpacking(b,this->channelWidth);
    doParsimUnpacking(b,this->txPowerSpectralDensity);
}

int NgvRadioEnvTag::getNgvMcs() const
{
    return this->ngvMcs;
}

void NgvRadioEnvTag::setNgvMcs(int ngvMcs)
{
    this->ngvMcs = ngvMcs;
}

int NgvRadioEnvTag::getNumSpatialStreams() const
{
    return this->numSpatialStreams;
}

void NgvRadioEnvTag::setNumSpatialStreams(int numSpatialStreams)
{
    this->numSpatialStreams = numSpatialStreams;
}

bool NgvRadioEnvTag::getPermittedAggregation() const
{
    return this->permittedAggregation;
}

void NgvRadioEnvTag::setPermittedAggregation(bool permittedAggregation)
{
    this->permittedAggregation = permittedAggregation;
}

int NgvRadioEnvTag::getNumRepetitions() const
{
    return this->numRepetitions;
}

void NgvRadioEnvTag::setNumRepetitions(int numRepetitions)
{
    this->numRepetitions = numRepetitions;
}

double NgvRadioEnvTag::getExpiryTime() const
{
    return this->expiryTime;
}

void NgvRadioEnvTag::setExpiryTime(double expiryTime)
{
    this->expiryTime = expiryTime;
}

int NgvRadioEnvTag::getChannelNumber() const
{
    return this->channelNumber;
}

void NgvRadioEnvTag::setChannelNumber(int channelNumber)
{
    this->channelNumber = channelNumber;
}

int NgvRadioEnvTag::getPrimaryChannelNumber() const
{
    return this->primaryChannelNumber;
}

void NgvRadioEnvTag::setPrimaryChannelNumber(int primaryChannelNumber)
{
    this->primaryChannelNumber = primaryChannelNumber;
}

int NgvRadioEnvTag::getChannelWidth() const
{
    return this->channelWidth;
}

void NgvRadioEnvTag::setChannelWidth(int channelWidth)
{
    this->channelWidth = channelWidth;
}

double NgvRadioEnvTag::getTxPowerSpectralDensity() const
{
    return this->txPowerSpectralDensity;
}

void NgvRadioEnvTag::setTxPowerSpectralDensity(double txPowerSpectralDensity)
{
    this->txPowerSpectralDensity = txPowerSpectralDensity;
}

class NgvRadioEnvTagDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_ngvMcs,
        FIELD_numSpatialStreams,
        FIELD_permittedAggregation,
        FIELD_numRepetitions,
        FIELD_expiryTime,
        FIELD_channelNumber,
        FIELD_primaryChannelNumber,
        FIELD_channelWidth,
        FIELD_txPowerSpectralDensity,
    };
  public:
    NgvRadioEnvTagDescriptor();
    virtual ~NgvRadioEnvTagDescriptor();

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

Register_ClassDescriptor(NgvRadioEnvTagDescriptor)

NgvRadioEnvTagDescriptor::NgvRadioEnvTagDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::NgvRadioEnvTag)), "omnetpp::cObject")
{
    propertyNames = nullptr;
}

NgvRadioEnvTagDescriptor::~NgvRadioEnvTagDescriptor()
{
    delete[] propertyNames;
}

bool NgvRadioEnvTagDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NgvRadioEnvTag *>(obj)!=nullptr;
}

const char **NgvRadioEnvTagDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *NgvRadioEnvTagDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int NgvRadioEnvTagDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 9+base->getFieldCount() : 9;
}

unsigned int NgvRadioEnvTagDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_ngvMcs
        FD_ISEDITABLE,    // FIELD_numSpatialStreams
        FD_ISEDITABLE,    // FIELD_permittedAggregation
        FD_ISEDITABLE,    // FIELD_numRepetitions
        FD_ISEDITABLE,    // FIELD_expiryTime
        FD_ISEDITABLE,    // FIELD_channelNumber
        FD_ISEDITABLE,    // FIELD_primaryChannelNumber
        FD_ISEDITABLE,    // FIELD_channelWidth
        FD_ISEDITABLE,    // FIELD_txPowerSpectralDensity
    };
    return (field >= 0 && field < 9) ? fieldTypeFlags[field] : 0;
}

const char *NgvRadioEnvTagDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ngvMcs",
        "numSpatialStreams",
        "permittedAggregation",
        "numRepetitions",
        "expiryTime",
        "channelNumber",
        "primaryChannelNumber",
        "channelWidth",
        "txPowerSpectralDensity",
    };
    return (field >= 0 && field < 9) ? fieldNames[field] : nullptr;
}

int NgvRadioEnvTagDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "ngvMcs") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "numSpatialStreams") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "permittedAggregation") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "numRepetitions") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "expiryTime") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "channelNumber") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "primaryChannelNumber") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "channelWidth") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "txPowerSpectralDensity") == 0) return baseIndex + 8;
    return base ? base->findField(fieldName) : -1;
}

const char *NgvRadioEnvTagDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_ngvMcs
        "int",    // FIELD_numSpatialStreams
        "bool",    // FIELD_permittedAggregation
        "int",    // FIELD_numRepetitions
        "double",    // FIELD_expiryTime
        "int",    // FIELD_channelNumber
        "int",    // FIELD_primaryChannelNumber
        "int",    // FIELD_channelWidth
        "double",    // FIELD_txPowerSpectralDensity
    };
    return (field >= 0 && field < 9) ? fieldTypeStrings[field] : nullptr;
}

const char **NgvRadioEnvTagDescriptor::getFieldPropertyNames(int field) const
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

const char *NgvRadioEnvTagDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int NgvRadioEnvTagDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    NgvRadioEnvTag *pp = omnetpp::fromAnyPtr<NgvRadioEnvTag>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void NgvRadioEnvTagDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    NgvRadioEnvTag *pp = omnetpp::fromAnyPtr<NgvRadioEnvTag>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'NgvRadioEnvTag'", field);
    }
}

const char *NgvRadioEnvTagDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    NgvRadioEnvTag *pp = omnetpp::fromAnyPtr<NgvRadioEnvTag>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NgvRadioEnvTagDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    NgvRadioEnvTag *pp = omnetpp::fromAnyPtr<NgvRadioEnvTag>(object); (void)pp;
    switch (field) {
        case FIELD_ngvMcs: return long2string(pp->getNgvMcs());
        case FIELD_numSpatialStreams: return long2string(pp->getNumSpatialStreams());
        case FIELD_permittedAggregation: return bool2string(pp->getPermittedAggregation());
        case FIELD_numRepetitions: return long2string(pp->getNumRepetitions());
        case FIELD_expiryTime: return double2string(pp->getExpiryTime());
        case FIELD_channelNumber: return long2string(pp->getChannelNumber());
        case FIELD_primaryChannelNumber: return long2string(pp->getPrimaryChannelNumber());
        case FIELD_channelWidth: return long2string(pp->getChannelWidth());
        case FIELD_txPowerSpectralDensity: return double2string(pp->getTxPowerSpectralDensity());
        default: return "";
    }
}

void NgvRadioEnvTagDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    NgvRadioEnvTag *pp = omnetpp::fromAnyPtr<NgvRadioEnvTag>(object); (void)pp;
    switch (field) {
        case FIELD_ngvMcs: pp->setNgvMcs(string2long(value)); break;
        case FIELD_numSpatialStreams: pp->setNumSpatialStreams(string2long(value)); break;
        case FIELD_permittedAggregation: pp->setPermittedAggregation(string2bool(value)); break;
        case FIELD_numRepetitions: pp->setNumRepetitions(string2long(value)); break;
        case FIELD_expiryTime: pp->setExpiryTime(string2double(value)); break;
        case FIELD_channelNumber: pp->setChannelNumber(string2long(value)); break;
        case FIELD_primaryChannelNumber: pp->setPrimaryChannelNumber(string2long(value)); break;
        case FIELD_channelWidth: pp->setChannelWidth(string2long(value)); break;
        case FIELD_txPowerSpectralDensity: pp->setTxPowerSpectralDensity(string2double(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'NgvRadioEnvTag'", field);
    }
}

omnetpp::cValue NgvRadioEnvTagDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    NgvRadioEnvTag *pp = omnetpp::fromAnyPtr<NgvRadioEnvTag>(object); (void)pp;
    switch (field) {
        case FIELD_ngvMcs: return pp->getNgvMcs();
        case FIELD_numSpatialStreams: return pp->getNumSpatialStreams();
        case FIELD_permittedAggregation: return pp->getPermittedAggregation();
        case FIELD_numRepetitions: return pp->getNumRepetitions();
        case FIELD_expiryTime: return pp->getExpiryTime();
        case FIELD_channelNumber: return pp->getChannelNumber();
        case FIELD_primaryChannelNumber: return pp->getPrimaryChannelNumber();
        case FIELD_channelWidth: return pp->getChannelWidth();
        case FIELD_txPowerSpectralDensity: return pp->getTxPowerSpectralDensity();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'NgvRadioEnvTag' as cValue -- field index out of range?", field);
    }
}

void NgvRadioEnvTagDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    NgvRadioEnvTag *pp = omnetpp::fromAnyPtr<NgvRadioEnvTag>(object); (void)pp;
    switch (field) {
        case FIELD_ngvMcs: pp->setNgvMcs(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_numSpatialStreams: pp->setNumSpatialStreams(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_permittedAggregation: pp->setPermittedAggregation(value.boolValue()); break;
        case FIELD_numRepetitions: pp->setNumRepetitions(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_expiryTime: pp->setExpiryTime(value.doubleValue()); break;
        case FIELD_channelNumber: pp->setChannelNumber(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_primaryChannelNumber: pp->setPrimaryChannelNumber(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_channelWidth: pp->setChannelWidth(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_txPowerSpectralDensity: pp->setTxPowerSpectralDensity(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'NgvRadioEnvTag'", field);
    }
}

const char *NgvRadioEnvTagDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr NgvRadioEnvTagDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    NgvRadioEnvTag *pp = omnetpp::fromAnyPtr<NgvRadioEnvTag>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void NgvRadioEnvTagDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    NgvRadioEnvTag *pp = omnetpp::fromAnyPtr<NgvRadioEnvTag>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'NgvRadioEnvTag'", field);
    }
}

}  // namespace ieee80211
}  // namespace inet

namespace omnetpp {

}  // namespace omnetpp

