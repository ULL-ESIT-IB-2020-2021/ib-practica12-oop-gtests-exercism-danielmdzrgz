# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Informática Básica
#
# @author Daniel Méndez <alu0101391793@ull.edu.es>
# @date 14 Enero 2021
# @brief CMakeLists.txt for complex modification program
# CMakeLists.txt defines the whole build
# CMake reads CMakeLists.txt sequentially
#
# Build process:
#   1. cd <project_folder>
#   2. mkdir build
#   3. cd build
#   4. cmake ..
#   5. make


cmake_minimum_required(VERSION 3.1)  # Mandatory

# set the project name 
project(GTests                # Mandatory
    VERSION 1.0
    DESCRIPTION "A simple CMake project for complex program"
    LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14) 						# Use c++14
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# tell cmake to output binaries here:
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# Debug and release flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# tell cmake where to look for *.h files
include_directories(${PROJECT_SOURCE_DIR}/src)

# Adds an executable target called "runTests" to be built from the source files listed in the command invocation.
add_executable(runTests
    tests/gtest_main.cc
    src/complex_mod.h
    src/complex_mod.cc
    tests/addition_test.cc
    tests/substraction_test.cc
    tests/multiplication_test.cc
    tests/division_test.cc)

add_executable(complex
    src/complex_mod.h
    src/complex_mod.cc
    src/complex_mod_main.cc)

target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

# Add expected compiler features to a target.
target_compile_features(runTests PRIVATE cxx_std_14)

# Add compile options to a target.
target_compile_options(runTests PRIVATE -Wall -Wextra -Wpedantic)