#include <iostream>
#include <sys/epoll.h>
#include "Channel.h"
#include "IChannelCallBack.h"

Channel::Channel(int epfd, int sockfd)
    :_epollfd(epfd)
    ,_sockfd(sockfd)
    ,_events(0)
    ,_revents(0)
    ,_callback(NULL){

}

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

void Channel::enableReading() {
    _events |= EPOLLIN;
    update();
}

void Channel::update() {
    struct epoll_event ev;
    ev.data.ptr = this;
    ev.events = _events;
    epoll_ctl(_epollfd, EPOLL_CTL_ADD, _sockfd, &ev);
}

