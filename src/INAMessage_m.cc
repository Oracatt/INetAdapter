//
// Generated file, do not edit! Created by nedtool 5.6 from INAMessage.msg.
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
#include "INAMessage_m.h"

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

namespace {
template <class T> inline
typename std::enable_if<std::is_polymorphic<T>::value && std::is_base_of<omnetpp::cObject,T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)(static_cast<const omnetpp::cObject *>(t));
}

template <class T> inline
typename std::enable_if<std::is_polymorphic<T>::value && !std::is_base_of<omnetpp::cObject,T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)dynamic_cast<const void *>(t);
}

template <class T> inline
typename std::enable_if<!std::is_polymorphic<T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)static_cast<const void *>(t);
}

}


// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule to generate operator<< for shared_ptr<T>
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const std::shared_ptr<T>& t) { return out << t.get(); }

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');

    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

Register_Class(INATypeMsg)

INATypeMsg::INATypeMsg() : ::inet::FieldsChunk()
{
}

INATypeMsg::INATypeMsg(const INATypeMsg& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

INATypeMsg::~INATypeMsg()
{
}

INATypeMsg& INATypeMsg::operator=(const INATypeMsg& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void INATypeMsg::copy(const INATypeMsg& other)
{
    this->senderID = other.senderID;
    this->msgKind = other.msgKind;
}

void INATypeMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->senderID);
    doParsimPacking(b,this->msgKind);
}

void INATypeMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->senderID);
    doParsimUnpacking(b,this->msgKind);
}

int INATypeMsg::getSenderID() const
{
    return this->senderID;
}

void INATypeMsg::setSenderID(int senderID)
{
    handleChange();
    this->senderID = senderID;
}

int INATypeMsg::getMsgKind() const
{
    return this->msgKind;
}

void INATypeMsg::setMsgKind(int msgKind)
{
    handleChange();
    this->msgKind = msgKind;
}

class INATypeMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_senderID,
        FIELD_msgKind,
    };
  public:
    INATypeMsgDescriptor();
    virtual ~INATypeMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(INATypeMsgDescriptor)

INATypeMsgDescriptor::INATypeMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(INATypeMsg)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

INATypeMsgDescriptor::~INATypeMsgDescriptor()
{
    delete[] propertynames;
}

bool INATypeMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<INATypeMsg *>(obj)!=nullptr;
}

const char **INATypeMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *INATypeMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int INATypeMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int INATypeMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_senderID
        FD_ISEDITABLE,    // FIELD_msgKind
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *INATypeMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "senderID",
        "msgKind",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int INATypeMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "senderID") == 0) return base+0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "msgKind") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *INATypeMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_senderID
        "int",    // FIELD_msgKind
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **INATypeMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *INATypeMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int INATypeMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    INATypeMsg *pp = (INATypeMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *INATypeMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    INATypeMsg *pp = (INATypeMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string INATypeMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    INATypeMsg *pp = (INATypeMsg *)object; (void)pp;
    switch (field) {
        case FIELD_senderID: return long2string(pp->getSenderID());
        case FIELD_msgKind: return long2string(pp->getMsgKind());
        default: return "";
    }
}

bool INATypeMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    INATypeMsg *pp = (INATypeMsg *)object; (void)pp;
    switch (field) {
        case FIELD_senderID: pp->setSenderID(string2long(value)); return true;
        case FIELD_msgKind: pp->setMsgKind(string2long(value)); return true;
        default: return false;
    }
}

const char *INATypeMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *INATypeMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    INATypeMsg *pp = (INATypeMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(INAUserMsgHeader)

INAUserMsgHeader::INAUserMsgHeader() : ::inet::FieldsChunk()
{
}

INAUserMsgHeader::INAUserMsgHeader(const INAUserMsgHeader& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

INAUserMsgHeader::~INAUserMsgHeader()
{
}

INAUserMsgHeader& INAUserMsgHeader::operator=(const INAUserMsgHeader& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void INAUserMsgHeader::copy(const INAUserMsgHeader& other)
{
    this->ptrType = other.ptrType;
}

void INAUserMsgHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->ptrType);
}

void INAUserMsgHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->ptrType);
}

int INAUserMsgHeader::getPtrType() const
{
    return this->ptrType;
}

void INAUserMsgHeader::setPtrType(int ptrType)
{
    handleChange();
    this->ptrType = ptrType;
}

class INAUserMsgHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_ptrType,
    };
  public:
    INAUserMsgHeaderDescriptor();
    virtual ~INAUserMsgHeaderDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(INAUserMsgHeaderDescriptor)

INAUserMsgHeaderDescriptor::INAUserMsgHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(INAUserMsgHeader)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

INAUserMsgHeaderDescriptor::~INAUserMsgHeaderDescriptor()
{
    delete[] propertynames;
}

bool INAUserMsgHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<INAUserMsgHeader *>(obj)!=nullptr;
}

