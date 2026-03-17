//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/linklayer/ieee80211/mac/ngv/NgvRadioEnvironmentReqTag.msg.
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
#include "NgvRadioEnvironmentReqTag_m.h"

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

Register_Class(NgvRadioEnvironmentReqTag)

NgvRadioEnvironmentReqTag::NgvRadioEnvironmentReqTag() : ::inet::TagBase()
{
}

NgvRadioEnvironmentReqTag::NgvRadioEnvironmentReqTag(const NgvRadioEnvironmentReqTag& other) : ::inet::TagBase(other)
{
    copy(other);
}

NgvRadioEnvironmentReqTag::~NgvRadioEnvironmentReqTag()
{
}

NgvRadioEnvironmentReqTag& NgvRadioEnvironmentReqTag::operator=(const NgvRadioEnvironmentReqTag& other)
{
    if (this == &other) return *this;
    ::inet::TagBase::operator=(other);
    copy(other);
    return *this;
}

void NgvRadioEnvironmentReqTag::copy(const NgvRadioEnvironmentReqTag& other)
{
    this->ppduFormatPresent = other.ppduFormatPresent;
    this->ppduFormat = other.ppduFormat;
    this->mcsPresent = other.mcsPresent;
    this->ngvMcs = other.ngvMcs;
    this->dataRateMbps = other.dataRateMbps;
    this->nssPresent = other.nssPresent;
    this->numSpatialStreams = other.numSpatialStreams;
    this->aggregationPresent = other.aggregationPresent;
    this->permittedAggregation = other.permittedAggregation;
    this->repetitionPresent = other.repetitionPresent;
    this->numRepetitions = other.numRepetitions;
    this->expiryPresent = other.expiryPresent;
    this->expiryTime = other.expiryTime;
    this->channelPresent = other.channelPresent;
    this->channelNumber = other.channelNumber;
    this->primaryChannelPresent = other.primaryChannelPresent;
    this->primaryChannelNumber = other.primaryChannelNumber;
    this->channelWidthPresent = other.channelWidthPresent;
    this->channelWidthMHz = other.channelWidthMHz;
}

void NgvRadioEnvironmentReqTag::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TagBase::parsimPack(b);
    doParsimPacking(b,this->ppduFormatPresent);
    doParsimPacking(b,this->ppduFormat);
    doParsimPacking(b,this->mcsPresent);
    doParsimPacking(b,this->ngvMcs);
    doParsimPacking(b,this->dataRateMbps);
    doParsimPacking(b,this->nssPresent);
    doParsimPacking(b,this->numSpatialStreams);
    doParsimPacking(b,this->aggregationPresent);
    doParsimPacking(b,this->permittedAggregation);
    doParsimPacking(b,this->repetitionPresent);
    doParsimPacking(b,this->numRepetitions);
    doParsimPacking(b,this->expiryPresent);
    doParsimPacking(b,this->expiryTime);
    doParsimPacking(b,this->channelPresent);
    doParsimPacking(b,this->channelNumber);
    doParsimPacking(b,this->primaryChannelPresent);
    doParsimPacking(b,this->primaryChannelNumber);
    doParsimPacking(b,this->channelWidthPresent);
    doParsimPacking(b,this->channelWidthMHz);
}

void NgvRadioEnvironmentReqTag::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TagBase::parsimUnpack(b);
    doParsimUnpacking(b,this->ppduFormatPresent);
    doParsimUnpacking(b,this->ppduFormat);
    doParsimUnpacking(b,this->mcsPresent);
    doParsimUnpacking(b,this->ngvMcs);
    doParsimUnpacking(b,this->dataRateMbps);
    doParsimUnpacking(b,this->nssPresent);
    doParsimUnpacking(b,this->numSpatialStreams);
    doParsimUnpacking(b,this->aggregationPresent);
    doParsimUnpacking(b,this->permittedAggregation);
    doParsimUnpacking(b,this->repetitionPresent);
    doParsimUnpacking(b,this->numRepetitions);
    doParsimUnpacking(b,this->expiryPresent);
    doParsimUnpacking(b,this->expiryTime);
    doParsimUnpacking(b,this->channelPresent);
    doParsimUnpacking(b,this->channelNumber);
    doParsimUnpacking(b,this->primaryChannelPresent);
    doParsimUnpacking(b,this->primaryChannelNumber);
    doParsimUnpacking(b,this->channelWidthPresent);
    doParsimUnpacking(b,this->channelWidthMHz);
}

