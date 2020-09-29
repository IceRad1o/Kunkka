#include "EchoServer.h"
#include "CurrentThread.h"
const int MESSAGE_LENGTH=8;
EchoServer::EchoServer(EventLoop *pLoop)
    :_pLoop(pLoop),_pServer(pLoop),_timer(-1),_index(0)

{
    _pServer.setCallback(this);
}

void EchoServer::start() {
    _pServer.start();
    _threadpool.start(1);
}

void EchoServer::onConnection(TcpConnection *pCon)
{
    std::cout<<"onConnection"<<std::endl;
}

void EchoServer::onMessage(TcpConnection *pCon, Buffer *pBuf)
{
    // codec

    while(pBuf->readableBytes() > MESSAGE_LENGTH) {
        std::string message = pBuf->retrieveAsString(MESSAGE_LENGTH);
        Task task(this, message, pCon);
        _threadpool.addTask(task);
    }

    //std::string message = pBuf->retrieveAsString(MESSAGE_LENGTH);
    //Task task(this, message, pCon);
    //_threadpool.addTask(task);
}

void EchoServer::onWriteComplete(TcpConnection *pCon) {
    std::cout<< "onWriteComplete\n";
}

void EchoServer::run2(const std::string& str, void* tcp) {
    std::cout<< "fib(30) = "<<fib(3) << " Tid: "<< CurrentThread::tid();
    ((TcpConnection*)tcp)->send(str);
}

int EchoServer::fib(int n) {
    return (n==1 || n==2)?1:(fib(n-1)+fib(n-2));
}