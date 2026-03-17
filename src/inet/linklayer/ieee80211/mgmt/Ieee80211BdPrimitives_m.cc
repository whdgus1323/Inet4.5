//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/linklayer/ieee80211/mgmt/Ieee80211BdPrimitives.msg.
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
#include "Ieee80211BdPrimitives_m.h"

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

Register_Class(MlmeRadioEnvironmentRequest)

MlmeRadioEnvironmentRequest::MlmeRadioEnvironmentRequest() : ::omnetpp::cObject()
{
}

MlmeRadioEnvironmentRequest::MlmeRadioEnvironmentRequest(const MlmeRadioEnvironmentRequest& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

MlmeRadioEnvironmentRequest::~MlmeRadioEnvironmentRequest()
{
}

MlmeRadioEnvironmentRequest& MlmeRadioEnvironmentRequest::operator=(const MlmeRadioEnvironmentRequest& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void MlmeRadioEnvironmentRequest::copy(const MlmeRadioEnvironmentRequest& other)
{
    this->radioEnvironmentMeasurementPeriod = other.radioEnvironmentMeasurementPeriod;
    this->stationMeasurementPeriod = other.stationMeasurementPeriod;
}

void MlmeRadioEnvironmentRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->radioEnvironmentMeasurementPeriod);
    doParsimPacking(b,this->stationMeasurementPeriod);
}

void MlmeRadioEnvironmentRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->radioEnvironmentMeasurementPeriod);
    doParsimUnpacking(b,this->stationMeasurementPeriod);
}

int MlmeRadioEnvironmentRequest::getRadioEnvironmentMeasurementPeriod() const
{
    return this->radioEnvironmentMeasurementPeriod;
}

void MlmeRadioEnvironmentRequest::setRadioEnvironmentMeasurementPeriod(int radioEnvironmentMeasurementPeriod)
{
    this->radioEnvironmentMeasurementPeriod = radioEnvironmentMeasurementPeriod;
}

int MlmeRadioEnvironmentRequest::getStationMeasurementPeriod() const
{
    return this->stationMeasurementPeriod;
}

void MlmeRadioEnvironmentRequest::setStationMeasurementPeriod(int stationMeasurementPeriod)
{
    this->stationMeasurementPeriod = stationMeasurementPeriod;
}

class MlmeRadioEnvironmentRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_radioEnvironmentMeasurementPeriod,
        FIELD_stationMeasurementPeriod,
    };
  public:
    MlmeRadioEnvironmentRequestDescriptor();
    virtual ~MlmeRadioEnvironmentRequestDescriptor();

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

Register_ClassDescriptor(MlmeRadioEnvironmentRequestDescriptor)

MlmeRadioEnvironmentRequestDescriptor::MlmeRadioEnvironmentRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::MlmeRadioEnvironmentRequest)), "omnetpp::cObject")
{
    propertyNames = nullptr;
}

MlmeRadioEnvironmentRequestDescriptor::~MlmeRadioEnvironmentRequestDescriptor()
{
    delete[] propertyNames;
}

bool MlmeRadioEnvironmentRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MlmeRadioEnvironmentRequest *>(obj)!=nullptr;
}

const char **MlmeRadioEnvironmentRequestDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MlmeRadioEnvironmentRequestDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MlmeRadioEnvironmentRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int MlmeRadioEnvironmentRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_radioEnvironmentMeasurementPeriod
        FD_ISEDITABLE,    // FIELD_stationMeasurementPeriod
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *MlmeRadioEnvironmentRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "radioEnvironmentMeasurementPeriod",
        "stationMeasurementPeriod",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int MlmeRadioEnvironmentRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "radioEnvironmentMeasurementPeriod") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "stationMeasurementPeriod") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *MlmeRadioEnvironmentRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_radioEnvironmentMeasurementPeriod
        "int",    // FIELD_stationMeasurementPeriod
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **MlmeRadioEnvironmentRequestDescriptor::getFieldPropertyNames(int field) const
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

const char *MlmeRadioEnvironmentRequestDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int MlmeRadioEnvironmentRequestDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MlmeRadioEnvironmentRequest *pp = omnetpp::fromAnyPtr<MlmeRadioEnvironmentRequest>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MlmeRadioEnvironmentRequestDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MlmeRadioEnvironmentRequest *pp = omnetpp::fromAnyPtr<MlmeRadioEnvironmentRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MlmeRadioEnvironmentRequest'", field);
    }
}

const char *MlmeRadioEnvironmentRequestDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MlmeRadioEnvironmentRequest *pp = omnetpp::fromAnyPtr<MlmeRadioEnvironmentRequest>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MlmeRadioEnvironmentRequestDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MlmeRadioEnvironmentRequest *pp = omnetpp::fromAnyPtr<MlmeRadioEnvironmentRequest>(object); (void)pp;
    switch (field) {
        case FIELD_radioEnvironmentMeasurementPeriod: return long2string(pp->getRadioEnvironmentMeasurementPeriod());
        case FIELD_stationMeasurementPeriod: return long2string(pp->getStationMeasurementPeriod());
        default: return "";
    }
}

void MlmeRadioEnvironmentRequestDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MlmeRadioEnvironmentRequest *pp = omnetpp::fromAnyPtr<MlmeRadioEnvironmentRequest>(object); (void)pp;
    switch (field) {
        case FIELD_radioEnvironmentMeasurementPeriod: pp->setRadioEnvironmentMeasurementPeriod(string2long(value)); break;
        case FIELD_stationMeasurementPeriod: pp->setStationMeasurementPeriod(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MlmeRadioEnvironmentRequest'", field);
    }
}

