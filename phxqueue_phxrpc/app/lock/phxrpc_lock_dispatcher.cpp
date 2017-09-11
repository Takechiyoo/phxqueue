/*phxrpc_lock_dispatcher.h

 Generated by phxrpc_pb2service from lock.proto

 Please DO NOT edit unless you know exactly what you are doing.

*/

#include "phxrpc_lock_dispatcher.h"

#include <errno.h>

#include "phxrpc/file.h"
#include "phxrpc/http.h"

#include "lock.pb.h"
#include "phxrpc_lock_service.h"


LockDispatcher::LockDispatcher(LockService &service, phxrpc::DispatcherArgs_t *dispatcher_args)
        : service_(service), dispatcher_args_(dispatcher_args) {}

LockDispatcher::~LockDispatcher() {}

const phxrpc::HttpDispatcher<LockDispatcher>::URIFuncMap &LockDispatcher::GetURIFuncMap() {
    static phxrpc::HttpDispatcher< LockDispatcher >::URIFuncMap uri_func_map = {
        {"/phxqueue_phxrpc.lock/PHXEcho", &LockDispatcher::PHXEcho},
        {"/phxqueue_phxrpc.lock/GetLockInfo", &LockDispatcher::GetLockInfo},
        {"/phxqueue_phxrpc.lock/AcquireLock", &LockDispatcher::AcquireLock}};
    return uri_func_map;
}

int LockDispatcher::PHXEcho(const phxrpc::HttpRequest &request, phxrpc::HttpResponse *response) {
    dispatcher_args_->server_monitor->SvrCall(-1, "PHXEcho", 1);

    int ret{0};

    google::protobuf::StringValue req;
    google::protobuf::StringValue resp;

    //unpack request
    {
        if (!req.ParseFromString(request.GetContent())) {
            phxrpc::log(LOG_ERR, "ERROR: FromBuffer fail size %zu ip %s",
                        request.GetContent().size(), request.GetClientIP());
            return -1 *EINVAL;
        }
    }

    //logic process
    {
        if (0 == ret) ret = service_.PHXEcho(req, &resp);
    }

    //pack response
    {
        if (!resp.SerializeToString(&(response->GetContent()))) {
            phxrpc::log(LOG_ERR, "ERROR: ToBuffer fail ip %s", request.GetClientIP());
            return -1 *ENOMEM;
        }
    }

    phxrpc::log(LOG_DEBUG, "RETN: PHXEcho = %d", ret);

    return ret;
}

int LockDispatcher::GetLockInfo(const phxrpc::HttpRequest &request, phxrpc::HttpResponse *response) {
    dispatcher_args_->server_monitor->SvrCall(1, "GetLockInfo", 1);

    int ret = 0;

    phxqueue::comm::proto::GetLockInfoRequest req;
    phxqueue::comm::proto::GetLockInfoResponse resp;

    //unpack request
    {
        if (!req.ParseFromString(request.GetContent())) {
            phxrpc::log(LOG_ERR, "ERROR: FromBuffer fail size %zu ip %s",
                request.GetContent().size(), request.GetClientIP());
            return -1 *EINVAL;
        }
    }

    //logic process
    {
        if (0 == ret) ret = service_.GetLockInfo(req, &resp);
    }

    //pack response
    {
        if (!resp.SerializeToString(&(response->GetContent()))) {
            phxrpc::log(LOG_ERR, "ERROR: ToBuffer fail ip %s", request.GetClientIP());
            return -1 *ENOMEM;
        }
    }

    phxrpc::log(LOG_DEBUG, "RETN: GetLockInfo = %d", ret);

    return ret;
}

int LockDispatcher::AcquireLock(const phxrpc::HttpRequest &request, phxrpc::HttpResponse *response) {
    dispatcher_args_->server_monitor->SvrCall(2, "AcquireLock", 1);

    int ret = 0;

    phxqueue::comm::proto::AcquireLockRequest req;
    phxqueue::comm::proto::AcquireLockResponse resp;

    //unpack request
    {
        if (!req.ParseFromString(request.GetContent())) {
            phxrpc::log(LOG_ERR, "ERROR: FromBuffer fail size %zu ip %s",
                request.GetContent().size(), request.GetClientIP());
            return -1 *EINVAL;
        }
    }

    //logic process
    {
        if (0 == ret) ret = service_.AcquireLock(req, &resp);
    }

    //pack response
    {
        if (!resp.SerializeToString(&(response->GetContent()))) {
            phxrpc::log(LOG_ERR, "ERROR: ToBuffer fail ip %s", request.GetClientIP());
            return -1 *ENOMEM;
        }
    }

    phxrpc::log(LOG_DEBUG, "RETN: AcquireLock = %d", ret);

    return ret;
}


//gzrd_Lib_CPP_Version_ID--start
#ifndef GZRD_SVN_ATTR
#define GZRD_SVN_ATTR "0"
#endif
static char gzrd_Lib_CPP_Version_ID[] __attribute__((used))="$HeadURL: http://scm-gy.tencent.com/gzrd/gzrd_mail_rep/phoenix_proj/trunk/phxqueue/phxqueue_phxrpc/src/lock/phxrpc_lock_dispatcher.cpp $ $Id: phxrpc_lock_dispatcher.cpp 2143928 2017-06-29 09:20:49Z walnuthe $ " GZRD_SVN_ATTR "__file__";
// gzrd_Lib_CPP_Version_ID--end

