#ifndef RANET_IMUDUOUSER_H
#define RANET_IMUDUOUSER_H

#include <string>
#include "Declare.h"
#include "Buffer.h"

class IMuduoUser
{
public:
    virtual void onConnection(TcpConnection *pCon) = 0;
    virtual void onMessage(TcpConnection *pCon, Buffer *data) = 0;
    virtual void onWriteComplete(TcpConnection *pCon) = 0;
};

#endif //RANET_IMUDUOUSER_H
