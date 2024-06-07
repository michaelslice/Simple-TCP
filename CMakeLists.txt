cmake_minimum_required(VERSION 3.10)
project(SimpleChat)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Globbing to collect source files
file(GLOB_RECURSE CLIENT_SOURCES "${CMAKE_SOURCE_DIR}/client/*.c")
file(GLOB_RECURSE SERVER_SOURCES "${CMAKE_SOURCE_DIR}/server/*.c")
set(COMMON_SOURCES "${CMAKE_SOURCE_DIR}/main.c")

# Include directories
include_directories("$CMAKE_SOURCE_DIR/client")
include_directories("$CMAKE_SOURCE_DIR/server")

# Ignore CMake-generated files
list(FILTER CLIENT_SOURCES EXCLUDE REGEX ".*CMakeCXXCompilerId.cpp$")
list(FILTER SERVER_SOURCES EXCLUDE REGEX ".*CMakeCXXCompilerId.cpp$")
list(FILTER COMMON_SOURCES EXCLUDE REGEX ".*CMakeCXXCompilerId.cpp$")

# add executables
add_executable(Client ${CLIENT_SOURCES} ${COMMON_SOURCES})
add_executable(Server ${SERVER_SOURCES} ${COMMON_SOURCES})