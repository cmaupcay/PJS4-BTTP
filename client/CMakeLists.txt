cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${EXECUTABLE_OUTPUT_PATH}/lib)

# DEPENDANCES
set(BTTP_DEMO OFF)
set(BTTP_TEST OFF)
include(${CMAKE_CURRENT_LIST_DIR}/../protocole/CMakeLists.txt)

# CONSTANTES
set(BTTP_CLIENT ${BTTP}-client) # Nom du projet CMake
set(BTTP_CLIENT_VERSION 0.1.2) # Version du client
set(BTTP_CLIENT_DEP ${BTTP_LIB}) # Dépendances
set(BTTP_CLIENT_RACINE ${CMAKE_CURRENT_LIST_DIR}/include/Racine.h) # En-tête racine (fichier de configuration)
set(BTTP_CLIENT_LIB ${BTTP_CLIENT} ${BTTP_CLIENT_DEP})
# Paramètres
## Réseau
if(NOT DEFINED BTTP_PORT)
    set(BTTP_PORT 1414) # Port par défaut des applications BTTP.
endif()
if(NOT DEFINED BTTP_TIMEOUT)
    set(BTTP_TIMEOUT 60000) # Temps d'attente maximum en reception (en ms)
endif()
## Dossier & Fichier
if(NOT DEFINED BTTP_DOSSIER)
    set(BTTP_DOSSIER .bttp) # Nom du dossier de travail du client
endif()
if(NOT DEFINED BTTP_IDENTITE_DOSSIER)
    set(BTTP_IDENTITE_DOSSIER id) # Nom du dossier où sont stockées les identités (relatif à BTTP_DOSSIER)
endif()
if(NOT DEFINED BTTP_IDENTITE_EXT)
    set(BTTP_IDENTITE_EXT asc) # Extension de fichier des identités
endif()
if(NOT DEFINED BTTP_SERVEUR_DOSSIER)
    set(BTTP_SERVEUR_DOSSIER srv) # Nom du dossier où sont stockées les serveurs enregistrés (relatif à BTTP_DOSSIER)
endif()
if(NOT DEFINED BTTP_SCRIPT_DOSSIER)
    set(BTTP_SCRIPT_DOSSIER src) # Nom du dossier où sont stockées les scripts (relatif à BTTP_DOSSIER)
endif()
### Valeurs par défaut
if(NOT DEFINED BTTP_UTILISER_CONTEXTE_PAR_DEFAUT)
    set(BTTP_UTILISER_CONTEXTE_PAR_DEFAUT true) # Défini si le client doit utiliser le dossier de contexte par défaut.
endif()
if(NOT DEFINED BTTP_CREATION_CHEMIN_PAR_DEFAUT)
    set(BTTP_CREATION_CHEMIN_PAR_DEFAUT true) # Défini si le client doit tenter de créer des chemins non existants.
endif()

# OPTIONS
if(NOT DEFINED BTTP_CLIENT_CLI)
    option(BTTP_CLIENT_CLI "Compile la version en ligne de commande du client." ON)
endif()
if(NOT DEFINED BTTP_CLIENT_GUI)
    option(BTTP_CLIENT_GUI "Compile la version graphique du client." ON)
endif()
if(NOT DEFINED BTTP_CLIENT_TEST)
    option(BTTP_CLIENT_TEST "Compile les tests du coeur du client." ON)
endif()

# PROJET
project(${BTTP_CLIENT} LANGUAGES CXX VERSION ${BTTP_CLIENT_VERSION})

# Configuration
configure_file(${BTTP_CLIENT_RACINE}.in ${BTTP_CLIENT_RACINE})
# Sources
file(
    GLOB_RECURSE
    BTTP_CLIENT_SRC
    ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp
)
# En-têtes
file(
    GLOB_RECURSE
    BTTP_CLIENT_INCLUDES
    ${CMAKE_CURRENT_LIST_DIR}/include/*.h
)
# Bibliothèque
add_library(
    ${BTTP_CLIENT}
    ${BTTP_CLIENT_SRC}
    ${BTTP_CLIENT_INCLUDES}
)
target_link_libraries(
    ${BTTP_CLIENT}
    ${BTTP_CLIENT_DEP}
)
target_include_directories(
    ${BTTP_CLIENT}
    PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include/"
)

# COMPLEMENTS
# CLI
if(BTTP_CLIENT_CLI)
    set(BTTP_CLIENT_CLI_DOSSIER ${CMAKE_CURRENT_LIST_DIR}/cli) # Dossier de référence du CLI
    include(${BTTP_CLIENT_CLI_DOSSIER}/CMakeLists.txt)
endif()
# GUI
if(BTTP_CLIENT_GUI)
    set(BTTP_CLIENT_GUI_DOSSIER ${CMAKE_CURRENT_LIST_DIR}/gui) # Dossier de référence du GUI
    include(${BTTP_CLIENT_GUI_DOSSIER}/CMakeLists.txt)
endif()

#Tests du coeur
if(BTTP_CLIENT_TEST)
    set(BTTP_CLIENT_TEST_DOSSIER ${CMAKE_CURRENT_LIST_DIR}/test)
    include(${BTTP_CLIENT_TEST_DOSSIER}/CMakeLists.txt)
endif()