#include "../../include/scripts/Scripts.h"

namespace BTTP
{
    namespace Client
    {
        namespace Scripts
        {
            const Script ajouter(
                const std::string nom, const std::string contenu,
                const Serveurs::Serveur& serveur,
                const Protocole::Identite& identite, const std::string mdp,
                const std::string dossier, 
                const bool utiliser_contexte,
                const bool creer_chemin
            )
            {
                // Annonce de l'ajout du script
                const Messages::DemandeAjout message{ nom };
                serveur.connexion().envoyer(
                    identite.chiffrer(message.construire(), serveur.cle(), mdp)
                );
                // Attente de la réponse définissant l'identifiant à utiliser.
                const std::string reponse = identite.dechiffrer(serveur.connexion().recevoir(), serveur.cle(), mdp);
                const Messages::ReponseAjout message_reponse{ reponse };
                const Script script{ serveur, message_reponse.id_script(), nom };
                // Enregistrement du fichier en local.
                Fichiers::ecrire(contenu, script.reference(), dossier, false, false, utiliser_contexte, creer_chemin);
                return script;
            }


            void supprimer(
                const Script script,
                const Serveurs::Serveur& serveur,
                const Protocole::Identite& identite, const std::string mdp,
                const std::string dossier, 
                const bool utiliser_contexte
            )
            {

                // Suppression du fichier local s'il existe.
                try {Fichiers::supprimer(script.reference(), dossier, utiliser_contexte);}
                catch (Erreur::Fichiers::Inexistant& e) { throw Erreur::Scripts::Inexistant(script); }
                const Messages::DemandeSuppression message{ script };
                serveur.connexion().envoyer(
                    identite.chiffrer(message.construire(), serveur.cle(), mdp)
                );
                const std::string reponse = identite.dechiffrer(serveur.connexion().recevoir(), serveur.cle(), mdp);
                if(reponse[0] == static_cast<char>(Protocole::Messages::Type::ERREUR)){

                    const Protocole::Messages::Erreur erreur {reponse};
                    throw BTTP::Erreur(erreur.nom(), erreur.message(), erreur.code());

                }
                else if (reponse[0] != static_cast<char>(Protocole::Messages::Type::PRET))
                    throw Protocole::Erreur::Messages::Type::Incoherent(reponse[0], reponse);

            }

            const std::string executer(
                const Script script, const std::string dossier, 
                const bool utiliser_contexte
            )
            {
                const std::string nom_fichier_sortie = script.nom() + "_tmp";
                const std::string fichier_sortie = Fichiers::chemin(nom_fichier_sortie, dossier, utiliser_contexte);
                const std::string reference = script.reference();
                const std::string chemin_script = Fichiers::chemin(reference, dossier, utiliser_contexte);
                const std::string commande = "./" + chemin_script + " > " + nom_fichier_sortie;
                if (Fichiers::existe(reference, dossier, utiliser_contexte) && system(commande.c_str()) >= 0)
                {
                    const std::string sortie = Fichiers::lire(nom_fichier_sortie, dossier, false, utiliser_contexte);
                    try 
                    {
                        Fichiers::supprimer(nom_fichier_sortie, dossier, utiliser_contexte);
                        return sortie;
                    }
                    catch (Erreur::Fichiers::Inexistant& e) { throw Erreur::Scripts::SupressionFichierSortie(nom_fichier_sortie); } 
                }
                throw Erreur::Scripts::Execution(script);
            }

            const std::vector<Script> liste(
                const Serveurs::Serveur& serveur, const std::string dossier, 
                const bool utiliser_contexte
            )
            {
                std::vector<Script> scripts;
                const std::vector<std::string> fichiers = Fichiers::liste(
                    dossier + '/' + serveur.nom(), utiliser_contexte    
                );
                for (const std::string& fichier : fichiers)
                    scripts.push_back(Script(serveur, fichier));
                return scripts;
            }
        }
    }
}