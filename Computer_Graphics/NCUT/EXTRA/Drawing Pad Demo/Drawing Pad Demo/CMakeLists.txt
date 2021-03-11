cmake_minimum_required(VERSION 3.10)
project(Drawing_Pad_Demo)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories(library ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

add_executable(Drawing_Pad_Demo main.cpp Drawing.cpp Drawing.hpp)

target_link_libraries(Drawing_Pad_Demo ${OPENGL_LIBRARIES} ${GLUT_glut_LIBRARY})
install(TARGETS Drawing_Pad_Demo RUNTIME DESTINATION bin)