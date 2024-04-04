if (PROJECT_IS_TOP_LEVEL)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

    ass_add_library(dummy_renderer RENDERER main.cpp)
    ass_add_library(dummy_game GAME main.cpp)

    add_custom_target(dummy DEPENDS dummy_renderer dummy_game)
endif ()