const char **INAUserMsgHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *INAUserMsgHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int INAUserMsgHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int INAUserMsgHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_ptrType
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *INAUserMsgHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ptrType",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int INAUserMsgHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "ptrType") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *INAUserMsgHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_ptrType
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **INAUserMsgHeaderDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *INAUserMsgHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int INAUserMsgHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    INAUserMsgHeader *pp = (INAUserMsgHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *INAUserMsgHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    INAUserMsgHeader *pp = (INAUserMsgHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string INAUserMsgHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    INAUserMsgHeader *pp = (INAUserMsgHeader *)object; (void)pp;
    switch (field) {
        case FIELD_ptrType: return long2string(pp->getPtrType());
        default: return "";
    }
}

bool INAUserMsgHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    INAUserMsgHeader *pp = (INAUserMsgHeader *)object; (void)pp;
    switch (field) {
        case FIELD_ptrType: pp->setPtrType(string2long(value)); return true;
        default: return false;
    }
}

const char *INAUserMsgHeaderDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *INAUserMsgHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    INAUserMsgHeader *pp = (INAUserMsgHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(INAUpdateMsg)

INAUpdateMsg::INAUpdateMsg() : ::inet::FieldsChunk()
{
}

INAUpdateMsg::INAUpdateMsg(const INAUpdateMsg& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

INAUpdateMsg::~INAUpdateMsg()
{
    delete [] this->neighborID;
    delete [] this->ack;
}

INAUpdateMsg& INAUpdateMsg::operator=(const INAUpdateMsg& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void INAUpdateMsg::copy(const INAUpdateMsg& other)
{
    this->neighborCount = other.neighborCount;
    delete [] this->neighborID;
    this->neighborID = (other.neighborID_arraysize==0) ? nullptr : new int[other.neighborID_arraysize];
    neighborID_arraysize = other.neighborID_arraysize;
    for (size_t i = 0; i < neighborID_arraysize; i++) {
        this->neighborID[i] = other.neighborID[i];
    }
    delete [] this->ack;
    this->ack = (other.ack_arraysize==0) ? nullptr : new bool[other.ack_arraysize];
    ack_arraysize = other.ack_arraysize;
    for (size_t i = 0; i < ack_arraysize; i++) {
        this->ack[i] = other.ack[i];
    }
    this->macAddress = other.macAddress;
}

void INAUpdateMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->neighborCount);
    b->pack(neighborID_arraysize);
    doParsimArrayPacking(b,this->neighborID,neighborID_arraysize);
    b->pack(ack_arraysize);
    doParsimArrayPacking(b,this->ack,ack_arraysize);
    doParsimPacking(b,this->macAddress);
}

void INAUpdateMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->neighborCount);
    delete [] this->neighborID;
    b->unpack(neighborID_arraysize);
    if (neighborID_arraysize == 0) {
        this->neighborID = nullptr;
    } else {
        this->neighborID = new int[neighborID_arraysize];
        doParsimArrayUnpacking(b,this->neighborID,neighborID_arraysize);
    }
    delete [] this->ack;
    b->unpack(ack_arraysize);
    if (ack_arraysize == 0) {
        this->ack = nullptr;
    } else {
        this->ack = new bool[ack_arraysize];
        doParsimArrayUnpacking(b,this->ack,ack_arraysize);
    }
    doParsimUnpacking(b,this->macAddress);
}

int16_t INAUpdateMsg::getNeighborCount() const
{
    return this->neighborCount;
}

void INAUpdateMsg::setNeighborCount(int16_t neighborCount)
{
    handleChange();
    this->neighborCount = neighborCount;
}

size_t INAUpdateMsg::getNeighborIDArraySize() const
{
    return neighborID_arraysize;
}

int INAUpdateMsg::getNeighborID(size_t k) const
{
    if (k >= neighborID_arraysize) throw omnetpp::cRuntimeError("Array of size neighborID_arraysize indexed by %lu", (unsigned long)k);
    return this->neighborID[k];
}

void INAUpdateMsg::setNeighborIDArraySize(size_t newSize)
{
    handleChange();
    int *neighborID2 = (newSize==0) ? nullptr : new int[newSize];
    size_t minSize = neighborID_arraysize < newSize ? neighborID_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        neighborID2[i] = this->neighborID[i];
    for (size_t i = minSize; i < newSize; i++)
        neighborID2[i] = 0;
    delete [] this->neighborID;
    this->neighborID = neighborID2;
    neighborID_arraysize = newSize;
}