omnetpp::cValue MlmeRadioEnvironmentRequestDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MlmeRadioEnvironmentRequest *pp = omnetpp::fromAnyPtr<MlmeRadioEnvironmentRequest>(object); (void)pp;
    switch (field) {
        case FIELD_radioEnvironmentMeasurementPeriod: return pp->getRadioEnvironmentMeasurementPeriod();
        case FIELD_stationMeasurementPeriod: return pp->getStationMeasurementPeriod();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MlmeRadioEnvironmentRequest' as cValue -- field index out of range?", field);
    }
}

void MlmeRadioEnvironmentRequestDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MlmeRadioEnvironmentRequest *pp = omnetpp::fromAnyPtr<MlmeRadioEnvironmentRequest>(object); (void)pp;
    switch (field) {
        case FIELD_radioEnvironmentMeasurementPeriod: pp->setRadioEnvironmentMeasurementPeriod(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_stationMeasurementPeriod: pp->setStationMeasurementPeriod(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MlmeRadioEnvironmentRequest'", field);
    }
}

const char *MlmeRadioEnvironmentRequestDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr MlmeRadioEnvironmentRequestDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MlmeRadioEnvironmentRequest *pp = omnetpp::fromAnyPtr<MlmeRadioEnvironmentRequest>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MlmeRadioEnvironmentRequestDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MlmeRadioEnvironmentRequest *pp = omnetpp::fromAnyPtr<MlmeRadioEnvironmentRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MlmeRadioEnvironmentRequest'", field);
    }
}

Register_Class(MlmeRadioEnvironmentIndication)

MlmeRadioEnvironmentIndication::MlmeRadioEnvironmentIndication() : ::omnetpp::cObject()
{
}

MlmeRadioEnvironmentIndication::MlmeRadioEnvironmentIndication(const MlmeRadioEnvironmentIndication& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

MlmeRadioEnvironmentIndication::~MlmeRadioEnvironmentIndication()
{
}

MlmeRadioEnvironmentIndication& MlmeRadioEnvironmentIndication::operator=(const MlmeRadioEnvironmentIndication& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void MlmeRadioEnvironmentIndication::copy(const MlmeRadioEnvironmentIndication& other)
{
    this->stationCount = other.stationCount;
    this->ngvCapabilityPercentage = other.ngvCapabilityPercentage;
    this->channelBusyPercentage = other.channelBusyPercentage;
}

void MlmeRadioEnvironmentIndication::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->stationCount);
    doParsimPacking(b,this->ngvCapabilityPercentage);
    doParsimPacking(b,this->channelBusyPercentage);
}

void MlmeRadioEnvironmentIndication::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->stationCount);
    doParsimUnpacking(b,this->ngvCapabilityPercentage);
    doParsimUnpacking(b,this->channelBusyPercentage);
}

int MlmeRadioEnvironmentIndication::getStationCount() const
{
    return this->stationCount;
}

void MlmeRadioEnvironmentIndication::setStationCount(int stationCount)
{
    this->stationCount = stationCount;
}

int MlmeRadioEnvironmentIndication::getNgvCapabilityPercentage() const
{
    return this->ngvCapabilityPercentage;
}

void MlmeRadioEnvironmentIndication::setNgvCapabilityPercentage(int ngvCapabilityPercentage)
{
    this->ngvCapabilityPercentage = ngvCapabilityPercentage;
}

int MlmeRadioEnvironmentIndication::getChannelBusyPercentage() const
{
    return this->channelBusyPercentage;
}

void MlmeRadioEnvironmentIndication::setChannelBusyPercentage(int channelBusyPercentage)
{
    this->channelBusyPercentage = channelBusyPercentage;
}

class MlmeRadioEnvironmentIndicationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_stationCount,
        FIELD_ngvCapabilityPercentage,
        FIELD_channelBusyPercentage,
    };
  public:
    MlmeRadioEnvironmentIndicationDescriptor();
    virtual ~MlmeRadioEnvironmentIndicationDescriptor();

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

Register_ClassDescriptor(MlmeRadioEnvironmentIndicationDescriptor)

MlmeRadioEnvironmentIndicationDescriptor::MlmeRadioEnvironmentIndicationDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::MlmeRadioEnvironmentIndication)), "omnetpp::cObject")
{
    propertyNames = nullptr;
}

MlmeRadioEnvironmentIndicationDescriptor::~MlmeRadioEnvironmentIndicationDescriptor()
{
    delete[] propertyNames;
}

bool MlmeRadioEnvironmentIndicationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MlmeRadioEnvironmentIndication *>(obj)!=nullptr;
}

const char **MlmeRadioEnvironmentIndicationDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MlmeRadioEnvironmentIndicationDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MlmeRadioEnvironmentIndicationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int MlmeRadioEnvironmentIndicationDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_stationCount
        FD_ISEDITABLE,    // FIELD_ngvCapabilityPercentage
        FD_ISEDITABLE,    // FIELD_channelBusyPercentage
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *MlmeRadioEnvironmentIndicationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "stationCount",
        "ngvCapabilityPercentage",
        "channelBusyPercentage",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int MlmeRadioEnvironmentIndicationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "stationCount") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "ngvCapabilityPercentage") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "channelBusyPercentage") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *MlmeRadioEnvironmentIndicationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_stationCount
        "int",    // FIELD_ngvCapabilityPercentage
        "int",    // FIELD_channelBusyPercentage
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **MlmeRadioEnvironmentIndicationDescriptor::getFieldPropertyNames(int field) const
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

const char *MlmeRadioEnvironmentIndicationDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int MlmeRadioEnvironmentIndicationDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MlmeRadioEnvironmentIndication *pp = omnetpp::fromAnyPtr<MlmeRadioEnvironmentIndication>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MlmeRadioEnvironmentIndicationDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MlmeRadioEnvironmentIndication *pp = omnetpp::fromAnyPtr<MlmeRadioEnvironmentIndication>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MlmeRadioEnvironmentIndication'", field);
    }
}

const char *MlmeRadioEnvironmentIndicationDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MlmeRadioEnvironmentIndication *pp = omnetpp::fromAnyPtr<MlmeRadioEnvironmentIndication>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MlmeRadioEnvironmentIndicationDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MlmeRadioEnvironmentIndication *pp = omnetpp::fromAnyPtr<MlmeRadioEnvironmentIndication>(object); (void)pp;
    switch (field) {
        case FIELD_stationCount: return long2string(pp->getStationCount());
        case FIELD_ngvCapabilityPercentage: return long2string(pp->getNgvCapabilityPercentage());
        case FIELD_channelBusyPercentage: return long2string(pp->getChannelBusyPercentage());
        default: return "";
    }
}

void MlmeRadioEnvironmentIndicationDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MlmeRadioEnvironmentIndication *pp = omnetpp::fromAnyPtr<MlmeRadioEnvironmentIndication>(object); (void)pp;
    switch (field) {
        case FIELD_stationCount: pp->setStationCount(string2long(value)); break;
        case FIELD_ngvCapabilityPercentage: pp->setNgvCapabilityPercentage(string2long(value)); break;
        case FIELD_channelBusyPercentage: pp->setChannelBusyPercentage(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MlmeRadioEnvironmentIndication'", field);
    }
}

omnetpp::cValue MlmeRadioEnvironmentIndicationDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MlmeRadioEnvironmentIndication *pp = omnetpp::fromAnyPtr<MlmeRadioEnvironmentIndication>(object); (void)pp;
    switch (field) {
        case FIELD_stationCount: return pp->getStationCount();
        case FIELD_ngvCapabilityPercentage: return pp->getNgvCapabilityPercentage();
        case FIELD_channelBusyPercentage: return pp->getChannelBusyPercentage();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MlmeRadioEnvironmentIndication' as cValue -- field index out of range?", field);
    }
}

void MlmeRadioEnvironmentIndicationDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MlmeRadioEnvironmentIndication *pp = omnetpp::fromAnyPtr<MlmeRadioEnvironmentIndication>(object); (void)pp;
    switch (field) {
        case FIELD_stationCount: pp->setStationCount(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_ngvCapabilityPercentage: pp->setNgvCapabilityPercentage(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_channelBusyPercentage: pp->setChannelBusyPercentage(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MlmeRadioEnvironmentIndication'", field);
    }
}

const char *MlmeRadioEnvironmentIndicationDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr MlmeRadioEnvironmentIndicationDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MlmeRadioEnvironmentIndication *pp = omnetpp::fromAnyPtr<MlmeRadioEnvironmentIndication>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MlmeRadioEnvironmentIndicationDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MlmeRadioEnvironmentIndication *pp = omnetpp::fromAnyPtr<MlmeRadioEnvironmentIndication>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MlmeRadioEnvironmentIndication'", field);
    }
}

Register_Enum(inet::ieee80211::NgvPpduFormat, (inet::ieee80211::NgvPpduFormat::NON_NGV_10, inet::ieee80211::NgvPpduFormat::NGV));

Register_Class(NgvRadioEnvironmentRequestVector)

NgvRadioEnvironmentRequestVector::NgvRadioEnvironmentRequestVector() : ::omnetpp::cObject()
{
}

