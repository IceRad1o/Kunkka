#include "EchoServer.h"

EchoServer::EchoServer(EventLoop *pLoop)
    :_pLoop(pLoop),_pServer(pLoop)

{
    _pServer.setCallback(this);
}

void EchoServer::start() {
    _pServer.start();
}

void EchoServer::onConnection(TcpConnection *pCon)
{
    std::cout<<"onConnection"<<std::endl;
}

void EchoServer::onMessage(TcpConnection *pCon, const std::string &data)
{
    std::cout<<"onMessage"<<std::endl;
    pCon->send(data);
}
