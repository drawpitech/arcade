option(BUILD_TESTING "Build tests" OFF)

if (BUILD_TESTING)
    enable_testing()
    include(FetchContent)

    fetchcontent_declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG v1.14.0
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
    fetchcontent_makeavailable(googletest)

    add_custom_target(ass_games_tests)
    add_custom_target(ass_renderers_tests)
    add_custom_target(ass_tests DEPENDS ass_games_tests ass_renderers_tests)
else ()
    message(STATUS "Tests not enabled")
endif ()

function(ass_add_tests name TYPE)
    if (NOT BUILD_TESTING)
        return()
    endif ()
    if ((NOT TYPE STREQUAL GAME) AND (NOT TYPE STREQUAL RENDERER))
        message(SEND_ERROR "Type must be GAME or RENDERER")
    endif ()
    set(TEST_SUITE_NAME ${name})
    set(SO_PATH "$<TARGET_FILE:ass>")
    set(CONFIG_PATH ${CMAKE_CURRENT_BINARY_DIR}/${name})
    file(GENERATE
            OUTPUT ${CONFIG_PATH}/configure.hpp
            CONTENT "#pragma once
#define TEST_SUITE_NAME ${name}Tests
#define SO_PATH \"$<TARGET_FILE:${name}>\"
"
    )
    if (TYPE STREQUAL GAME)
        add_executable(${name}_test ${ASS_SOURCE_DIR}/test/test_game.cpp)
        add_dependencies(ass_games_tests ${name}_test)
    else ()
        add_executable(${name}_test ${ASS_SOURCE_DIR}/test/test_renderer.cpp)
        add_dependencies(ass_renderers_tests ${name}_test)
    endif ()
    target_include_directories(${name}_test PRIVATE ${CONFIG_PATH})
    include(GoogleTest)
    target_link_libraries(${name}_test PRIVATE GTest::gtest_main ass)
    gtest_discover_tests(${name}_test
            XML_OUTPUT_DIR ${PROJECT_BINARY_DIR}/logs/
    )
endfunction()
