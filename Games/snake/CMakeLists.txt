set(TARGET arcade_snake)
include(../../CMakeCommonLib.txt)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(arcade_snake ${CURSES_LIBRARIES})
