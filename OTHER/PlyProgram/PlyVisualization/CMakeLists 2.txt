cmake_minimum_required(VERSION 3.17)
PROJECT(PlyVisualization)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/OpenGL/include)
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/OpenGL/libs)

aux_source_directory(./src SRC_DIRS)

include_directories(./src ./src/ply ./src/shader)

add_subdirectory(src/ply)
add_subdirectory(src/shader)

INCLUDE_DIRECTORIES(${INCLUDE_DIR})
link_directories(${LIB_DIR})

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

add_executable(${PROJECT_NAME} ${SRC_DIRS})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

target_link_libraries(${PROJECT_NAME} glfw ply shader ${OPENGL_LIBRARIES} ${GLM_LIBRARY})