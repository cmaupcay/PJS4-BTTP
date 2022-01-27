cmake_minimum_required(VERSION 3.10)

project(BTTP VERSION 0.0.2)

set(BTTP_DEP OpenPGP segvcatch)
# find_package(OpenPGP REQUIRED)
# find_package(segvcatch REQUIRED)

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

# Executable de test
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE bttp)
add_executable(
    ${EXECUTABLE}
    tests/bttp.cpp
)
target_link_libraries(
    ${EXECUTABLE} 
    ${PROJECT_NAME}
    ${BTTP_DEP}
)