get_directory_name(TARGET)

## Create Shared Library
add_library(${TARGET} SHARED
    src/point.cpp
)