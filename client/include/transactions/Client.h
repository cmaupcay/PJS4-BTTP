#ifndef H_BTTP_CLIENT_TRANSACTION_CLIENT
#define H_BTTP_CLIENT_TRANSACTION_CLIENT

#include "../serveurs/Appareil.h"
#include "../serveurs/Serveur.h"

namespace BTTP
{
    namespace Client
    {
        namespace Transactions
        {
            class Client : public Protocole::Transactions::Client
            {
            private:
                // TODO Synchronisation des horloges via serveur RTC
                /**
                 * @brief Vérification d'une entête de vérification ajouté à un message de contrôle par l'appareil de contrôle.
                 * @param entete Entête à vérifier.
                 * @return true L'entête est valide.
                 * @return false L'entête n'est pas valide.
                 */
                const bool verifier_entete(const std::string& entete) const { return true; }

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
            };
        }
    }
}

#endif