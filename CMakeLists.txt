cmake_minimum_required (VERSION 3.6.1)
project (checkers)

set (CHECKERS_VERSION_MAJOR 0)
set (CHECKERS_VERSION_MINOR 0)
set (CHECKERS_VERSION_PATCH 0)

configure_file ( 
	"${PROJECT_SOURCE_DIR}/include/config.hpp.in" 
	"${PROJECT_SOURCE_DIR}/include/config.hpp"	
)

include_directories (include)

file (GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/source/*.cpp")

add_executable (checkers ${SOURCES})
