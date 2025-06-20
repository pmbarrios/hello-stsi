cmake_minimum_required(VERSION 3.10)
project(SoftclipPipeline)

# Use g++ from Homebrew
set(CMAKE_CXX_COMPILER "/opt/homebrew/bin/g++-15")
set(CMAKE_CXX_STANDARD 11)

# Include htslib headers
include_directories(/opt/homebrew/include)
link_directories(/opt/homebrew/lib)

# Build Hello World (already existing)
add_executable(softclip main.cpp)

# Build your new BAM reader
add_executable(read_bam read_bam.cpp)

# Link htslib to read_bam
target_link_libraries(read_bam hts)
