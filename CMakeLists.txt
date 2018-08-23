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


set(LIB_SOURCES
    ${CMAKE_SOURCE_DIR}/lib/Display.cpp 
    ${CMAKE_SOURCE_DIR}/lib/Mesh.cpp
    ${CMAKE_SOURCE_DIR}/lib/Shader.cpp
)


pybind11_add_module(pygroundgl SHARED ${LIB_SOURCES} lib/pybind11_bindings.cpp)

add_library(pygroundgl_cpp ${LIB_SOURCES})

add_executable(Test tests/test.cpp)
target_link_libraries(Test pygroundgl_cpp)
add_custom_command(
    TARGET Test 
    PRE_BUILD 
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/tests/res $<TARGET_FILE_DIR:Test>/res
)