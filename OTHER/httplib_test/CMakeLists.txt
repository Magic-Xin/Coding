cmake_minimum_required(VERSION 3.19)
project(httplib_test)

set(CMAKE_CXX_STANDARD 14)

add_executable(httplib_test main.cpp httplib.h)