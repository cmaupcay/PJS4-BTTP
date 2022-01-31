# CONSTANTES
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(BTTP_TEST_EXE test)
set(BTTP_TEST_DEP gtest)

# FICHIERS
# Sources
file(
    GLOB_RECURSE
    BTTP_TEST_SRC
    src/*.cpp
)
# En-têtes
file(
    GLOB_RECURSE
    BTTP_TEST_INCLUDES
    include/*.h
)

# EXECUTABLE
add_executable(
    ${BTTP_TEST_EXE}
    ${BTTP_TEST_SRC}
    ${BTTP_TEST_INCLUDES}
)
target_link_libraries(
    ${BTTP_TEST_EXE} 
    ${BTTP_LIB}
    ${BTTP_TEST_DEP}
)