set(TARGET arcade_snake)
include(../../CMakeCommonLib.cmake)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(arcade_snake ${CURSES_LIBRARIES})
