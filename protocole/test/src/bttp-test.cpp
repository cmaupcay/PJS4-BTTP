#include "../include/identite/Identite.h"
#include "../../demo/include/Outils.h"

int main(int argc, char* argv[])
{

    BTTP::Protocole::Contexte::initialiser();

    std::cout << "bttp v" << BTTP_VERSION << " - test" << std::endl;

    ::testing::InitGoogleTest(&argc, argv);
    const int retour = RUN_ALL_TESTS();

    return retour;
}