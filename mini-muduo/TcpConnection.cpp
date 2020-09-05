#include <iostream>
#include <string>
#include "TcpConnection.h"

TcpConnection::TcpConnection(EventLoop *loop, int sockfd)
    :_sockfd(sockfd)
    ,_loop(loop)
    ,_pUser(NULL)
{
    _pChannel = new Channel(_loop, _sockfd);
    _pChannel->setCallBack(this);
    _pChannel->enableReading();
}

void TcpConnection::send(const std::string &message) {
    int n = ::write(_sockfd, message.c_str(), message.size());
    if( n!= static_cast<int>(message.size())){
        std::cout<<" write error!" << message.size()-n<<"bytes left"<<std::endl;
    }
}

void TcpConnection::connectedEstablished() {
    if(_pUser)
        _pUser->onConnection(this);
}

void TcpConnection::setUser(IMuduoUser *pUser) {
    _pUser = pUser;
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
        std::string buf(line, readlen); // char* to string, care the length
        _pUser->onMessage(this, buf);
    }
}
