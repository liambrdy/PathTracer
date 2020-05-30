add_executable(pathtracer main.cpp)
target_link_libraries(pathtracer PRIVATE math project_options project_warnings)

add_subdirectory(math)
add_subdirectory(core)