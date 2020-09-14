#include <iostream>
#include <sys/eventfd.h>
#include <unistd.h>
#include "EventLoop.h"
#include <vector>
#include "Epoll.h"
#include "Channel.h"
#include "Timestamp.h"
#include "TimerQueue.h"

EventLoop::EventLoop()
    :_quit(false)
    ,_poller(new Epoll()) // memory leak;
{
    _eventfd = createEventfd();
    _wakeupChannel = new Channel(this, _eventfd);
    _wakeupChannel->setCallBack(this);
    _wakeupChannel->enableReading();
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

void EventLoop::queueLoop(IRun *pRun, void* param) {
    Runner r(pRun, param);
    _pendingFunctors.push_back(r);
    wakeup();
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
    std::vector<Runner> tempRuns;
    tempRuns.swap(_pendingFunctors); // avoid deadlock
    for(auto it=tempRuns.begin();it != tempRuns.end(); ++it){
        (*it).doRun();
    }
}

long EventLoop::runAt(Timestamp when, IRun *pRun) {
    return (long)(_pTimerQueue->addTimer(pRun, when, 0.0));
}

long EventLoop::runAfter(double delay, IRun *pRun) {
    return (long)_pTimerQueue->addTimer(pRun, Timestamp::nowAfter(delay), 0.0);
}

long EventLoop::runEvery(double interval, IRun *pRun) {
    return (long)_pTimerQueue->addTimer(pRun, Timestamp::nowAfter(interval), interval);
}

void EventLoop::cancelTimer(int timerId) {
    _pTimerQueue->cancelTimer(timerId);
}
