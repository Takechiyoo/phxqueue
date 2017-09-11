/* scheduler_service_impl.cpp

 Generated by phxrpc_pb2service from scheduler.proto

*/

#include "scheduler_service_impl.h"

#include "phxrpc/file.h"

#include "scheduler_server_config.h"


SchedulerServiceImpl::SchedulerServiceImpl(ServiceArgs_t &app_args)
    : args_(app_args), scheduler_(app_args.scheduler) {}

SchedulerServiceImpl::~SchedulerServiceImpl() {}

int SchedulerServiceImpl::PHXEcho(const google::protobuf::StringValue &req,
                                  google::protobuf::StringValue *resp) {
    resp->set_value(req.value());
    return 0;
}

int SchedulerServiceImpl::GetAddrScale(const phxqueue::comm::proto::GetAddrScaleRequest &req,
                                       phxqueue::comm::proto::GetAddrScaleResponse *resp) {
    int ret{static_cast<int>(scheduler_->GetAddrScale(req, *resp))};

    if (0 != ret) {
        QLErr("Scheduler GetAddrScale err %d", ret);
    }

    return ret;
}



//gzrd_Lib_CPP_Version_ID--start
#ifndef GZRD_SVN_ATTR
#define GZRD_SVN_ATTR "0"
#endif
static char gzrd_Lib_CPP_Version_ID[] __attribute__((used))="$HeadURL: http://scm-gy.tencent.com/gzrd/gzrd_mail_rep/phoenix_proj/trunk/phxqueue/phxqueue_phxrpc/src/scheduler/scheduler_service_impl.cpp $ $Id: scheduler_service_impl.cpp 2144319 2017-06-29 12:19:19Z walnuthe $ " GZRD_SVN_ATTR "__file__";
// gzrd_Lib_CPP_Version_ID--end

