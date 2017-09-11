/* phxrpc_lock_stub.cpp

 Generated by phxrpc_pb2client from lock.proto

 Please DO NOT edit unless you know exactly what you are doing.

*/

#include "phxrpc/rpc.h"
#include "phxrpc/network.h"

#include "phxrpc_lock_stub.h"
#include "lock.pb.h"


LockStub::LockStub(phxrpc::BaseTcpStream &socket, phxrpc::ClientMonitor &client_monitor)
        : socket_(socket), client_monitor_(client_monitor), keep_alive_(false) {}

LockStub::~LockStub() {}

void LockStub::SetKeepAlive(const bool keep_alive) {
    keep_alive_ = keep_alive;
}

int LockStub::PHXEcho(const google::protobuf::StringValue &req,
                      google::protobuf::StringValue *resp) {
    phxrpc::HttpCaller caller(socket_, client_monitor_);
    caller.SetURI("/phxqueue_phxrpc.lock/PHXEcho", -1);
    caller.SetKeepAlive(keep_alive_);
    return caller.Call(req, resp);
}

int LockStub::GetLockInfo(const phxqueue::comm::proto::GetLockInfoRequest &req,
                          phxqueue::comm::proto::GetLockInfoResponse *resp) {
    phxrpc::HttpCaller caller(socket_, client_monitor_);
    caller.SetURI("/phxqueue_phxrpc.lock/GetLockInfo", 1);
    caller.SetKeepAlive(keep_alive_);
    return caller.Call(req, resp);
}

int LockStub::AcquireLock(const phxqueue::comm::proto::AcquireLockRequest &req,
                          phxqueue::comm::proto::AcquireLockResponse *resp) {
    phxrpc::HttpCaller caller(socket_, client_monitor_);
    caller.SetURI("/phxqueue_phxrpc.lock/AcquireLock", 2);
    caller.SetKeepAlive(keep_alive_);
    return caller.Call(req, resp);
}


//gzrd_Lib_CPP_Version_ID--start
#ifndef GZRD_SVN_ATTR
#define GZRD_SVN_ATTR "0"
#endif
static char gzrd_Lib_CPP_Version_ID[] __attribute__((used))="$HeadURL: http://scm-gy.tencent.com/gzrd/gzrd_mail_rep/phoenix_proj/trunk/phxqueue/phxqueue_phxrpc/src/lock/phxrpc_lock_stub.cpp $ $Id: phxrpc_lock_stub.cpp 2143928 2017-06-29 09:20:49Z walnuthe $ " GZRD_SVN_ATTR "__file__";
// gzrd_Lib_CPP_Version_ID--end

