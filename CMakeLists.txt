cmake_minimum_required(VERSION 3.24)
project(file_stats)

set(CMAKE_CXX_STANDARD 23)

set(SOURCE_FILES
    src/main.cpp
    include/arg_parser.h
    src/arg_parser.cpp
    )

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE include)

option(LOG_TYPES "Log deduced auto types" ON)
message(STATUS "Logging deduced auto types: ${LOG_TYPES}")
if(LOG_TYPES)
    target_compile_definitions(${PROJECT_NAME} PUBLIC LOG_AUTO_TYPES)
endif()

set(DEFAULT_TOP_WORDS_COUNT_PARAM 10 CACHE STRING "Default top words list length")
target_compile_definitions(${PROJECT_NAME} PRIVATE DEFAULT_TOP_WORDS_COUNT=${DEFAUL_TOP_WORDS_COUNT_PARAM})
message(STATUS "DEFAULT_TOP_WORDS_COUNT = ${DEFAULT_TOP_WORDS_COUNT_PARAM}")
