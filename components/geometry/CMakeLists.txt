get_directory_name(TARGET)

## Create Shared Library
add_library(${TARGET} SHARED
    src/point.cpp
)

# Copy file
target_include_directories(${TARGET} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
    $<INSTALL_INTERFACE:${INSTALL_INCLUDE_DIRECTORY}>
)

# Install library
## Header file
install(
    DIRECTORY include
    DESTINATION ${CMAKE_INSTALL_PREFIX}
    FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp" PATTERN "*.inl"
)
## SO file
install(
    TARGETS ${TARGET}
    EXPORT ${TARGET}Config
    DESTINATION ${INSTALL_LIBRARY_DIR}
)