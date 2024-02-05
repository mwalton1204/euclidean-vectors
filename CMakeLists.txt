cmake_minimum_required(VERSION 3.10)
project(tests)

# Add executable for your test code
add_executable(tests Tests/tests.cpp Vec2/vec2.cpp)

# Include directories
target_include_directories(tests PRIVATE Tests Tests/Doctest Vec2)

# Set C++ standard
set_target_properties(tests PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS NO)
