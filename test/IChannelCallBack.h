#ifndef RANET_ICHANNELCALLBACK_H
#define RANET_ICHANNELCALLBACK_H

class IChannelCallBack
{
public:
    void virtual OnIn(int sockfd){}
};
#endif //RANET_ICHANNELCALLBACK_H
