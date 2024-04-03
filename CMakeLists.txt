cmake_minimum_required(VERSION 3.27)

set(CMAKE_GENERATOR
    "Unix Makefiles"
    CACHE STRING "generator")

project(
  Arcade
  LANGUAGES CXX
  VERSION 0.1.0)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "release")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "debug")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -g3 -fsanitize=address,leak,undefined -fanalyzer")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3 -fsanitize=address,leak,undefined -fanalyzer")
endif()

# ↓ Libraries
include(FindPkgConfig)
add_subdirectory(lib/ASS)

# ↓ Arcade binary
add_subdirectory(Arcade)

# ↓ Games
add_subdirectory(Games/snake)
# add_subdirectory(Games/menu)

# ↓ Renderer
add_subdirectory(Renderer/NCurses)
add_subdirectory(Renderer/SDL2)
