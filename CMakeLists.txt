cmake_minimum_required(VERSION 3.22)

project(main)

option(ENABLE_DEBUG "Enable Use of GDB For Debugging" OFF)
option(ENABLE_TESTS "Enable GoogleTest For Testing" OFF)
option(ENABLE_LINT "Enable Use of clang-tidy For Linting" ON)

# Hash for googletest (Update regularly)
set(GOOGLETEST_GIT_TAG "52eb8108c5bdec04579160ae17225d66034bd723") # v1.17.0

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion -Wsign-conversion")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic-errors")

if(${ENABLE_DEBUG})
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb")
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -DNDEBUG")
endif()

if(${ENABLE_LINT})
	set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
	file(CREATE_LINK
		"${CMAKE_BINARY_DIR}/compile_commands.json"
		"${CMAKE_SOURCE_DIR}/compile_commands.json"
		SYMBOLIC
	)
endif()

include_directories(src)

add_subdirectory(src)

if(${ENABLE_TESTS})
	add_subdirectory(test)
endif()
