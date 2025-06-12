cmake_minimum_required(VERSION 3.10)
project(SoftclipPipeline)

# Use g++ from Homebrew (installed as gcc-15)
set(CMAKE_CXX_COMPILER "/opt/homebrew/bin/g++-15")
set(CMAKE_CXX_STANDARD 11)

add_executable(softclip main.cpp)
