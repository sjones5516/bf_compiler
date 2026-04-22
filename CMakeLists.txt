cmake_minimum_required(VERSION 3.28)
project(
        BF_Compiler
        VERSION 0.0.1
        DESCRIPTION "A Brainfuck compiler"
        LANGUAGES CXX
)

# Configure C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Custom options
option(BUILD_TESTING "Build the test suite" OFF)

include(FetchContent)

# Create .gitignore in build dir on initial configuration
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/.gitignore" "/*")

# Forbid in-source builds
if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(FATAL_ERROR "In-source builds are not permitted.")
endif ()

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

if (BUILD_TESTING)
    # Setup GoogleTest
    FetchContent_Declare(
            googletest
            # Regularly update hash to latest version
            URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
    enable_testing()
endif ()

# Default build configuration as Debug
message(STATUS "Setting build type to 'Debug' as none was specified.")
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")

# Add subdirectories
add_subdirectory(src)
