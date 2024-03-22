file(GLOB_RECURSE sources "*.cpp")
add_executable(arcade ${sources})

target_compile_features(arcade PUBLIC cxx_std_20)

set_target_properties(
  arcade
  PROPERTIES PREFIX "../"
             EXPORT_COMPILE_COMMANDS ON
             CXX_STANDARD_REQUIRED ON
             INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)
