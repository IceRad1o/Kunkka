#ifndef RANET_EVENTLOOP_H
#define RANET_EVENTLOOP_H

#include "Declare.h"

class EventLoop
{
public:
    EventLoop();
    ~EventLoop() = default;
    void loop();
    void update(Channel *channel);
private:
    bool _quit;
    Epoll* _poller;
};

#endif //RANET_EVENTLOOP_H
