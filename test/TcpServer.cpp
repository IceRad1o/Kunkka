#include "TcpServer.h"
#include "Channel.h"
TcpServer::TcpServer():_epfd(-1),_listenfd(-1)
{}

int TcpServer::setnonblocking(int fd)
{
    int old_flags = fcntl(fd, F_GETFL);
    int new_flags = old_flags|O_NONBLOCK;
    fcntl(fd, F_SETFL, new_flags);
    return old_flags;
}

int TcpServer::createAndListen() {
    int optval=1;
    int listenfd;
    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));

    //setnonblocking(listenfd);
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(listenfd, (SA*)&servaddr, sizeof(servaddr));
    listen(listenfd, LISTENQ);
    std::cout<<"start listening"<<std::endl;
    return listenfd;
}

void TcpServer::OnIn(int sockfd)
{
    std::cout<< "OnIn: "<<sockfd<<std::endl;
    if(sockfd == _listenfd)
    {
        int connfd;
        struct sockaddr_in cliaddr;
        socklen_t clilen = sizeof(cliaddr);
        connfd = accept(_listenfd, (SA*)&cliaddr, &clilen);
        if(connfd>0){
            std::cout<<"new connection from"<<"["<<inet_ntoa(cliaddr.sin_addr)<<":"<<ntohs(cliaddr.sin_port)<<"]"
            <<"new socket fd"<<connfd<<std::endl;
        }
        else{
            std::cout<<"accept error:"<<connfd<<"errno:"<<errno<<std::endl;
        }
        setnonblocking(connfd);
        // memory leak
        Channel *pChannel = new Channel(_epfd, connfd);
        pChannel->setCallBack(this);
        pChannel->enableReading();
    }
    else
    {
        int readlen;
        char line[MAXLINE];
        if(sockfd < 0){
            std::cout<<"EPOLLIN sockfd <0"<< std::endl;
            return;
        }
        bzero(line, MAXLINE);
        if ((readlen = read(sockfd, line, MAXLINE)) < 0) {
            if (errno == ECONNRESET) {
                std::cout << "ECONNREST closed socket fd" << std::endl;
                close(sockfd);
            }
        } else if (readlen == 0) {
            std::cout << "read 0 closed socket fd" << std::endl;
            close(sockfd);
        } else {
            if (write(sockfd, line, readlen) != readlen)
                std::cout << "write doesn't finish at one time" << std::endl;
        }
    }
}


void TcpServer::start()
{
    if ( (_epfd = epoll_create(1))<0){
        std::cout<<"epoll_create error"<<std::endl;
    }
    _listenfd = createAndListen();
    Channel *pChannel = new Channel(_epfd, _listenfd);
    pChannel->setCallBack(this);
    pChannel->enableReading();

    for(; ;)
    {
        std::vector<Channel*> channels;
        int fds = epoll_wait(_epfd, _events, MAX_EVENTS, -1);
        if(fds<0){
            std::cout<<"epoll wait error"<<errno<<std::endl;
            break;
        }
        for(int i=0; i<fds; i++)
        {
            Channel *pChannel = static_cast<Channel*>(_events[i].data.ptr);
            pChannel->setRevents(_events[i].events);
            channels.push_back(pChannel);
        }
        std::vector<Channel*>::iterator it;
        for(it = channels.begin();it!=channels.end(); ++it)
        {
            (*it)->handleEvent();
        }
    }
}
