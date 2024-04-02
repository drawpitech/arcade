option(MAKE_TESTS "Build tests" OFF)

if (MAKE_TESTS)
    enable_testing()
    include(FetchContent)

    fetchcontent_declare(
            googletest
            URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    fetchcontent_makeavailable(googletest)

    include(GoogleTest)

    add_custom_target(games_tests)
    add_custom_target(renderers_tests)

    add_custom_target(ass_tests DEPENDS games_tests renderers_tests)
endif ()

function(ass_add_tests name TYPE)
    if (NOT MAKE_TESTS)
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
        add_executable(${name}_test ${CMAKE_SOURCE_DIR}/test/test_game.cpp)
        add_dependencies(games_tests ${name}_test)
    else ()
        add_executable(${name}_test ${CMAKE_SOURCE_DIR}/test/test_renderer.cpp)
        add_dependencies(renderers_tests ${name}_test)
    endif ()
    target_include_directories(${name}_test PRIVATE ${CONFIG_PATH})
    target_link_libraries(${name}_test PRIVATE GTest::gtest_main ass)
    gtest_discover_tests(${name}_test)
endfunction()
