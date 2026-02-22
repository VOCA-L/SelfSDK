# Cpp version 
macro(define_cpp_version)
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED true)
endmacro(define_cpp_version)

macro(define_c_version)
    set(CMAKE_C_STANDARD 11)
    set(CMAKE_C_STANDARD_REQUIRED true)
endmacro(define_c_version)

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

# Macro for building test program
macro(build_test_program)
    set(OPTIONS)
    set(ONE_VALUE_ARGS TARGET)
    set(MULTI_VALUE_ARGS SOURCES)

    cmake_parse_arguments(ARG
    "${OPTIONS}"
    "${ONE_VALUE_ARGS}"
    "${MULTI_VALUE_ARGS}"
    ${ARGN}
    )

    add_executable(${ARG_TARGET} ${ARG_SOURCES})
    set_target_properties(${ARG_TARGET} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${INSTALL_EXECUTE_DIR}/test/${ARG_TARGET})
endmacro()

# macro for building shared library
macro(build_shared_library)
    set(OPTIONS)
    set(ONE_VALUE_ARGS TARGET)
    set(MULTI_VALUE_ARGS SOURCES)

    cmake_parse_arguments(ARG
    "${OPTIONS}"
    "${ONE_VALUE_ARGS}"
    "${MULTI_VALUE_ARGS}"
    ${ARGN}
    )

    add_library(${ARG_TARGET} SHARED ${ARG_SOURCES})
    set_target_properties(${ARG_TARGET} PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${INSTALL_SHARED_LIBRARY_DIRECTORY})
endmacro(build_shared_library)

# macro for building static library
macro(build_static_library)
    set(OPTIONS)
    set(ONE_VALUE_ARGS TARGET)
    set(MULTI_VALUE_ARGS SOURCES)

    cmake_parse_arguments(ARG
    "${OPTIONS}"
    "${ONE_VALUE_ARGS}"
    "${MULTI_VALUE_ARGS}"
    ${ARGN}
    )

    add_library(${ARG_TARGET} STATIC ${ARG_SOURCES})
    set_target_properties(${ARG_TARGET} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${INSTALL_STATIC_LIBRARY_DIRECTORY})
endmacro(build_static_library LIBRARY_NAME ARGS)