NgvRadioEnvironmentRequestVector::NgvRadioEnvironmentRequestVector(const NgvRadioEnvironmentRequestVector& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

NgvRadioEnvironmentRequestVector::~NgvRadioEnvironmentRequestVector()
{
}

NgvRadioEnvironmentRequestVector& NgvRadioEnvironmentRequestVector::operator=(const NgvRadioEnvironmentRequestVector& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void NgvRadioEnvironmentRequestVector::copy(const NgvRadioEnvironmentRequestVector& other)
{
    this->ppduFormat = other.ppduFormat;
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

void NgvRadioEnvironmentRequestVector::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->ppduFormat);
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

void NgvRadioEnvironmentRequestVector::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->ppduFormat);
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

NgvPpduFormat NgvRadioEnvironmentRequestVector::getPpduFormat() const
{
    return this->ppduFormat;
}

void NgvRadioEnvironmentRequestVector::setPpduFormat(NgvPpduFormat ppduFormat)
{
    this->ppduFormat = ppduFormat;
}

int NgvRadioEnvironmentRequestVector::getNgvMcs() const
{
    return this->ngvMcs;
}

void NgvRadioEnvironmentRequestVector::setNgvMcs(int ngvMcs)
{
    this->ngvMcs = ngvMcs;
}

int NgvRadioEnvironmentRequestVector::getNumSpatialStreams() const
{
    return this->numSpatialStreams;
}

void NgvRadioEnvironmentRequestVector::setNumSpatialStreams(int numSpatialStreams)
{
    this->numSpatialStreams = numSpatialStreams;
}

bool NgvRadioEnvironmentRequestVector::getPermittedAggregation() const
{
    return this->permittedAggregation;
}

void NgvRadioEnvironmentRequestVector::setPermittedAggregation(bool permittedAggregation)
{
    this->permittedAggregation = permittedAggregation;
}

int NgvRadioEnvironmentRequestVector::getNumRepetitions() const
{
    return this->numRepetitions;
}

void NgvRadioEnvironmentRequestVector::setNumRepetitions(int numRepetitions)
{
    this->numRepetitions = numRepetitions;
}

::omnetpp::simtime_t NgvRadioEnvironmentRequestVector::getExpiryTime() const
{
    return this->expiryTime;
}

void NgvRadioEnvironmentRequestVector::setExpiryTime(::omnetpp::simtime_t expiryTime)
{
    this->expiryTime = expiryTime;
}

int NgvRadioEnvironmentRequestVector::getChannelNumber() const
{
    return this->channelNumber;
}

void NgvRadioEnvironmentRequestVector::setChannelNumber(int channelNumber)
{
    this->channelNumber = channelNumber;
}

int NgvRadioEnvironmentRequestVector::getPrimaryChannelNumber() const
{
    return this->primaryChannelNumber;
}

void NgvRadioEnvironmentRequestVector::setPrimaryChannelNumber(int primaryChannelNumber)
{
    this->primaryChannelNumber = primaryChannelNumber;
}

int NgvRadioEnvironmentRequestVector::getChannelWidth() const
{
    return this->channelWidth;
}

void NgvRadioEnvironmentRequestVector::setChannelWidth(int channelWidth)
{
    this->channelWidth = channelWidth;
}

double NgvRadioEnvironmentRequestVector::getTxPowerSpectralDensity() const
{
    return this->txPowerSpectralDensity;
}

void NgvRadioEnvironmentRequestVector::setTxPowerSpectralDensity(double txPowerSpectralDensity)
{
    this->txPowerSpectralDensity = txPowerSpectralDensity;
}

class NgvRadioEnvironmentRequestVectorDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_ppduFormat,
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
    NgvRadioEnvironmentRequestVectorDescriptor();
    virtual ~NgvRadioEnvironmentRequestVectorDescriptor();

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

Register_ClassDescriptor(NgvRadioEnvironmentRequestVectorDescriptor)

NgvRadioEnvironmentRequestVectorDescriptor::NgvRadioEnvironmentRequestVectorDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::NgvRadioEnvironmentRequestVector)), "omnetpp::cObject")
{
    propertyNames = nullptr;
}

NgvRadioEnvironmentRequestVectorDescriptor::~NgvRadioEnvironmentRequestVectorDescriptor()
{
    delete[] propertyNames;
}

bool NgvRadioEnvironmentRequestVectorDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NgvRadioEnvironmentRequestVector *>(obj)!=nullptr;
}

const char **NgvRadioEnvironmentRequestVectorDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *NgvRadioEnvironmentRequestVectorDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int NgvRadioEnvironmentRequestVectorDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 10+base->getFieldCount() : 10;
}

unsigned int NgvRadioEnvironmentRequestVectorDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_ppduFormat
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
    return (field >= 0 && field < 10) ? fieldTypeFlags[field] : 0;
}

const char *NgvRadioEnvironmentRequestVectorDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ppduFormat",
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
    return (field >= 0 && field < 10) ? fieldNames[field] : nullptr;
}

int NgvRadioEnvironmentRequestVectorDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "ppduFormat") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "ngvMcs") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "numSpatialStreams") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "permittedAggregation") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "numRepetitions") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "expiryTime") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "channelNumber") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "primaryChannelNumber") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "channelWidth") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "txPowerSpectralDensity") == 0) return baseIndex + 9;
    return base ? base->findField(fieldName) : -1;
}

const char *NgvRadioEnvironmentRequestVectorDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::ieee80211::NgvPpduFormat",    // FIELD_ppduFormat
        "int",    // FIELD_ngvMcs
        "int",    // FIELD_numSpatialStreams
        "bool",    // FIELD_permittedAggregation
        "int",    // FIELD_numRepetitions
        "omnetpp::simtime_t",    // FIELD_expiryTime
        "int",    // FIELD_channelNumber
        "int",    // FIELD_primaryChannelNumber
        "int",    // FIELD_channelWidth
        "double",    // FIELD_txPowerSpectralDensity
    };
    return (field >= 0 && field < 10) ? fieldTypeStrings[field] : nullptr;
}

const char **NgvRadioEnvironmentRequestVectorDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_ppduFormat: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *NgvRadioEnvironmentRequestVectorDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_ppduFormat:
            if (!strcmp(propertyName, "enum")) return "inet::ieee80211::NgvPpduFormat";
            return nullptr;
        default: return nullptr;
    }
}

int NgvRadioEnvironmentRequestVectorDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    NgvRadioEnvironmentRequestVector *pp = omnetpp::fromAnyPtr<NgvRadioEnvironmentRequestVector>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void NgvRadioEnvironmentRequestVectorDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    NgvRadioEnvironmentRequestVector *pp = omnetpp::fromAnyPtr<NgvRadioEnvironmentRequestVector>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'NgvRadioEnvironmentRequestVector'", field);
    }
}

