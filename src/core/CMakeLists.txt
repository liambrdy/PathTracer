set(SOURCES Primitive.cpp)
set(HEADERS Primitive.h)

add_library(core OBJECT ${SOURCES} ${HEADERS})
target_link_libraries(core PRIVATE project_options project_warnings math)
target_include_directories(core INTERFACE ../)