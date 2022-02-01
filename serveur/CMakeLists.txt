cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${EXECUTABLE_OUTPUT_PATH}/lib)

# DEPENDANCES
include(${CMAKE_CURRENT_LIST_DIR}/../protocole/CMakeLists.txt)

# CONSTANTES
set(BTTP_SERVEUR bttp-serveur) # Nom du projet CMake
set(BTTP_SERVEUR_VERSION 0.0.1) # Version du serveur
set(BTTP_SERVEUR_DEP ${BTTP_LIB}) # Dépendances
set(BTTP_SERVEUR_RACINE ${CMAKE_CURRENT_LIST_DIR}//include/Racine.h) # En-tête racine (fichier de configuration)

# PROJET
project(${BTTP_SERVEUR} LANGUAGES CXX VERSION ${BTTP_SERVEUR_VERSION})

# EXECUTABLE
# Configuration
configure_file(${BTTP_SERVEUR_RACINE}.in ${BTTP_SERVEUR_RACINE})
# Sources
file(
    GLOB_RECURSE
    BTTP_SERVEUR_SRC
    src/*.cpp
)
# En-têtes
file(
    GLOB_RECURSE
    BTTP_SERVEUR_INCLUDES
    include/*.h
)

# Bibliothèque
add_executable(
    ${BTTP_SERVEUR}
    ${BTTP_SERVEUR_SRC}
    ${BTTP_SERVEUR_INCLUDES}
)
target_link_libraries(
    ${BTTP_SERVEUR}
    ${BTTP_SERVEUR_DEP}
)
