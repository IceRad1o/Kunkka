#ifndef RANET_ECHOSERVER_H
#define RANET_ECHOSERVER_H

#include "Timer.h"
#include "IMuduoUser.h"
#include "TcpServer.h"

class EchoServer: public IMuduoUser, public IRun
{
public:
    EchoServer(EventLoop *pLoop);
    ~EchoServer() = default;
    void start();
    void onConnection(TcpConnection *pCon) override;
    void onMessage(TcpConnection *pCon, Buffer *pBuf) override;
    void onWriteComplete(TcpConnection *pCon) override;

    void run(void* param) override;
private:
    EventLoop *_pLoop;
    TcpServer _pServer;
    //long _timer;
    long _timer;
    int _index;
};

#endif //RANET_ECHOSERVER_H
