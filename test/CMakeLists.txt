# Install googletest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG ${GOOGLETEST_GIT_TAG}
	SOURCE_DIR ${CMAKE_SOURCE_DIR}/lib/googletest
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(BINARY ${CMAKE_PROJECT_NAME}-test)
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

add_executable(${BINARY} ${TEST_SOURCES})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)

add_test(NAME ${BINARY} COMMAND ${BINARY})
