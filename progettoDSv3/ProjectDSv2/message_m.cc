//
// Generated file, do not edit! Created by opp_msgtool 6.0 from message.msg.
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
#include "message_m.h"

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

Operation::Operation()
{
}

void __doPacking(omnetpp::cCommBuffer *b, const Operation& a)
{
    doParsimPacking(b,a.type);
    doParsimPacking(b,a.key);
    doParsimPacking(b,a.value);
    doParsimPacking(b,a.clientId);
    doParsimPacking(b,a.serverId);
    doParsimPacking(b,a.transId);
    doParsimPacking(b,a.ts);
}

void __doUnpacking(omnetpp::cCommBuffer *b, Operation& a)
{
    doParsimUnpacking(b,a.type);
    doParsimUnpacking(b,a.key);
    doParsimUnpacking(b,a.value);
    doParsimUnpacking(b,a.clientId);
    doParsimUnpacking(b,a.serverId);
    doParsimUnpacking(b,a.transId);
    doParsimUnpacking(b,a.ts);
}

class OperationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_type,
        FIELD_key,
        FIELD_value,
        FIELD_clientId,
        FIELD_serverId,
        FIELD_transId,
        FIELD_ts,
    };
  public:
    OperationDescriptor();
    virtual ~OperationDescriptor();

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

Register_ClassDescriptor(OperationDescriptor)

OperationDescriptor::OperationDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(Operation)), "")
{
    propertyNames = nullptr;
}

OperationDescriptor::~OperationDescriptor()
{
    delete[] propertyNames;
}

bool OperationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Operation *>(obj)!=nullptr;
}

const char **OperationDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *OperationDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int OperationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 7+base->getFieldCount() : 7;
}

unsigned int OperationDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_type
        FD_ISEDITABLE,    // FIELD_key
        FD_ISEDITABLE,    // FIELD_value
        FD_ISEDITABLE,    // FIELD_clientId
        FD_ISEDITABLE,    // FIELD_serverId
        FD_ISEDITABLE,    // FIELD_transId
        FD_ISEDITABLE,    // FIELD_ts
    };
    return (field >= 0 && field < 7) ? fieldTypeFlags[field] : 0;
}

const char *OperationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
        "key",
        "value",
        "clientId",
        "serverId",
        "transId",
        "ts",
    };
    return (field >= 0 && field < 7) ? fieldNames[field] : nullptr;
}

int OperationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "type") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "key") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "value") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "clientId") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "serverId") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "transId") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "ts") == 0) return baseIndex + 6;
    return base ? base->findField(fieldName) : -1;
}

const char *OperationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_type
        "int",    // FIELD_key
        "int",    // FIELD_value
        "int",    // FIELD_clientId
        "int",    // FIELD_serverId
        "int",    // FIELD_transId
        "omnetpp::simtime_t",    // FIELD_ts
    };
    return (field >= 0 && field < 7) ? fieldTypeStrings[field] : nullptr;
}

const char **OperationDescriptor::getFieldPropertyNames(int field) const
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

const char *OperationDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int OperationDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    Operation *pp = omnetpp::fromAnyPtr<Operation>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void OperationDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    Operation *pp = omnetpp::fromAnyPtr<Operation>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Operation'", field);
    }
}

const char *OperationDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    Operation *pp = omnetpp::fromAnyPtr<Operation>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OperationDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    Operation *pp = omnetpp::fromAnyPtr<Operation>(object); (void)pp;
    switch (field) {
        case FIELD_type: return long2string(pp->type);
        case FIELD_key: return long2string(pp->key);
        case FIELD_value: return long2string(pp->value);
        case FIELD_clientId: return long2string(pp->clientId);
        case FIELD_serverId: return long2string(pp->serverId);
        case FIELD_transId: return long2string(pp->transId);
        case FIELD_ts: return simtime2string(pp->ts);
        default: return "";
    }
}

void OperationDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Operation *pp = omnetpp::fromAnyPtr<Operation>(object); (void)pp;
    switch (field) {
        case FIELD_type: pp->type = string2long(value); break;
        case FIELD_key: pp->key = string2long(value); break;
        case FIELD_value: pp->value = string2long(value); break;
        case FIELD_clientId: pp->clientId = string2long(value); break;
        case FIELD_serverId: pp->serverId = string2long(value); break;
        case FIELD_transId: pp->transId = string2long(value); break;
        case FIELD_ts: pp->ts = string2simtime(value); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Operation'", field);
    }
}

