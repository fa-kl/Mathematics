# Mathematics/CMakeLists.txt
cmake_minimum_required(VERSION 3.16)

project(Mathematics)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Unit tests
include(CTest)
enable_testing()
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG origin/main)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)
include(ClangTidy)

# Clean
add_custom_target(CleanAll
        COMMAND ${CMAKE_COMMAND} -E rm -rf ${CMAKE_BINARY_DIR}/*
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

# Subdirectories and libraries
add_subdirectory(Utils)
add_subdirectory(LinAlg)
add_subdirectory(Test)

# Main library
add_library(Math Math.cpp)
target_include_directories(Math PUBLIC Math.h)
target_link_libraries(Math PUBLIC Utils LinAlg)

# Main executable
add_executable(Main Main.cpp)
target_link_libraries(Main PRIVATE Math)
