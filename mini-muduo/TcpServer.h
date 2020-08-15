#ifndef RANET_TCPSERVER_H
#define RANET_TCPSERVER_H

#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <string.h>
#include <iostream>
#include <unistd.h>

#include "IChannelCallBack.h"
#include "IAcceptorCallBack.h"
#include "Channel.h"
#include "TcpConnection.h"
#include "Acceptor.h"
#include <map>
#include <vector>

class TcpServer : public IAcceptorCallBack
{
public:
    TcpServer();
    ~TcpServer() = default;
    void start();
    virtual void newConnection(int sockfd);
private:
    void update(Channel* pChannel, int op);
    int _epfd;
    struct epoll_event _events[MAX_EVENTS];
    std::map<int, TcpConnection*> _connections;
    Acceptor *_pAcceptor;
};

#endif //RANET_TCPSERVER_H
