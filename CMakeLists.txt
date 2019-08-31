#[[
  Configuraciones globales.
]]
cmake_minimum_required(VERSION 3.14)
project(final_fight)
set(CMAKE_CXX_STANDARD 17)

#[[
  Compilar la test suite de Google.
  https://github.com/google/googletest/blob/master/googletest/README.md.
]]
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

#[[
  Compilar los tests.
]]
FILE(GLOB ModelTestSources test/*.cpp)
FILE(GLOB ModelSources model/*.cpp)
add_executable(tests ${ModelTestSources} ${ModelSources})
target_link_libraries(tests gtest_main)
add_test(NAME model_tests COMMAND model_tests)

#[[
  Compilar hello world de SDL.
]]
# Create executables:
add_executable(hello_world_sdl 01_hello_SDL.cpp)
# Find SDL2 libraries:
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
# Link to executable:
target_link_libraries(hello_world_sdl LINK_PUBLIC ${SDL2_LIBRARIES})