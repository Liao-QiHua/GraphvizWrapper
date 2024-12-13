# Each test source file starts with "test_",
# and each file is guaranteed to have a main function.
file(GLOB TEST_SOURCES "test_*.cpp")

# Enable the ctest feature.In ctest, the main function returns 0 to
# indicate that the test is passed.
enable_testing()

# Specify the output path for the executable.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Iterate through each source file to create an executable file.
foreach(TEST_SOURCE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_SOURCE})
    target_link_directories(${TEST_NAME} PUBLIC ${CMAKE_SOURCE_DIR})
    target_link_libraries(${TEST_NAME} GraphvizWrapper)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()