omnetpp::cValue OperationDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    Operation *pp = omnetpp::fromAnyPtr<Operation>(object); (void)pp;
    switch (field) {
        case FIELD_type: return pp->type;
        case FIELD_key: return pp->key;
        case FIELD_value: return pp->value;
        case FIELD_clientId: return pp->clientId;
        case FIELD_serverId: return pp->serverId;
        case FIELD_transId: return pp->transId;
        case FIELD_ts: return pp->ts.dbl();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'Operation' as cValue -- field index out of range?", field);
    }
}

void OperationDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Operation *pp = omnetpp::fromAnyPtr<Operation>(object); (void)pp;
    switch (field) {
        case FIELD_type: pp->type = omnetpp::checked_int_cast<int>(value.intValue()); break;
        case FIELD_key: pp->key = omnetpp::checked_int_cast<int>(value.intValue()); break;
        case FIELD_value: pp->value = omnetpp::checked_int_cast<int>(value.intValue()); break;
        case FIELD_clientId: pp->clientId = omnetpp::checked_int_cast<int>(value.intValue()); break;
        case FIELD_serverId: pp->serverId = omnetpp::checked_int_cast<int>(value.intValue()); break;
        case FIELD_transId: pp->transId = omnetpp::checked_int_cast<int>(value.intValue()); break;
        case FIELD_ts: pp->ts = value.doubleValue(); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Operation'", field);
    }
}

const char *OperationDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr OperationDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    Operation *pp = omnetpp::fromAnyPtr<Operation>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void OperationDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    Operation *pp = omnetpp::fromAnyPtr<Operation>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Operation'", field);
    }
}

Register_Class(Transaction)

Transaction::Transaction(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

Transaction::Transaction(const Transaction& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

Transaction::~Transaction()
{
}

Transaction& Transaction::operator=(const Transaction& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void Transaction::copy(const Transaction& other)
{
    for (size_t i = 0; i < 2; i++) {
        this->operations[i] = other.operations[i];
    }
}

void Transaction::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimArrayPacking(b,this->operations,2);
}

void Transaction::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimArrayUnpacking(b,this->operations,2);
}

size_t Transaction::getOperationsArraySize() const
{
    return 2;
}

const Operation& Transaction::getOperations(size_t k) const
{
    if (k >= 2) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)2, (unsigned long)k);
    return this->operations[k];
}

void Transaction::setOperations(size_t k, const Operation& operations)
{
    if (k >= 2) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)2, (unsigned long)k);
    this->operations[k] = operations;
}

class TransactionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_operations,
    };
  public:
    TransactionDescriptor();
    virtual ~TransactionDescriptor();

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

Register_ClassDescriptor(TransactionDescriptor)

TransactionDescriptor::TransactionDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(Transaction)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

TransactionDescriptor::~TransactionDescriptor()
{
    delete[] propertyNames;
}

bool TransactionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Transaction *>(obj)!=nullptr;
}

const char **TransactionDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *TransactionDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int TransactionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int TransactionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND,    // FIELD_operations
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *TransactionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "operations",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int TransactionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "operations") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *TransactionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "Operation",    // FIELD_operations
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **TransactionDescriptor::getFieldPropertyNames(int field) const
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

const char *TransactionDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int TransactionDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    Transaction *pp = omnetpp::fromAnyPtr<Transaction>(object); (void)pp;
    switch (field) {
        case FIELD_operations: return 2;
        default: return 0;
    }
}

void TransactionDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    Transaction *pp = omnetpp::fromAnyPtr<Transaction>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Transaction'", field);
    }
}

const char *TransactionDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    Transaction *pp = omnetpp::fromAnyPtr<Transaction>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TransactionDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    Transaction *pp = omnetpp::fromAnyPtr<Transaction>(object); (void)pp;
    switch (field) {
        case FIELD_operations: return "";
        default: return "";
    }
}

void TransactionDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Transaction *pp = omnetpp::fromAnyPtr<Transaction>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Transaction'", field);
    }
}

omnetpp::cValue TransactionDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    Transaction *pp = omnetpp::fromAnyPtr<Transaction>(object); (void)pp;
    switch (field) {
        case FIELD_operations: return omnetpp::toAnyPtr(&pp->getOperations(i)); break;
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'Transaction' as cValue -- field index out of range?", field);
    }
}

void TransactionDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Transaction *pp = omnetpp::fromAnyPtr<Transaction>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Transaction'", field);
    }
}

const char *TransactionDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_operations: return omnetpp::opp_typename(typeid(Operation));
        default: return nullptr;
    };
}

omnetpp::any_ptr TransactionDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    Transaction *pp = omnetpp::fromAnyPtr<Transaction>(object); (void)pp;
    switch (field) {
        case FIELD_operations: return omnetpp::toAnyPtr(&pp->getOperations(i)); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void TransactionDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    Transaction *pp = omnetpp::fromAnyPtr<Transaction>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Transaction'", field);
    }
}

Register_Class(DoOperation)

DoOperation::DoOperation(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

DoOperation::DoOperation(const DoOperation& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

DoOperation::~DoOperation()
{
}

DoOperation& DoOperation::operator=(const DoOperation& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void DoOperation::copy(const DoOperation& other)
{
    this->op = other.op;
}

void DoOperation::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->op);
}

void DoOperation::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->op);
}

const Operation& DoOperation::getOp() const
{
    return this->op;
}

void DoOperation::setOp(const Operation& op)
{
    this->op = op;
}

class DoOperationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_op,
    };
  public:
    DoOperationDescriptor();
    virtual ~DoOperationDescriptor();

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

Register_ClassDescriptor(DoOperationDescriptor)

DoOperationDescriptor::DoOperationDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(DoOperation)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

DoOperationDescriptor::~DoOperationDescriptor()
{
    delete[] propertyNames;
}

bool DoOperationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DoOperation *>(obj)!=nullptr;
}

const char **DoOperationDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *DoOperationDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int DoOperationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int DoOperationDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,    // FIELD_op
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *DoOperationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "op",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int DoOperationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "op") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *DoOperationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "Operation",    // FIELD_op
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **DoOperationDescriptor::getFieldPropertyNames(int field) const
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

const char *DoOperationDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int DoOperationDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    DoOperation *pp = omnetpp::fromAnyPtr<DoOperation>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void DoOperationDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    DoOperation *pp = omnetpp::fromAnyPtr<DoOperation>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'DoOperation'", field);
    }
}

const char *DoOperationDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    DoOperation *pp = omnetpp::fromAnyPtr<DoOperation>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DoOperationDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    DoOperation *pp = omnetpp::fromAnyPtr<DoOperation>(object); (void)pp;
    switch (field) {
        case FIELD_op: return "";
        default: return "";
    }
}

void DoOperationDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DoOperation *pp = omnetpp::fromAnyPtr<DoOperation>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DoOperation'", field);
    }
}

omnetpp::cValue DoOperationDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    DoOperation *pp = omnetpp::fromAnyPtr<DoOperation>(object); (void)pp;
    switch (field) {
        case FIELD_op: return omnetpp::toAnyPtr(&pp->getOp()); break;
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'DoOperation' as cValue -- field index out of range?", field);
    }
}

void DoOperationDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DoOperation *pp = omnetpp::fromAnyPtr<DoOperation>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DoOperation'", field);
    }
}

const char *DoOperationDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_op: return omnetpp::opp_typename(typeid(Operation));
        default: return nullptr;
    };
}

omnetpp::any_ptr DoOperationDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    DoOperation *pp = omnetpp::fromAnyPtr<DoOperation>(object); (void)pp;
    switch (field) {
        case FIELD_op: return omnetpp::toAnyPtr(&pp->getOp()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void DoOperationDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    DoOperation *pp = omnetpp::fromAnyPtr<DoOperation>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DoOperation'", field);
    }
}

Register_Class(Ack)

Ack::Ack(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

Ack::Ack(const Ack& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

Ack::~Ack()
{
}

Ack& Ack::operator=(const Ack& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void Ack::copy(const Ack& other)
{
    this->serverId = other.serverId;
    this->ts = other.ts;
    this->clientId = other.clientId;
}

void Ack::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->serverId);
    doParsimPacking(b,this->ts);
    doParsimPacking(b,this->clientId);
}

void Ack::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->serverId);
    doParsimUnpacking(b,this->ts);
    doParsimUnpacking(b,this->clientId);
}

int Ack::getServerId() const
{
    return this->serverId;
}

void Ack::setServerId(int serverId)
{
    this->serverId = serverId;
}

omnetpp::simtime_t Ack::getTs() const
{
    return this->ts;
}

