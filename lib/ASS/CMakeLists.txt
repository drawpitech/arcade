cmake_minimum_required(VERSION 3.27)

project(ASS
        VERSION 1.0
        DESCRIPTION "Arcade standard specifications"
        LANGUAGES CXX
)

add_library(ass INTERFACE)
target_include_directories(ass INTERFACE include)
target_compile_options(ass INTERFACE "$<$<CXX_COMPILER_ID:Clang,GNU>:-Wno-return-type-c-linkage>")


include(cmake/MakeDoc.cmake)
include(cmake/MakeTests.cmake)
include(cmake/MakeLib.cmake)

add_subdirectory(dummy)
