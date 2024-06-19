cmake_minimum_required(VERSION 3.25)

project("Ejemplo 7" VERSION 1.0.0 LANGUAGES C)

set(CMAKE_BUILD_TYPE Debug)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GOBJECT REQUIRED IMPORTED_TARGET gobject-2.0)

add_executable(ejemplo07 ../src/main.c ../src/tdouble.c)
target_include_directories(ejemplo07 PRIVATE ../src)
target_link_libraries(ejemplo07 PRIVATE PkgConfig::GOBJECT)

