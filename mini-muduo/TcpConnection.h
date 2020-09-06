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
#include "Buffer.h"

class TcpConnection : public IChannelCallBack, public IRun
{
public:
    TcpConnection(EventLoop *loop, int sockfd);
    ~TcpConnection() = default;

    void send(const std::string& message);
    void connectedEstablished();
    void setUser(IMuduoUser *pUser);
    void setCallback(IAcceptorCallBack *pCallback);
    void handleRead() override;
    void handleWrite() override;
    void run() override;
private:
    int _sockfd;
    Channel *_pChannel;
    EventLoop *_loop;
    IMuduoUser *_pUser;
    Buffer _inBuf;
    Buffer _outBuf;
};


#endif //RANET_TCPCONNECTION_H
