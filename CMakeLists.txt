cmake_minimum_required(VERSION 3.22)

project(main)

option(ENABLE_TESTS "Enable GoogleTest For Testing" OFF)

# Hash for googletest (Update regularly)
set(GOOGLETEST_GIT_TAG "52eb8108c5bdec04579160ae17225d66034bd723") # v1.17.0

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# For clang-tidy
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
file(CREATE_LINK
  "${CMAKE_BINARY_DIR}/compile_commands.json"
  "${CMAKE_SOURCE_DIR}/compile_commands.json"
  SYMBOLIC
)

include_directories(src)

add_subdirectory(src)

if(${ENABLE_TESTS})
	add_subdirectory(test)
endif()