void Ack::setTs(omnetpp::simtime_t ts)
{
    this->ts = ts;
}

int Ack::getClientId() const
{
    return this->clientId;
}

void Ack::setClientId(int clientId)
{
    this->clientId = clientId;
}

class AckDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_serverId,
        FIELD_ts,
        FIELD_clientId,
    };
  public:
    AckDescriptor();
    virtual ~AckDescriptor();

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

Register_ClassDescriptor(AckDescriptor)

AckDescriptor::AckDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(Ack)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

AckDescriptor::~AckDescriptor()
{
    delete[] propertyNames;
}

bool AckDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ack *>(obj)!=nullptr;
}

const char **AckDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *AckDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int AckDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int AckDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_serverId
        FD_ISEDITABLE,    // FIELD_ts
        FD_ISEDITABLE,    // FIELD_clientId
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *AckDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "serverId",
        "ts",
        "clientId",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int AckDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "serverId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "ts") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "clientId") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *AckDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_serverId
        "omnetpp::simtime_t",    // FIELD_ts
        "int",    // FIELD_clientId
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **AckDescriptor::getFieldPropertyNames(int field) const
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

const char *AckDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int AckDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    Ack *pp = omnetpp::fromAnyPtr<Ack>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void AckDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    Ack *pp = omnetpp::fromAnyPtr<Ack>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Ack'", field);
    }
}

const char *AckDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    Ack *pp = omnetpp::fromAnyPtr<Ack>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AckDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    Ack *pp = omnetpp::fromAnyPtr<Ack>(object); (void)pp;
    switch (field) {
        case FIELD_serverId: return long2string(pp->getServerId());
        case FIELD_ts: return simtime2string(pp->getTs());
        case FIELD_clientId: return long2string(pp->getClientId());
        default: return "";
    }
}

void AckDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Ack *pp = omnetpp::fromAnyPtr<Ack>(object); (void)pp;
    switch (field) {
        case FIELD_serverId: pp->setServerId(string2long(value)); break;
        case FIELD_ts: pp->setTs(string2simtime(value)); break;
        case FIELD_clientId: pp->setClientId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ack'", field);
    }
}

omnetpp::cValue AckDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    Ack *pp = omnetpp::fromAnyPtr<Ack>(object); (void)pp;
    switch (field) {
        case FIELD_serverId: return pp->getServerId();
        case FIELD_ts: return pp->getTs().dbl();
        case FIELD_clientId: return pp->getClientId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'Ack' as cValue -- field index out of range?", field);
    }
}

void AckDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Ack *pp = omnetpp::fromAnyPtr<Ack>(object); (void)pp;
    switch (field) {
        case FIELD_serverId: pp->setServerId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_ts: pp->setTs(value.doubleValue()); break;
        case FIELD_clientId: pp->setClientId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ack'", field);
    }
}

const char *AckDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr AckDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    Ack *pp = omnetpp::fromAnyPtr<Ack>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void AckDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    Ack *pp = omnetpp::fromAnyPtr<Ack>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Ack'", field);
    }
}

Register_Class(Nack)

Nack::Nack(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

Nack::Nack(const Nack& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

Nack::~Nack()
{
}

Nack& Nack::operator=(const Nack& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void Nack::copy(const Nack& other)
{
    this->serverId = other.serverId;
    this->ts = other.ts;
    this->clientId = other.clientId;
}

void Nack::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->serverId);
    doParsimPacking(b,this->ts);
    doParsimPacking(b,this->clientId);
}

void Nack::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->serverId);
    doParsimUnpacking(b,this->ts);
    doParsimUnpacking(b,this->clientId);
}

int Nack::getServerId() const
{
    return this->serverId;
}

void Nack::setServerId(int serverId)
{
    this->serverId = serverId;
}

omnetpp::simtime_t Nack::getTs() const
{
    return this->ts;
}

void Nack::setTs(omnetpp::simtime_t ts)
{
    this->ts = ts;
}

int Nack::getClientId() const
{
    return this->clientId;
}

void Nack::setClientId(int clientId)
{
    this->clientId = clientId;
}

class NackDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_serverId,
        FIELD_ts,
        FIELD_clientId,
    };
  public:
    NackDescriptor();
    virtual ~NackDescriptor();

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

Register_ClassDescriptor(NackDescriptor)

NackDescriptor::NackDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(Nack)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

NackDescriptor::~NackDescriptor()
{
    delete[] propertyNames;
}

