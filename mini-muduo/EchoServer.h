#ifndef RANET_ECHOSERVER_H
#define RANET_ECHOSERVER_H

#include "IMuduoUser.h"
#include "TcpServer.h"

class EchoServer: public IMuduoUser
{
public:
    EchoServer(EventLoop *pLoop);
    ~EchoServer() = default;
    void start();
    virtual void onConnection(TcpConnection *pCon);
    virtual void onMessage(TcpConnection *pCon, const std::string& data);
private:
    EventLoop *_pLoop;
    TcpServer _pServer;
};

#endif //RANET_ECHOSERVER_H
