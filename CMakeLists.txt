cmake_minimum_required (VERSION 3.6.1)

project (checkers)

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

set (CHECKERS_VERSION_MAJOR 0)
set (CHECKERS_VERSION_MINOR 0)
set (CHECKERS_VERSION_PATCH 0)

set (
    CHECKERS_VERSION
    "${CHECKERS_VERSION_MAJOR}.${CHECKERS_VERSION_MINOR}.${CHECKERS_VERSION_PATCH}"
)

configure_file (
	"${PROJECT_SOURCE_DIR}/include/config.hpp.in"
	"${PROJECT_SOURCE_DIR}/include/config.hpp"
)

file (GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/source/*.cpp")
file (GLOB_RECURSE TESTS   "${PROJECT_SOURCE_DIR}/test/*.cpp")

set (TESTS ${TESTS} ${SOURCES})
list (FILTER TESTS EXCLUDE REGEX ".*checkers.cpp$")

add_executable (checkers ${SOURCES})
add_subdirectory ("${PROJECT_SOURCE_DIR}/external/catch")

message(${CATCH_INCLUDE_DIR})

enable_testing (true)
add_executable (checkers_test ${TESTS})
add_dependencies(checkers_test catch)
include_directories(${CATCH_INCLUDE_DIR} include)
add_test (NAME test_suite COMMAND checkers_test)

