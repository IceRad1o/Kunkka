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
#include "Declare.h"
#include "Define.h"

#include <map>
#include <vector>

class TcpServer : public IChannelCallBack
{
public:
    TcpServer();
    ~TcpServer() = default;
    void start();
    virtual void OnIn(int sockfd);
private:
    int createAndListen();
    int setnonblocking(int);

    void update(Channel* pChannel, int op);
    int _epfd;
    int _listenfd;
    struct epoll_event _events[MAX_EVENTS];
    const int SERV_PORT = 9877;
    std::map<int, Channel*> _channels;
};

#endif //RANET_TCPSERVER_H
