#ifndef RANET_EVENTLOOP_H
#define RANET_EVENTLOOP_H

#include <vector>
#include "IChannelCallBack.h"
#include "Declare.h"
#include "IRun.h"

class EventLoop : public IChannelCallBack
{
public:
    class Runner
    {
    public:
        Runner(IRun* r, void* p):_pRun(r),_param(p)
        {}
        void doRun()
        {
            _pRun->run(_param);
        }
    private:
        IRun* _pRun;
        void* _param;
    };

    EventLoop();
    ~EventLoop() = default;
    void loop();
    void update(Channel *channel);
    void queueLoop(IRun *pRun, void* param);

    // Timer
    long runAt(Timestamp when, IRun* pRun);
    long runAfter(double delay, IRun* pRun);
    long runEvery(double interval, IRun* pRun);
    void cancelTimer(int timerId);

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
    std::vector<Runner> _pendingFunctors;
    TimerQueue* _pTimerQueue;
};

#endif //RANET_EVENTLOOP_H
