#include "TcpServer.h"

TcpServer::TcpServer(EventLoop *loop):_loop(loop),_pAcceptor(NULL)
{}

void TcpServer::newConnection(int sockfd)
{
    TcpConnection *tcp = new TcpConnection(_loop, sockfd);
    _connections[sockfd] = tcp;
}

void TcpServer::start()
{
    _pAcceptor = new Acceptor(_loop);
    _pAcceptor->setCallBack(this);
    _pAcceptor->start();
}
