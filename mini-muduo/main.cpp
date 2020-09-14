#include "EchoServer.h"
#include "EventLoop.h"

int main(int argc, char **argv) {
    EventLoop loop;
    EchoServer echoserver(&loop);
    echoserver.start();
    loop.loop();
    return 0;
}

