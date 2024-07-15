
cmake_minimum_required(VERSION 3.0)

project(advanced_programming)

set(CMAKE_CXX_STANDARD 20)
find_package(OpenCV REQUIRED)

file(GLOB MAIN_SOURCES ${CMAKE_CURRENT_LIST_DIR}/main.cpp ${CMAKE_CURRENT_LIST_DIR}/display.cpp ${CMAKE_CURRENT_LIST_DIR}/objects.cpp)


add_executable(${PROJECT_NAME} ${MAIN_SOURCES})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})