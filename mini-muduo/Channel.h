#ifndef RANET_CHANNEL_H
#define RANET_CHANNEL_H

#include "IChannelCallBack.h"
#include "EventLoop.h"
class Channel
{
public:
    Channel(EventLoop *loop, int sockfd);
    ~Channel() = default;
    void setCallBack(IChannelCallBack* callBack);
    void handleEvent();
    void setRevents(int revents);
    void enableReading();
    int getSockfd();
    int getEvents();
private:
    void update();
    int _sockfd;
    int _events;
    int _revents;
    IChannelCallBack* _callback;
    EventLoop *_loop;
};

#endif //RANET_CHANNEL_H
