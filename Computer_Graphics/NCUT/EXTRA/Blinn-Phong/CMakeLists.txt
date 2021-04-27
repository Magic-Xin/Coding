cmake_minimum_required(VERSION 3.17)
PROJECT(Blinn_Phong)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/OpenGL/include)
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/OpenGL/libs)

INCLUDE_DIRECTORIES(${INCLUDE_DIR})
link_directories(${LIB_DIR})

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

add_executable(${PROJECT_NAME} main.cpp camera.hpp shader.hpp glad.c)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)

target_link_libraries(${PROJECT_NAME} glfw ${OPENGL_LIBRARIES} ${GLM_LIBRARY})