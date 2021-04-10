set(CMAKE_CXX_STANDARD 17)

aux_source_directory(. PLY_DIR)
add_library(ply ${PLY_DIR})