void INAUpdateMsg::setNeighborID(size_t k, int neighborID)
{
    if (k >= neighborID_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->neighborID[k] = neighborID;
}

void INAUpdateMsg::insertNeighborID(size_t k, int neighborID)
{
    handleChange();
    if (k > neighborID_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = neighborID_arraysize + 1;
    int *neighborID2 = new int[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        neighborID2[i] = this->neighborID[i];
    neighborID2[k] = neighborID;
    for (i = k + 1; i < newSize; i++)
        neighborID2[i] = this->neighborID[i-1];
    delete [] this->neighborID;
    this->neighborID = neighborID2;
    neighborID_arraysize = newSize;
}

void INAUpdateMsg::insertNeighborID(int neighborID)
{
    insertNeighborID(neighborID_arraysize, neighborID);
}

void INAUpdateMsg::eraseNeighborID(size_t k)
{
    if (k >= neighborID_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = neighborID_arraysize - 1;
    int *neighborID2 = (newSize == 0) ? nullptr : new int[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        neighborID2[i] = this->neighborID[i];
    for (i = k; i < newSize; i++)
        neighborID2[i] = this->neighborID[i+1];
    delete [] this->neighborID;
    this->neighborID = neighborID2;
    neighborID_arraysize = newSize;
}

size_t INAUpdateMsg::getAckArraySize() const
{
    return ack_arraysize;
}

bool INAUpdateMsg::getAck(size_t k) const
{
    if (k >= ack_arraysize) throw omnetpp::cRuntimeError("Array of size ack_arraysize indexed by %lu", (unsigned long)k);
    return this->ack[k];
}

void INAUpdateMsg::setAckArraySize(size_t newSize)
{
    handleChange();
    bool *ack2 = (newSize==0) ? nullptr : new bool[newSize];
    size_t minSize = ack_arraysize < newSize ? ack_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        ack2[i] = this->ack[i];
    for (size_t i = minSize; i < newSize; i++)
        ack2[i] = false;
    delete [] this->ack;
    this->ack = ack2;
    ack_arraysize = newSize;
}

void INAUpdateMsg::setAck(size_t k, bool ack)
{
    if (k >= ack_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->ack[k] = ack;
}

void INAUpdateMsg::insertAck(size_t k, bool ack)
{
    handleChange();
    if (k > ack_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = ack_arraysize + 1;
    bool *ack2 = new bool[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        ack2[i] = this->ack[i];
    ack2[k] = ack;
    for (i = k + 1; i < newSize; i++)
        ack2[i] = this->ack[i-1];
    delete [] this->ack;
    this->ack = ack2;
    ack_arraysize = newSize;
}

void INAUpdateMsg::insertAck(bool ack)
{
    insertAck(ack_arraysize, ack);
}

void INAUpdateMsg::eraseAck(size_t k)
{
    if (k >= ack_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = ack_arraysize - 1;
    bool *ack2 = (newSize == 0) ? nullptr : new bool[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        ack2[i] = this->ack[i];
    for (i = k; i < newSize; i++)
        ack2[i] = this->ack[i+1];
    delete [] this->ack;
    this->ack = ack2;
    ack_arraysize = newSize;
}

const char * INAUpdateMsg::getMacAddress() const
{
    return this->macAddress.c_str();
}

void INAUpdateMsg::setMacAddress(const char * macAddress)
{
    handleChange();
    this->macAddress = macAddress;
}

class INAUpdateMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_neighborCount,
        FIELD_neighborID,
        FIELD_ack,
        FIELD_macAddress,
    };
  public:
    INAUpdateMsgDescriptor();
    virtual ~INAUpdateMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(INAUpdateMsgDescriptor)

INAUpdateMsgDescriptor::INAUpdateMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(INAUpdateMsg)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

INAUpdateMsgDescriptor::~INAUpdateMsgDescriptor()
{
    delete[] propertynames;
}

bool INAUpdateMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<INAUpdateMsg *>(obj)!=nullptr;
}

const char **INAUpdateMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *INAUpdateMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int INAUpdateMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int INAUpdateMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_neighborCount
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_neighborID
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_ack
        FD_ISEDITABLE,    // FIELD_macAddress
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *INAUpdateMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "neighborCount",
        "neighborID",
        "ack",
        "macAddress",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int INAUpdateMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'n' && strcmp(fieldName, "neighborCount") == 0) return base+0;
    if (fieldName[0] == 'n' && strcmp(fieldName, "neighborID") == 0) return base+1;
    if (fieldName[0] == 'a' && strcmp(fieldName, "ack") == 0) return base+2;
    if (fieldName[0] == 'm' && strcmp(fieldName, "macAddress") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *INAUpdateMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int16_t",    // FIELD_neighborCount
        "int",    // FIELD_neighborID
        "bool",    // FIELD_ack
        "string",    // FIELD_macAddress
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **INAUpdateMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *INAUpdateMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int INAUpdateMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    INAUpdateMsg *pp = (INAUpdateMsg *)object; (void)pp;
    switch (field) {
        case FIELD_neighborID: return pp->getNeighborIDArraySize();
        case FIELD_ack: return pp->getAckArraySize();
        default: return 0;
    }
}

const char *INAUpdateMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    INAUpdateMsg *pp = (INAUpdateMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string INAUpdateMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    INAUpdateMsg *pp = (INAUpdateMsg *)object; (void)pp;
    switch (field) {
        case FIELD_neighborCount: return long2string(pp->getNeighborCount());
        case FIELD_neighborID: return long2string(pp->getNeighborID(i));
        case FIELD_ack: return bool2string(pp->getAck(i));
        case FIELD_macAddress: return oppstring2string(pp->getMacAddress());
        default: return "";
    }
}

bool INAUpdateMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    INAUpdateMsg *pp = (INAUpdateMsg *)object; (void)pp;
    switch (field) {
        case FIELD_neighborCount: pp->setNeighborCount(string2long(value)); return true;
        case FIELD_neighborID: pp->setNeighborID(i,string2long(value)); return true;
        case FIELD_ack: pp->setAck(i,string2bool(value)); return true;
        case FIELD_macAddress: pp->setMacAddress((value)); return true;
        default: return false;
    }
}

const char *INAUpdateMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *INAUpdateMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    INAUpdateMsg *pp = (INAUpdateMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(INAUserMsg_KDataMsg)

INAUserMsg_KDataMsg::INAUserMsg_KDataMsg() : ::inet::FieldsChunk()
{
    take(&this->data);
}

INAUserMsg_KDataMsg::INAUserMsg_KDataMsg(const INAUserMsg_KDataMsg& other) : ::inet::FieldsChunk(other)
{
    take(&this->data);
    copy(other);
}

INAUserMsg_KDataMsg::~INAUserMsg_KDataMsg()
{
    drop(&this->data);
}

INAUserMsg_KDataMsg& INAUserMsg_KDataMsg::operator=(const INAUserMsg_KDataMsg& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void INAUserMsg_KDataMsg::copy(const INAUserMsg_KDataMsg& other)
{
    this->data = other.data;
    this->data.setName(other.data.getName());
}

void INAUserMsg_KDataMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->data);
}

void INAUserMsg_KDataMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->data);
}

const KDataMsg& INAUserMsg_KDataMsg::getData() const
{
    return this->data;
}

void INAUserMsg_KDataMsg::setData(const KDataMsg& data)
{
    handleChange();
    this->data = data;
}

class INAUserMsg_KDataMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_data,
    };
  public:
    INAUserMsg_KDataMsgDescriptor();
    virtual ~INAUserMsg_KDataMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(INAUserMsg_KDataMsgDescriptor)

INAUserMsg_KDataMsgDescriptor::INAUserMsg_KDataMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(INAUserMsg_KDataMsg)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

INAUserMsg_KDataMsgDescriptor::~INAUserMsg_KDataMsgDescriptor()
{
    delete[] propertynames;
}

bool INAUserMsg_KDataMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<INAUserMsg_KDataMsg *>(obj)!=nullptr;
}

const char **INAUserMsg_KDataMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *INAUserMsg_KDataMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int INAUserMsg_KDataMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int INAUserMsg_KDataMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,    // FIELD_data
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *INAUserMsg_KDataMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "data",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int INAUserMsg_KDataMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'd' && strcmp(fieldName, "data") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *INAUserMsg_KDataMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "KDataMsg",    // FIELD_data
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **INAUserMsg_KDataMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *INAUserMsg_KDataMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int INAUserMsg_KDataMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KDataMsg *pp = (INAUserMsg_KDataMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *INAUserMsg_KDataMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KDataMsg *pp = (INAUserMsg_KDataMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string INAUserMsg_KDataMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KDataMsg *pp = (INAUserMsg_KDataMsg *)object; (void)pp;
    switch (field) {
        case FIELD_data: {std::stringstream out; out << pp->getData(); return out.str();}
        default: return "";
    }
}

bool INAUserMsg_KDataMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KDataMsg *pp = (INAUserMsg_KDataMsg *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *INAUserMsg_KDataMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_data: return omnetpp::opp_typename(typeid(KDataMsg));
        default: return nullptr;
    };
}

void *INAUserMsg_KDataMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KDataMsg *pp = (INAUserMsg_KDataMsg *)object; (void)pp;
    switch (field) {
        case FIELD_data: return toVoidPtr(&pp->getData()); break;
        default: return nullptr;
    }
}

Register_Class(INAUserMsg_KFeedbackMsg)

INAUserMsg_KFeedbackMsg::INAUserMsg_KFeedbackMsg() : ::inet::FieldsChunk()
{
    take(&this->data);
}

INAUserMsg_KFeedbackMsg::INAUserMsg_KFeedbackMsg(const INAUserMsg_KFeedbackMsg& other) : ::inet::FieldsChunk(other)
{
    take(&this->data);
    copy(other);
}

INAUserMsg_KFeedbackMsg::~INAUserMsg_KFeedbackMsg()
{
    drop(&this->data);
}

INAUserMsg_KFeedbackMsg& INAUserMsg_KFeedbackMsg::operator=(const INAUserMsg_KFeedbackMsg& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void INAUserMsg_KFeedbackMsg::copy(const INAUserMsg_KFeedbackMsg& other)
{
    this->data = other.data;
    this->data.setName(other.data.getName());
}

void INAUserMsg_KFeedbackMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->data);
}

