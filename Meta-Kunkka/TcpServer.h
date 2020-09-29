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
#include <map>
#include <vector>
#include "Acceptor.h"
#include "IMuduoUser.h"

class TcpServer : public IAcceptorCallBack
{
public:
    TcpServer(EventLoop *loop);
    ~TcpServer() = default;
    void start();
    void setCallback(IMuduoUser* pUser);
    virtual void newConnection(int sockfd);
private:
    struct epoll_event _events[MAX_EVENTS];
    std::map<int, TcpConnection*> _connections;
    Acceptor *_pAcceptor;
    EventLoop *_loop;
    IMuduoUser *_pUser;
};

#endif //RANET_TCPSERVER_H
