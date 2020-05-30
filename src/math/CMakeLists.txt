set(SOURCES Vec3.cpp Ray.cpp Hit.cpp Sphere.cpp)
set(HEADERS Vec3.h Ray.h Hit.h Sphere.h)

add_library(math OBJECT ${SOURCES} ${HEADERS})
target_link_libraries(math PRIVATE project_options project_warnings)
target_include_directories(math INTERFACE ../)