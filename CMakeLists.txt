
cmake_minimum_required(VERSION 3.0)

project(advanced_programming)

set(CMAKE_CXX_STANDARD 17)

file(GLOB MAIN_SOURCES ${CMAKE_CURRENT_LIST_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${MAIN_SOURCES})