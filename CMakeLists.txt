cmake_minimum_required(VERSION 2.8.7)
project(flare_random_dungeon_maker)

set(CMAKE_CXX_FLAGS "-std=c++0x -Wall -Wextra -Wunused -Wshadow -Woverloaded-virtual -Wunreachable-code -Wconversion ${CMAKE_CXX_FLAGS}")

include_directories(src)
 
set(MAIN_SOURCE main.cpp)
file(GLOB SOURCES "src/*.cpp")
 
add_executable(random_dungeon_maker ${SOURCES} ${MAIN_SOURCE})

