#ifndef RANET_ECHOSERVER_H
#define RANET_ECHOSERVER_H

#include "IMuduoUser.h"
#include "TcpServer.h"
#include "IRun.h"
#include "ThreadPool.h"

class EchoServer: public IMuduoUser, public IRun2
{
public:
    EchoServer(EventLoop *pLoop);
    ~EchoServer() = default;
    void start();
    void onConnection(TcpConnection *pCon) override;
    void onMessage(TcpConnection *pCon, Buffer *pBuf) override;
    void onWriteComplete(TcpConnection *pCon) override;

    virtual void run2(const std::string& message, void* tcp);
private:
    int fib(int n);
    EventLoop *_pLoop;
    TcpServer _pServer;
    int _timer;
    int _index;
    ThreadPool _threadpool;
};

#endif //RANET_ECHOSERVER_H
