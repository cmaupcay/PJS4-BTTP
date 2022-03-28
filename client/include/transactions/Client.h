#ifndef H_BTTP_CLIENT_TRANSACTION_CLIENT
#define H_BTTP_CLIENT_TRANSACTION_CLIENT

#include "../serveurs/Appareil.h"
#include "../serveurs/Serveur.h"
#include "../serveurs/Script.h"

namespace BTTP
{
    namespace Client
    {
        namespace Transactions
        {
            // TODO Synchronisation des horloges via serveur RTC
            /**
             * @brief Vérification d'une entête de vérification ajouté à un message de contrôle par l'appareil de contrôle.
             * @param entete Entête à vérifier.
             * @return true L'entête est valide.
             * @return false L'entête n'est pas valide.
             */
            const bool verifier_entete_controle(const std::string& entete);

            class Client : public Protocole::Transactions::Client
            {
            private:
                /**
                 * @brief Vérification d'une entête de vérification ajouté à un message de contrôle par l'appareil de contrôle.
                 * @param entete Entête à vérifier.
                 * @return true L'entête est valide.
                 * @return false L'entête n'est pas valide.
                 */
                const bool verifier_entete(const std::string& entete) override { return verifier_entete_controle(entete); }

            public:
                /**
                 * @brief Construction d'une nouvelle transaction avec un appareil distant.
                 * @param identite Identité locale.
                 * @param appareil_distant Appareil distant cible.
                 * @param controleur Serveur de contrôle de référence.
                 */
                Client(
                    const Protocole::Identite& identite,
                    const Appareil& appareil_distant,
                    const Serveurs::Serveur& controleur
                ) : Protocole::Transactions::Client(
                    identite, appareil_distant.cle(),
                    controleur.cle(), controleur.connexion()
                )
                {}

                /**
                 * @brief Demande l'exécution du script sur l'appareil distant.
                 * @param script Script cible.
                 * @param mdp Mot de passe de l'identité local.
                 */
                const Protocole::Messages::Resultat executer(const Scripts::Script& script, const std::string mdp);
            };
        }
    }
}

#endif