add_custom_target(ass_renderers)
add_custom_target(ass_games)

function(ass_add_library name TYPE)
    if ((NOT TYPE STREQUAL "GAME") AND (NOT TYPE STREQUAL "RENDERER"))
        message(SEND_ERROR "Type must be GAME or RENDERER")
    endif ()
    add_library(${name} SHARED ${ARGN})
    target_link_libraries(${name} PRIVATE ass)
    set_target_properties(${name} PROPERTIES
            PREFIX arcade_
    )
    if (TYPE STREQUAL GAME)
        add_dependencies(ass_games ${name})
    else ()
        add_dependencies(ass_renderers ${name})
    endif ()
    ass_add_tests(${name} ${TYPE})
endfunction()
