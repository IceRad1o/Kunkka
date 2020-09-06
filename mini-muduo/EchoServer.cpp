#include "EchoServer.h"

const int MESSAGE_LENGTH=8;
EchoServer::EchoServer(EventLoop *pLoop)
    :_pLoop(pLoop),_pServer(pLoop)

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
    pCon->send(message + "\n");
}

void EchoServer::onWriteComplete(TcpConnection *pCon) {
    std::cout<< "onWriteComplete\n";
}