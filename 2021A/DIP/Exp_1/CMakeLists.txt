cmake_minimum_required(VERSION 3.20)
project(Exp_1)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

add_executable(Exp_1 main.cpp)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})