#ifndef RANET_TCPCONNECTION_H
#define RANET_TCPCONNECTION_H
#include "Define.h"
#include "IChannelCallBack.h"
#include <string.h>
#include <unistd.h>
#include <iostream>
#include "Channel.h"
#include "EventLoop.h"

class TcpConnection : public IChannelCallBack
{
public:
    TcpConnection(EventLoop *loop, int sockfd);
    ~TcpConnection() = default;
    virtual void OnIn(int sockfd);

private:
    int _sockfd;
    Channel *_pChannel;
    EventLoop *_loop;
};


#endif //RANET_TCPCONNECTION_H
