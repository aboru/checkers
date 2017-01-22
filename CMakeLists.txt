# Copyright 2016 Anders Borg [aboru]
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required (VERSION 3.6.1)

project (checkers)

# set (CMAKE_CXX_STANDARD 11)
# set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_FLAGS "-g -Wall -Wextra -m64")

set (CHECKERS_VERSION_MAJOR 0)
set (CHECKERS_VERSION_MINOR 1)
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
list (FILTER TESTS EXCLUDE REGEX ".*main.cpp$")

list (FILTER TESTS EXCLUDE REGEX ".*(~|#)+.*")
list (FILTER SOURCES EXCLUDE REGEX ".*(~|#)+.*")

add_executable (checkers ${SOURCES})
target_link_libraries (checkers)

add_subdirectory ("${PROJECT_SOURCE_DIR}/external/catch")

enable_testing (true)
add_executable (checkers_test ${TESTS})
target_link_libraries(checkers_test)
add_dependencies(checkers_test catch)
include_directories(${CATCH_INCLUDE_DIR} include)
add_test (NAME test_suite COMMAND checkers_test)