const char *NgvRadioEnvironmentRequestVectorDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    NgvRadioEnvironmentRequestVector *pp = omnetpp::fromAnyPtr<NgvRadioEnvironmentRequestVector>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NgvRadioEnvironmentRequestVectorDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    NgvRadioEnvironmentRequestVector *pp = omnetpp::fromAnyPtr<NgvRadioEnvironmentRequestVector>(object); (void)pp;
    switch (field) {
        case FIELD_ppduFormat: return enum2string(pp->getPpduFormat(), "inet::ieee80211::NgvPpduFormat");
        case FIELD_ngvMcs: return long2string(pp->getNgvMcs());
        case FIELD_numSpatialStreams: return long2string(pp->getNumSpatialStreams());
        case FIELD_permittedAggregation: return bool2string(pp->getPermittedAggregation());
        case FIELD_numRepetitions: return long2string(pp->getNumRepetitions());
        case FIELD_expiryTime: return simtime2string(pp->getExpiryTime());
        case FIELD_channelNumber: return long2string(pp->getChannelNumber());
        case FIELD_primaryChannelNumber: return long2string(pp->getPrimaryChannelNumber());
        case FIELD_channelWidth: return long2string(pp->getChannelWidth());
        case FIELD_txPowerSpectralDensity: return double2string(pp->getTxPowerSpectralDensity());
        default: return "";
    }
}

void NgvRadioEnvironmentRequestVectorDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    NgvRadioEnvironmentRequestVector *pp = omnetpp::fromAnyPtr<NgvRadioEnvironmentRequestVector>(object); (void)pp;
    switch (field) {
        case FIELD_ngvMcs: pp->setNgvMcs(string2long(value)); break;
        case FIELD_numSpatialStreams: pp->setNumSpatialStreams(string2long(value)); break;
        case FIELD_permittedAggregation: pp->setPermittedAggregation(string2bool(value)); break;
        case FIELD_numRepetitions: pp->setNumRepetitions(string2long(value)); break;
        case FIELD_expiryTime: pp->setExpiryTime(string2simtime(value)); break;
        case FIELD_channelNumber: pp->setChannelNumber(string2long(value)); break;
        case FIELD_primaryChannelNumber: pp->setPrimaryChannelNumber(string2long(value)); break;
        case FIELD_channelWidth: pp->setChannelWidth(string2long(value)); break;
        case FIELD_txPowerSpectralDensity: pp->setTxPowerSpectralDensity(string2double(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'NgvRadioEnvironmentRequestVector'", field);
    }
}

omnetpp::cValue NgvRadioEnvironmentRequestVectorDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    NgvRadioEnvironmentRequestVector *pp = omnetpp::fromAnyPtr<NgvRadioEnvironmentRequestVector>(object); (void)pp;
    switch (field) {
        case FIELD_ppduFormat: return static_cast<int>(pp->getPpduFormat());
        case FIELD_ngvMcs: return pp->getNgvMcs();
        case FIELD_numSpatialStreams: return pp->getNumSpatialStreams();
        case FIELD_permittedAggregation: return pp->getPermittedAggregation();
        case FIELD_numRepetitions: return pp->getNumRepetitions();
        case FIELD_expiryTime: return pp->getExpiryTime().dbl();
        case FIELD_channelNumber: return pp->getChannelNumber();
        case FIELD_primaryChannelNumber: return pp->getPrimaryChannelNumber();
        case FIELD_channelWidth: return pp->getChannelWidth();
        case FIELD_txPowerSpectralDensity: return pp->getTxPowerSpectralDensity();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'NgvRadioEnvironmentRequestVector' as cValue -- field index out of range?", field);
    }
}

void NgvRadioEnvironmentRequestVectorDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    NgvRadioEnvironmentRequestVector *pp = omnetpp::fromAnyPtr<NgvRadioEnvironmentRequestVector>(object); (void)pp;
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
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'NgvRadioEnvironmentRequestVector'", field);
    }
}

const char *NgvRadioEnvironmentRequestVectorDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr NgvRadioEnvironmentRequestVectorDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    NgvRadioEnvironmentRequestVector *pp = omnetpp::fromAnyPtr<NgvRadioEnvironmentRequestVector>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void NgvRadioEnvironmentRequestVectorDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    NgvRadioEnvironmentRequestVector *pp = omnetpp::fromAnyPtr<NgvRadioEnvironmentRequestVector>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'NgvRadioEnvironmentRequestVector'", field);
    }
}

Register_Class(MaUnitdataRequest)

MaUnitdataRequest::MaUnitdataRequest() : ::omnetpp::cObject()
{
}

MaUnitdataRequest::MaUnitdataRequest(const MaUnitdataRequest& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

MaUnitdataRequest::~MaUnitdataRequest()
{
}

MaUnitdataRequest& MaUnitdataRequest::operator=(const MaUnitdataRequest& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void MaUnitdataRequest::copy(const MaUnitdataRequest& other)
{
    this->receiverAddress = other.receiverAddress;
    this->msduId = other.msduId;
    this->radioEnvRequestVector = other.radioEnvRequestVector;
}

void MaUnitdataRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->receiverAddress);
    doParsimPacking(b,this->msduId);
    doParsimPacking(b,this->radioEnvRequestVector);
}

void MaUnitdataRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->receiverAddress);
    doParsimUnpacking(b,this->msduId);
    doParsimUnpacking(b,this->radioEnvRequestVector);
}

const ::inet::MacAddress& MaUnitdataRequest::getReceiverAddress() const
{
    return this->receiverAddress;
}

void MaUnitdataRequest::setReceiverAddress(const ::inet::MacAddress& receiverAddress)
{
    this->receiverAddress = receiverAddress;
}

