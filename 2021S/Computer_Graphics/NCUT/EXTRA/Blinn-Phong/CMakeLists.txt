cmake_minimum_required(VERSION 3.17)
PROJECT(Blinn_Phong)

set(CMAKE_CXX_STANDARD 14)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/OpenGL/include)
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/OpenGL/libs)

INCLUDE_DIRECTORIES(${INCLUDE_DIR})
link_directories(${LIB_DIR})

find_package(OpenGL REQUIRED)

if(APPLE)
    find_package(glfw3 REQUIRED)
    find_package(glm REQUIRED)
else()
    link_libraries(glfw3)
endif()


add_executable(${PROJECT_NAME} main.cpp camera.hpp shader.hpp glad.c)

if(APPLE)
    target_link_libraries(${PROJECT_NAME} glfw ${OPENGL_LIBRARIES} ${GLM_LIBRARY})
else()
    target_link_libraries(${PROJECT_NAME} glfw3 ${OPENGL_LIBRARIES})
endif()