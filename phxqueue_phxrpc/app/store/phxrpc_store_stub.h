/* phxrpc_store_stub.h

 Generated by phxrpc_pb2client from store.proto

 Please DO NOT edit unless you know exactly what you are doing.

*/

#pragma once

#include "store.pb.h"


namespace phxrpc {


class BaseTcpStream;
class ClientMonitor;


}


class StoreStub {
  public:
    StoreStub(phxrpc::BaseTcpStream &socket, phxrpc::ClientMonitor &client_monitor);
    ~StoreStub();

    void SetKeepAlive(const bool keep_alive);

    int PHXEcho(const google::protobuf::StringValue &req,
                google::protobuf::StringValue *resp);

    int Add(const phxqueue::comm::proto::AddRequest &req,
            phxqueue::comm::proto::AddResponse *resp);

    int Get(const phxqueue::comm::proto::GetRequest &req,
            phxqueue::comm::proto::GetResponse *resp);

  private:
    phxrpc::BaseTcpStream &socket_;
    phxrpc::ClientMonitor &client_monitor_;
    bool keep_alive_;
};

