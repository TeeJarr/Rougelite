cmake_minimum_required(VERSION 3.31.5)
project(Rougelite LANGUAGES CXX)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find raylib
find_package(raylib REQUIRED)

# Add src directory to include paths
include_directories(src)

# Collect all source files automatically
file(GLOB_RECURSE SOURCES src/*.cpp src/Components*.cpp src/Entity/*.cpp src/Logic/*.cpp)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME} raylib)
target_include_directories(${PROJECT_NAME} PUBLIC include include/Entity)

