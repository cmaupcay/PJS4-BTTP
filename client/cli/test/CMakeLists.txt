# CONSTANTES
set(BTTP_CLIENT_CLI_TEST_EXE ${BTTP_CLIENT_CLI_EXE}-test)
set(BTTP_CLIENT_CLI_TEST_DEP gtest)
set(BTTP_CLIENT_CLI_TEST_RACINE ${CMAKE_CURRENT_LIST_DIR}/include/Racine.h) # En-tête racine (fichier de configuration)

# DEBUG
set(BTTP_CLIENT_CLI_TEST_DOSSIER_TMP true) # Défini si le dossier doit être effacer à la fin des tests

# DEPENDANCES
if(NOT TARGET gtest)
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/modules/googletest)
endif()

# FICHIERS
configure_file(${BTTP_CLIENT_CLI_TEST_RACINE}.in ${BTTP_CLIENT_CLI_TEST_RACINE})
# Sources
file(
    GLOB_RECURSE
    BTTP_CLIENT_CLI_TEST_SRC
    ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp
)
# En-têtes
file(
    GLOB_RECURSE
    BTTP_CLIENT_CLI_TEST_INCLUDES
    ${CMAKE_CURRENT_LIST_DIR}/include/*.h
)

list(
    REMOVE_ITEM 
    BTTP_CLIENT_CLI_SRC 
    ${BTTP_CLIENT_CLI_MAIN}
)



# EXECUTABLE
add_executable(
    ${BTTP_CLIENT_CLI_TEST_EXE}
    ${BTTP_CLIENT_CLI_SRC}
    ${BTTP_CLIENT_CLI_INCLUDES}
    ${BTTP_CLIENT_CLI_TEST_SRC}
    ${BTTP_CLIENT_CLI_TEST_INCLUDES}
    # ${BTTP_DEMO_OUTILS}
)
target_link_libraries(
    ${BTTP_CLIENT_CLI_TEST_EXE}
    ${BTTP_CLIENT_LIB}
    ${BTTP_CLIENT_CLI_TEST_DEP}    
)
set_target_properties(
    ${BTTP_CLIENT_CLI_TEST_EXE} 
    PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY 
    "${EXECUTABLE_OUTPUT_PATH}/tests"
)