const char * MaUnitdataRequest::getMsduId() const
{
    return this->msduId.c_str();
}

void MaUnitdataRequest::setMsduId(const char * msduId)
{
    this->msduId = msduId;
}

const NgvRadioEnvironmentRequestVector& MaUnitdataRequest::getRadioEnvRequestVector() const
{
    return this->radioEnvRequestVector;
}

void MaUnitdataRequest::setRadioEnvRequestVector(const NgvRadioEnvironmentRequestVector& radioEnvRequestVector)
{
    this->radioEnvRequestVector = radioEnvRequestVector;
}

class MaUnitdataRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_receiverAddress,
        FIELD_msduId,
        FIELD_radioEnvRequestVector,
    };
  public:
    MaUnitdataRequestDescriptor();
    virtual ~MaUnitdataRequestDescriptor();

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

Register_ClassDescriptor(MaUnitdataRequestDescriptor)

MaUnitdataRequestDescriptor::MaUnitdataRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::MaUnitdataRequest)), "omnetpp::cObject")
{
    propertyNames = nullptr;
}

MaUnitdataRequestDescriptor::~MaUnitdataRequestDescriptor()
{
    delete[] propertyNames;
}

bool MaUnitdataRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MaUnitdataRequest *>(obj)!=nullptr;
}

const char **MaUnitdataRequestDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MaUnitdataRequestDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MaUnitdataRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int MaUnitdataRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_receiverAddress
        FD_ISEDITABLE,    // FIELD_msduId
        FD_ISCOMPOUND | FD_ISCOBJECT,    // FIELD_radioEnvRequestVector
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *MaUnitdataRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "receiverAddress",
        "msduId",
        "radioEnvRequestVector",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int MaUnitdataRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "receiverAddress") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "msduId") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "radioEnvRequestVector") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *MaUnitdataRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::MacAddress",    // FIELD_receiverAddress
        "string",    // FIELD_msduId
        "inet::ieee80211::NgvRadioEnvironmentRequestVector",    // FIELD_radioEnvRequestVector
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **MaUnitdataRequestDescriptor::getFieldPropertyNames(int field) const
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

const char *MaUnitdataRequestDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int MaUnitdataRequestDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MaUnitdataRequest *pp = omnetpp::fromAnyPtr<MaUnitdataRequest>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MaUnitdataRequestDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MaUnitdataRequest *pp = omnetpp::fromAnyPtr<MaUnitdataRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MaUnitdataRequest'", field);
    }
}

const char *MaUnitdataRequestDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MaUnitdataRequest *pp = omnetpp::fromAnyPtr<MaUnitdataRequest>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MaUnitdataRequestDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MaUnitdataRequest *pp = omnetpp::fromAnyPtr<MaUnitdataRequest>(object); (void)pp;
    switch (field) {
        case FIELD_receiverAddress: return pp->getReceiverAddress().str();
        case FIELD_msduId: return oppstring2string(pp->getMsduId());
        case FIELD_radioEnvRequestVector: return pp->getRadioEnvRequestVector().str();
        default: return "";
    }
}

void MaUnitdataRequestDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MaUnitdataRequest *pp = omnetpp::fromAnyPtr<MaUnitdataRequest>(object); (void)pp;
    switch (field) {
        case FIELD_msduId: pp->setMsduId((value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MaUnitdataRequest'", field);
    }
}

omnetpp::cValue MaUnitdataRequestDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MaUnitdataRequest *pp = omnetpp::fromAnyPtr<MaUnitdataRequest>(object); (void)pp;
    switch (field) {
        case FIELD_receiverAddress: return omnetpp::toAnyPtr(&pp->getReceiverAddress()); break;
        case FIELD_msduId: return pp->getMsduId();
        case FIELD_radioEnvRequestVector: return omnetpp::toAnyPtr(&pp->getRadioEnvRequestVector()); break;
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MaUnitdataRequest' as cValue -- field index out of range?", field);
    }
}

void MaUnitdataRequestDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MaUnitdataRequest *pp = omnetpp::fromAnyPtr<MaUnitdataRequest>(object); (void)pp;
    switch (field) {
        case FIELD_msduId: pp->setMsduId(value.stringValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MaUnitdataRequest'", field);
    }
}

const char *MaUnitdataRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_radioEnvRequestVector: return omnetpp::opp_typename(typeid(NgvRadioEnvironmentRequestVector));
        default: return nullptr;
    };
}

omnetpp::any_ptr MaUnitdataRequestDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MaUnitdataRequest *pp = omnetpp::fromAnyPtr<MaUnitdataRequest>(object); (void)pp;
    switch (field) {
        case FIELD_receiverAddress: return omnetpp::toAnyPtr(&pp->getReceiverAddress()); break;
        case FIELD_radioEnvRequestVector: return omnetpp::toAnyPtr(&pp->getRadioEnvRequestVector()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MaUnitdataRequestDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MaUnitdataRequest *pp = omnetpp::fromAnyPtr<MaUnitdataRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MaUnitdataRequest'", field);
    }
}

Register_Class(MaUnitdataIndication)

MaUnitdataIndication::MaUnitdataIndication() : ::omnetpp::cObject()
{
}

