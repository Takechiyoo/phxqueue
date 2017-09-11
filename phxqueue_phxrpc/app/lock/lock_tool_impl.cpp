/* lock_tool_impl.cpp

 Generated by phxrpc_pb2tool from lock.proto

*/

#include "phxrpc/file.h"

#include "lock_client.h"
#include "lock_tool_impl.h"


using namespace phxrpc;


LockToolImpl::LockToolImpl() {}

LockToolImpl::~LockToolImpl() {}

int LockToolImpl::PHXEcho(phxrpc::OptMap &opt_map) {
    google::protobuf::StringValue req;
    google::protobuf::StringValue resp;

    if (NULL == opt_map.Get('s')) return -1;

    req.set_value(opt_map.Get('s'));

    LockClient client;
    int ret = client.PHXEcho(req, &resp);
    printf("%s return %d\n", __func__, ret);
    printf("resp: {\n%s}\n", resp.DebugString().c_str());

    return ret;
}

int LockToolImpl::GetLockInfo(phxrpc::OptMap &opt_map) {
    phxqueue::comm::proto::GetLockInfoRequest req;
    phxqueue::comm::proto::GetLockInfoResponse resp;

    //TODO: fill req from opt_map


    LockClient client;
    int ret = client.GetLockInfo(req, &resp);
    printf("%s return %d\n", __func__, ret);
    printf("resp: {\n%s}\n", resp.DebugString().c_str());

    return ret;
}

int LockToolImpl::AcquireLock(phxrpc::OptMap &opt_map) {
    phxqueue::comm::proto::AcquireLockRequest req;
    phxqueue::comm::proto::AcquireLockResponse resp;

    //TODO: fill req from opt_map


    LockClient client;
    int ret = client.AcquireLock(req, &resp);
    printf("%s return %d\n", __func__, ret);
    printf("resp: {\n%s}\n", resp.DebugString().c_str());

    return ret;
}

