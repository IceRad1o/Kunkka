#ifndef RANET_TCPCONNECTION_H
#define RANET_TCPCONNECTION_H
#include "Define.h"
#include "IChannelCallBack.h"
#include <string.h>
#include <unistd.h>
#include <iostream>
#include "Channel.h"
#include "EventLoop.h"
#include "IMuduoUser.h"

class TcpConnection : public IChannelCallBack
{
public:
    TcpConnection(EventLoop *loop, int sockfd);
    ~TcpConnection() = default;
    virtual void OnIn(int sockfd);

    void send(const std::string& message);
    void connectedEstablished();
    void setUser(IMuduoUser *pUser);
    void setCallback(IAcceptorCallBack *pCallback);

private:
    int _sockfd;
    Channel *_pChannel;
    EventLoop *_loop;
    IMuduoUser *_pUser;
};


#endif //RANET_TCPCONNECTION_H
