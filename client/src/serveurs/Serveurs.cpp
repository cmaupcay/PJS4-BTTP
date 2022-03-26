#include "../../include/serveurs/Serveurs.h"

namespace BTTP
{
    namespace Client
    {
        namespace Serveurs
        {

            const bool ajout(
                Serveur& serveur,
                const Protocole::Identite* identite, const std::string mdp,
                const std::string dossier, const bool utiliser_contexte,
                const bool creer_chemin
            )
            {
                // Vérification de l'inexistence du serveur dans les fichiers.
                if (Fichiers::existe(serveur.nom(), dossier, utiliser_contexte)) return false;
                // Ouverture de la connexion.
                if (!serveur.connexion()->ouverte()) serveur.connexion()->ouvrir();
                // Récéption de la clé publique du serveur (envoyée en clair).
                const Protocole::Cle::Publique cle_serveur = Protocole::Messages::ClePublique(serveur.connexion()->recevoir()).cle();
                // Envoi de la clé publique de l'identité locale.
                const Protocole::Messages::ClePublique reponse{ identite->cle_publique() };
                serveur.connexion()->envoyer(identite->chiffrer(reponse.construire(), cle_serveur, mdp));
                // Confirmation de l'ajout.
                const std::string confirmation = identite->dechiffrer(serveur.connexion()->recevoir(), cle_serveur, mdp);
                if (confirmation[0] == static_cast<char>(Protocole::Messages::Type::PRET))
                {
                    // Enregistrement local des informations du serveur.
                    serveur.modifier_cle(&cle_serveur);
                    Fichiers::ecrire(serveur.serialiser(), serveur.nom(), dossier, false, false, utiliser_contexte, creer_chemin);
                    return true;
                }
                return false;
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
        }
    }
}