# Default Setting
## cmake version
cmake_minimum_required(VERSION 3.20)

## Project information
project(SelfSDK VERSION 1.0.0)

# Configuraion version
configure_file(
    "${PROJECT_SOURCE_DIR}/cmake/sdk_config.h.in"
    "${CMAKE_SOURCE_DIR}/sdk_config.h"
)

# Import CMAKE utilitis
include(cmake/macro.cmake)
include(cmake/directory.cmake)

define_cpp_version()

# Print Compiler information
message(STATUS " - Compiler")
message(STATUS " - ID       \t: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS " - Version  \t: ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS " - Path     \t: ${CMAKE_CXX_COMPILER}")

# Debugging or Release mode 
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUGGING_MODE)
endif()

# Add sub directory
## Components
add_subdirectory(components/geometry)

## Test program
add_subdirectory(test/geometry)
# target_include_directories(SelfSDK PUBLIC componets)