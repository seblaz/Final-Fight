#[[
  Configuraciones globales.
]]
cmake_minimum_required(VERSION 3.14)
project(final_fight)
set(CMAKE_CXX_STANDARD 17)

#[[
  Para hacer profiling.
]]
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

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
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/vendor/cmake-sl2-image/" "${CMAKE_SOURCE_DIR}/vendor/cmake-sdl-mixer/")

#[[
  Para que funcione pthread.
]]
SET(CMAKE_CXX_FLAGS -pthread)

#[[
  Definición de variables.
]]
FILE(GLOB_RECURSE TestSources test/*.cpp)

FILE(GLOB_RECURSE ModelSources src/modelo/*.cpp)
FILE(GLOB_RECURSE PhysicsSources src/fisica/*.cpp)
FILE(GLOB_RECURSE GraphicsSources src/graficos/*.cpp)
FILE(GLOB_RECURSE InputSources src/comportamiento/*.cpp)
FILE(GLOB_RECURSE StatesSources src/estados/*.cpp)
FILE(GLOB_RECURSE ServicesSources src/servicios/*.cpp)
FILE(GLOB_RECURSE Configurations *.xml)
FILE(GLOB_RECURSE ClientSources src/cliente/*.cpp)
FILE(GLOB_RECURSE ServerSources src/servidor/*.cpp)
FILE(GLOB_RECURSE EventSources src/eventos/*.cpp)
FILE(GLOB_RECURSE UsuarioSources src/usuario/*.cpp)
FILE(GLOB_RECURSE UtilsSources src/utils/*.cpp)
FILE(GLOB_RECURSE SoundSources src/sonidos/*.cpp)

find_package(SDL2 REQUIRED) # Find SDL2 libraries.
find_package(XercesC REQUIRED) # Find Xerces
find_package(SDL2_image REQUIRED) # Find SDL2-IMAGE libraries
find_package(SDL2TTF REQUIRED)
find_package(SDL2_mixer REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_MIXER_INCLUDE_DIR})

#[[
  Compilar los tests.
]]
#add_executable(tests ${TestSources} ${ModelSources} ${GraphicsSources} ${InputSources} ${StatesSources} ${ServicesSources} ${PhysicsSources} ${IASources} ${UsuarioSources})
#target_link_libraries(tests gtest_main gmock_main ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2TTF_LIBRARY} ${XercesC_LIBRARIES})
#add_test(NAME model_tests COMMAND model_tests)

#[[
  Copiar los assets
]]
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${Configurations} DESTINATION ${CMAKE_BINARY_DIR})

#[[
  Compilar el cliente.
]]
add_executable(cliente ${ClientSources} ${ModelSources} ${GraphicsSources} ${ServicesSources} ${UsuarioSources} ${UtilsSources} ${SoundSources} src/modelo/serializables/Arma.cpp src/modelo/serializables/Arma.h)
target_link_libraries(cliente ${XercesC_LIBRARIES} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2TTF_LIBRARY} ${SDL2_MIXER_LIBRARY})

#[[
  Compilar el servidor.
]]
add_executable(servidor ${ServerSources} ${ServicesSources} ${EventSources} ${ModelSources} ${StatesSources} ${PhysicsSources} ${UsuarioSources} ${UtilsSources} src/servidor/notificadores/NotificadorDeGolpesJugador.cpp src/servidor/notificadores/NotificadorDeGolpesJugador.h)
target_link_libraries(servidor ${XercesC_LIBRARIES})
