cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

# CONSTANTES
set(BTTP BTTP) # Nom du projet CMake
set(BTTP_VERSION 0.0.2) # Version du protocole
set(BTTP_DEP OpenPGP segvcatch) # Dépendances
set(BTTP_DOSSIER .bttp) # Dossier de travail par défaut
set(BTTP_RACINE ${CMAKE_CURRENT_SOURCE_DIR}/include/Racine.h) # En-tête racine (fichier de configuration)
set(BTTP_DOSSIER_LIB lib) # Dossier des bibliothèques

# OPTIONS
option(BTTP_DEMO "Compile la démonstration du protocole." ON)
option(BTTP_TEST "Compile les tests du protocole." ON)

# PROJET
project(${BTTP} VERSION ${BTTP_VERSION})
set(BTTP_LIB ${PROJECT_NAME} ${BTTP_DEP})

# DEPENDANCES
# TODO Utiliser find_package

# FICHIERS
# Configuration
configure_file(${BTTP_RACINE}.in ${BTTP_RACINE})
# Sources
file(
    GLOB_RECURSE
    BTTP_SRC
    src/*.cpp
)
# En-têtes
file(
    GLOB_RECURSE
    BTTP_INCLUDES
    include/*.h
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
    add_subdirectory(${BTTP_DOSSIER_LIB}/googletest)
    add_subdirectory(test)
endif()