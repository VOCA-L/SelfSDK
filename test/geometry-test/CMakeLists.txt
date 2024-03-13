get_directory_name(TARGET)

# Execute file
add_executable(${TARGET}
    test.cpp
)

# target_link_libraries(${TARGET})

install(TARGETS ${TARGET} DESTINATION ${INSTALL_EXECUTE_DIRECTORY})