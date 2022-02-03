#include "../../include/commandes/Commandes.h"

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            namespace Commandes
            {
                const std::vector<Commande*> commandes()
                {
                    std::vector<Commande*> c;

                    return c;
                }

                const int resoudre(const int argc, const char** argv)
                {
                    if (argc > 1)
                    {
                        const std::vector<Commande*> com = commandes();
                        const size_t n_com = com.size();
                        for (int c = 0; c < n_com; c++)
                            if (argv[1] == com[c]->nom())
                            {
                                try { return com[c]->executer(argc, argv); }
                                catch (Erreur::Commande_Syntaxe& err)
                                {
                                    Console::afficher(com[c]->aide());
                                    return err.code();
                                }
                            }
                        throw Erreur::Commande_Inconnue(argv[1]);
                    }
                    Console::afficher(aide());
                    return EXIT_FAILURE;
                }

                const std::string aide()
                {
                    return "Usage : bttp-cli <commande> [options]";
                }
            }
        }
    }
}