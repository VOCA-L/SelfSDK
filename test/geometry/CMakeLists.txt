get_directory_name(TARGET)
add_executable(${TARGET}
  main.cpp
)

set_target_properties(${TARGET} PROPERTIES INSTALL_RPATH "$ORIGIN/../lib")
target_link_libraries(${TARGET}
  ${PREFIX}_geometry
)

install(TARGETS ${TARGET} DESTINATION ${INSTALL_EXECUTE_DIR})