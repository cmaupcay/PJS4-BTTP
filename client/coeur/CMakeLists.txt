# CONSTANTES
# Paramètres
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
### Valeurs par défaut
if(NOT DEFINED BTTP_UTILISER_CONTEXTE_PAR_DEFAUT)
    set(BTTP_UTILISER_CONTEXTE_PAR_DEFAUT true) # Défini si le client doit utiliser le dossier de contexte par défaut.
endif()
if(NOT DEFINED BTTP_CREATION_CHEMIN_PAR_DEFAUT)
    set(BTTP_CREATION_CHEMIN_PAR_DEFAUT true) # Défini si le client doit tenter de créer des chemins non existants.
endif()

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