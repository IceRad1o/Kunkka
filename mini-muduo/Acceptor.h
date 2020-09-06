#ifndef RANET_ACCEPTOR_H
#define RANET_ACCEPTOR_H

#include "Define.h"
#include "Declare.h"
#include "Channel.h"
#include "IChannelCallBack.h"
#include "IAcceptorCallBack.h"
#include "Declare.h"
#include "Define.h"
#include "TcpConnection.h"
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <arpa/inet.h>

class Acceptor : public IChannelCallBack
{
public:
    Acceptor(EventLoop *loop);
    ~Acceptor() = default;

    virtual void handleRead();
    virtual void handleWrite();
    void setCallBack(IAcceptorCallBack* pCallBack);
    void start();
private:
    int createAndListen();
    int _listenfd;
    Channel *_pAcceptChannel;
    IAcceptorCallBack* _pCallBack;
    EventLoop *_loop;
};

#endif //RANET_ACCEPTOR_H