void INAUserMsg_KFeedbackMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->data);
}

const KFeedbackMsg& INAUserMsg_KFeedbackMsg::getData() const
{
    return this->data;
}

void INAUserMsg_KFeedbackMsg::setData(const KFeedbackMsg& data)
{
    handleChange();
    this->data = data;
}

class INAUserMsg_KFeedbackMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_data,
    };
  public:
    INAUserMsg_KFeedbackMsgDescriptor();
    virtual ~INAUserMsg_KFeedbackMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(INAUserMsg_KFeedbackMsgDescriptor)

INAUserMsg_KFeedbackMsgDescriptor::INAUserMsg_KFeedbackMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(INAUserMsg_KFeedbackMsg)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

INAUserMsg_KFeedbackMsgDescriptor::~INAUserMsg_KFeedbackMsgDescriptor()
{
    delete[] propertynames;
}

bool INAUserMsg_KFeedbackMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<INAUserMsg_KFeedbackMsg *>(obj)!=nullptr;
}

const char **INAUserMsg_KFeedbackMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *INAUserMsg_KFeedbackMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int INAUserMsg_KFeedbackMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int INAUserMsg_KFeedbackMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,    // FIELD_data
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *INAUserMsg_KFeedbackMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "data",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int INAUserMsg_KFeedbackMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'd' && strcmp(fieldName, "data") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *INAUserMsg_KFeedbackMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "KFeedbackMsg",    // FIELD_data
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **INAUserMsg_KFeedbackMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *INAUserMsg_KFeedbackMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int INAUserMsg_KFeedbackMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KFeedbackMsg *pp = (INAUserMsg_KFeedbackMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *INAUserMsg_KFeedbackMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KFeedbackMsg *pp = (INAUserMsg_KFeedbackMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string INAUserMsg_KFeedbackMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KFeedbackMsg *pp = (INAUserMsg_KFeedbackMsg *)object; (void)pp;
    switch (field) {
        case FIELD_data: {std::stringstream out; out << pp->getData(); return out.str();}
        default: return "";
    }
}

bool INAUserMsg_KFeedbackMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KFeedbackMsg *pp = (INAUserMsg_KFeedbackMsg *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *INAUserMsg_KFeedbackMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_data: return omnetpp::opp_typename(typeid(KFeedbackMsg));
        default: return nullptr;
    };
}

