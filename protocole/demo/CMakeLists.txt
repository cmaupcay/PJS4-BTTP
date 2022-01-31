# CONSTANTES
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin) # Exécutables (../bin)
set(BTTP_DEMO_EXE demo)

# FICHIERS
# Sources
file(
    GLOB_RECURSE
    BTTP_DEMO_SRC
    src/*.cpp
)
# En-têtes
file(
    GLOB_RECURSE
    BTTP_DEMO_INCLUDE
    include/*.h
)

# EXECUTABLE
add_executable(
    ${BTTP_DEMO_EXE}
    ${BTTP_DEMO_SRC}
    ${BTTP_DEMO_INCLUDE}
)
target_link_libraries(
    ${BTTP_DEMO_EXE}
    ${BTTP_LIB}
)
