cmake_minimum_required(VERSION 2.8.12)
cmake_policy(SET CMP0004 OLD)

project(pygroundgl)


#----------- Dependecies -----------
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
link_libraries(${SDL2_LIBRARIES})

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARIES})

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
link_libraries(${OPENGL_LIBRARIES})
#-----------------------------------

add_subdirectory(pybind11)

pybind11_add_module(display lib/Display.cpp)
file(WRITE __init__.py "")