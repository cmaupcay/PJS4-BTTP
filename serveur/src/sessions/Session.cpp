#include "../../include/sessions/Session.h"

namespace BTTP
{
    namespace Serveur
    {
        namespace Sessions
        {
            const bool Session::authentification()
            {

                const std::string mdp = this->contexte->variable(BTTP_SERVEUR_IDENITITE_VAR_MDP).valeur;

                Journal::ecrire(BTTP_SERVEUR_COMPOSANT_SESSIONS_SESSION, "Authentification appareil.");

                const Client::Serveurs::Messages::DemandeEmpreinteCle demande;

                this->connexion()->envoyer(demande.construire());

                Journal::ecrire(BTTP_SERVEUR_COMPOSANT_SESSIONS_SESSION, "En attente de l'empreinte du client.");

                const Protocole::Identite::MessageNonVerifie retourEmpreinte { 
                    this->connexion()->recevoir(), *this->contexte->identite().get(), mdp
                };
                if (retourEmpreinte.clair()[0] == static_cast<char>(Protocole::Messages::Type::ERREUR))
                {
                    const Protocole::Messages::Erreur erreur{ retourEmpreinte.clair() };
                    throw BTTP::Erreur(erreur.nom(), erreur.message(), erreur.code());
                }

                const std::string empreinte = Client::Serveurs::Messages::ReponseEmpreinteCle(retourEmpreinte.clair()).data();

                std::vector<std::vector<Data::Argument>> rep;

                std::vector<Data::Argument> select;
                std::vector <Data::Argument> where;

                select.push_back(Data::Argument {"*"});
                where.push_back(Data::Argument {"empreinte_cle_publique", empreinte, Data::Type::TEXTE});

                if(this->source()->selectionner("terminal", select, where).size() == 0)
                
                {

                    Journal::ecrire(BTTP_SERVEUR_COMPOSANT_SESSIONS_SESSION, "Nouvel utilisateur");

                    const Protocole::Messages::Erreur erreur;

                    this->connexion()->envoyer(erreur.construire());

                    const Protocole::Identite::MessageNonVerifie pret { 
                        this->connexion()->recevoir(), *this->contexte->identite().get(), mdp
                    };
                    
                    if (pret.clair()[0] == static_cast<char>(Protocole::Messages::Type::ERREUR))
                    {
                        const Protocole::Messages::Erreur erreur{ pret.clair() };
                        throw BTTP::Erreur(erreur.nom(), erreur.message(), erreur.code());
                    }            

                    const Client::Serveurs::Messages::DemandeClePublique demandeCle;

                    this->connexion()->envoyer(demandeCle.construire());

                    Journal::ecrire(BTTP_SERVEUR_COMPOSANT_SESSIONS_SESSION, "Demande clé publique");

                    const Protocole::Identite::MessageNonVerifie demandeNonVerifiee { this->connexion()->recevoir(), *this->contexte->identite().get(), mdp};
                    
                    Journal::ecrire(BTTP_SERVEUR_COMPOSANT_SESSIONS_SESSION, "Clé publique reçue");

                    // Reception de la clé publique du client
                    const Protocole::Cle::Publique cle = Client::Serveurs::Messages::ReponseClePublique(demandeNonVerifiee.clair()).cle();

                    if(!demandeNonVerifiee.verifier(cle))
                        return false;
            
                    // à partir de maintenant tous les échanges seront chiffrés et vérifiés
                    const Protocole::Messages::Pret confirmation;
                    this->connexion()->envoyer(this->contexte->identite()->chiffrer(confirmation.construire(), cle, mdp));
    
                    // envoi de la demande de l'utilisateur
                    const Client::Serveurs::Messages::DemandeUtilisateur demandeUtilisateur;
                    this->connexion()->envoyer(this->contexte->identite()->chiffrer(demandeUtilisateur.construire(), cle, mdp));
                    
                    // Reception de l'utilisateur
                    const Client::Serveurs::Messages::ReponseUtilisateur reponseUtilisateur { this->contexte->identite()->dechiffrer(this->connexion()->recevoir(), cle, mdp) };

                    Protocole::Messages::Reponse reponse;

                    reponse.deconstruire(reponseUtilisateur.data());

                    const std::string utilisateur = reponse.data();

                    // Envoi de la confirmation
                    this->connexion()->envoyer(this->contexte->identite()->chiffrer(confirmation.construire(), cle, mdp));

                    // Envoi de la demande de mot de passe
                    const Client::Serveurs::Messages::DemandeMotDePasse demandeMDP { utilisateur };
                    this->connexion()->envoyer(this->contexte->identite()->chiffrer(demandeMDP.construire(), cle, mdp));

                    // Reception du mot de passe
                    const Client::Serveurs::Messages::ReponseMotDePasse reponseMDP { this->contexte->identite()->dechiffrer(this->connexion()->recevoir(), cle, mdp)};

                    reponse.deconstruire(reponseMDP.data());

                    const std::string mdpUtilisateur = reponse.data();

                    Journal::ecrire(BTTP_SERVEUR_COMPOSANT_SESSIONS_SESSION, "Identifiants récupérés");

                    std::string mdpHash;

                    std::vector<Data::Argument> selection;
                    std::vector<Data::Argument> conditions;

                    selection.push_back(Data::Argument {"id", "", Data::Type::NOMBRE});
                    conditions.push_back(Data::Argument {"pseudo", utilisateur, Data::Type::TEXTE});
                    conditions.push_back(Data::Argument {"mdp", mdpUtilisateur, Data::Type::TEXTE});

                    const std::vector<std::vector<Data::Argument>> resultat = this->source()->selectionner("utilisateur", selection, conditions);

                    if(resultat.size() > 0)
                        this->connexion()->envoyer(this->contexte->identite()->chiffrer(confirmation.construire(), cle, mdp));
                    else
                    {
                        Protocole::Messages::Erreur erreur;

                        this->connexion()->envoyer(this->contexte->identite()->chiffrer(erreur.construire(), cle, mdp));
                        return false;

                    }

                    std::vector<Data::Argument> selectionInser;

                    selectionInser.push_back(Data::Argument {"cle_publique", cle.exporter(), Data::Type::TEXTE});
                    selectionInser.push_back(Data::Argument {"empreinte_cle_publique", cle.empreinte(), Data::Type::TEXTE});
                    selectionInser.push_back(Data::Argument {"nom", "terminal 1", Data::Type::TEXTE});
                    selectionInser.push_back(Data::Argument {"disponible", "1", Data::Type::NOMBRE});
                    selectionInser.push_back(Data::Argument {"id_proprietaire", resultat.at(0).at(0).valeur, Data::Type::NOMBRE});
                    selectionInser.push_back(Data::Argument {"meta", "informations additionnelles", Data::Type::TEXTE});

                    this->source()->inserer("terminal", selectionInser);

                    Journal::ecrire(BTTP_SERVEUR_COMPOSANT_SESSIONS_SESSION, "Insertion du terminal effectuée");

                    return true;
                    
                }
                else
                {
                    Journal::ecrire(BTTP_SERVEUR_COMPOSANT_SESSIONS_SESSION, "Appareil connu.");
                    std::vector<Data::Argument> selection;
                    std::vector<Data::Argument> conditions;

                    selection.push_back(Data::Argument {"cle_publique", "", Data::Type::TEXTE});
                    conditions.push_back(Data::Argument {"empreinte_cle_publique", empreinte, Data::Type::TEXTE});

                    // On récupère la clé publique associée à l'empreinte
                    Protocole::Cle::Publique cle {this->source()->selectionner("terminal", selection, conditions).at(0).at(0).valeur};
                    
                    // On vérifie si le message provient bien de celui qu'il prétend être
                    if(!retourEmpreinte.verifier(cle))
                        return false;

                    Journal::ecrire(BTTP_SERVEUR_COMPOSANT_SESSIONS_SESSION, "Appareil vérifié.");

                    return true; 

                }

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
                    const std::string question = this->connexion()->recevoir();
                    Protocole::Messages::Demande demande;
                    try
                    {
                        const Protocole::Identite::MessageNonVerifie demandeNonVerifiee { question, *this->contexte->identite().get(), mdp
                        };

                        demande.deconstruire(demandeNonVerifiee.clair());
                    }
                    catch(const BTTP::Erreur& e)
                    {
                        demande.deconstruire(question);
                    }

                    const std::string& champs = demande.champs();
                    if (champs == BTTP_DEMANDE_CLE_PUBLIQUE) // Envoi de la clé publique en clair : ajout du serveur.
                    {
                        this->definir_type(Type::INITIALISATION);
                        Journal::ecrire(BTTP_SERVEUR_COMPOSANT_SESSIONS_SESSION, "Partage de la clé publique au client...");
                        const Client::Serveurs::Messages::ReponseClePublique reponse{ this->contexte->identite()->cle_publique() };
                        this->connexion()->envoyer(reponse.construire());
                        const Protocole::Identite::MessageNonVerifie retour { 
                            this->connexion()->recevoir(), *this->contexte->identite().get(), mdp
                        };
                        if (retour.clair()[0] == static_cast<char>(Protocole::Messages::Type::ERREUR))
                        {
                            const Protocole::Messages::Erreur erreur{ retour.clair() };
                            throw BTTP::Erreur(erreur.nom(), erreur.message(), erreur.code());
                        }

                        const Protocole::Cle::Publique cle_client = Client::Serveurs::Messages::ReponseClePublique(retour.clair()).cle();

                        if(!retour.verifier(cle_client))
                            return; // TODO Erreur dédiée 

                        Journal::ecrire(BTTP_SERVEUR_COMPOSANT_SESSIONS_SESSION, "Client ajouté !");

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