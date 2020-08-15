#include "TcpServer.h"

TcpServer::TcpServer():_epfd(-1),_pAcceptor(NULL)
{}

void TcpServer::newConnection(int sockfd)
{
    TcpConnection *tcp = new TcpConnection(_epfd, sockfd);
    _connections[sockfd] = tcp;
}

void TcpServer::start()
{
    if ( (_epfd = epoll_create(1))<0){
        std::cout<<"epoll_create error"<<std::endl;
    }
    _pAcceptor = new Acceptor(_epfd);
    _pAcceptor->setCallBack(this);
    _pAcceptor->start();

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