bool NackDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Nack *>(obj)!=nullptr;
}

const char **NackDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *NackDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int NackDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int NackDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_serverId
        FD_ISEDITABLE,    // FIELD_ts
        FD_ISEDITABLE,    // FIELD_clientId
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *NackDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "serverId",
        "ts",
        "clientId",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int NackDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "serverId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "ts") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "clientId") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *NackDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_serverId
        "omnetpp::simtime_t",    // FIELD_ts
        "int",    // FIELD_clientId
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **NackDescriptor::getFieldPropertyNames(int field) const
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

const char *NackDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int NackDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    Nack *pp = omnetpp::fromAnyPtr<Nack>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void NackDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    Nack *pp = omnetpp::fromAnyPtr<Nack>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Nack'", field);
    }
}

const char *NackDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    Nack *pp = omnetpp::fromAnyPtr<Nack>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NackDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    Nack *pp = omnetpp::fromAnyPtr<Nack>(object); (void)pp;
    switch (field) {
        case FIELD_serverId: return long2string(pp->getServerId());
        case FIELD_ts: return simtime2string(pp->getTs());
        case FIELD_clientId: return long2string(pp->getClientId());
        default: return "";
    }
}

void NackDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Nack *pp = omnetpp::fromAnyPtr<Nack>(object); (void)pp;
    switch (field) {
        case FIELD_serverId: pp->setServerId(string2long(value)); break;
        case FIELD_ts: pp->setTs(string2simtime(value)); break;
        case FIELD_clientId: pp->setClientId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Nack'", field);
    }
}

omnetpp::cValue NackDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    Nack *pp = omnetpp::fromAnyPtr<Nack>(object); (void)pp;
    switch (field) {
        case FIELD_serverId: return pp->getServerId();
        case FIELD_ts: return pp->getTs().dbl();
        case FIELD_clientId: return pp->getClientId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'Nack' as cValue -- field index out of range?", field);
    }
}

void NackDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Nack *pp = omnetpp::fromAnyPtr<Nack>(object); (void)pp;
    switch (field) {
        case FIELD_serverId: pp->setServerId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_ts: pp->setTs(value.doubleValue()); break;
        case FIELD_clientId: pp->setClientId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Nack'", field);
    }
}

const char *NackDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr NackDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    Nack *pp = omnetpp::fromAnyPtr<Nack>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void NackDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    Nack *pp = omnetpp::fromAnyPtr<Nack>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Nack'", field);
    }
}

Register_Class(Commit)

Commit::Commit(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

Commit::Commit(const Commit& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

Commit::~Commit()
{
}

Commit& Commit::operator=(const Commit& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void Commit::copy(const Commit& other)
{
    this->serverId = other.serverId;
    this->ts = other.ts;
    this->clientId = other.clientId;
}

void Commit::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->serverId);
    doParsimPacking(b,this->ts);
    doParsimPacking(b,this->clientId);
}

void Commit::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->serverId);
    doParsimUnpacking(b,this->ts);
    doParsimUnpacking(b,this->clientId);
}

int Commit::getServerId() const
{
    return this->serverId;
}

void Commit::setServerId(int serverId)
{
    this->serverId = serverId;
}

omnetpp::simtime_t Commit::getTs() const
{
    return this->ts;
}

void Commit::setTs(omnetpp::simtime_t ts)
{
    this->ts = ts;
}

int Commit::getClientId() const
{
    return this->clientId;
}

void Commit::setClientId(int clientId)
{
    this->clientId = clientId;
}

class CommitDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_serverId,
        FIELD_ts,
        FIELD_clientId,
    };
  public:
    CommitDescriptor();
    virtual ~CommitDescriptor();

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

Register_ClassDescriptor(CommitDescriptor)

CommitDescriptor::CommitDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(Commit)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

CommitDescriptor::~CommitDescriptor()
{
    delete[] propertyNames;
}

bool CommitDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Commit *>(obj)!=nullptr;
}

const char **CommitDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *CommitDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int CommitDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int CommitDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_serverId
        FD_ISEDITABLE,    // FIELD_ts
        FD_ISEDITABLE,    // FIELD_clientId
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *CommitDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "serverId",
        "ts",
        "clientId",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int CommitDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "serverId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "ts") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "clientId") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *CommitDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_serverId
        "omnetpp::simtime_t",    // FIELD_ts
        "int",    // FIELD_clientId
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **CommitDescriptor::getFieldPropertyNames(int field) const
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