bool NgvRadioEnvironmentReqTag::getPpduFormatPresent() const
{
    return this->ppduFormatPresent;
}

void NgvRadioEnvironmentReqTag::setPpduFormatPresent(bool ppduFormatPresent)
{
    this->ppduFormatPresent = ppduFormatPresent;
}

int NgvRadioEnvironmentReqTag::getPpduFormat() const
{
    return this->ppduFormat;
}

void NgvRadioEnvironmentReqTag::setPpduFormat(int ppduFormat)
{
    this->ppduFormat = ppduFormat;
}

bool NgvRadioEnvironmentReqTag::getMcsPresent() const
{
    return this->mcsPresent;
}

void NgvRadioEnvironmentReqTag::setMcsPresent(bool mcsPresent)
{
    this->mcsPresent = mcsPresent;
}

int NgvRadioEnvironmentReqTag::getNgvMcs() const
{
    return this->ngvMcs;
}

void NgvRadioEnvironmentReqTag::setNgvMcs(int ngvMcs)
{
    this->ngvMcs = ngvMcs;
}

double NgvRadioEnvironmentReqTag::getDataRateMbps() const
{
    return this->dataRateMbps;
}

void NgvRadioEnvironmentReqTag::setDataRateMbps(double dataRateMbps)
{
    this->dataRateMbps = dataRateMbps;
}

bool NgvRadioEnvironmentReqTag::getNssPresent() const
{
    return this->nssPresent;
}

void NgvRadioEnvironmentReqTag::setNssPresent(bool nssPresent)
{
    this->nssPresent = nssPresent;
}

int NgvRadioEnvironmentReqTag::getNumSpatialStreams() const
{
    return this->numSpatialStreams;
}

void NgvRadioEnvironmentReqTag::setNumSpatialStreams(int numSpatialStreams)
{
    this->numSpatialStreams = numSpatialStreams;
}

bool NgvRadioEnvironmentReqTag::getAggregationPresent() const
{
    return this->aggregationPresent;
}

void NgvRadioEnvironmentReqTag::setAggregationPresent(bool aggregationPresent)
{
    this->aggregationPresent = aggregationPresent;
}

bool NgvRadioEnvironmentReqTag::getPermittedAggregation() const
{
    return this->permittedAggregation;
}

void NgvRadioEnvironmentReqTag::setPermittedAggregation(bool permittedAggregation)
{
    this->permittedAggregation = permittedAggregation;
}

bool NgvRadioEnvironmentReqTag::getRepetitionPresent() const
{
    return this->repetitionPresent;
}

void NgvRadioEnvironmentReqTag::setRepetitionPresent(bool repetitionPresent)
{
    this->repetitionPresent = repetitionPresent;
}

int NgvRadioEnvironmentReqTag::getNumRepetitions() const
{
    return this->numRepetitions;
}

void NgvRadioEnvironmentReqTag::setNumRepetitions(int numRepetitions)
{
    this->numRepetitions = numRepetitions;
}

bool NgvRadioEnvironmentReqTag::getExpiryPresent() const
{
    return this->expiryPresent;
}

void NgvRadioEnvironmentReqTag::setExpiryPresent(bool expiryPresent)
{
    this->expiryPresent = expiryPresent;
}

double NgvRadioEnvironmentReqTag::getExpiryTime() const
{
    return this->expiryTime;
}

void NgvRadioEnvironmentReqTag::setExpiryTime(double expiryTime)
{
    this->expiryTime = expiryTime;
}

bool NgvRadioEnvironmentReqTag::getChannelPresent() const
{
    return this->channelPresent;
}

void NgvRadioEnvironmentReqTag::setChannelPresent(bool channelPresent)
{
    this->channelPresent = channelPresent;
}

