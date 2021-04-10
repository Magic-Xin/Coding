set(CMAKE_CXX_STANDARD 17)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../OpenGL/include)
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../OpenGL/libs)

INCLUDE_DIRECTORIES(${INCLUDE_DIR})
link_directories(${LIB_DIR})

aux_source_directory(. SHADER_DIR)
add_library(shader ${SHADER_DIR})