const char *CommitDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int CommitDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    Commit *pp = omnetpp::fromAnyPtr<Commit>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void CommitDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    Commit *pp = omnetpp::fromAnyPtr<Commit>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Commit'", field);
    }
}

const char *CommitDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    Commit *pp = omnetpp::fromAnyPtr<Commit>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string CommitDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    Commit *pp = omnetpp::fromAnyPtr<Commit>(object); (void)pp;
    switch (field) {
        case FIELD_serverId: return long2string(pp->getServerId());
        case FIELD_ts: return simtime2string(pp->getTs());
        case FIELD_clientId: return long2string(pp->getClientId());
        default: return "";
    }
}

void CommitDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Commit *pp = omnetpp::fromAnyPtr<Commit>(object); (void)pp;
    switch (field) {
        case FIELD_serverId: pp->setServerId(string2long(value)); break;
        case FIELD_ts: pp->setTs(string2simtime(value)); break;
        case FIELD_clientId: pp->setClientId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Commit'", field);
    }
}

omnetpp::cValue CommitDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    Commit *pp = omnetpp::fromAnyPtr<Commit>(object); (void)pp;
    switch (field) {
        case FIELD_serverId: return pp->getServerId();
        case FIELD_ts: return pp->getTs().dbl();
        case FIELD_clientId: return pp->getClientId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'Commit' as cValue -- field index out of range?", field);
    }
}

void CommitDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Commit *pp = omnetpp::fromAnyPtr<Commit>(object); (void)pp;
    switch (field) {
        case FIELD_serverId: pp->setServerId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_ts: pp->setTs(value.doubleValue()); break;
        case FIELD_clientId: pp->setClientId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Commit'", field);
    }
}

const char *CommitDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr CommitDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    Commit *pp = omnetpp::fromAnyPtr<Commit>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void CommitDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    Commit *pp = omnetpp::fromAnyPtr<Commit>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Commit'", field);
    }
}

Register_Class(Abort)

Abort::Abort(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

Abort::Abort(const Abort& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

Abort::~Abort()
{
}

Abort& Abort::operator=(const Abort& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void Abort::copy(const Abort& other)
{
    this->serverId = other.serverId;
    this->ts = other.ts;
    this->clientId = other.clientId;
}

void Abort::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->serverId);
    doParsimPacking(b,this->ts);
    doParsimPacking(b,this->clientId);
}

void Abort::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->serverId);
    doParsimUnpacking(b,this->ts);
    doParsimUnpacking(b,this->clientId);
}

int Abort::getServerId() const
{
    return this->serverId;
}

void Abort::setServerId(int serverId)
{
    this->serverId = serverId;
}

omnetpp::simtime_t Abort::getTs() const
{
    return this->ts;
}

void Abort::setTs(omnetpp::simtime_t ts)
{
    this->ts = ts;
}

int Abort::getClientId() const
{
    return this->clientId;
}

void Abort::setClientId(int clientId)
{
    this->clientId = clientId;
}

class AbortDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_serverId,
        FIELD_ts,
        FIELD_clientId,
    };
  public:
    AbortDescriptor();
    virtual ~AbortDescriptor();

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

Register_ClassDescriptor(AbortDescriptor)

AbortDescriptor::AbortDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(Abort)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

AbortDescriptor::~AbortDescriptor()
{
    delete[] propertyNames;
}

bool AbortDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Abort *>(obj)!=nullptr;
}

const char **AbortDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *AbortDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int AbortDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int AbortDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_serverId
        FD_ISEDITABLE,    // FIELD_ts
        FD_ISEDITABLE,    // FIELD_clientId
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *AbortDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "serverId",
        "ts",
        "clientId",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int AbortDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "serverId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "ts") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "clientId") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *AbortDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_serverId
        "omnetpp::simtime_t",    // FIELD_ts
        "int",    // FIELD_clientId
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **AbortDescriptor::getFieldPropertyNames(int field) const
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

const char *AbortDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int AbortDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    Abort *pp = omnetpp::fromAnyPtr<Abort>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void AbortDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    Abort *pp = omnetpp::fromAnyPtr<Abort>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Abort'", field);
    }
}

