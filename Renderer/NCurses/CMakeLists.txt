set(TARGET ncurses)
include(${CMAKE_SOURCE_DIR}/CMakeCommonLib.cmake)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(${TARGET} ${CURSES_LIBRARIES})
