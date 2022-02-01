# Configuration
configure_file(${BTTP_CLIENT_RACINE}.in ${BTTP_CLIENT_RACINE})

# Sources
file(
    GLOB_RECURSE
    BTTP_CLIENT_SRC
    src/*.cpp
)
# En-têtes
file(
    GLOB_RECURSE
    BTTP_CLIENT_INCLUDES
    include/*.h
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