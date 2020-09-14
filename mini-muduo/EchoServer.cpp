#include "EchoServer.h"

const int MESSAGE_LENGTH=8;
EchoServer::EchoServer(EventLoop *pLoop)
    :_pLoop(pLoop),_pServer(pLoop),_timer(-1),_index(0)

{
    _pServer.setCallback(this);
}

void EchoServer::start() {
    _pServer.start();
}

void EchoServer::onConnection(TcpConnection *pCon)
{
    std::cout<<"onConnection"<<std::endl;
}

void EchoServer::onMessage(TcpConnection *pCon, Buffer *pBuf)
{
    // codec
    /*
    while(pBuf->readableBytes() > MESSAGE_LENGTH) {
        std::string message = pBuf->retrieveAsString(MESSAGE_LENGTH);
        pCon->send(message + "\n");
    }
     */
    std::string message = pBuf->retrieveAsString(pBuf->readableBytes());
    pCon->send(message);

    // _timer = _pLoop->runEvery(0.5,this);
}

void EchoServer::onWriteComplete(TcpConnection *pCon) {
    std::cout<< "onWriteComplete\n";
}

void EchoServer::run(void *param) {
    std::cout<< "index: "<< _index <<std::endl;
    if(_index++ == 3){
        _pLoop->cancelTimer(_timer);
        _index = 0;
    }
}