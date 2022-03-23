#include "../include/CLI.h"

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            const int executer(const int& argc, const char** argv)
            {
                // Détermination du dossier de travail...
                Contexte::initialiser(
                    // On prend le dossier où est situé l'exécutable.
                    std::filesystem::canonical(Fichiers::dossier(argv[0])).string()
                );

                // Affichage introductif
                Console::afficher(BTTP_CLIENT_CLI_INTRO);
                Console::afficher("Dossier : " + Contexte::dossier());

                // TODO Déplacer dans la classe de gestion d'identité du coeur du client (pas l'affichage, pas besoin d'un pointeur dans la fonction)
                Protocole::Identite* id = nullptr;
                try
                {
                    Console::afficher("Importation de votre identité... ", false);
                    id = new Protocole::Identite(Identites::importer("user"));
                    Console::afficher("FAIT");
                }
                catch (Client::Erreur::Fichiers::Inexistant& err)
                {
                    Console::afficher("ERREUR");
                    Console::afficher("Génération de votre identité... ", false);
                    id = new Protocole::Identite("user", "contact", "mdp");
                    Console::afficher("FAIT");
                    Console::afficher("Exportation de votre identité...", false);
                    Identites::exporter(*id);
                    Console::afficher("FAIT");
                }

                Console::afficher(""); // Saut de ligne

                const int code = Commandes::resoudre(argc, argv);

                // Affichage de sortie
                Console::afficher(""); // Saut de ligne

                return code;
            }
        }
    }
}