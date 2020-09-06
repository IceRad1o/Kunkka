#include "TcpServer.h"
#include "Acceptor.h"

TcpServer::TcpServer(EventLoop *loop):_loop(loop),_pAcceptor(NULL),_pUser(NULL)
{}

void TcpServer::newConnection(int sockfd)
{
    TcpConnection *tcp = new TcpConnection(_loop, sockfd);
    _connections[sockfd] = tcp;
    tcp->setUser(_pUser);
    tcp->connectedEstablished();
}

void TcpServer::start()
{
    _pAcceptor = new Acceptor(_loop);
    _pAcceptor->setCallBack(this);
    _pAcceptor->start();
}

void TcpServer::setCallback(IMuduoUser *user)
{
    _pUser = user;
}
