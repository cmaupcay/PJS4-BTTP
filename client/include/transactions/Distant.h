#ifndef H_BTTP_CLIENT_TRANSACTION_DISTANT
#define H_BTTP_CLIENT_TRANSACTION_DISTANT

#include "Client.h"

namespace BTTP
{
    namespace Client
    {
        namespace Transactions
        {
            class Distant : public Protocole::Transactions::Distant
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
                 * @brief Construction d'une nouvelle transaction distante.
                 * @param identite Identité locale à utiliser.
                 * @param client Clé publique de l'appareil client.
                 * @param controleur Serveur de contrôle.
                 * @param cles_autorisees Liste des empreintes clés publiques des appareils autorisés.
                 */
                Distant(
                    const Protocole::Identite& identite, const std::string& message_ouverture,
                    const Serveurs::Serveur& controleur, const std::vector<std::string>& cles_autorisees
                ) : Protocole::Transactions::Distant(
                    identite, message_ouverture,
                    controleur.cle(), controleur.connexion(),
                    cles_autorisees
                )
                {}

                void lancer(const std::string mdp) noexcept;
            };
        }
    }
}

#endif