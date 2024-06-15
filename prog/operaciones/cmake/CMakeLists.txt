cmake_minimum_required(VERSION 3.25)

project("Operaciones" VERSION 1.0.0 LANGUAGES C)

set(CMAKE_BUILD_TYPE Debug)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GOBJECT REQUIRED IMPORTED_TARGET gobject-2.0)

add_executable(operaciones ../src/main.c ../src/tdouble.c)
target_include_directories(operaciones PRIVATE ../src)
target_link_libraries(operaciones PRIVATE PkgConfig::GOBJECT)

