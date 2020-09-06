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
    void onConnection(TcpConnection *pCon) override;
    void onMessage(TcpConnection *pCon, Buffer *pBuf) override;
    void onWriteComplete(TcpConnection *pCon) override;
private:
    EventLoop *_pLoop;
    TcpServer _pServer;
};

#endif //RANET_ECHOSERVER_H
