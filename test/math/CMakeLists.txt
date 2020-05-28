add_executable(math_tests Vec3Tests.cpp)
target_link_libraries(math_tests PRIVATE project_options project_warnings math catch_main)

catch_discover_tests(
    math_tests
    TEST_PREFIX
    "mathtests."
    WORKING_DIRECTORY
    "${CMAKE_SOURCE_DIR}"
    EXTRA_ARGS
    -s
    --reporter=xml
    --out=test.xml
)