void *INAUserMsg_KFeedbackMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KFeedbackMsg *pp = (INAUserMsg_KFeedbackMsg *)object; (void)pp;
    switch (field) {
        case FIELD_data: return toVoidPtr(&pp->getData()); break;
        default: return nullptr;
    }
}

Register_Class(INAUserMsg_KSummaryVectorMsg)

INAUserMsg_KSummaryVectorMsg::INAUserMsg_KSummaryVectorMsg() : ::inet::FieldsChunk()
{
    take(&this->data);
}

INAUserMsg_KSummaryVectorMsg::INAUserMsg_KSummaryVectorMsg(const INAUserMsg_KSummaryVectorMsg& other) : ::inet::FieldsChunk(other)
{
    take(&this->data);
    copy(other);
}

INAUserMsg_KSummaryVectorMsg::~INAUserMsg_KSummaryVectorMsg()
{
    drop(&this->data);
}

INAUserMsg_KSummaryVectorMsg& INAUserMsg_KSummaryVectorMsg::operator=(const INAUserMsg_KSummaryVectorMsg& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void INAUserMsg_KSummaryVectorMsg::copy(const INAUserMsg_KSummaryVectorMsg& other)
{
    this->data = other.data;
    this->data.setName(other.data.getName());
}

void INAUserMsg_KSummaryVectorMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->data);
}

void INAUserMsg_KSummaryVectorMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->data);
}

const KSummaryVectorMsg& INAUserMsg_KSummaryVectorMsg::getData() const
{
    return this->data;
}

void INAUserMsg_KSummaryVectorMsg::setData(const KSummaryVectorMsg& data)
{
    handleChange();
    this->data = data;
}

class INAUserMsg_KSummaryVectorMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_data,
    };
  public:
    INAUserMsg_KSummaryVectorMsgDescriptor();
    virtual ~INAUserMsg_KSummaryVectorMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(INAUserMsg_KSummaryVectorMsgDescriptor)

INAUserMsg_KSummaryVectorMsgDescriptor::INAUserMsg_KSummaryVectorMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(INAUserMsg_KSummaryVectorMsg)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

INAUserMsg_KSummaryVectorMsgDescriptor::~INAUserMsg_KSummaryVectorMsgDescriptor()
{
    delete[] propertynames;
}

bool INAUserMsg_KSummaryVectorMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<INAUserMsg_KSummaryVectorMsg *>(obj)!=nullptr;
}

const char **INAUserMsg_KSummaryVectorMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *INAUserMsg_KSummaryVectorMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int INAUserMsg_KSummaryVectorMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int INAUserMsg_KSummaryVectorMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,    // FIELD_data
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *INAUserMsg_KSummaryVectorMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "data",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int INAUserMsg_KSummaryVectorMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'd' && strcmp(fieldName, "data") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *INAUserMsg_KSummaryVectorMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "KSummaryVectorMsg",    // FIELD_data
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **INAUserMsg_KSummaryVectorMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *INAUserMsg_KSummaryVectorMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int INAUserMsg_KSummaryVectorMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KSummaryVectorMsg *pp = (INAUserMsg_KSummaryVectorMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *INAUserMsg_KSummaryVectorMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KSummaryVectorMsg *pp = (INAUserMsg_KSummaryVectorMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string INAUserMsg_KSummaryVectorMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KSummaryVectorMsg *pp = (INAUserMsg_KSummaryVectorMsg *)object; (void)pp;
    switch (field) {
        case FIELD_data: {std::stringstream out; out << pp->getData(); return out.str();}
        default: return "";
    }
}

bool INAUserMsg_KSummaryVectorMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KSummaryVectorMsg *pp = (INAUserMsg_KSummaryVectorMsg *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *INAUserMsg_KSummaryVectorMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_data: return omnetpp::opp_typename(typeid(KSummaryVectorMsg));
        default: return nullptr;
    };
}

