# Default Setting
## cmake version
cmake_minimum_required(VERSION 3.20)

## Project information
project(SelfSDK VERSION 1.0.0 LANGUAGES C CXX)

# Import CMAKE utilitis
include(cmake/build.cmake)
include(cmake/macro.cmake)
include(cmake/directory.cmake)

# Set C/C++ standard and version
define_cpp_version()
define_c_version()

# Debugging or Release mode 
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUGGING_MODE)
endif()

# Add sub directory
add_subdirectory(${COMPONENTS_PATH}) # Components
add_subdirectory(${TEST_PATH})       # Test Programs