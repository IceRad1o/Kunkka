#include <iostream>
#include <sys/epoll.h>
#include "Channel.h"
#include "IChannelCallBack.h"

Channel::Channel(EventLoop *loop, int sockfd)
    :_sockfd(sockfd)
    ,_events(0)
    ,_revents(0)
    ,_callback(NULL)
    ,_loop(loop){}

void Channel::setCallBack(IChannelCallBack *callBack) {
    _callback = callBack;
}

void Channel::setRevents(int revents) {
    _revents = revents;
}

void Channel::handleEvent() {
    if(_revents & EPOLLIN)
        _callback->OnIn(_sockfd);
}

int Channel::getSockfd() {
    return _sockfd;
}

int Channel::getEvents(){
    return _events;
}

void Channel::enableReading() {
    _events |= EPOLLIN;
    update();
}

void Channel::update() {
    _loop->update(this);
}

