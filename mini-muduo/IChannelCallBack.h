#ifndef RANET_ICHANNELCALLBACK_H
#define RANET_ICHANNELCALLBACK_H

class IChannelCallBack
{
public:
    virtual void OnIn(int sockfd) = 0;
};
#endif //RANET_ICHANNELCALLBACK_H
