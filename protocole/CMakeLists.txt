cmake_minimum_required(VERSION 3.10)

project(BTTP VERSION 0.0.2)

set(CMAKE_CXX_STANDARD 17)

file(
    GLOB_RECURSE
    sources
    src/*
)
file(
    GLOB_RECURSE
    includes
    include/*
)
add_library(
    ${PROJECT_NAME}
    ${sources}
    ${includes}
)

# Pour les tests unitaires
add_subdirectory(lib/googletest)
add_subdirectory(tests)

add_subdirectory(cli)