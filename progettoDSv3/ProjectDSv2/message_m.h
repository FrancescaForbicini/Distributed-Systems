//
// Generated file, do not edit! Created by opp_msgtool 6.0 from message.msg.
//

#ifndef __MESSAGE_M_H
#define __MESSAGE_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

struct Operation;
class Transaction;
class DoOperation;
class Ack;
class Nack;
class Commit;
class Abort;
class WriteVal;
class ReadVal;
/**
 * Struct generated from message.msg:1 by opp_msgtool.
 */
struct Operation
{
    Operation();
    int type = 0;
    int key = 0;
    int value = 0;
    int clientId = 0;
    int serverId = 0;
    int transId = 0;
    omnetpp::simtime_t ts = SIMTIME_ZERO;
};

// helpers for local use
void __doPacking(omnetpp::cCommBuffer *b, const Operation& a);
void __doUnpacking(omnetpp::cCommBuffer *b, Operation& a);

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Operation& obj) { __doPacking(b, obj); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Operation& obj) { __doUnpacking(b, obj); }

/**
 * Class generated from <tt>message.msg:12</tt> by opp_msgtool.
 * <pre>
 * message Transaction
 * {
 *     Operation operations[2];
 * 
 * }
 * </pre>
 */
class Transaction : public ::omnetpp::cMessage
{
  protected:
    Operation operations[2];

  private:
    void copy(const Transaction& other);

  protected:
    bool operator==(const Transaction&) = delete;

