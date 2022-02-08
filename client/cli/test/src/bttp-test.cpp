#include "../include/Racine.h"

int main(int argc, char* argv[])
{

    BTTP::Client::Contexte::initialiser();

    std::cout << "bttp client v" << BTTP_VERSION << " - test" << std::endl;

    ::testing::InitGoogleTest(&argc, argv);
    const int retour = RUN_ALL_TESTS();

    return retour;
}