# Configuraion version
configure_file(
    "${PROJECT_SOURCE_DIR}/cmake/sdk_config.h.in"
    "${CMAKE_SOURCE_DIR}/sdk_config.h"
)

# Print Compiler information
message(STATUS " $ Compiler Information")
message(STATUS " $ Compiler \t: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS " $ Version  \t: ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS " $ Path     \t: ${CMAKE_CXX_COMPILER}") 