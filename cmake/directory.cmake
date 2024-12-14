# Source code path
set(COMPONENTS_PATH ${CMAKE_SOURCE_DIR}/components)
set(TEST_PATH ${CMAKE_SOURCE_DIR}/test)

# Output path
set(CMAKE_INSTALL_PREFIX              ${CMAKE_SOURCE_DIR}/output)       # Install root path
set(INSTALL_EXECUTE_DIR               ${CMAKE_INSTALL_PREFIX}/bin)      # Execute path
set(INSTALL_SHARED_LIBRARY_DIRECTORY  ${CMAKE_INSTALL_PREFIX}/lib)      # Shared Library path
set(INSTALL_STATIC_LIBRARY_DIRECTORY  ${CMAKE_INSTALL_PREFIX}/lib)      # Static Library path
set(INSTALL_INCLUDE_DIRECTORY         ${CMAKE_INSTALL_PREFIX}/include)  # Header  path

# Include directory
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${COMPONENTS_PATH})
include_directories(${TEST_PATH})