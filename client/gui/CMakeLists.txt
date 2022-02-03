# Constantes
set(BTTP_CLIENT_GUI_EXE ${BTTP}-gui) # Dossier de référence du CLI

# Sources
file(
    GLOB_RECURSE
    BTTP_CLIENT_GUI_SRC
    ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp
)
# En-têtes
file(
    GLOB_RECURSE
    BTTP_CLIENT_GUI_INCLUDES
    ${CMAKE_CURRENT_LIST_DIR}/include/*.h
)

# Executable
add_executable(
    ${BTTP_CLIENT_GUI_EXE}
    ${BTTP_CLIENT_GUI_SRC}
    ${BTTP_CLIENT_GUI_INCLUDES}
)
target_link_libraries(
    ${BTTP_CLIENT_GUI_EXE}
    ${BTTP_CLIENT_LIB}
)