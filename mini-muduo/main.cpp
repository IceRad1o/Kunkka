#include <iostream>
#include "TcpServer.h"
#include "EventLoop.h"

int main(int argc, char **argv) {
    EventLoop loop;
    TcpServer tcpserver(&loop);
    tcpserver.start();
    loop.loop();
    return 0;
}

