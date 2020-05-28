cmake_minimum_required(VERSION 3.16)

project(
    PathTracer
    VERSION 0.1.0
    LANGUAGES CXX
)

include(cmake/ProjectSettings.cmake)
include(cmake/ProjectWarnings.cmake)
include(cmake/StaticAnalyzers.cmake)
include(cmake/Sanitizers.cmake)
include(cmake/Conan.cmake)

add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)
enable_sanitizers(project_options)

add_library(project_warnings INTERFACE)
set_project_warnings(project_warnings)

run_conan()

option(ENABLE_TESTING "Enable testing" ON)
if (ENABLE_TESTING)
    enable_testing()
    add_subdirectory(test)
endif ()

add_subdirectory(src)
