#include "EventLoop.h"
#include <vector>
#include "Epoll.h"
#include "Channel.h"

EventLoop::EventLoop()
    :_quit(false)
    ,_poller(new Epoll()) // memory leak;
{}

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