const char *AbortDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    Abort *pp = omnetpp::fromAnyPtr<Abort>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AbortDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    Abort *pp = omnetpp::fromAnyPtr<Abort>(object); (void)pp;
    switch (field) {
        case FIELD_serverId: return long2string(pp->getServerId());
        case FIELD_ts: return simtime2string(pp->getTs());
        case FIELD_clientId: return long2string(pp->getClientId());
        default: return "";
    }
}

void AbortDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Abort *pp = omnetpp::fromAnyPtr<Abort>(object); (void)pp;
    switch (field) {
        case FIELD_serverId: pp->setServerId(string2long(value)); break;
        case FIELD_ts: pp->setTs(string2simtime(value)); break;
        case FIELD_clientId: pp->setClientId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Abort'", field);
    }
}

omnetpp::cValue AbortDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    Abort *pp = omnetpp::fromAnyPtr<Abort>(object); (void)pp;
    switch (field) {
        case FIELD_serverId: return pp->getServerId();
        case FIELD_ts: return pp->getTs().dbl();
        case FIELD_clientId: return pp->getClientId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'Abort' as cValue -- field index out of range?", field);
    }
}

void AbortDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Abort *pp = omnetpp::fromAnyPtr<Abort>(object); (void)pp;
    switch (field) {
        case FIELD_serverId: pp->setServerId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_ts: pp->setTs(value.doubleValue()); break;
        case FIELD_clientId: pp->setClientId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Abort'", field);
    }
}

const char *AbortDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr AbortDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    Abort *pp = omnetpp::fromAnyPtr<Abort>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void AbortDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    Abort *pp = omnetpp::fromAnyPtr<Abort>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Abort'", field);
    }
}

Register_Class(WriteVal)

WriteVal::WriteVal(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

WriteVal::WriteVal(const WriteVal& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

WriteVal::~WriteVal()
{
}

WriteVal& WriteVal::operator=(const WriteVal& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void WriteVal::copy(const WriteVal& other)
{
    this->key = other.key;
    this->value = other.value;
}

void WriteVal::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->key);
    doParsimPacking(b,this->value);
}

void WriteVal::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->key);
    doParsimUnpacking(b,this->value);
}

int WriteVal::getKey() const
{
    return this->key;
}

void WriteVal::setKey(int key)
{
    this->key = key;
}

int WriteVal::getValue() const
{
    return this->value;
}

void WriteVal::setValue(int value)
{
    this->value = value;
}

class WriteValDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_key,
        FIELD_value,
    };
  public:
    WriteValDescriptor();
    virtual ~WriteValDescriptor();

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

Register_ClassDescriptor(WriteValDescriptor)

WriteValDescriptor::WriteValDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(WriteVal)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

WriteValDescriptor::~WriteValDescriptor()
{
    delete[] propertyNames;
}

bool WriteValDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<WriteVal *>(obj)!=nullptr;
}

const char **WriteValDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *WriteValDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int WriteValDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int WriteValDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_key
        FD_ISEDITABLE,    // FIELD_value
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *WriteValDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "key",
        "value",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int WriteValDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "key") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "value") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *WriteValDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_key
        "int",    // FIELD_value
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **WriteValDescriptor::getFieldPropertyNames(int field) const
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

const char *WriteValDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int WriteValDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    WriteVal *pp = omnetpp::fromAnyPtr<WriteVal>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void WriteValDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    WriteVal *pp = omnetpp::fromAnyPtr<WriteVal>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'WriteVal'", field);
    }
}

const char *WriteValDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    WriteVal *pp = omnetpp::fromAnyPtr<WriteVal>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string WriteValDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    WriteVal *pp = omnetpp::fromAnyPtr<WriteVal>(object); (void)pp;
    switch (field) {
        case FIELD_key: return long2string(pp->getKey());
        case FIELD_value: return long2string(pp->getValue());
        default: return "";
    }
}

void WriteValDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    WriteVal *pp = omnetpp::fromAnyPtr<WriteVal>(object); (void)pp;
    switch (field) {
        case FIELD_key: pp->setKey(string2long(value)); break;
        case FIELD_value: pp->setValue(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'WriteVal'", field);
    }
}

omnetpp::cValue WriteValDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    WriteVal *pp = omnetpp::fromAnyPtr<WriteVal>(object); (void)pp;
    switch (field) {
        case FIELD_key: return pp->getKey();
        case FIELD_value: return pp->getValue();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'WriteVal' as cValue -- field index out of range?", field);
    }
}

void WriteValDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    WriteVal *pp = omnetpp::fromAnyPtr<WriteVal>(object); (void)pp;
    switch (field) {
        case FIELD_key: pp->setKey(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_value: pp->setValue(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'WriteVal'", field);
    }
}

const char *WriteValDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr WriteValDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    WriteVal *pp = omnetpp::fromAnyPtr<WriteVal>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void WriteValDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    WriteVal *pp = omnetpp::fromAnyPtr<WriteVal>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'WriteVal'", field);
    }
}

Register_Class(ReadVal)

ReadVal::ReadVal(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

ReadVal::ReadVal(const ReadVal& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

ReadVal::~ReadVal()
{
}

ReadVal& ReadVal::operator=(const ReadVal& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void ReadVal::copy(const ReadVal& other)
{
    this->key = other.key;
    this->value = other.value;
    this->clientId = other.clientId;
}

void ReadVal::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->key);
    doParsimPacking(b,this->value);
    doParsimPacking(b,this->clientId);
}

void ReadVal::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->key);
    doParsimUnpacking(b,this->value);
    doParsimUnpacking(b,this->clientId);
}

int ReadVal::getKey() const
{
    return this->key;
}

void ReadVal::setKey(int key)
{
    this->key = key;
}

int ReadVal::getValue() const
{
    return this->value;
}

void ReadVal::setValue(int value)
{
    this->value = value;
}

int ReadVal::getClientId() const
{
    return this->clientId;
}

void ReadVal::setClientId(int clientId)
{
    this->clientId = clientId;
}

class ReadValDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_key,
        FIELD_value,
        FIELD_clientId,
    };
  public:
    ReadValDescriptor();
    virtual ~ReadValDescriptor();

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

Register_ClassDescriptor(ReadValDescriptor)

ReadValDescriptor::ReadValDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(ReadVal)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

ReadValDescriptor::~ReadValDescriptor()
{
    delete[] propertyNames;
}

bool ReadValDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ReadVal *>(obj)!=nullptr;
}

const char **ReadValDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *ReadValDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int ReadValDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int ReadValDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_key
        FD_ISEDITABLE,    // FIELD_value
        FD_ISEDITABLE,    // FIELD_clientId
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *ReadValDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "key",
        "value",
        "clientId",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int ReadValDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "key") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "value") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "clientId") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *ReadValDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_key
        "int",    // FIELD_value
        "int",    // FIELD_clientId
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **ReadValDescriptor::getFieldPropertyNames(int field) const
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

const char *ReadValDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int ReadValDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    ReadVal *pp = omnetpp::fromAnyPtr<ReadVal>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void ReadValDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    ReadVal *pp = omnetpp::fromAnyPtr<ReadVal>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'ReadVal'", field);
    }
}

const char *ReadValDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    ReadVal *pp = omnetpp::fromAnyPtr<ReadVal>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ReadValDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    ReadVal *pp = omnetpp::fromAnyPtr<ReadVal>(object); (void)pp;
    switch (field) {
        case FIELD_key: return long2string(pp->getKey());
        case FIELD_value: return long2string(pp->getValue());
        case FIELD_clientId: return long2string(pp->getClientId());
        default: return "";
    }
}

void ReadValDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ReadVal *pp = omnetpp::fromAnyPtr<ReadVal>(object); (void)pp;
    switch (field) {
        case FIELD_key: pp->setKey(string2long(value)); break;
        case FIELD_value: pp->setValue(string2long(value)); break;
        case FIELD_clientId: pp->setClientId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ReadVal'", field);
    }
}

omnetpp::cValue ReadValDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    ReadVal *pp = omnetpp::fromAnyPtr<ReadVal>(object); (void)pp;
    switch (field) {
        case FIELD_key: return pp->getKey();
        case FIELD_value: return pp->getValue();
        case FIELD_clientId: return pp->getClientId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'ReadVal' as cValue -- field index out of range?", field);
    }
}

void ReadValDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ReadVal *pp = omnetpp::fromAnyPtr<ReadVal>(object); (void)pp;
    switch (field) {
        case FIELD_key: pp->setKey(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_value: pp->setValue(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_clientId: pp->setClientId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ReadVal'", field);
    }
}

const char *ReadValDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr ReadValDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    ReadVal *pp = omnetpp::fromAnyPtr<ReadVal>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void ReadValDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    ReadVal *pp = omnetpp::fromAnyPtr<ReadVal>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ReadVal'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

