cmake_minimum_required(VERSION 3.7)
project(myapp)

set(CMAKE_CXX_STANDARD 14)

# Create executables:
add_executable(myapp 01_hello_SDL.cpp)
add_executable(myapp_calc calc.cpp)
add_executable(FilesManager/FileManager.cpp)
add_executable(FilesManager/Logger.cpp)

# Create a library:
# add_library (test_library STATIC calc.cpp)
# Link it to calc:
# find_library(TEST_LIBRARY test_library cmake-build-debug)
# target_link_libraries(myapp_calc LINK_PUBLIC ${TEST_LIBRARY})

# Find SDL2 libraries:
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
# Link to executable:
target_link_libraries(myapp LINK_PUBLIC ${SDL2_LIBRARIES})

