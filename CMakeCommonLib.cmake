file(GLOB_RECURSE sources "*.cpp")
add_library(${TARGET} SHARED ${sources})

target_compile_features(${TARGET} PUBLIC cxx_std_20)

target_link_libraries(${TARGET} ass)

set_target_properties(
  ${TARGET}
  PROPERTIES PREFIX "../../lib/"
             EXPORT_COMPILE_COMMANDS ON
             CXX_STANDARD_REQUIRED ON
             INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)