int NgvRadioEnvironmentReqTag::getChannelNumber() const
{
    return this->channelNumber;
}

void NgvRadioEnvironmentReqTag::setChannelNumber(int channelNumber)
{
    this->channelNumber = channelNumber;
}

bool NgvRadioEnvironmentReqTag::getPrimaryChannelPresent() const
{
    return this->primaryChannelPresent;
}

void NgvRadioEnvironmentReqTag::setPrimaryChannelPresent(bool primaryChannelPresent)
{
    this->primaryChannelPresent = primaryChannelPresent;
}

int NgvRadioEnvironmentReqTag::getPrimaryChannelNumber() const
{
    return this->primaryChannelNumber;
}

void NgvRadioEnvironmentReqTag::setPrimaryChannelNumber(int primaryChannelNumber)
{
    this->primaryChannelNumber = primaryChannelNumber;
}

bool NgvRadioEnvironmentReqTag::getChannelWidthPresent() const
{
    return this->channelWidthPresent;
}

void NgvRadioEnvironmentReqTag::setChannelWidthPresent(bool channelWidthPresent)
{
    this->channelWidthPresent = channelWidthPresent;
}

int NgvRadioEnvironmentReqTag::getChannelWidthMHz() const
{
    return this->channelWidthMHz;
}

void NgvRadioEnvironmentReqTag::setChannelWidthMHz(int channelWidthMHz)
{
    this->channelWidthMHz = channelWidthMHz;
}

class NgvRadioEnvironmentReqTagDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_ppduFormatPresent,
        FIELD_ppduFormat,
        FIELD_mcsPresent,
        FIELD_ngvMcs,
        FIELD_dataRateMbps,
        FIELD_nssPresent,
        FIELD_numSpatialStreams,
        FIELD_aggregationPresent,
        FIELD_permittedAggregation,
        FIELD_repetitionPresent,
        FIELD_numRepetitions,
        FIELD_expiryPresent,
        FIELD_expiryTime,
        FIELD_channelPresent,
        FIELD_channelNumber,
        FIELD_primaryChannelPresent,
        FIELD_primaryChannelNumber,
        FIELD_channelWidthPresent,
        FIELD_channelWidthMHz,
    };
  public:
    NgvRadioEnvironmentReqTagDescriptor();
    virtual ~NgvRadioEnvironmentReqTagDescriptor();

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

Register_ClassDescriptor(NgvRadioEnvironmentReqTagDescriptor)

NgvRadioEnvironmentReqTagDescriptor::NgvRadioEnvironmentReqTagDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::NgvRadioEnvironmentReqTag)), "inet::TagBase")
{
    propertyNames = nullptr;
}

NgvRadioEnvironmentReqTagDescriptor::~NgvRadioEnvironmentReqTagDescriptor()
{
    delete[] propertyNames;
}

bool NgvRadioEnvironmentReqTagDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NgvRadioEnvironmentReqTag *>(obj)!=nullptr;
}

const char **NgvRadioEnvironmentReqTagDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *NgvRadioEnvironmentReqTagDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int NgvRadioEnvironmentReqTagDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 19+base->getFieldCount() : 19;
}

unsigned int NgvRadioEnvironmentReqTagDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_ppduFormatPresent
        FD_ISEDITABLE,    // FIELD_ppduFormat
        FD_ISEDITABLE,    // FIELD_mcsPresent
        FD_ISEDITABLE,    // FIELD_ngvMcs
        FD_ISEDITABLE,    // FIELD_dataRateMbps
        FD_ISEDITABLE,    // FIELD_nssPresent
        FD_ISEDITABLE,    // FIELD_numSpatialStreams
        FD_ISEDITABLE,    // FIELD_aggregationPresent
        FD_ISEDITABLE,    // FIELD_permittedAggregation
        FD_ISEDITABLE,    // FIELD_repetitionPresent
        FD_ISEDITABLE,    // FIELD_numRepetitions
        FD_ISEDITABLE,    // FIELD_expiryPresent
        FD_ISEDITABLE,    // FIELD_expiryTime
        FD_ISEDITABLE,    // FIELD_channelPresent
        FD_ISEDITABLE,    // FIELD_channelNumber
        FD_ISEDITABLE,    // FIELD_primaryChannelPresent
        FD_ISEDITABLE,    // FIELD_primaryChannelNumber
        FD_ISEDITABLE,    // FIELD_channelWidthPresent
        FD_ISEDITABLE,    // FIELD_channelWidthMHz
    };
    return (field >= 0 && field < 19) ? fieldTypeFlags[field] : 0;
}

const char *NgvRadioEnvironmentReqTagDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ppduFormatPresent",
        "ppduFormat",
        "mcsPresent",
        "ngvMcs",
        "dataRateMbps",
        "nssPresent",
        "numSpatialStreams",
        "aggregationPresent",
        "permittedAggregation",
        "repetitionPresent",
        "numRepetitions",
        "expiryPresent",
        "expiryTime",
        "channelPresent",
        "channelNumber",
        "primaryChannelPresent",
        "primaryChannelNumber",
        "channelWidthPresent",
        "channelWidthMHz",
    };
    return (field >= 0 && field < 19) ? fieldNames[field] : nullptr;
}

int NgvRadioEnvironmentReqTagDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "ppduFormatPresent") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "ppduFormat") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "mcsPresent") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "ngvMcs") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "dataRateMbps") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "nssPresent") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "numSpatialStreams") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "aggregationPresent") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "permittedAggregation") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "repetitionPresent") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "numRepetitions") == 0) return baseIndex + 10;
    if (strcmp(fieldName, "expiryPresent") == 0) return baseIndex + 11;
    if (strcmp(fieldName, "expiryTime") == 0) return baseIndex + 12;
    if (strcmp(fieldName, "channelPresent") == 0) return baseIndex + 13;
    if (strcmp(fieldName, "channelNumber") == 0) return baseIndex + 14;
    if (strcmp(fieldName, "primaryChannelPresent") == 0) return baseIndex + 15;
    if (strcmp(fieldName, "primaryChannelNumber") == 0) return baseIndex + 16;
    if (strcmp(fieldName, "channelWidthPresent") == 0) return baseIndex + 17;
    if (strcmp(fieldName, "channelWidthMHz") == 0) return baseIndex + 18;
    return base ? base->findField(fieldName) : -1;
}

const char *NgvRadioEnvironmentReqTagDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_ppduFormatPresent
        "int",    // FIELD_ppduFormat
        "bool",    // FIELD_mcsPresent
        "int",    // FIELD_ngvMcs
        "double",    // FIELD_dataRateMbps
        "bool",    // FIELD_nssPresent
        "int",    // FIELD_numSpatialStreams
        "bool",    // FIELD_aggregationPresent
        "bool",    // FIELD_permittedAggregation
        "bool",    // FIELD_repetitionPresent
        "int",    // FIELD_numRepetitions
        "bool",    // FIELD_expiryPresent
        "double",    // FIELD_expiryTime
        "bool",    // FIELD_channelPresent
        "int",    // FIELD_channelNumber
        "bool",    // FIELD_primaryChannelPresent
        "int",    // FIELD_primaryChannelNumber
        "bool",    // FIELD_channelWidthPresent
        "int",    // FIELD_channelWidthMHz
    };
    return (field >= 0 && field < 19) ? fieldTypeStrings[field] : nullptr;
}

const char **NgvRadioEnvironmentReqTagDescriptor::getFieldPropertyNames(int field) const
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

const char *NgvRadioEnvironmentReqTagDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int NgvRadioEnvironmentReqTagDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    NgvRadioEnvironmentReqTag *pp = omnetpp::fromAnyPtr<NgvRadioEnvironmentReqTag>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void NgvRadioEnvironmentReqTagDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    NgvRadioEnvironmentReqTag *pp = omnetpp::fromAnyPtr<NgvRadioEnvironmentReqTag>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'NgvRadioEnvironmentReqTag'", field);
    }
}

const char *NgvRadioEnvironmentReqTagDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    NgvRadioEnvironmentReqTag *pp = omnetpp::fromAnyPtr<NgvRadioEnvironmentReqTag>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NgvRadioEnvironmentReqTagDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    NgvRadioEnvironmentReqTag *pp = omnetpp::fromAnyPtr<NgvRadioEnvironmentReqTag>(object); (void)pp;
    switch (field) {
        case FIELD_ppduFormatPresent: return bool2string(pp->getPpduFormatPresent());
        case FIELD_ppduFormat: return long2string(pp->getPpduFormat());
        case FIELD_mcsPresent: return bool2string(pp->getMcsPresent());
        case FIELD_ngvMcs: return long2string(pp->getNgvMcs());
        case FIELD_dataRateMbps: return double2string(pp->getDataRateMbps());
        case FIELD_nssPresent: return bool2string(pp->getNssPresent());
        case FIELD_numSpatialStreams: return long2string(pp->getNumSpatialStreams());
        case FIELD_aggregationPresent: return bool2string(pp->getAggregationPresent());
        case FIELD_permittedAggregation: return bool2string(pp->getPermittedAggregation());
        case FIELD_repetitionPresent: return bool2string(pp->getRepetitionPresent());
        case FIELD_numRepetitions: return long2string(pp->getNumRepetitions());
        case FIELD_expiryPresent: return bool2string(pp->getExpiryPresent());
        case FIELD_expiryTime: return double2string(pp->getExpiryTime());
        case FIELD_channelPresent: return bool2string(pp->getChannelPresent());
        case FIELD_channelNumber: return long2string(pp->getChannelNumber());
        case FIELD_primaryChannelPresent: return bool2string(pp->getPrimaryChannelPresent());
        case FIELD_primaryChannelNumber: return long2string(pp->getPrimaryChannelNumber());
        case FIELD_channelWidthPresent: return bool2string(pp->getChannelWidthPresent());
        case FIELD_channelWidthMHz: return long2string(pp->getChannelWidthMHz());
        default: return "";
    }
}

void NgvRadioEnvironmentReqTagDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    NgvRadioEnvironmentReqTag *pp = omnetpp::fromAnyPtr<NgvRadioEnvironmentReqTag>(object); (void)pp;
    switch (field) {
        case FIELD_ppduFormatPresent: pp->setPpduFormatPresent(string2bool(value)); break;
        case FIELD_ppduFormat: pp->setPpduFormat(string2long(value)); break;
        case FIELD_mcsPresent: pp->setMcsPresent(string2bool(value)); break;
        case FIELD_ngvMcs: pp->setNgvMcs(string2long(value)); break;
        case FIELD_dataRateMbps: pp->setDataRateMbps(string2double(value)); break;
        case FIELD_nssPresent: pp->setNssPresent(string2bool(value)); break;
        case FIELD_numSpatialStreams: pp->setNumSpatialStreams(string2long(value)); break;
        case FIELD_aggregationPresent: pp->setAggregationPresent(string2bool(value)); break;
        case FIELD_permittedAggregation: pp->setPermittedAggregation(string2bool(value)); break;
        case FIELD_repetitionPresent: pp->setRepetitionPresent(string2bool(value)); break;
        case FIELD_numRepetitions: pp->setNumRepetitions(string2long(value)); break;
        case FIELD_expiryPresent: pp->setExpiryPresent(string2bool(value)); break;
        case FIELD_expiryTime: pp->setExpiryTime(string2double(value)); break;
        case FIELD_channelPresent: pp->setChannelPresent(string2bool(value)); break;
        case FIELD_channelNumber: pp->setChannelNumber(string2long(value)); break;
        case FIELD_primaryChannelPresent: pp->setPrimaryChannelPresent(string2bool(value)); break;
        case FIELD_primaryChannelNumber: pp->setPrimaryChannelNumber(string2long(value)); break;
        case FIELD_channelWidthPresent: pp->setChannelWidthPresent(string2bool(value)); break;
        case FIELD_channelWidthMHz: pp->setChannelWidthMHz(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'NgvRadioEnvironmentReqTag'", field);
    }
}