void *INAUserMsg_KSummaryVectorMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KSummaryVectorMsg *pp = (INAUserMsg_KSummaryVectorMsg *)object; (void)pp;
    switch (field) {
        case FIELD_data: return toVoidPtr(&pp->getData()); break;
        default: return nullptr;
    }
}

Register_Class(INAUserMsg_KDataRequestMsg)

INAUserMsg_KDataRequestMsg::INAUserMsg_KDataRequestMsg() : ::inet::FieldsChunk()
{
    take(&this->data);
}

INAUserMsg_KDataRequestMsg::INAUserMsg_KDataRequestMsg(const INAUserMsg_KDataRequestMsg& other) : ::inet::FieldsChunk(other)
{
    take(&this->data);
    copy(other);
}

INAUserMsg_KDataRequestMsg::~INAUserMsg_KDataRequestMsg()
{
    drop(&this->data);
}

INAUserMsg_KDataRequestMsg& INAUserMsg_KDataRequestMsg::operator=(const INAUserMsg_KDataRequestMsg& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void INAUserMsg_KDataRequestMsg::copy(const INAUserMsg_KDataRequestMsg& other)
{
    this->data = other.data;
    this->data.setName(other.data.getName());
}

void INAUserMsg_KDataRequestMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->data);
}

void INAUserMsg_KDataRequestMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->data);
}

const KDataRequestMsg& INAUserMsg_KDataRequestMsg::getData() const
{
    return this->data;
}

void INAUserMsg_KDataRequestMsg::setData(const KDataRequestMsg& data)
{
    handleChange();
    this->data = data;
}

class INAUserMsg_KDataRequestMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_data,
    };
  public:
    INAUserMsg_KDataRequestMsgDescriptor();
    virtual ~INAUserMsg_KDataRequestMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(INAUserMsg_KDataRequestMsgDescriptor)

INAUserMsg_KDataRequestMsgDescriptor::INAUserMsg_KDataRequestMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(INAUserMsg_KDataRequestMsg)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

INAUserMsg_KDataRequestMsgDescriptor::~INAUserMsg_KDataRequestMsgDescriptor()
{
    delete[] propertynames;
}

bool INAUserMsg_KDataRequestMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<INAUserMsg_KDataRequestMsg *>(obj)!=nullptr;
}

const char **INAUserMsg_KDataRequestMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *INAUserMsg_KDataRequestMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int INAUserMsg_KDataRequestMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int INAUserMsg_KDataRequestMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,    // FIELD_data
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *INAUserMsg_KDataRequestMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "data",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int INAUserMsg_KDataRequestMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'd' && strcmp(fieldName, "data") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *INAUserMsg_KDataRequestMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "KDataRequestMsg",    // FIELD_data
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **INAUserMsg_KDataRequestMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *INAUserMsg_KDataRequestMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int INAUserMsg_KDataRequestMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KDataRequestMsg *pp = (INAUserMsg_KDataRequestMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *INAUserMsg_KDataRequestMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KDataRequestMsg *pp = (INAUserMsg_KDataRequestMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string INAUserMsg_KDataRequestMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KDataRequestMsg *pp = (INAUserMsg_KDataRequestMsg *)object; (void)pp;
    switch (field) {
        case FIELD_data: {std::stringstream out; out << pp->getData(); return out.str();}
        default: return "";
    }
}

bool INAUserMsg_KDataRequestMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KDataRequestMsg *pp = (INAUserMsg_KDataRequestMsg *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *INAUserMsg_KDataRequestMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_data: return omnetpp::opp_typename(typeid(KDataRequestMsg));
        default: return nullptr;
    };
}

void *INAUserMsg_KDataRequestMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KDataRequestMsg *pp = (INAUserMsg_KDataRequestMsg *)object; (void)pp;
    switch (field) {
        case FIELD_data: return toVoidPtr(&pp->getData()); break;
        default: return nullptr;
    }
}

Register_Class(INAUserMsg_KReactionMsg)

INAUserMsg_KReactionMsg::INAUserMsg_KReactionMsg() : ::inet::FieldsChunk()
{
    take(&this->data);
}

INAUserMsg_KReactionMsg::INAUserMsg_KReactionMsg(const INAUserMsg_KReactionMsg& other) : ::inet::FieldsChunk(other)
{
    take(&this->data);
    copy(other);
}

INAUserMsg_KReactionMsg::~INAUserMsg_KReactionMsg()
{
    drop(&this->data);
}

INAUserMsg_KReactionMsg& INAUserMsg_KReactionMsg::operator=(const INAUserMsg_KReactionMsg& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void INAUserMsg_KReactionMsg::copy(const INAUserMsg_KReactionMsg& other)
{
    this->data = other.data;
    this->data.setName(other.data.getName());
}

void INAUserMsg_KReactionMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->data);
}

