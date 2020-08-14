#ifndef RANET_CHANNEL_H
#define RANET_CHANNEL_H

#include "IChannelCallBack.h"

class Channel
{
public:
    Channel(int epfd, int sockfd);
    ~Channel() = default;
    void setCallBack(IChannelCallBack* callBack);
    void handleEvent();
    void setRevents(int revents);
    int getSockfd();
    void enableReading();
private:
    void update();
    int _epollfd;
    int _sockfd;
    int _events;
    int _revents;
    IChannelCallBack* _callback;
};

#endif //RANET_CHANNEL_H
