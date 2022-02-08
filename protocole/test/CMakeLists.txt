# CONSTANTES
set(BTTP_TEST_EXE ${BTTP}-test)
set(BTTP_TEST_DEP gtest)
set(BTTP_TEST_RACINE ${CMAKE_CURRENT_LIST_DIR}/include/Racine.h) # En-tête racine (fichier de configuration)
# DEBUG
set(BTTP_TEST_DOSSIER_TMP true) # Défini si le dossier doit être effacer à la fin des tests

# DEPENDANCES
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/modules/googletest)

# FICHIERS
configure_file(${BTTP_TEST_RACINE}.in ${BTTP_TEST_RACINE})
# Sources
file(
    GLOB_RECURSE
    BTTP_TEST_SRC
    ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp
)
# En-têtes
file(
    GLOB_RECURSE
    BTTP_TEST_INCLUDES
    ${CMAKE_CURRENT_LIST_DIR}/include/*.h
)

# EXECUTABLE
add_executable(
    ${BTTP_TEST_EXE}
    ${BTTP_TEST_SRC}
    ${BTTP_TEST_INCLUDES}
    ${BTTP_DEMO_OUTILS}
)
target_link_libraries(
    ${BTTP_TEST_EXE} 
    ${BTTP_LIB}
    ${BTTP_TEST_DEP}
)
set_target_properties(
    ${BTTP_TEST_EXE} 
    PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY 
    "${EXECUTABLE_OUTPUT_PATH}/tests"
)