  public:
    Transaction(const char *name=nullptr, short kind=0);
    Transaction(const Transaction& other);
    virtual ~Transaction();
    Transaction& operator=(const Transaction& other);
    virtual Transaction *dup() const override {return new Transaction(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual size_t getOperationsArraySize() const;
    virtual const Operation& getOperations(size_t k) const;
    virtual Operation& getOperationsForUpdate(size_t k) { return const_cast<Operation&>(const_cast<Transaction*>(this)->getOperations(k));}
    virtual void setOperations(size_t k, const Operation& operations);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Transaction& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Transaction& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>message.msg:19</tt> by opp_msgtool.
 * <pre>
 * message DoOperation
 * {
 *     Operation op;
 * 
 * }
 * </pre>
 */
class DoOperation : public ::omnetpp::cMessage
{
  protected:
    Operation op;

  private:
    void copy(const DoOperation& other);

  protected:
    bool operator==(const DoOperation&) = delete;

  public:
    DoOperation(const char *name=nullptr, short kind=0);
    DoOperation(const DoOperation& other);
    virtual ~DoOperation();
    DoOperation& operator=(const DoOperation& other);
    virtual DoOperation *dup() const override {return new DoOperation(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual const Operation& getOp() const;
    virtual Operation& getOpForUpdate() { return const_cast<Operation&>(const_cast<DoOperation*>(this)->getOp());}
    virtual void setOp(const Operation& op);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const DoOperation& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, DoOperation& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>message.msg:25</tt> by opp_msgtool.
 * <pre>
 * message Ack
 * {
 *     int serverId;
 *     simtime_t ts;
 *     int clientId;
 * 
 * }
 * </pre>
 */
class Ack : public ::omnetpp::cMessage
{
  protected:
    int serverId = 0;
    omnetpp::simtime_t ts = SIMTIME_ZERO;
    int clientId = 0;

  private:
    void copy(const Ack& other);

  protected:
    bool operator==(const Ack&) = delete;

  public:
    Ack(const char *name=nullptr, short kind=0);
    Ack(const Ack& other);
    virtual ~Ack();
    Ack& operator=(const Ack& other);
    virtual Ack *dup() const override {return new Ack(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getServerId() const;
    virtual void setServerId(int serverId);

    virtual omnetpp::simtime_t getTs() const;
    virtual void setTs(omnetpp::simtime_t ts);

    virtual int getClientId() const;
    virtual void setClientId(int clientId);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ack& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ack& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>message.msg:32</tt> by opp_msgtool.
 * <pre>
 * message Nack
 * {
 *     int serverId;
 *     simtime_t ts;
 *     int clientId;
 * }
 * </pre>
 */
class Nack : public ::omnetpp::cMessage
{
  protected:
    int serverId = 0;
    omnetpp::simtime_t ts = SIMTIME_ZERO;
    int clientId = 0;

  private:
    void copy(const Nack& other);

  protected:
    bool operator==(const Nack&) = delete;

  public:
    Nack(const char *name=nullptr, short kind=0);
    Nack(const Nack& other);
    virtual ~Nack();
    Nack& operator=(const Nack& other);
    virtual Nack *dup() const override {return new Nack(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getServerId() const;
    virtual void setServerId(int serverId);

    virtual omnetpp::simtime_t getTs() const;
    virtual void setTs(omnetpp::simtime_t ts);

    virtual int getClientId() const;
    virtual void setClientId(int clientId);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Nack& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Nack& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>message.msg:38</tt> by opp_msgtool.
 * <pre>
 * message Commit
 * {
 *     int serverId;
 *     simtime_t ts;
 *     int clientId;
 * }
 * </pre>
 */
class Commit : public ::omnetpp::cMessage
{
  protected:
    int serverId = 0;
    omnetpp::simtime_t ts = SIMTIME_ZERO;
    int clientId = 0;

  private:
    void copy(const Commit& other);

  protected:
    bool operator==(const Commit&) = delete;

  public:
    Commit(const char *name=nullptr, short kind=0);
    Commit(const Commit& other);
    virtual ~Commit();
    Commit& operator=(const Commit& other);
    virtual Commit *dup() const override {return new Commit(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getServerId() const;
    virtual void setServerId(int serverId);

    virtual omnetpp::simtime_t getTs() const;
    virtual void setTs(omnetpp::simtime_t ts);

    virtual int getClientId() const;
    virtual void setClientId(int clientId);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Commit& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Commit& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>message.msg:44</tt> by opp_msgtool.
 * <pre>
 * message Abort
 * {
 *     int serverId;
 *     simtime_t ts;
 *     int clientId;
 * }
 * </pre>
 */
class Abort : public ::omnetpp::cMessage
{
  protected:
    int serverId = 0;
    omnetpp::simtime_t ts = SIMTIME_ZERO;
    int clientId = 0;

  private:
    void copy(const Abort& other);

  protected:
    bool operator==(const Abort&) = delete;

  public:
    Abort(const char *name=nullptr, short kind=0);
    Abort(const Abort& other);
    virtual ~Abort();
    Abort& operator=(const Abort& other);
    virtual Abort *dup() const override {return new Abort(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getServerId() const;
    virtual void setServerId(int serverId);

    virtual omnetpp::simtime_t getTs() const;
    virtual void setTs(omnetpp::simtime_t ts);

    virtual int getClientId() const;
    virtual void setClientId(int clientId);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Abort& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Abort& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>message.msg:50</tt> by opp_msgtool.
 * <pre>
 * message WriteVal
 * {
 *     int key;
 *     int value;
 * }
 * </pre>
 */
class WriteVal : public ::omnetpp::cMessage
{
  protected:
    int key = 0;
    int value = 0;

  private:
    void copy(const WriteVal& other);

  protected:
    bool operator==(const WriteVal&) = delete;

  public:
    WriteVal(const char *name=nullptr, short kind=0);
    WriteVal(const WriteVal& other);
    virtual ~WriteVal();
    WriteVal& operator=(const WriteVal& other);
    virtual WriteVal *dup() const override {return new WriteVal(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getKey() const;
    virtual void setKey(int key);

    virtual int getValue() const;
    virtual void setValue(int value);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const WriteVal& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, WriteVal& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>message.msg:55</tt> by opp_msgtool.
 * <pre>
 * message ReadVal
 * {
 *     int key;
 *     int value;
 *     int clientId;
 * }
 * </pre>
 */
class ReadVal : public ::omnetpp::cMessage
{
  protected:
    int key = 0;
    int value = 0;
    int clientId = 0;

  private:
    void copy(const ReadVal& other);

  protected:
    bool operator==(const ReadVal&) = delete;

  public:
    ReadVal(const char *name=nullptr, short kind=0);
    ReadVal(const ReadVal& other);
    virtual ~ReadVal();
    ReadVal& operator=(const ReadVal& other);
    virtual ReadVal *dup() const override {return new ReadVal(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getKey() const;
    virtual void setKey(int key);

    virtual int getValue() const;
    virtual void setValue(int value);

    virtual int getClientId() const;
    virtual void setClientId(int clientId);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const ReadVal& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, ReadVal& obj) {obj.parsimUnpack(b);}


namespace omnetpp {

inline any_ptr toAnyPtr(const Operation *p) {return any_ptr(p);}
template<> inline Operation *fromAnyPtr(any_ptr ptr) { return ptr.get<Operation>(); }
template<> inline Transaction *fromAnyPtr(any_ptr ptr) { return check_and_cast<Transaction*>(ptr.get<cObject>()); }
template<> inline DoOperation *fromAnyPtr(any_ptr ptr) { return check_and_cast<DoOperation*>(ptr.get<cObject>()); }
template<> inline Ack *fromAnyPtr(any_ptr ptr) { return check_and_cast<Ack*>(ptr.get<cObject>()); }
template<> inline Nack *fromAnyPtr(any_ptr ptr) { return check_and_cast<Nack*>(ptr.get<cObject>()); }
template<> inline Commit *fromAnyPtr(any_ptr ptr) { return check_and_cast<Commit*>(ptr.get<cObject>()); }
template<> inline Abort *fromAnyPtr(any_ptr ptr) { return check_and_cast<Abort*>(ptr.get<cObject>()); }
template<> inline WriteVal *fromAnyPtr(any_ptr ptr) { return check_and_cast<WriteVal*>(ptr.get<cObject>()); }
template<> inline ReadVal *fromAnyPtr(any_ptr ptr) { return check_and_cast<ReadVal*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __MESSAGE_M_H

