build_test_program(
TARGET    
    utility_test 
SOURCES
    main.cpp
    ${COMPONENTS_PATH}/utility/crc/src/crc8.c
    ${COMPONENTS_PATH}/utility/crc/src/crc16.c
    )