MaUnitdataIndication::MaUnitdataIndication(const MaUnitdataIndication& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

MaUnitdataIndication::~MaUnitdataIndication()
{
}

MaUnitdataIndication& MaUnitdataIndication::operator=(const MaUnitdataIndication& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void MaUnitdataIndication::copy(const MaUnitdataIndication& other)
{
    this->transmitterAddress = other.transmitterAddress;
    this->msduId = other.msduId;
    this->channelBusyPercentage = other.channelBusyPercentage;
}

void MaUnitdataIndication::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->transmitterAddress);
    doParsimPacking(b,this->msduId);
    doParsimPacking(b,this->channelBusyPercentage);
}

void MaUnitdataIndication::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->transmitterAddress);
    doParsimUnpacking(b,this->msduId);
    doParsimUnpacking(b,this->channelBusyPercentage);
}

const ::inet::MacAddress& MaUnitdataIndication::getTransmitterAddress() const
{
    return this->transmitterAddress;
}

void MaUnitdataIndication::setTransmitterAddress(const ::inet::MacAddress& transmitterAddress)
{
    this->transmitterAddress = transmitterAddress;
}

const char * MaUnitdataIndication::getMsduId() const
{
    return this->msduId.c_str();
}

void MaUnitdataIndication::setMsduId(const char * msduId)
{
    this->msduId = msduId;
}

int MaUnitdataIndication::getChannelBusyPercentage() const
{
    return this->channelBusyPercentage;
}

void MaUnitdataIndication::setChannelBusyPercentage(int channelBusyPercentage)
{
    this->channelBusyPercentage = channelBusyPercentage;
}

class MaUnitdataIndicationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_transmitterAddress,
        FIELD_msduId,
        FIELD_channelBusyPercentage,
    };
  public:
    MaUnitdataIndicationDescriptor();
    virtual ~MaUnitdataIndicationDescriptor();

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

Register_ClassDescriptor(MaUnitdataIndicationDescriptor)

MaUnitdataIndicationDescriptor::MaUnitdataIndicationDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::MaUnitdataIndication)), "omnetpp::cObject")
{
    propertyNames = nullptr;
}

MaUnitdataIndicationDescriptor::~MaUnitdataIndicationDescriptor()
{
    delete[] propertyNames;
}

bool MaUnitdataIndicationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MaUnitdataIndication *>(obj)!=nullptr;
}

const char **MaUnitdataIndicationDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MaUnitdataIndicationDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MaUnitdataIndicationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int MaUnitdataIndicationDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_transmitterAddress
        FD_ISEDITABLE,    // FIELD_msduId
        FD_ISEDITABLE,    // FIELD_channelBusyPercentage
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *MaUnitdataIndicationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "transmitterAddress",
        "msduId",
        "channelBusyPercentage",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int MaUnitdataIndicationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "transmitterAddress") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "msduId") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "channelBusyPercentage") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *MaUnitdataIndicationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::MacAddress",    // FIELD_transmitterAddress
        "string",    // FIELD_msduId
        "int",    // FIELD_channelBusyPercentage
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **MaUnitdataIndicationDescriptor::getFieldPropertyNames(int field) const
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

const char *MaUnitdataIndicationDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int MaUnitdataIndicationDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MaUnitdataIndication *pp = omnetpp::fromAnyPtr<MaUnitdataIndication>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MaUnitdataIndicationDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MaUnitdataIndication *pp = omnetpp::fromAnyPtr<MaUnitdataIndication>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MaUnitdataIndication'", field);
    }
}

const char *MaUnitdataIndicationDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MaUnitdataIndication *pp = omnetpp::fromAnyPtr<MaUnitdataIndication>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MaUnitdataIndicationDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MaUnitdataIndication *pp = omnetpp::fromAnyPtr<MaUnitdataIndication>(object); (void)pp;
    switch (field) {
        case FIELD_transmitterAddress: return pp->getTransmitterAddress().str();
        case FIELD_msduId: return oppstring2string(pp->getMsduId());
        case FIELD_channelBusyPercentage: return long2string(pp->getChannelBusyPercentage());
        default: return "";
    }
}

void MaUnitdataIndicationDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MaUnitdataIndication *pp = omnetpp::fromAnyPtr<MaUnitdataIndication>(object); (void)pp;
    switch (field) {
        case FIELD_msduId: pp->setMsduId((value)); break;
        case FIELD_channelBusyPercentage: pp->setChannelBusyPercentage(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MaUnitdataIndication'", field);
    }
}

omnetpp::cValue MaUnitdataIndicationDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MaUnitdataIndication *pp = omnetpp::fromAnyPtr<MaUnitdataIndication>(object); (void)pp;
    switch (field) {
        case FIELD_transmitterAddress: return omnetpp::toAnyPtr(&pp->getTransmitterAddress()); break;
        case FIELD_msduId: return pp->getMsduId();
        case FIELD_channelBusyPercentage: return pp->getChannelBusyPercentage();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MaUnitdataIndication' as cValue -- field index out of range?", field);
    }
}

void MaUnitdataIndicationDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MaUnitdataIndication *pp = omnetpp::fromAnyPtr<MaUnitdataIndication>(object); (void)pp;
    switch (field) {
        case FIELD_msduId: pp->setMsduId(value.stringValue()); break;
        case FIELD_channelBusyPercentage: pp->setChannelBusyPercentage(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MaUnitdataIndication'", field);
    }
}

const char *MaUnitdataIndicationDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr MaUnitdataIndicationDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MaUnitdataIndication *pp = omnetpp::fromAnyPtr<MaUnitdataIndication>(object); (void)pp;
    switch (field) {
        case FIELD_transmitterAddress: return omnetpp::toAnyPtr(&pp->getTransmitterAddress()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MaUnitdataIndicationDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MaUnitdataIndication *pp = omnetpp::fromAnyPtr<MaUnitdataIndication>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MaUnitdataIndication'", field);
    }
}

