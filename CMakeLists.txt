# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name
project(chessCLI)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_COMPILER g++)

# Set the main source directory
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

# Add all source directories (assuming each subdirectory in src has cpp and hpp files)
file(GLOB_RECURSE SRC_FILES "${SRC_DIR}/*.cpp")

# Define the executable target
add_executable(chessCLI ${SRC_FILES})

# Include directories (so it knows where to find headers)
include_directories(${SRC_DIR})