omnetpp::cValue NgvRadioEnvironmentReqTagDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    NgvRadioEnvironmentReqTag *pp = omnetpp::fromAnyPtr<NgvRadioEnvironmentReqTag>(object); (void)pp;
    switch (field) {
        case FIELD_ppduFormatPresent: return pp->getPpduFormatPresent();
        case FIELD_ppduFormat: return pp->getPpduFormat();
        case FIELD_mcsPresent: return pp->getMcsPresent();
        case FIELD_ngvMcs: return pp->getNgvMcs();
        case FIELD_dataRateMbps: return pp->getDataRateMbps();
        case FIELD_nssPresent: return pp->getNssPresent();
        case FIELD_numSpatialStreams: return pp->getNumSpatialStreams();
        case FIELD_aggregationPresent: return pp->getAggregationPresent();
        case FIELD_permittedAggregation: return pp->getPermittedAggregation();
        case FIELD_repetitionPresent: return pp->getRepetitionPresent();
        case FIELD_numRepetitions: return pp->getNumRepetitions();
        case FIELD_expiryPresent: return pp->getExpiryPresent();
        case FIELD_expiryTime: return pp->getExpiryTime();
        case FIELD_channelPresent: return pp->getChannelPresent();
        case FIELD_channelNumber: return pp->getChannelNumber();
        case FIELD_primaryChannelPresent: return pp->getPrimaryChannelPresent();
        case FIELD_primaryChannelNumber: return pp->getPrimaryChannelNumber();
        case FIELD_channelWidthPresent: return pp->getChannelWidthPresent();
        case FIELD_channelWidthMHz: return pp->getChannelWidthMHz();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'NgvRadioEnvironmentReqTag' as cValue -- field index out of range?", field);
    }
}

void NgvRadioEnvironmentReqTagDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    NgvRadioEnvironmentReqTag *pp = omnetpp::fromAnyPtr<NgvRadioEnvironmentReqTag>(object); (void)pp;
    switch (field) {
        case FIELD_ppduFormatPresent: pp->setPpduFormatPresent(value.boolValue()); break;
        case FIELD_ppduFormat: pp->setPpduFormat(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_mcsPresent: pp->setMcsPresent(value.boolValue()); break;
        case FIELD_ngvMcs: pp->setNgvMcs(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_dataRateMbps: pp->setDataRateMbps(value.doubleValue()); break;
        case FIELD_nssPresent: pp->setNssPresent(value.boolValue()); break;
        case FIELD_numSpatialStreams: pp->setNumSpatialStreams(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_aggregationPresent: pp->setAggregationPresent(value.boolValue()); break;
        case FIELD_permittedAggregation: pp->setPermittedAggregation(value.boolValue()); break;
        case FIELD_repetitionPresent: pp->setRepetitionPresent(value.boolValue()); break;
        case FIELD_numRepetitions: pp->setNumRepetitions(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_expiryPresent: pp->setExpiryPresent(value.boolValue()); break;
        case FIELD_expiryTime: pp->setExpiryTime(value.doubleValue()); break;
        case FIELD_channelPresent: pp->setChannelPresent(value.boolValue()); break;
        case FIELD_channelNumber: pp->setChannelNumber(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_primaryChannelPresent: pp->setPrimaryChannelPresent(value.boolValue()); break;
        case FIELD_primaryChannelNumber: pp->setPrimaryChannelNumber(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_channelWidthPresent: pp->setChannelWidthPresent(value.boolValue()); break;
        case FIELD_channelWidthMHz: pp->setChannelWidthMHz(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'NgvRadioEnvironmentReqTag'", field);
    }
}

const char *NgvRadioEnvironmentReqTagDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr NgvRadioEnvironmentReqTagDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    NgvRadioEnvironmentReqTag *pp = omnetpp::fromAnyPtr<NgvRadioEnvironmentReqTag>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void NgvRadioEnvironmentReqTagDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    NgvRadioEnvironmentReqTag *pp = omnetpp::fromAnyPtr<NgvRadioEnvironmentReqTag>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'NgvRadioEnvironmentReqTag'", field);
    }
}

}  // namespace inet

namespace omnetpp {

}  // namespace omnetpp

