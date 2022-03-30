#include "../../include/sessions/Session.h"

namespace BTTP
{
    namespace Serveur
    {
        namespace Sessions
        {
            const bool Session::authentification()
            {
                // TODO AUTHENTIFICATION
                // TODO Demande de l'empreinte.
                // TODO Verification de l'empreinte dans la table.
                // TODO Si existante, authentification réussie (en cas de fraude, l'attaquant ne pourra pas déchiffrer les messages à moins de posséder la clé privéé).
                // TODO Si inexistante, authentification par compte (utilisateur/mot de passe).
                // TODO Ajout en base.
                return false;
            }

            void Session::mode_distant(const std::string& mdp)
            {
                Journal::ecrire(BTTP_SERVEUR_COMPOSANT_SESSIONS_SESSION, "Nouvel appareil distant.");
                this->definir_type(Type::DISTANT);
                while (this->connexion()->ouverte()) {}
            }

            void Session::mode_client(const std::string& mdp, const Protocole::Messages::Demande& demande_initiale)
            {
                Journal::ecrire(BTTP_SERVEUR_COMPOSANT_SESSIONS_SESSION, "Nouveau client.");
                this->definir_type(Type::CLIENT);

                while (this->connexion()->ouverte())
                {
                    // paquet = this->contexte->identite()->dechiffrer
                }
            }

            void Session::lancer()
            {
                size_t id = LONG_MAX;

                try
                {
                    id = this->_gestionnaire->ajout_session(this);
                    const std::string mdp = this->contexte->variable(BTTP_SERVEUR_IDENITITE_VAR_MDP).valeur;

                    Journal::ecrire(BTTP_SERVEUR_COMPOSANT_SESSIONS_SESSION, "En attente du client...");
                    Protocole::Messages::Demande demande{ this->connexion()->recevoir() };
                    const std::string& champs = demande.champs();
                    if (champs == BTTP_DEMANDE_CLE_PUBLIQUE) // Envoi de la clé publique en clair : ajout du serveur.
                    {
                        this->definir_type(Type::INITIALISATION);
                        Journal::ecrire(BTTP_SERVEUR_COMPOSANT_SESSIONS_SESSION, "Partage de la clé publique au client...");
                        const Client::Serveurs::Messages::ReponseClePublique reponse{ this->contexte->identite()->cle_publique() };
                        this->connexion()->envoyer(reponse.construire());
                        const Protocole::Identite::MessageNonVerifie confirmation{ 
                            this->connexion()->recevoir(), *this->contexte->identite().get(), mdp
                        };
                        if (confirmation.clair()[0] == static_cast<char>(Protocole::Messages::Type::ERREUR))
                        {
                            const Protocole::Messages::Erreur erreur{ confirmation.clair() };
                            throw BTTP::Erreur(erreur.nom(), erreur.message(), erreur.code());
                        }
                    }
                    else if (champs == BTTP_DEMANDE_AUTH)
                    {
                        if (this->authentification())
                        {
                            // TODO Attente du premier message et délégation au mode.
                            Journal::ecrire(BTTP_SERVEUR_COMPOSANT_SESSIONS_SESSION, "Définition du type de client...");
                            demande.deconstruire( 
                                this->contexte->identite()->dechiffrer(
                                    this->connexion()->recevoir(), *this->client()->cle().get(), mdp
                                )
                            );
                            if (demande.champs() == BTTP_DEMANDE_DISTANT) this->mode_distant(mdp);
                            else this->mode_client(mdp, demande);
                        }
                        // else throw ... // TODO Erreur Authentification.
                    }
                    // else throw ... // TODO Erreur Demande incohérente.

                }
                catch (BTTP::Erreur& erreur)
                { 
                    Journal::ecrire(BTTP_SERVEUR_COMPOSANT_SESSIONS_SESSION, "Une erreur est survenue dans la session.");
                    Journal::ecrire(erreur);
                }

                try
                {
                    Journal::ecrire(BTTP_SERVEUR_COMPOSANT_SESSIONS_SESSION, "Fermeture de la session...");
                    this->connexion()->fermer();
                    this->_gestionnaire->supprimer_session(id);
                }
                catch (BTTP::Erreur& erreur)
                {
                    Journal::ecrire(BTTP_SERVEUR_COMPOSANT_SESSIONS_SESSION, "Impossible de fermer la session.");
                    Journal::ecrire(erreur);
                }
            }
        }
    }
}