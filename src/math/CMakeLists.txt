set(SOURCES Vec3.cpp)

set(HEADERS Vec3.h)

add_library(math OBJECT ${SOURCES} ${HEADERS})
target_link_libraries(math PRIVATE project_options project_warnings)
target_include_directories(math INTERFACE ../)