cmake_minimum_required(VERSION 3.0.0)
project(AAPV-BSA VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(include)

set(SOURCES src/main.cpp, src/BinarySearch.cpp)

file(GLOB SOURCES "src/*.cpp")

add_executable(AAPV-BSA ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
