#include <iostream>
//#include <sys/epoll.h>
#include "../unp/unp.h"



int setnonblocking(int fd)
{
    int old_flags = fcntl(fd, F_GETFL);
    int new_flags = old_flags|O_NONBLOCK;
    fcntl(fd, F_SETFL, new_flags);
    return old_flags;
}

int createAndListen()
{
    int optval=1;
    int listenfd;
    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));

    //setnonblocking(listenfd);
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);
    Bind(listenfd, (SA*)&servaddr, sizeof(servaddr));
    Listen(listenfd, LISTENQ);

    return listenfd;
}



void lt()
{

}

void et()
{

}

int main(int argc, char **agrv) {
    struct eopll_event ev, events[MAX_EVENTS];


}
