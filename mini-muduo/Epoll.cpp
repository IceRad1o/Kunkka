//
// Created by jialeiwang on 8/15/20.
//

#include "Epoll.h"
#include <iostream>
#include "Channel.h"

const int kNew = -1;
const int kAdded = 1;

Epoll::Epoll()
{
    _epfd = ::epoll_create(1);
    if(_epfd <= 0){
        std::cout<<"epoll_create error"<<std::endl;
    }
}

void Epoll::poll(std::vector<Channel *> *pChannels)
{
    int fds = ::epoll_wait(_epfd, _events, MAX_EVENTS, -1);
    if(fds<0){
        std::cout<<"epoll wait error"<<errno<<std::endl;
        return;
    }
    for(int i=0; i<fds; i++)
    {
        Channel *pChannel = static_cast<Channel*>(_events[i].data.ptr);
        pChannel->setRevents(_events[i].events);
        pChannels->push_back(pChannel);
    }
}

void Epoll::update(Channel *channel)
{
    int index = channel->getIndex();
    if(index == kNew){
        struct epoll_event ev;
        ev.data.ptr = channel;
        ev.events = channel->getEvents();
        int fd = channel->getSockfd();
        channel->setIndex(kAdded);
        ::epoll_ctl(_epfd, EPOLL_CTL_ADD, fd, &ev);
    }
    else{
        struct epoll_event ev;
        ev.data.ptr = channel;
        ev.events = channel->getEvents();
        int fd = channel->getSockfd();
        ::epoll_ctl(_epfd, EPOLL_CTL_MOD, fd, &ev);
    }
}