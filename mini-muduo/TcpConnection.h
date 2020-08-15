#ifndef RANET_TCPCONNECTION_H
#define RANET_TCPCONNECTION_H

#include "IChannelCallBack.h"
#include "Define.h"
#include <string.h>
#include <unistd.h>
#include <iostream>
#include "Channel.h"

class TcpConnection : public IChannelCallBack
{
public:
    TcpConnection(int epfd, int sockfd);
    ~TcpConnection() = default;
    virtual void OnIn(int sockfd);

private:
    int _epfd;
    int _sockfd;
    Channel *_pChannel;
};


#endif //RANET_TCPCONNECTION_H
