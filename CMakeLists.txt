cmake_minimum_required(VERSION 3.27)

project(ASS
        VERSION 1.0
        DESCRIPTION "Arcade standard specifications"
        LANGUAGES CXX
)


if (PROJECT_IS_TOP_LEVEL)
add_executable(dummy main.cpp)
target_link_libraries(dummy ass)
endif ()

add_library(ass INTERFACE)
target_include_directories(ass INTERFACE include)

target_compile_features(ass INTERFACE cxx_std_20)

include(cmake/MakeDoc.cmake)
