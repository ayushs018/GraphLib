cmake_minimum_required(VERSION 3.10)
project(GraphLib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# headers
include_directories(include)

# submodules
add_subdirectory(src)
add_subdirectory(tests)
