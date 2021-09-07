project(perf-ex-cpp)
cmake_minimum_required(VERSION 2.8)
file(GLOB_RECURSE SRC_LIST *.cpp)
add_executable(${PROJECT_NAME} ${SRC_LIST})

