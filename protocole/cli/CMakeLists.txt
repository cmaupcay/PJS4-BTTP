set(BTTP_DEP OpenPGP segvcatch)
# find_package(OpenPGP REQUIRED)
# find_package(segvcatch REQUIRED)

# Executable de test
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE cli)
add_executable(
    ${EXECUTABLE}
    cli.cpp
)
target_link_libraries(
    ${EXECUTABLE} 
    ${PROJECT_NAME}
    ${BTTP_DEP}
)
