cmake_minimum_required(VERSION 2.8)

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")#就是这两行东东
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

set(CMAKE_BUILD_TYPE Debug)

project(socket CXX)

set(CMAKE_CXX_COMPILER, "g++")

add_executable(test test.cpp socket.cpp socket_util.cpp ip_address.cpp thread.cpp)
add_executable(client client.cpp socket.cpp socket_util.cpp ip_address.cpp)
target_link_libraries(test pthread)
