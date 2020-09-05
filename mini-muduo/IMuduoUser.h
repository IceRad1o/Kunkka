#ifndef RANET_IMUDUOUSER_H
#define RANET_IMUDUOUSER_H

#include <string>
#include "Declare.h"

class IMuduoUser
{
public:
    virtual void onConnection(TcpConnection *pCon) = 0;
    virtual void onMessage(TcpConnection *pCon, const std::string& data) = 0;
};

#endif //RANET_IMUDUOUSER_H
