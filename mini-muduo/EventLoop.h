#ifndef RANET_EVENTLOOP_H
#define RANET_EVENTLOOP_H

#include <vector>
#include "IChannelCallBack.h"
#include "Declare.h"
#include "Task.h"
#include "Mutex.h"

class EventLoop : public IChannelCallBack
{
public:
    EventLoop();
    ~EventLoop() = default;
    void loop();
    void update(Channel *channel);
    void queueLoop(Task& task);
    void runInLoop(Task& task);
    bool isInLoopThread();
    // Timer
    int runAt(Timestamp when, IRun0* pRun);
    int runAfter(double delay, IRun0* pRun);
    int runEvery(double interval, IRun0* pRun);
    void cancelTimer(int timerId);

    virtual void handleRead();
    virtual void handleWrite();
private:
    void wakeup();
    int createEventfd();
    void doPendingFunctors();

    bool _quit;
    bool _callingPendingFunctors;
    Epoll* _poller;
    int _eventfd;
    const pid_t _threadId;
    Channel *_pEventfdChannel;
    MutexLock _mutex;
    std::vector<Task> _pendingFunctors;
    TimerQueue* _pTimerQueue;
};

#endif //RANET_EVENTLOOP_H
