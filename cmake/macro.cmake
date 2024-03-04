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