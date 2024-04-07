set(TARGET ncurses)

include(${CMAKE_SOURCE_DIR}/CMakeCommonLib.cmake)

set(CURSES_NEED_NCURSES TRUE)
set(CURSES_NEED_WIDE TRUE)
find_package(Curses REQUIRED)
include_directories(${NCURSES_INCLUDEDIR})
target_link_libraries(${TARGET} ${NCURSES_LIBRARIES})
