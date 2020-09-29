#include <iostream>
#include <sys/eventfd.h>
#include <unistd.h>
#include "EventLoop.h"
#include <vector>
#include "Epoll.h"
#include "Channel.h"
#include "Timestamp.h"
#include "TimerQueue.h"
#include "CurrentThread.h"

EventLoop::EventLoop()
    :_quit(false)
    ,_poller(new Epoll()) // memory leak;
    ,_callingPendingFunctors(false)
    ,_threadId(CurrentThread::tid())
    ,_pTimerQueue(new TimerQueue(this))
{
    _eventfd = createEventfd();
    _pEventfdChannel = new Channel(this, _eventfd);
    _pEventfdChannel->setCallBack(this);
    _pEventfdChannel->enableReading();
}

void EventLoop::loop()
{
    while(!_quit){
        std::vector<Channel*> channels;
        _poller->poll(&channels);

        std::vector<Channel*>::iterator it;
        for(it=channels.begin(); it!=channels.end(); ++it)
        {
            (*it)->handleEvent();
        }
        doPendingFunctors();
    }
}

void EventLoop::update(Channel *channel)
{
    _poller->update(channel);
}

void EventLoop::queueLoop(Task& task) {
    {
        MutexLockGuard guard(_mutex);
        _pendingFunctors.push_back(task);
    }
    if(!isInLoopThread() || _callingPendingFunctors){ //?
        wakeup();
    }
}

void EventLoop::runInLoop(Task &task) {
    if(isInLoopThread()){
        task.doTask();
    }
    else{
        queueLoop(task);
    }
}

void EventLoop::handleRead() {
    uint64_t one = 1;
    ssize_t n = ::read(_eventfd, &one, sizeof one);
    if(n != sizeof(one)){
        std::cout<<"Eventloop::handleRead() reads " << n << "bytes\n";
    }
}

void EventLoop::handleWrite() {
}

void EventLoop::wakeup() {
    uint64_t one = 1;
    ssize_t n = ::write(_eventfd, &one, sizeof one);
    if(n != sizeof(one)){
        std::cout<<"Eventloop::handleRead() writes " << n << "bytes\n";
    }
}

int EventLoop::createEventfd() {
    int evtfd = ::eventfd(0, EFD_NONBLOCK | EFD_CLOEXEC);
    if(evtfd<0){
        std::cout<<" Failed in eventfd" << std::endl;
    }
    return evtfd;
}

void EventLoop::doPendingFunctors() {
    std::vector<Task> tempRuns;
    _callingPendingFunctors = true;
    {
        MutexLockGuard guard(_mutex);
        tempRuns.swap(_pendingFunctors);
    }
    for(auto it = tempRuns.begin(); it!=tempRuns.end();it++)
    {
        it->doTask();
    }
}

int EventLoop::runAt(Timestamp when, IRun0 *pRun) {
    return _pTimerQueue->addTimer(pRun, when, 0.0);
}

int EventLoop::runAfter(double delay, IRun0 *pRun) {
    return _pTimerQueue->addTimer(pRun, Timestamp::nowAfter(delay), 0.0);
}

int EventLoop::runEvery(double interval, IRun0 *pRun) {
    return _pTimerQueue->addTimer(pRun, Timestamp::nowAfter(interval), interval);
}

void EventLoop::cancelTimer(int timerId) {
    _pTimerQueue->cancelTimer(timerId);
}

bool EventLoop::isInLoopThread() {
    return _threadId == CurrentThread::tid();
}
