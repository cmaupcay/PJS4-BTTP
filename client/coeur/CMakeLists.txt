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