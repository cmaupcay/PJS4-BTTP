# Constantes
set(BTTP_CLIENT_CLI_EXE ${BTTP}-cli) # Dossier de référence du CLI
set(BTTP_CLIENT_CLI_VERSION 0.0.1) # Version du CLI
set(BTTP_CLIENT_CLI_RACINE ${CMAKE_CURRENT_LIST_DIR}/include/Racine.h) # En-tête racine (fichier de configuration)

# Configuration
configure_file(${BTTP_CLIENT_CLI_RACINE}.in ${BTTP_CLIENT_CLI_RACINE})

# Sources
file(
    GLOB_RECURSE
    BTTP_CLIENT_CLI_SRC
    ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp
)
# En-têtes
file(
    GLOB_RECURSE
    BTTP_CLIENT_CLI_INCLUDES
    ${CMAKE_CURRENT_LIST_DIR}/include/*.h
)

# Executable
add_executable(
    ${BTTP_CLIENT_CLI_EXE}
    ${BTTP_CLIENT_CLI_SRC}
    ${BTTP_CLIENT_CLI_INCLUDES}
)
target_link_libraries(
    ${BTTP_CLIENT_CLI_EXE}
    ${BTTP_CLIENT_LIB}
)