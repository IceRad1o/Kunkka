#include "Acceptor.h"

Acceptor::Acceptor(EventLoop *loop)
    :_loop(loop)
    ,_listenfd(-1)
    ,_pAcceptChannel(NULL)
    ,_pCallBack(NULL)
{}

void Acceptor::start()
{
    _listenfd = createAndListen();
    _pAcceptChannel = new Channel(_loop, _listenfd);
    _pAcceptChannel->setCallBack(this);
    _pAcceptChannel->enableReading();
}

int Acceptor::createAndListen()
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

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(listenfd, (SA*)&servaddr, sizeof(servaddr));
    listen(listenfd, LISTENQ);
    std::cout<<"start listening"<<std::endl;
    return listenfd;
}

void Acceptor::setCallBack(IAcceptorCallBack *pCallBack)
{
    _pCallBack = pCallBack;
}

void Acceptor::OnIn(int socket)
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

    _pCallBack->newConnection(connfd);
}