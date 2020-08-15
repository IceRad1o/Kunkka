#ifndef RANET_IACCEPTORCALLBACK_H
#define RANET_IACCEPTORCALLBACK_H

class IAcceptorCallBack
{
public:
    virtual void newConnection(int sockfd){};
};

#endif //RANET_IACCEPTORCALLBACK_H
