cmake_minimum_required(VERSION 3.11)

project(cam_grabber)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -pthread")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -Wall -pthread")

add_subdirectory(common)
add_subdirectory(ai)
add_subdirectory(navigation)
add_subdirectory(cam)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE common cam ai navigation)