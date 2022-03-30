#include "../../include/serveurs/Serveurs.h"

namespace BTTP
{
    namespace Client
    {
        namespace Serveurs
        {

            void ajout(
                Serveur& serveur,
                const Protocole::Identite& identite, const std::string mdp,
                const std::string dossier, const Contexte* contexte,
                const bool creer_chemin
            )
            {
                // Vérification de l'inexistence du serveur dans les fichiers.
                if (Fichiers::existe(serveur.nom(), dossier, contexte)) throw Erreur::Serveurs::DejaPresent(serveur);
                // Ouverture de la connexion.
                if (!serveur.connexion().ouverte()) serveur.connexion().ouvrir();
                // Demande de la clé publique.
                const Messages::DemandeClePublique demande;
                serveur.connexion().envoyer(demande.construire());
                // Récéption de la clé publique du serveur (en clair).
                const Protocole::Cle::Publique cle_serveur = Messages::ReponseClePublique(serveur.connexion().recevoir()).cle();
                // Envoi d'une confirmation.
                const Protocole::Messages::Pret reponse;
                serveur.connexion().envoyer(
                    identite.chiffrer(reponse.construire(), cle_serveur, mdp)
                );
                // Enregistrement local des informations du serveur.
                serveur.modifier_cle(&cle_serveur);
                Fichiers::ecrire(serveur.serialiser(), serveur.nom(), dossier, false, true, contexte, creer_chemin);
            }

            const std::vector<Serveur> liste(asio::io_context& contexte_asio, const std::string dossier, Contexte* contexte)
            {
                std::vector<Serveur> serveurs;
                const std::vector<std::string> fichiers = Fichiers::liste(dossier, contexte);
                std::string contenu;
                for (const std::string& fichier : fichiers)
                    serveurs.push_back(charger(fichier, contexte_asio, dossier, contexte));
                return serveurs;
            }   

            const std::vector<Appareil> appareils(const Serveur& serveur, const Protocole::Identite& identite, const std::string mdp)
            {
                // if (!serveur.authentifie()) throw // TODO Erreur NonAuthentifie
                const Messages::DemandeAppareils demande;
                serveur.connexion().envoyer(identite.chiffrer(demande.construire(), serveur.cle(), mdp));
                const std::string paquet_reponse = identite.dechiffrer(serveur.connexion().recevoir(), serveur.cle(), mdp);
                const Messages::ReponseAppareils reponse{ paquet_reponse };
                return reponse.appareils();
            }

            const std::vector<Script> scripts(const Appareil& appareil, const Serveur& serveur, const Protocole::Identite& identite, const std::string mdp)
            {
                // if (!serveur.authentifie()) throw // TODO Erreur NonAuthentifie
                const Messages::DemandeScripts demande{ appareil };
                serveur.connexion().envoyer(identite.chiffrer(demande.construire(), serveur.cle(), mdp));
                const std::string paquet_reponse = identite.dechiffrer(serveur.connexion().recevoir(), serveur.cle(), mdp);
                const Messages::ReponseScripts reponse{ paquet_reponse };
                return reponse.scripts();
            }
        }
    }
}