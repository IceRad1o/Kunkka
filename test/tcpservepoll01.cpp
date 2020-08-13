#include <iostream>
#include <sys/epoll.h>
#include "unp/unp.h"

int setnonblocking(int fd)
{
    int old_flags = fcntl(fd, F_GETFL);
    int new_flags = old_flags|O_NONBLOCK;
    fcntl(fd, F_SETFL, new_flags);
    return old_flags;
}

void addfd(int epollfd, int fd, bool enable_et)
{
    epoll_event event;
}

void lt()
{

}

void et()
{

}

int main(int argc, char **agrv) {
    int listenfd;
    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);
    Bind(listenfd, (SA*)&servaddr, sizeof(servaddr));
    Listen(listenfd, LISTENQ);
}
