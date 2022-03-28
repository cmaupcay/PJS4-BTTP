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
                const std::string dossier, const bool utiliser_contexte,
                const bool creer_chemin
            )
            {
                // Vérification de l'inexistence du serveur dans les fichiers.
                if (Fichiers::existe(serveur.nom(), dossier, utiliser_contexte)) throw Erreur::Serveurs::DejaPresent(serveur);
                // Ouverture de la connexion.
                if (!serveur.connexion().ouverte()) serveur.connexion().ouvrir();
                // Récéption de la clé publique du serveur (envoyée en clair).
                const Protocole::Cle::Publique cle_serveur = Protocole::Messages::ClePublique(serveur.connexion().recevoir()).cle();
                // Envoi de la clé publique de l'identité locale.
                const Protocole::Messages::ClePublique reponse{ identite.cle_publique() };
                serveur.connexion().envoyer(identite.chiffrer(reponse.construire(), cle_serveur, mdp));
                // Confirmation de l'ajout.
                const std::string confirmation = identite.dechiffrer(serveur.connexion().recevoir(), cle_serveur, mdp);
                if(confirmation[0] == static_cast<char>(Protocole::Messages::Type::ERREUR)){

                    const Protocole::Messages::Erreur erreur {confirmation};
                    throw BTTP::Erreur(erreur.nom(), erreur.message(), erreur.code());

                }
                else if (confirmation[0] != static_cast<char>(Protocole::Messages::Type::PRET))
                    throw Protocole::Erreur::Messages::Type::Incoherent(confirmation[0], confirmation);                
            
                // Enregistrement local des informations du serveur.
                serveur.modifier_cle(&cle_serveur);
                Fichiers::ecrire(serveur.serialiser(), serveur.nom(), dossier, false, false, utiliser_contexte, creer_chemin);
            }

            const std::vector<Serveur> liste(const std::string dossier, const bool utiliser_contexte)
            {
                std::vector<Serveur> serveurs;
                const std::vector<std::string> fichiers = Fichiers::liste(dossier, utiliser_contexte);
                std::string contenu;
                for (const std::string& fichier : fichiers)
                    serveurs.push_back(charger(fichier, dossier, utiliser_contexte));
                return serveurs;
            }   

            const std::vector<Appareil> appareils(const Serveur& serveur, const Protocole::Identite& identite, const std::string mdp)
            {
                const Messages::DemandeAppareils demande;
                serveur.connexion().envoyer(identite.chiffrer(demande.construire(), serveur.cle(), mdp));
                const std::string paquet_reponse = identite.dechiffrer(serveur.connexion().recevoir(), serveur.cle(), mdp);
                const Messages::ReponseAppareils reponse{ paquet_reponse };
                return reponse.appareils();
            }

            const std::vector<Script> scripts(const Appareil& appareil, const Serveur& serveur, const Protocole::Identite& identite, const std::string mdp)
            {
                const Messages::DemandeScripts demande{ appareil };
                serveur.connexion().envoyer(identite.chiffrer(demande.construire(), serveur.cle(), mdp));
                const std::string paquet_reponse = identite.dechiffrer(serveur.connexion().recevoir(), serveur.cle(), mdp);
                const Messages::ReponseScripts reponse{ paquet_reponse };
                return reponse.scripts();
            }
        }
    }
}