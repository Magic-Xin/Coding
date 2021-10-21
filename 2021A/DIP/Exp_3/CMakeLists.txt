cmake_minimum_required(VERSION 3.20)
project(Exp_3)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenCV REQUIRED)

add_executable(Exp_2 main.cpp)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})