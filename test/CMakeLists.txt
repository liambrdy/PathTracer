if (CONAN_CATCH2_ROOT_DEBUG)
    include(${CONAN_CATCH2_ROOT_DEBUG}/lib/cmake/Catch2/Catch.cmake)
else ()
    include(${CONAN_CATCH2_ROOT}/lib/cmake/Catch2/Catch.cmake)
endif ()

add_library(catch_main catch_main.cpp)
target_link_libraries(catch_main PUBLIC CONAN_PKG::catch2)
target_link_libraries(catch_main PRIVATE project_options)

add_executable(tests tests.cpp)
target_link_libraries(tests PRIVATE project_options project_warnings catch_main)

catch_discover_tests(
    tests
    TEST_PREFIX
    "unittests."
    WORKING_DIRECTORY
    "${CMAKE_SOURCE_DIR}"
    EXTRA_ARGS
    -s
    --reporter=xml
    --out=test.xml
)
