cmake_minimum_required(VERSION 3.16)
project(ranet)

set(CMAKE_CXX_STANDARD 14)

add_executable(ranet main.cpp test/TcpServer.cpp test/TcpServer.h net/Eventloop.h base/noncopyable.h test/Channel.h test/Channel.cpp test/IChannelCallBack.h test/Declare.h test/Define.h)

#add_executable(daytimetcpcli unp/daytimetcpcli.cpp unp/error.cpp net/Eventloop.cpp)
#add_executable(daytimetcpsrv unp/daytimetcpsrv.cpp unp/error.cpp)
#add_executable(tcpserv01 unp/tcpserv01.cpp unp/error.cpp unp/robustio.cpp unp/wrapsock.cpp unp/str_echo.cpp)
#add_executable(tcpcli01 unp/tcpcli01.cpp unp/error.cpp unp/robustio.cpp unp/wrapsock.cpp unp/str_cli.cpp unp/strcliselect01.cpp)

#add_executable(tcpservselect unp/tcpservselect01.cpp unp/error.cpp unp/robustio.cpp unp/wrapsock.cpp unp/wrapunix.cpp)
#add_executable(tcpservpoll unp/tcpservpoll01.cpp)
#add_executable(tcpservepoll test/tcpservepoll01.cpp unp/error.cpp unp/wrapsock.cpp)