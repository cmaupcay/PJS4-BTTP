#include "../include/CLI.h"

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            const int executer(const int& argc, const char** argv)
            {
                // Détermination du dossier de travail
                std::string dossier;
                if (std::getenv(BTTP_CLIENT_CLI_ENV_DOSSIER) == NULL)
                    dossier = std::filesystem::current_path();
                else dossier = std::getenv(BTTP_CLIENT_CLI_ENV_DOSSIER);
                Protocole::Contexte::initialiser();
                Coeur::Contexte::initialiser(dossier);


                // Affichage introductif
                Console::afficher(BTTP_CLIENT_CLI_INTRO);
                Console::afficher("Dossier : " + Coeur::Contexte::dossier());
                Console::afficher(""); // Saut de ligne

                const int code = Commandes::resoudre(argc, argv);

                // Affichage de sortie
                Console::afficher(""); // Saut de ligne

                return code;
            }
        }
    }
}