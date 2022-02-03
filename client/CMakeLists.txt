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
set(BTTP_CLIENT_VERSION 0.0.1) # Version du client
set(BTTP_CLIENT_DEP ${BTTP_LIB}) # Dépendances
set(BTTP_CLIENT_COEUR_DOSSIER ${CMAKE_CURRENT_LIST_DIR}/coeur) # Dossier de référence du coeur
set(BTTP_CLIENT_RACINE ${BTTP_CLIENT_COEUR_DOSSIER}/include/Racine.h) # En-tête racine (fichier de configuration)
set(BTTP_CLIENT_LIB ${BTTP_CLIENT} ${BTTP_CLIENT_DEP})

# OPTIONS
if(NOT DEFINED BTTP_CLIENT_CLI)
    option(BTTP_CLIENT_CLI "Compile la version en ligne de commande du client." ON)
endif()
if(NOT DEFINED BTTP_CLIENT_GUI)
    option(BTTP_CLIENT_GUI "Compile la version graphique du client." ON)
endif()

# PROJET
project(${BTTP_CLIENT} LANGUAGES CXX VERSION ${BTTP_CLIENT_VERSION})

include(${BTTP_CLIENT_COEUR_DOSSIER}/CMakeLists.txt)

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