void INAUserMsg_KReactionMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->data);
}

const KReactionMsg& INAUserMsg_KReactionMsg::getData() const
{
    return this->data;
}

void INAUserMsg_KReactionMsg::setData(const KReactionMsg& data)
{
    handleChange();
    this->data = data;
}

class INAUserMsg_KReactionMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_data,
    };
  public:
    INAUserMsg_KReactionMsgDescriptor();
    virtual ~INAUserMsg_KReactionMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(INAUserMsg_KReactionMsgDescriptor)

INAUserMsg_KReactionMsgDescriptor::INAUserMsg_KReactionMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(INAUserMsg_KReactionMsg)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

INAUserMsg_KReactionMsgDescriptor::~INAUserMsg_KReactionMsgDescriptor()
{
    delete[] propertynames;
}

bool INAUserMsg_KReactionMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<INAUserMsg_KReactionMsg *>(obj)!=nullptr;
}

const char **INAUserMsg_KReactionMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *INAUserMsg_KReactionMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int INAUserMsg_KReactionMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int INAUserMsg_KReactionMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,    // FIELD_data
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *INAUserMsg_KReactionMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "data",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int INAUserMsg_KReactionMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'd' && strcmp(fieldName, "data") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *INAUserMsg_KReactionMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "KReactionMsg",    // FIELD_data
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **INAUserMsg_KReactionMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *INAUserMsg_KReactionMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int INAUserMsg_KReactionMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KReactionMsg *pp = (INAUserMsg_KReactionMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *INAUserMsg_KReactionMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KReactionMsg *pp = (INAUserMsg_KReactionMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string INAUserMsg_KReactionMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KReactionMsg *pp = (INAUserMsg_KReactionMsg *)object; (void)pp;
    switch (field) {
        case FIELD_data: {std::stringstream out; out << pp->getData(); return out.str();}
        default: return "";
    }
}

bool INAUserMsg_KReactionMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KReactionMsg *pp = (INAUserMsg_KReactionMsg *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *INAUserMsg_KReactionMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_data: return omnetpp::opp_typename(typeid(KReactionMsg));
        default: return nullptr;
    };
}

void *INAUserMsg_KReactionMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KReactionMsg *pp = (INAUserMsg_KReactionMsg *)object; (void)pp;
    switch (field) {
        case FIELD_data: return toVoidPtr(&pp->getData()); break;
        default: return nullptr;
    }
}

Register_Class(INAUserMsg_KDPtableRequestMsg)

INAUserMsg_KDPtableRequestMsg::INAUserMsg_KDPtableRequestMsg() : ::inet::FieldsChunk()
{
    take(&this->data);
}

INAUserMsg_KDPtableRequestMsg::INAUserMsg_KDPtableRequestMsg(const INAUserMsg_KDPtableRequestMsg& other) : ::inet::FieldsChunk(other)
{
    take(&this->data);
    copy(other);
}

INAUserMsg_KDPtableRequestMsg::~INAUserMsg_KDPtableRequestMsg()
{
    drop(&this->data);
}

INAUserMsg_KDPtableRequestMsg& INAUserMsg_KDPtableRequestMsg::operator=(const INAUserMsg_KDPtableRequestMsg& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void INAUserMsg_KDPtableRequestMsg::copy(const INAUserMsg_KDPtableRequestMsg& other)
{
    this->data = other.data;
    this->data.setName(other.data.getName());
}

void INAUserMsg_KDPtableRequestMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->data);
}

void INAUserMsg_KDPtableRequestMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->data);
}

const KDPtableRequestMsg& INAUserMsg_KDPtableRequestMsg::getData() const
{
    return this->data;
}

void INAUserMsg_KDPtableRequestMsg::setData(const KDPtableRequestMsg& data)
{
    handleChange();
    this->data = data;
}

class INAUserMsg_KDPtableRequestMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_data,
    };
  public:
    INAUserMsg_KDPtableRequestMsgDescriptor();
    virtual ~INAUserMsg_KDPtableRequestMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(INAUserMsg_KDPtableRequestMsgDescriptor)

INAUserMsg_KDPtableRequestMsgDescriptor::INAUserMsg_KDPtableRequestMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(INAUserMsg_KDPtableRequestMsg)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

INAUserMsg_KDPtableRequestMsgDescriptor::~INAUserMsg_KDPtableRequestMsgDescriptor()
{
    delete[] propertynames;
}

bool INAUserMsg_KDPtableRequestMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<INAUserMsg_KDPtableRequestMsg *>(obj)!=nullptr;
}

