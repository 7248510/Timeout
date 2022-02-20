cmake_minimum_required(VERSION 3.20)
project(test)

set(CMAKE_CXX_STANDARD 20)

include_directories(fmt/include/)
add_executable(test main.cpp timeout.h)
