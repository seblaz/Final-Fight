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

# Se agrega los cmake de sdl2-image
# https://github.com/trenki2/SDL2Test
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/vendor/cmake-sl2-image/")

#[[
  Definición de variables.
]]
FILE(GLOB TestSources test/*.cpp)
FILE(GLOB ModelSources modelo/*.cpp)
FILE(GLOB ModelMapSources modelo/mapeables/*.cpp)
FILE(GLOB MainSources main/*.cpp)
FILE(GLOB PhysicsSources fisica/*.cpp)
FILE(GLOB GraphicsSources graficos/*.cpp)
FILE(GLOB SpriteSources graficos/sprite/*.cpp)
FILE(GLOB InputSources comportamiento/*.cpp)
FILE(GLOB StatesSources modelo/estados/*.cpp)
FILE(GLOB ServicesSources servicios/*.cpp)

find_package(SDL2 REQUIRED) # Find SDL2 libraries.
find_package(XercesC REQUIRED) # Find Xerces
find_package(SDL2_image REQUIRED) # Find SDL2-IMAGE libraries
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

#[[
  Compilar los tests.
]]
add_executable(tests ${TestSources} ${ModelSources} ${GraphicsSources} ${ModelMapSources} ${InputSources} ${StatesSources} ${ServicesSources} ${SpriteSources} modelo/estados/Caminando.h modelo/estados/Caminando.cpp)
target_link_libraries(tests gtest_main gmock_main ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${XercesC_LIBRARIES})
add_test(NAME model_tests COMMAND model_tests)

#[[
  Compilar el juego.
]]
add_executable(${CMAKE_PROJECT_NAME} ${MainSources} ${PhysicsSources} ${ModelSources} ${GraphicsSources} ${SpriteSources} ${ModelMapSources} ${InputSources} ${StatesSources} ${ServicesSources} )
target_link_libraries(${CMAKE_PROJECT_NAME} LINK_PUBLIC ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${XercesC_LIBRARIES})

#[[
  Copiar los assets
]]
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
file(COPY Configuracion.xml DESTINATION ${CMAKE_BINARY_DIR})
