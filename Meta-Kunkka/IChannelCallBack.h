#ifndef RANET_ICHANNELCALLBACK_H
#define RANET_ICHANNELCALLBACK_H

class IChannelCallBack
{
public:
    virtual void handleRead() = 0;
    virtual void handleWrite() = 0;
};
#endif //RANET_ICHANNELCALLBACK_H
