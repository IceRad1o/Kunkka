#include "TcpConnection.h"

TcpConnection::TcpConnection(EventLoop *loop, int sockfd)
    :_sockfd(sockfd)
    ,_loop(loop)
{
    _pChannel = new Channel(_loop, _sockfd);
    _pChannel->setCallBack(this);
    _pChannel->enableReading();
}

void TcpConnection::OnIn(int sockfd)
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
