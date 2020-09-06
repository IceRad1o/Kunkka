#include <iostream>
#include <sys/eventfd.h>
#include <unistd.h>
#include "EventLoop.h"
#include <vector>
#include "Epoll.h"
#include "Channel.h"

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
    }
}

void EventLoop::update(Channel *channel)
{
    _poller->update(channel);
}

void EventLoop::queueLoop(IRun *pRun) {
    _pendingFunctors.push_back(pRun);
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
    std::vector<IRun*> tempRuns;
    tempRuns.swap(_pendingFunctors); // avoid deadlock
    for(auto it=tempRuns.begin();it != tempRuns.end(); ++it){
        (*it)->run();
    }
}
