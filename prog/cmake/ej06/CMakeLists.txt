cmake_minimum_required(VERSION 3.25)

project("prueba" VERSION 1.0.0 LANGUAGES C)

set(CMAKE_BUILD_TYPE Debug)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GOBJECT REQUIRED IMPORTED_TARGET gobject-2.0)

add_executable(prueba main.c tdoble.c)
target_link_libraries(prueba PRIVATE PkgConfig::GOBJECT)

