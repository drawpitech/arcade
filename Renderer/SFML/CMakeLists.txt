set(TARGET sfml)
include(${CMAKE_SOURCE_DIR}/CMakeCommonLib.cmake)

pkg_search_module(SFML REQUIRED sfml-all)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(${TARGET} ${SFML_LIBRARIES})
