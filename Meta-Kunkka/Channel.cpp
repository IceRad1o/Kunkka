#include <iostream>
#include <sys/epoll.h>
#include "Channel.h"
#include "IChannelCallBack.h"

Channel::Channel(EventLoop *loop, int sockfd)
    :_sockfd(sockfd)
    ,_events(0)
    ,_revents(0)
    ,_index(-1)
    ,_callback(NULL)
    ,_loop(loop){}

void Channel::setCallBack(IChannelCallBack *callBack) {
    _callback = callBack;
}

void Channel::setRevents(int revents) {
    _revents = revents;
}

void Channel::setIndex(int index) {
    _index = index;
}
void Channel::handleEvent() {
    if(_revents & EPOLLIN)
        _callback->handleRead();
    if(_revents & EPOLLOUT)
        _callback->handleWrite();
}

void Channel::enableReading() {
    _events |= EPOLLIN;
    update();
}

void Channel::enableWriting() {
    _events |= EPOLLOUT;
    update();
}

void Channel::disableWriting() {
    _events &= ~EPOLLOUT;
    update();
}

bool Channel::isWriting() {
    return _events & EPOLLOUT;
}

void Channel::update() {
    _loop->update(this);
}

int Channel::getSockfd() {
    return _sockfd;
}

int Channel::getEvents(){
    return _events;
}

int Channel::getIndex() {
    return _index;
}