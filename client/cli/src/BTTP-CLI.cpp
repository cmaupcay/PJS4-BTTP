#include "../include/BTTP-CLI.h"

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            const Protocole::Identite definir_identite()
            {

                std::vector<Protocole::Identite> identites = Client::Identites::liste();
                size_t n_identites = identites.size();
                if (n_identites == 0)
                {
                    Console::saut();
                    throw Erreur::Identite();
                }
                else if (n_identites == 1) return identites[0];
                else
                {
                    // Affichage des identités locales.
                    size_t i_identite = n_identites;
                    while (i_identite >= n_identites || i_identite < 0)
                    {
                        Console::saut();
                        Console::afficher("> Sélection de l'identité : ");
                        for (size_t i = 0; i < n_identites; i++)
                            Console::afficher("\t#" + std::to_string(i) + " - " + Protocole::Meta(identites[i].cle_publique()).afficher());
                        Console::saut();
                        // Sélection dans la liste.
                        i_identite = std::atol(Console::demander("Identite à utiliser : ").c_str());
                    }
                    return identites[i_identite];
                }
            }

            const int executer(const int& argc, const char** argv)
            {
                Contexte::initialiser(argc, argv);

                // Affichage introductif
                Console::afficher(BTTP_CLIENT_CLI_INTRO);
                Console::afficher("Dossier : " + Contexte::client()->dossier());

                // Définition de l'identité, sauf si aucune commande n'est renseignée ou pour la commande de gestion des identités.
                if (argc > 1 && strcmp(argv[1], BTTP_COMMANDE_IDENTITES) != 0)
                {
                    const Protocole::Identite id = definir_identite();
                    Contexte::client()->modifier_identite(id);
                    // Affichage de l'identité courante.
                    Console::saut();
                    Console::afficher("Identité : " + Protocole::Meta(id.cle_publique()).afficher());
                }
                
                Console::saut();
                const int code = Commandes::resoudre(argc, argv);
                Console::saut();

                return code;
            }
        }
    }
}