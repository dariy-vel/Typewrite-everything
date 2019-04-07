# cmake_minimum_required(VERSION <specify CMake version here>)
project(keys)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall" )


add_executable(keys main.cpp)
target_link_libraries(keys winmm)
