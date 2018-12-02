cmake_minimum_required(VERSION 3.0.0)
project(vector VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(vec_lib vec_lib.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
