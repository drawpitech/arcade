set(TARGET sdl2)
include(${CMAKE_SOURCE_DIR}/CMakeCommonLib.cmake)

pkg_search_module(SDL2 REQUIRED sdl2>=2.0.0)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
pkg_search_module(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
target_link_libraries(${TARGET} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES}
                      ${SDL2TTF_LIBRARIES})
