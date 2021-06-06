cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_NAME Test1)
set(SOURCE_FILES main.cpp Drawing.h Drawing.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})