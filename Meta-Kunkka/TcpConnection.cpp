#include <iostream>
#include <string>
#include "TcpConnection.h"
#include "Task.h"
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
    std::cout<<"isinLoopThread: "<<_loop->isInLoopThread()<<std::endl;
    std::cout<<"message to be sent: "<<message<<std::endl;
    if(_loop->isInLoopThread()){
        sendInLoop(message);
    }
    else{
        Task task(this, message, this);
        _loop->runInLoop(task);
    }
}

void TcpConnection::sendInLoop(const std::string &message) {
    int n = 0;
    if(_outBuf.readableBytes() ==0) {
        n = ::write(_sockfd, message.c_str(), message.size());
        if(n<0){
            std::cout<< "write error";
        }
        if(n == message.size()){
            Task task(this);
            _loop->queueLoop(task); //invoke onWriteComplete
        }
    }
    if( n < static_cast<int>(message.size())){
        _outBuf.append(message.substr(n, message.size()));
        if(_pChannel->isWriting()){
            // add EPOLLOUT
            _pChannel->enableWriting();
        }
    }
}


void TcpConnection::handleRead() {
    int sockfd = _pChannel->getSockfd();
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
        std::string linestr(line, readlen);
        _inBuf.append(linestr);
        _pUser->onMessage(this, &_inBuf);
    }
}

void TcpConnection::handleWrite() {
    int sockfd = _pChannel->getSockfd();
    if(_pChannel->isWriting())
    {
        int n = write(sockfd, _outBuf.peek(), _outBuf.readableBytes());
        if(n>0){
            std::cout<<"write "<<n<<"bytes data"<<std::endl;
            _outBuf.retrive(n);
            if(_outBuf.readableBytes() == 0) {
                _pChannel->disableWriting();  //remove EPOLLOUT
                Task task(this);
                _loop->queueLoop(task);  // notify
            }
        }
    }
}

void TcpConnection::connectedEstablished() {
    if(_pUser)
        _pUser->onConnection(this);
}

void TcpConnection::setUser(IMuduoUser *pUser) {
    _pUser = pUser;
}

void TcpConnection::run0() {
    _pUser->onWriteComplete(this);
}

void TcpConnection::run2(const std::string &message, void *param) {
    sendInLoop(message);
}


