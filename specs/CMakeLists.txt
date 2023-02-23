
set(BUILD_TESTING OFF)
set(CATCH_INSTALL_DOCS OFF)

add_subdirectory(${CMAKE_SOURCE_DIR}/third_party/Catch2)
# These tests can use the Catch2-provided main
add_executable(runtests)
target_link_libraries(runtests PUBLIC Catch2::Catch2WithMain)
# These tests need their own main
# add_executable(custom-main-tests test.cpp test-main.cpp)
# target_link_libraries(custom-main-tests PRIVATE Catch2::Catch2)

set(TESTS_DIR ${CMAKE_SOURCE_DIR}/specs/tests)
target_sources(runtests PRIVATE
    ${TESTS_DIR}/mytest.cpp
)

add_test(NAME tests COMMAND runtests)