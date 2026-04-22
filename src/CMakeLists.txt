set(SOURCE_FILES
  token.cpp
)
set(EXEC_SOURCE_FILES
  main.cpp
)
  message(STATUS "Configuring for desktop.")
  add_library(BF_Core ${SOURCE_FILES})
  if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_compile_options(BF_Core PRIVATE -march=native)
  endif()

# Header files go in include directory and are automatically discovered
target_include_directories(BF_Core PUBLIC include)

# Compile definitions by build configuration
target_compile_definitions(
        BF_Core PRIVATE

        # Debug
        $<$<CONFIG:Debug>:DEBUG_MODE=1>
        $<$<CONFIG:Debug>:ENABLE_ASSERTS>

        # Release
        $<$<CONFIG:Release>:RELEASE_MODE=1>
        $<$<CONFIG:Release>:NO_LOGGING>

        # MinSizeRel
        $<$<CONFIG:MinSizeRel>:OPTIMIZE_FOR_SIZE=1>

        # RelWithDebInfo
        $<$<CONFIG:RelWithDebInfo>:RELEASE_MODE=1>
        $<$<CONFIG:RelWithDebInfo>:ENABLE_PROFILING>

        # EmScripten
        $<$<CONFIG:EmScripten>:RELEASE_MODE=1>
)

# Compile options by build configuration
target_compile_options(
        BF_Core PRIVATE
        $<$<CONFIG:Debug>:-g -O0 -Wall>
        $<$<CONFIG:Release>:-O3 -march=native -DNDEBUG>
        $<$<CONFIG:MinSizeRel>:-Os -DNDEBUG>
        $<$<CONFIG:RelWithDebInfo>:-O2 -g>
)

if(BUILD_TESTING)
  # Configure testing
  add_executable(BF_test EXCLUDE_FROM_ALL)
  target_link_libraries(BF_test PRIVATE GTest::gtest_main)
  target_compile_definitions(BF_test PRIVATE UNIT_TESTING)
  add_subdirectory(tests)
  include(GoogleTest)
  gtest_discover_tests(BF_test)
endif ()

add_executable(BF_Compiler ${SOURCE_FILES} ${EXEC_SOURCE_FILES})
