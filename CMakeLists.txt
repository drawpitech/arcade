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
add_subdirectory(Arcade)

# ↓ Games
add_subdirectory(Games/snake)

# ↓ Renderer
add_subdirectory(Renderer/NCurses)
