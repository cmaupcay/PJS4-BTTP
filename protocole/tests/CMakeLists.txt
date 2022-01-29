set(TEST_DEP OpenPGP segvcatch gtest)
# find_package(OpenPGP REQUIRED)
# find_package(segvcatch REQUIRED)
# find_package(gtest REQUIRED)

# Executable de test
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/tests)
set(EXECUTABLE tests)
add_executable(
    ${EXECUTABLE}
    src/main.cpp src/IdentiteTest.cpp
)
target_link_libraries(
    ${EXECUTABLE} 
    ${PROJECT_NAME}
    ${TEST_DEP}
)