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
    Acceptor(int epfd);
    ~Acceptor() = default;

    void virtual OnIn(int socket);
    void setCallBack(IAcceptorCallBack* pCallBack);
    void start();
private:
    int createAndListen();
    int _epfd;
    int _listenfd;
    Channel *_pAcceptChannel;
    IAcceptorCallBack* _pCallBack;
};

#endif //RANET_ACCEPTOR_H
