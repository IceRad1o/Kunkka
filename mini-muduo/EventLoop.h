#ifndef RANET_EVENTLOOP_H
#define RANET_EVENTLOOP_H

#include <vector>
#include "IChannelCallBack.h"
#include "Declare.h"
#include "IRun.h"

class EventLoop : public IChannelCallBack
{
public:
    EventLoop();
    ~EventLoop() = default;
    void loop();
    void update(Channel *channel);
    void queueLoop(IRun *pRun);

    virtual void handleRead();
    virtual void handleWrite();
private:
    void wakeup();
    int createEventfd();
    void doPendingFunctors();

    bool _quit;
    Epoll* _poller;
    int _eventfd;
    Channel *_wakeupChannel;
    std::vector<IRun*> _pendingFunctors;
};

#endif //RANET_EVENTLOOP_H
