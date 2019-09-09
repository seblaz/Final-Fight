cmake_minimum_required(VERSION 3.7)
project(myapp)

set(CMAKE_CXX_STANDARD 17)

# Create executables:
FILE(GLOB services services/*.cpp)
add_executable(service ${services} main.cpp)
