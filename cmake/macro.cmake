# Cpp version 
macro(define_cpp_version)
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED true)
endmacro(define_cpp_version)

# Directory Name
macro(get_directory_name PROJECT_NAME_VAR)
    get_filename_component(CURRENT_LIST_FILE "${CMAKE_CURRENT_LIST_DIR}" DIRECTORY)
    get_filename_component(FOLDER_TITLE "${CMAKE_CURRENT_LIST_DIR}" NAME)
    set(${PROJECT_NAME_VAR} ${FOLDER_TITLE})
endmacro()

macro(get_target_name PROJECT_NAME_VAR)
    get_directory_name(DIRECTORY_NAME)
    set(${PROJECT_NAME_VAR} ${PREFIX}_${DIRECTORY_NAME})
endmacro()

# macro for building test program
macro(build_test_program TEST_PROGRAM ARGS)
    add_executable(${TEST_PROGRAM} ${ARGS})
    set_target_properties(${TEST_PROGRAM} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${INSTALL_EXECUTE_DIR}/test/${TEST_PROGRAM})
endmacro()

# macro for building shared library
macro(build_shared_library LIBRARY_NAME ARGS)
    add_library(${LIBRARY_NAME} SHARED ${ARGS})
    set_target_properties(${LIBRARY_NAME} PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${INSTALL_SHARED_LIBRARY_DIRECTORY})
endmacro(build_shared_library LIBRARY_NAME ARGS)

# macro for building static library
macro(build_static_library LIBRARY_NAME ARGS)
    add_library(${LIBRARY_NAME} STATIC ${ARGS})
    set_target_properties(${LIBRARY_NAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${INSTALL_STATIC_LIBRARY_DIRECTORY})
endmacro(build_static_library LIBRARY_NAME ARGS)