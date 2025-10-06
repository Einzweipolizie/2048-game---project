cmake_minimum_required(VERSION 3.10)
project(2048Game C)

set(CMAKE_C_STANDARD 99)

# Tell the compiler where to find your headers
include_directories(include)

# Collect all .c files in src/ folder
file(GLOB SOURCES src/*.c)

# Create the executable
add_executable(2048 ${SOURCES})

# Find Raylib library
find_package(raylib REQUIRED)
# Link Raylib to your program
target_link_libraries(2048 raylib)
