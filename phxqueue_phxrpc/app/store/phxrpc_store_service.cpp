/* phxrpc_store_service.cpp

 Generated by phxrpc_pb2service from store.proto

 Please DO NOT edit unless you know exactly what you are doing.

*/

#include "phxrpc_store_service.h"

#include "phxrpc/file.h"

#include "store.pb.h"


StoreService::StoreService() {}

StoreService::~StoreService() {}

int StoreService::PHXEcho(const google::protobuf::StringValue &/* req */,
                          google::protobuf::StringValue */* resp */) {
    phxrpc::log(LOG_ERR, "ERROR: PHXEcho unimplemented");
    return -1;
}

int StoreService::Add(const phxqueue::comm::proto::AddRequest &/* req */,
                      phxqueue::comm::proto::AddResponse */* resp */) {
    phxrpc::log(LOG_ERR, "ERROR: Add unimplemented");
    return -1;
}

int StoreService::Get(const phxqueue::comm::proto::GetRequest &/* req */,
                      phxqueue::comm::proto::GetResponse */* resp */) {
    phxrpc::log(LOG_ERR, "ERROR: Get unimplemented");
    return -1;
}


//gzrd_Lib_CPP_Version_ID--start
#ifndef GZRD_SVN_ATTR
#define GZRD_SVN_ATTR "0"
#endif
static char gzrd_Lib_CPP_Version_ID[] __attribute__((used))="$HeadURL$ $Id$ " GZRD_SVN_ATTR "__file__";
// gzrd_Lib_CPP_Version_ID--end

