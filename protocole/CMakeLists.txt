cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

# CONSTANTES
set(BTTP_VERSION 0.0.2) # Version du protocole
set(BTTP_DEP OpenPGP segvcatch) # Dépendances

# PROJET
project(BTTP VERSION ${BTTP_VERSION})
set(BTTP_LIB ${PROJECT_NAME} ${BTTP_DEP})

# DEPENDANCES
# TODO Utiliser find_package

# FICHIERS
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
    ${PROJECT_NAME}
    ${BTTP_SRC}
    ${BTTP_INCLUDES}
)

# COMPLEMENTS
add_subdirectory(demo)
add_subdirectory(test)