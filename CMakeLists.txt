cmake_minimum_required(VERSION 3.27)

set(CMAKE_GENERATOR
    "Unix Makefiles"
    CACHE STRING "generator")

project(
  Arcade
  LANGUAGES CXX
  VERSION 0.1.0)

# ↓ ASS library
add_subdirectory(lib/ASS)

# ↓ arcade binary
set(CMAKE_CXX_STANDARD 20)
file(GLOB_RECURSE sources "Arcade/*.cpp")
add_executable(arcade ${sources})
