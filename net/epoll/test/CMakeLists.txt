cmake_minimum_required(VERSION 2.8)

project(tcpserver CXX)

set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -g -ggdb")#就是这两行东东
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_COMPILER "g++")

add_executable(tcpserver test_echo_server.cpp ../tcp_server.cpp ../event_loop.cpp ../sapper.cpp ../socket.cpp ../socket_util.cpp ../ip_address.cpp ../epoller.cpp ../base/thread.cpp ../base/date_time.cpp ../base/mutex.hpp ../poller.h)
target_link_libraries(tcpserver pthread)

