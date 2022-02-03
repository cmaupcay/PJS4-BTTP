cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${EXECUTABLE_OUTPUT_PATH}/lib)

# CONSTANTES
set(BTTP bttp) # Nom du projet CMake
set(BTTP_VERSION 0.0.6) # Version du protocole
set(BTTP_DEP OpenPGP segvcatch) # Dépendances
set(BTTP_DOSSIER .bttp) # Dossier de travail par défaut
set(BTTP_RACINE ${CMAKE_CURRENT_LIST_DIR}/include/Racine.h) # En-tête racine (fichier de configuration)
set(BTTP_LIB ${BTTP} ${BTTP_DEP}) # Importation de la librairie et de ses dépendances

# OPTIONS
option(BTTP_DEMO "Compile la démonstration du protocole." OFF)
option(BTTP_TEST "Compile les tests du protocole." OFF)

# PROJET
project(${BTTP} LANGUAGES CXX VERSION ${BTTP_VERSION})

# DEPENDANCES
# TODO Utiliser find_package

# FICHIERS
# Configuration
configure_file(${BTTP_RACINE}.in ${BTTP_RACINE})
# Sources
file(
    GLOB_RECURSE
    BTTP_SRC
    ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp
)
# En-têtes
file(
    GLOB_RECURSE
    BTTP_INCLUDES
    ${CMAKE_CURRENT_LIST_DIR}/include/*.h
)

# BIBLIOTHEQUE
add_library(
    ${BTTP}
    ${BTTP_SRC}
    ${BTTP_INCLUDES}
)

# COMPLEMENTS
# Démonstration
if(BTTP_DEMO)
    add_subdirectory(demo)
endif()
# Tests
if(BTTP_TEST)
    add_subdirectory(test)
endif()

# CACHE
unset(BTTP_DEMO CACHE)
unset(BTTP_TEXT CACHE)
