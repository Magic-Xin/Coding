cmake_minimum_required(VERSION 3.17)
project(PlyToBinary)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp tinyply.cpp tinyply.h)

add_executable(PlyToBinary ${SOURCE_FILES})