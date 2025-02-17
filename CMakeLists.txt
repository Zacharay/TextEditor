cmake_minimum_required(VERSION 3.29)
project(TextEditor)

set(CMAKE_CXX_STANDARD 20)

# Specify the SDL2 folder (manually downloaded SDL2)
set(SDL2_PATH "${CMAKE_SOURCE_DIR}/SDL2-2.0.10/")
set(SDL2_INCLUDE_DIR "${SDL2_PATH}/include")
set(SDL2_LIB_DIR "${SDL2_PATH}/lib")

# Include SDL2 and project headers
include_directories(${SDL2_INCLUDE_DIR} /usr/include/SDL2 ${CMAKE_SOURCE_DIR}/include)

# Gather all source files
file(GLOB SOURCES src/*.cpp main.cpp)

# Add the executable
add_executable(TextEditor ${SOURCES})

# Link SDL2 and SDL2_ttf libraries
target_link_libraries(TextEditor ${CMAKE_SOURCE_DIR}/libSDL2.a /usr/lib64/libSDL2_ttf.so)
