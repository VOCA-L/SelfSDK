# Default Setting
## cmake version
cmake_minimum_required(VERSION 3.20)

## Project information
project(SelfSDK VERSION 1.0.0)

# Import CMAKE utilitis
include(cmake/macro.cmake)
include(cmake/directory.cmake)

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
add_subdirectory(components/geometry)

# target_include_directories(SelfSDK PUBLIC componets)