Register_Class(MaUnitdataStatusIndication)

MaUnitdataStatusIndication::MaUnitdataStatusIndication() : ::omnetpp::cObject()
{
}

MaUnitdataStatusIndication::MaUnitdataStatusIndication(const MaUnitdataStatusIndication& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

MaUnitdataStatusIndication::~MaUnitdataStatusIndication()
{
}

MaUnitdataStatusIndication& MaUnitdataStatusIndication::operator=(const MaUnitdataStatusIndication& other)
{
    if (this == &other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void MaUnitdataStatusIndication::copy(const MaUnitdataStatusIndication& other)
{
    this->msduId = other.msduId;
    this->success = other.success;
}

void MaUnitdataStatusIndication::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->msduId);
    doParsimPacking(b,this->success);
}

void MaUnitdataStatusIndication::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->msduId);
    doParsimUnpacking(b,this->success);
}

const char * MaUnitdataStatusIndication::getMsduId() const
{
    return this->msduId.c_str();
}

void MaUnitdataStatusIndication::setMsduId(const char * msduId)
{
    this->msduId = msduId;
}

bool MaUnitdataStatusIndication::getSuccess() const
{
    return this->success;
}

void MaUnitdataStatusIndication::setSuccess(bool success)
{
    this->success = success;
}

class MaUnitdataStatusIndicationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_msduId,
        FIELD_success,
    };
  public:
    MaUnitdataStatusIndicationDescriptor();
    virtual ~MaUnitdataStatusIndicationDescriptor();

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

Register_ClassDescriptor(MaUnitdataStatusIndicationDescriptor)

MaUnitdataStatusIndicationDescriptor::MaUnitdataStatusIndicationDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ieee80211::MaUnitdataStatusIndication)), "omnetpp::cObject")
{
    propertyNames = nullptr;
}

MaUnitdataStatusIndicationDescriptor::~MaUnitdataStatusIndicationDescriptor()
{
    delete[] propertyNames;
}

bool MaUnitdataStatusIndicationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MaUnitdataStatusIndication *>(obj)!=nullptr;
}

const char **MaUnitdataStatusIndicationDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MaUnitdataStatusIndicationDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MaUnitdataStatusIndicationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int MaUnitdataStatusIndicationDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_msduId
        FD_ISEDITABLE,    // FIELD_success
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *MaUnitdataStatusIndicationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "msduId",
        "success",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int MaUnitdataStatusIndicationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "msduId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "success") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *MaUnitdataStatusIndicationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_msduId
        "bool",    // FIELD_success
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **MaUnitdataStatusIndicationDescriptor::getFieldPropertyNames(int field) const
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

const char *MaUnitdataStatusIndicationDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int MaUnitdataStatusIndicationDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MaUnitdataStatusIndication *pp = omnetpp::fromAnyPtr<MaUnitdataStatusIndication>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MaUnitdataStatusIndicationDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MaUnitdataStatusIndication *pp = omnetpp::fromAnyPtr<MaUnitdataStatusIndication>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MaUnitdataStatusIndication'", field);
    }
}

const char *MaUnitdataStatusIndicationDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MaUnitdataStatusIndication *pp = omnetpp::fromAnyPtr<MaUnitdataStatusIndication>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MaUnitdataStatusIndicationDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MaUnitdataStatusIndication *pp = omnetpp::fromAnyPtr<MaUnitdataStatusIndication>(object); (void)pp;
    switch (field) {
        case FIELD_msduId: return oppstring2string(pp->getMsduId());
        case FIELD_success: return bool2string(pp->getSuccess());
        default: return "";
    }
}

void MaUnitdataStatusIndicationDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MaUnitdataStatusIndication *pp = omnetpp::fromAnyPtr<MaUnitdataStatusIndication>(object); (void)pp;
    switch (field) {
        case FIELD_msduId: pp->setMsduId((value)); break;
        case FIELD_success: pp->setSuccess(string2bool(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MaUnitdataStatusIndication'", field);
    }
}

omnetpp::cValue MaUnitdataStatusIndicationDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MaUnitdataStatusIndication *pp = omnetpp::fromAnyPtr<MaUnitdataStatusIndication>(object); (void)pp;
    switch (field) {
        case FIELD_msduId: return pp->getMsduId();
        case FIELD_success: return pp->getSuccess();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MaUnitdataStatusIndication' as cValue -- field index out of range?", field);
    }
}

void MaUnitdataStatusIndicationDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MaUnitdataStatusIndication *pp = omnetpp::fromAnyPtr<MaUnitdataStatusIndication>(object); (void)pp;
    switch (field) {
        case FIELD_msduId: pp->setMsduId(value.stringValue()); break;
        case FIELD_success: pp->setSuccess(value.boolValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MaUnitdataStatusIndication'", field);
    }
}

const char *MaUnitdataStatusIndicationDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr MaUnitdataStatusIndicationDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MaUnitdataStatusIndication *pp = omnetpp::fromAnyPtr<MaUnitdataStatusIndication>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MaUnitdataStatusIndicationDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MaUnitdataStatusIndication *pp = omnetpp::fromAnyPtr<MaUnitdataStatusIndication>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MaUnitdataStatusIndication'", field);
    }
}

}  // namespace ieee80211
}  // namespace inet

namespace omnetpp {

}  // namespace omnetpp

