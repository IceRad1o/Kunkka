
cmake_minimum_required(VERSION 3.16)
project(ranet)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_C_FLAGS -m32)
#set(CMAKE_CXX_FLAGS -m32)

add_executable(ranet main.cpp)
add_executable(minimuduo mini-muduo/main.cpp mini-muduo/TcpServer.cpp mini-muduo/TcpServer.h net/Eventloop.h base/noncopyable.h mini-muduo/Channel.h mini-muduo/Channel.cpp mini-muduo/IChannelCallBack.h mini-muduo/Declare.h mini-muduo/Define.h mini-muduo/Acceptor.cpp mini-muduo/Acceptor.h mini-muduo/IAcceptorCallBack.h mini-muduo/TcpConnection.cpp mini-muduo/TcpConnection.h mini-muduo/Define.cpp mini-muduo/EventLoop.cpp mini-muduo/EventLoop.h mini-muduo/Epoll.cpp mini-muduo/Epoll.h mini-muduo/main.cpp mini-muduo/IMuduoUser.h mini-muduo/EchoServer.cpp mini-muduo/EchoServer.h mini-muduo/Buffer.cpp mini-muduo/Buffer.h mini-muduo/IRun.h mini-muduo/Timestamp.cpp mini-muduo/Timestamp.h mini-muduo/TimerQueue.cpp mini-muduo/TimerQueue.h mini-muduo/Timer.h)

#add_executable(daytimetcpcli unp/daytimetcpcli.cpp unp/error.cpp net/Eventloop.cpp)
#add_executable(daytimetcpsrv unp/daytimetcpsrv.cpp unp/error.cpp)
#add_executable(tcpserv01 unp/tcpserv01.cpp unp/error.cpp unp/robustio.cpp unp/wrapsock.cpp unp/str_echo.cpp)
#add_executable(tcpcli01 unp/tcpcli01.cpp unp/error.cpp unp/robustio.cpp unp/wrapsock.cpp unp/str_cli.cpp unp/strcliselect01.cpp)

#add_executable(tcpservselect unp/tcpservselect01.cpp unp/error.cpp unp/robustio.cpp unp/wrapsock.cpp unp/wrapunix.cpp)
#add_executable(tcpservpoll unp/tcpservpoll01.cpp)
#add_executable(tcpservepoll mini-muduo/tcpservepoll01.cpp unp/error.cpp unp/wrapsock.cpp)