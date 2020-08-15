#ifndef RANET_DEFINE_H
#define RANET_DEFINE_H

#include <fcntl.h>

#define MAXLINE 100
#define MAX_EVENTS 500
#define LISTENQ 5
#define SERV_PORT 9877
#define SA struct sockaddr

int setnonblocking(int fd);

#endif //RANET_DEFINE_H
