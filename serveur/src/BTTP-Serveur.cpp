#include "../include/BTTP-Serveur.h"

namespace BTTP
{
    namespace Serveur
    {
        std::unique_ptr<Client::Contexte> definir_contexte(const char** argv)
        {
            const std::string dossier = std::filesystem::canonical(Client::Fichiers::dossier(argv[0])).string();
            // TODO Vérifier existence fichier et lever une erreur si inexistant.
            return std::make_unique<Client::Contexte>(dossier);
        }

        void definir_identite(std::unique_ptr<Client::Contexte>& contexte, const int& argc, const char** argv, const std::string& mdp)
        {
            const std::string fichier_identite = (argc >= 2 ? argv[1] : BTTP_SERVEUR_IDENTITE_PAR_DEFAUT);
            const Protocole::Identite* identite = nullptr;
            try 
            {
                Journal::ecrire("Identite", "Importation de \"" + fichier_identite + "\"...");
                identite = new Protocole::Identite{ Client::Identites::importer(fichier_identite, BTTP_IDENTITE_DOSSIER, contexte.get()) };
            }
            catch (BTTP::Erreur& erreur)
            {
                Journal::ecrire(erreur);
                Journal::ecrire("Identite", "Génération...");
                identite = new Protocole::Identite(fichier_identite, BTTP_SERVEUR_IDENTITE_CONTACT_PAR_DEFAUT, mdp);
                Client::Identites::exporter(*identite, BTTP_IDENTITE_DOSSIER, contexte.get());
            }
            contexte->modifier_identite(*identite);
        }

        const int executer(const int& argc, const char** argv, const std::string& mdp)
        {
            Journal::ecrire(BTTP_SERVEUR_INTRO);

            std::unique_ptr<Client::Contexte> contexte = definir_contexte(argv);
            Journal::ecrire("Contexte créé. Dossier : " + contexte->dossier());

            definir_identite(contexte, argc, argv, mdp);
            contexte->ajouter_variable({ BTTP_SERVEUR_IDENITITE_VAR_MDP, mdp });
            Journal::ecrire("Identité importée. Empreinte : " + contexte->identite()->cle_publique().empreinte());
            
            std::unique_ptr<Data::Source> source = std::make_unique<Data::Source>(contexte);
            std::unique_ptr<Sessions::Gestionnaire> sessions = std::make_unique<Sessions::Gestionnaire>(contexte);

            Accepteur accepteur{ BTTP_PORT, contexte, source, sessions };
            accepteur.lancer();

            sessions->fermer();

            return 0;
        }
    }
}