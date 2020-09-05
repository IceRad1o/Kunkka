#include <iostream>
#include "EchoServer.h"
#include "TcpServer.h"
#include "EventLoop.h"

int main(int argc, char **argv) {
    EventLoop loop;
    EchoServer echoserver(&loop);
    echoserver.start();
    loop.loop();
    return 0;
}

