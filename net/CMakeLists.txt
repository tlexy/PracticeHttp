cmake_minimum_required(VERSION 2.8)

project(ip_test CXX)

set(CMAKE_CXX_COMPILER "g++")

add_executable(ip_test ip_address.cpp test_ip.cpp)