const char **INAUserMsg_KDPtableRequestMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *INAUserMsg_KDPtableRequestMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int INAUserMsg_KDPtableRequestMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int INAUserMsg_KDPtableRequestMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,    // FIELD_data
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *INAUserMsg_KDPtableRequestMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "data",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int INAUserMsg_KDPtableRequestMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'd' && strcmp(fieldName, "data") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *INAUserMsg_KDPtableRequestMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "KDPtableRequestMsg",    // FIELD_data
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **INAUserMsg_KDPtableRequestMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *INAUserMsg_KDPtableRequestMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int INAUserMsg_KDPtableRequestMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KDPtableRequestMsg *pp = (INAUserMsg_KDPtableRequestMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *INAUserMsg_KDPtableRequestMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KDPtableRequestMsg *pp = (INAUserMsg_KDPtableRequestMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string INAUserMsg_KDPtableRequestMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KDPtableRequestMsg *pp = (INAUserMsg_KDPtableRequestMsg *)object; (void)pp;
    switch (field) {
        case FIELD_data: {std::stringstream out; out << pp->getData(); return out.str();}
        default: return "";
    }
}

bool INAUserMsg_KDPtableRequestMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KDPtableRequestMsg *pp = (INAUserMsg_KDPtableRequestMsg *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *INAUserMsg_KDPtableRequestMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_data: return omnetpp::opp_typename(typeid(KDPtableRequestMsg));
        default: return nullptr;
    };
}

void *INAUserMsg_KDPtableRequestMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KDPtableRequestMsg *pp = (INAUserMsg_KDPtableRequestMsg *)object; (void)pp;
    switch (field) {
        case FIELD_data: return toVoidPtr(&pp->getData()); break;
        default: return nullptr;
    }
}

Register_Class(INAUserMsg_KDPtableDataMsg)

INAUserMsg_KDPtableDataMsg::INAUserMsg_KDPtableDataMsg() : ::inet::FieldsChunk()
{
    take(&this->data);
}

INAUserMsg_KDPtableDataMsg::INAUserMsg_KDPtableDataMsg(const INAUserMsg_KDPtableDataMsg& other) : ::inet::FieldsChunk(other)
{
    take(&this->data);
    copy(other);
}

INAUserMsg_KDPtableDataMsg::~INAUserMsg_KDPtableDataMsg()
{
    drop(&this->data);
}

INAUserMsg_KDPtableDataMsg& INAUserMsg_KDPtableDataMsg::operator=(const INAUserMsg_KDPtableDataMsg& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void INAUserMsg_KDPtableDataMsg::copy(const INAUserMsg_KDPtableDataMsg& other)
{
    this->data = other.data;
    this->data.setName(other.data.getName());
}

void INAUserMsg_KDPtableDataMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->data);
}

void INAUserMsg_KDPtableDataMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->data);
}

const KDPtableDataMsg& INAUserMsg_KDPtableDataMsg::getData() const
{
    return this->data;
}

void INAUserMsg_KDPtableDataMsg::setData(const KDPtableDataMsg& data)
{
    handleChange();
    this->data = data;
}

class INAUserMsg_KDPtableDataMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_data,
    };
  public:
    INAUserMsg_KDPtableDataMsgDescriptor();
    virtual ~INAUserMsg_KDPtableDataMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(INAUserMsg_KDPtableDataMsgDescriptor)

INAUserMsg_KDPtableDataMsgDescriptor::INAUserMsg_KDPtableDataMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(INAUserMsg_KDPtableDataMsg)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

INAUserMsg_KDPtableDataMsgDescriptor::~INAUserMsg_KDPtableDataMsgDescriptor()
{
    delete[] propertynames;
}

bool INAUserMsg_KDPtableDataMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<INAUserMsg_KDPtableDataMsg *>(obj)!=nullptr;
}

const char **INAUserMsg_KDPtableDataMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *INAUserMsg_KDPtableDataMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int INAUserMsg_KDPtableDataMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int INAUserMsg_KDPtableDataMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,    // FIELD_data
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *INAUserMsg_KDPtableDataMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "data",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int INAUserMsg_KDPtableDataMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'd' && strcmp(fieldName, "data") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *INAUserMsg_KDPtableDataMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "KDPtableDataMsg",    // FIELD_data
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **INAUserMsg_KDPtableDataMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *INAUserMsg_KDPtableDataMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int INAUserMsg_KDPtableDataMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KDPtableDataMsg *pp = (INAUserMsg_KDPtableDataMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *INAUserMsg_KDPtableDataMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KDPtableDataMsg *pp = (INAUserMsg_KDPtableDataMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string INAUserMsg_KDPtableDataMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KDPtableDataMsg *pp = (INAUserMsg_KDPtableDataMsg *)object; (void)pp;
    switch (field) {
        case FIELD_data: {std::stringstream out; out << pp->getData(); return out.str();}
        default: return "";
    }
}

bool INAUserMsg_KDPtableDataMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KDPtableDataMsg *pp = (INAUserMsg_KDPtableDataMsg *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *INAUserMsg_KDPtableDataMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_data: return omnetpp::opp_typename(typeid(KDPtableDataMsg));
        default: return nullptr;
    };
}

void *INAUserMsg_KDPtableDataMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    INAUserMsg_KDPtableDataMsg *pp = (INAUserMsg_KDPtableDataMsg *)object; (void)pp;
    switch (field) {
        case FIELD_data: return toVoidPtr(&pp->getData()); break;
        default: return nullptr;
    }
}

