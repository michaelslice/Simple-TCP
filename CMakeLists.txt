cmake_minimum_required(VERSION 3.10)
project(TradingEngine)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Globbing to collect source files
file(GLOB_RECURSE SOURCES 
    #"${PROJECT_SOURCE_DIR}/*.h"
    #"${PROJECT_SOURCE_DIR}/*.c"

    # "${PROJECT_SOURCE_DIR}/Orderbook/*.cpp"
    main.c
)

# Ignore CMake-generated files
list(FILTER SOURCES EXCLUDE REGEX ".*CMakeCXXCompilerId.cpp$")

# Add executable target, using all files listed in SOURCES


# add_executable(Chat ${SOURCES})
add_executable(Chat ${SOURCES})