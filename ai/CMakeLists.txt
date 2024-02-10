cmake_minimum_required(VERSION 3.11)

project(ai)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -Wall")

add_library(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/ai.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC common)