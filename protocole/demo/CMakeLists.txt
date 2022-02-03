# CONSTANTES
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin) # Exécutables (../bin)
set(BTTP_DEMO_EXE ${BTTP}-demo)

# FICHIERS
# Sources
file(
    GLOB_RECURSE
    BTTP_DEMO_SRC
    ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp
)
# En-têtes
file(
    GLOB_RECURSE
    BTTP_DEMO_INCLUDE
    ${CMAKE_CURRENT_LIST_DIR}/include/*.h
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
