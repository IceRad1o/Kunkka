cmake_minimum_required(VERSION 3.16)
project(ranet)

set(CMAKE_CXX_STANDARD 14)

add_executable(ranet main.cpp)
add_executable(daytimetcpcli ./unp/daytimetcpcli.cpp)
add_executable(daytimetcpsrv ./unp/daytimetcpsrv.cpp)