#include <iostream>
#include <sys/epoll.h>
#include "../unp/unp.h"

/* Version01 just a echo server example using epoll, can test with tcpcli01 echo */

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

int main(int argc, char **agrv) {
    int epfd;
    int listenfd, connfd, sockfd;
    int readlen;
    char line[MAXLINE];
    struct sockaddr_in cliaddr;
    struct epoll_event ev, events[MAX_EVENTS];
    socklen_t clilen = sizeof(cliaddr);

    if( (epfd = epoll_create(1))<0){
        std::cout<<"epoll_create error"<<std::endl;
    }
    listenfd = createAndListen();
    ev.data.fd = listenfd;
    ev.events = EPOLLIN;
    epoll_ctl(epfd, EPOLL_CTL_ADD, listenfd, &ev);
    for(; ;)
    {
        int fds = epoll_wait(epfd, events, MAX_EVENTS, -1);
        if(fds<0){
            std::cout<<"epoll wait error"<<errno<<std::endl;
            break;
        }
        for(int i=0; i<fds; i++)
        {
            if(events[i].data.fd == listenfd)
            {
                if( (connfd = Accept(listenfd, (SA*)&cliaddr, &clilen)) )
                {
                    std::cout<<"new connection"<<std::endl;
                }
                else
                {
                    std::cout<<"accept error"<<std::endl;
                }
                setnonblocking(connfd);
                ev.data.fd = connfd;
                ev.events = EPOLLIN;
                if((epoll_ctl(epfd, EPOLL_CTL_ADD, connfd, &ev)) ==-1 ){
                    std::cout<<"epoll_ctl error"<<std::endl;
                }
            }

            else if(events[i].events & EPOLLIN)
            {
                sockfd = events[i].data.fd;
                if( (readlen = read(sockfd, line, MAXLINE))<0)
                {
                    if(errno == ECONNRESET)
                    {
                        std::cout<<"ECONNREST closed socket fd"<<std::endl;
                        close(sockfd);
                    }
                }
                else if(readlen==0)
                {
                    std::cout<<"read 0 closed socket fd"<<std::endl;
                    close(sockfd);
                }
                else
                {
                    if(write(sockfd, line, readlen) != readlen)
                    std::cout<<"write doesn't finish at one time"<<std::endl;
                }
            }
        }
    }
    return 0;
}
