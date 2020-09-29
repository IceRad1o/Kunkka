#ifndef RANET_TCPCONNECTION_H
#define RANET_TCPCONNECTION_H
#include "Declare.h"
#include "Define.h"
#include "IChannelCallBack.h"
#include <string.h>
#include <unistd.h>
#include <iostream>
#include "Channel.h"
#include "EventLoop.h"
#include "IMuduoUser.h"
#include "Buffer.h"
#include "IRun.h"

class TcpConnection : public IChannelCallBack, public IRun0,public IRun2
{
public:
    TcpConnection(EventLoop *loop, int sockfd);
    ~TcpConnection() = default;

    void send(const std::string& message);
    void sendInLoop(const std::string& message);
    void connectedEstablished();
    void setUser(IMuduoUser *pUser);

    void setCallback(IAcceptorCallBack *pCallback);
    void handleRead() override;
    void handleWrite() override;
    virtual void run0();
    virtual void run2(const std::string& message, void* param);
private:
    int _sockfd;
    Channel *_pChannel;
    EventLoop *_loop;
    IMuduoUser *_pUser;
    Buffer _inBuf;
    Buffer _outBuf;
};


#endif //RANET_TCPCONNECTION_H
