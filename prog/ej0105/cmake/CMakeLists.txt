cmake_minimum_required(VERSION 3.25)

project("prueba" VERSION 1.0.0 LANGUAGES C)

set(CMAKE_BUILD_TYPE Debug)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GOBJECT REQUIRED IMPORTED_TARGET gobject-2.0)

add_executable(ejemplo01 ../src/ejemplo01.c)
add_executable(ejemplo02 ../src/ejemplo02.c)
add_executable(ejemplo03 ../src/ejemplo03.c)
add_executable(ejemplo04 ../src/ejemplo04.c)
add_executable(ejemplo05 ../src/ejemplo05.c)

target_link_libraries(ejemplo01 PRIVATE PkgConfig::GOBJECT)
target_link_libraries(ejemplo02 PRIVATE PkgConfig::GOBJECT)
target_link_libraries(ejemplo03 PRIVATE PkgConfig::GOBJECT)
target_link_libraries(ejemplo04 PRIVATE PkgConfig::GOBJECT)
target_link_libraries(ejemplo05 PRIVATE PkgConfig::GOBJECT)
