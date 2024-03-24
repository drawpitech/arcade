set(TARGET arcade_ncurses)
include(../../CMakeCommonLib.txt)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(${TARGET} ${CURSES_LIBRARIES})
