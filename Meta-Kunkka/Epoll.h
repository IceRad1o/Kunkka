#ifndef RANET_EPOLL_H
#define RANET_EPOLL_H

#include <sys/epoll.h>
#include <vector>
#include "Declare.h"
#include "Define.h"

class Epoll
{
public:
    Epoll();
    ~Epoll() = default;
    void poll(std::vector<Channel*> *pChannels);
    void update(Channel *channel);
private:
    int _epfd;
    struct epoll_event _events[MAX_EVENTS];
};

#endif //RANET_EPOLL_H
