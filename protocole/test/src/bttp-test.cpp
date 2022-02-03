#include "../include/identite/Identite.h"
#include "../../demo/include/Outils.h"

int main(int argc, char* argv[])
{
    // Nom du dossier de travail
    const std::string dossier = dossier_depuis_fichier(argv[0]) + '/' + BTTP_TEST_DOSSIER;
    // Supression du dossier de travail temporaire
    if (std::filesystem::is_directory(dossier)) std::filesystem::remove_all(dossier);
    // Initialisation de la bibliothèque
    BTTP::Protocole::Contexte::initialiser(dossier);

    BTTP::Protocole::Test::Identite::dossier = dossier;

    std::cout << "bttp v" << BTTP_VERSION << " - test" << std::endl;
    std::cout << "Dossier de travail : " << BTTP::Protocole::Contexte::dossier() << std::endl;

    ::testing::InitGoogleTest(&argc, argv);
    const int retour = RUN_ALL_TESTS();

    // Supression du dossier de travail temporaire
    if (BTTP_TEST_DOSSIER_TMP && std::filesystem::is_directory(dossier))
            std::filesystem::remove_all(dossier);

    return retour;
}