#include "../include/Racine.h"

int main(int argc, char* argv[])
{

    BTTP::Protocole::Contexte::initialiser();

    std::cout << "bttp v" << BTTP_SERVEUR_VERSION << " - test" << std::endl;

    ::testing::InitGoogleTest(&argc, argv);
    const int retour = RUN_ALL_TESTS();

    return retour;
}