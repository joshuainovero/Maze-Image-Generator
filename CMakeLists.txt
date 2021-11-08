# Build static library
# Outputs to (this directory) -> (lib directory)


cmake_minimum_required(VERSION 3.21.0)

project(mazeimage)

set(CIMG_FLAGS "-march=native -Dcimg_jpeg=1 -Dcimg_display=0")
set(GCC_FLAGS "-Wall -std=c++17")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_FLAGS} ${CIMG_FLAGS}")

set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include/MazeImage++/utils")
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB INCLUDE_FILES ${INCLUDE_DIR}/*.h)
file (GLOB SRC_FILES ${SRC_DIR}/*.cpp)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
set(CMAKE_BUILD_FILES_DIRECTORY ${PROJECT_SOURCE_DIR}/build)

add_library(img_maze STATIC ${INCLUDE_FILES} ${SRC_FILES})