#include <iostream>
#include "test/TcpServer.h"

int main(int argc, char **argv) {
    TcpServer tcpserver;
    tcpserver.start();
    return 0;
}
