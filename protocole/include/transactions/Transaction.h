#ifndef H_BTTP_TRANSACTION
#define H_BTTP_TRANSACTION

#include "../identite/Meta.h"
#include "../messages/Messages.h"
#include "../messages/controle/Messages.h"
#include "../IConnexion.h"

#include "erreur/DejaFermee.h"
#include "erreur/DejaOuverte.h"
#include "erreur/Fermee.h"
#include "erreur/EnteteInvalide.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Transactions
        {
            /**
             * @brief Interface des transactions BTTP.
             */
            class ITransaction
            {
            public:
                /**
                 * @brief Indique si la transaction est ouverte à l'envoi d'un message.
                 * @return true La transaction est ouverte.
                 * @return false La transaction est fermée.
                 */
                virtual const bool ouverte() const = 0;
                /**
                 * @brief Ouvre la transaction si elle est fermée.
                 * @param mdp Mot de passe de l'identité locale.
                 */
                virtual void ouvrir(const std::string mdp) = 0;
                /**
                 * @brief Ferme la transaction si elle est ouverte.
                 * @param mdp Mot de passe de l'identité locale.
                 */
                virtual void fermer(const std::string mdp) = 0;
            };

            /**
             * @brief Classe de base des transactions BTTP implémentées dans le protocole.
             */
            class _Transaction : public ITransaction
            {
            private:
                /** Drapeau indiquant si la transaction a été ouverte. */
                bool _ouverte;

                /** Connexion réseau. */
                IConnexion& _connexion;

                /** Identité locale. */
                const Identite& _identite;

            protected:
                /**
                 * @brief Construction d'une nouvelle transaction.
                 * @note N'ouvre pas la transaction.
                 * @param connexion Connexion réseau à utiliser.
                 * @param identite Identité locale.
                 */
                _Transaction(IConnexion& connexion, const Identite& identite);

                /**
                 * @brief Retourne l'identité locale utilisée par la transaction.
                 * @return const Identite& Identité locale.
                 */
                inline const Identite& identite() const { return this->_identite; }
                /**
                 * @brief Retourne la connexion réseau utilisée par la transaction.
                 * @return IConnexion& Connexion réseau.
                 */
                inline IConnexion& connexion() const { return this->_connexion; }

                /**
                 * @brief Procédure d'ouverture de la transaction.
                 * @param mdp Mot de passe de l'identité locale.
                 */
                virtual void ouverture(const std::string& mdp) = 0;
                /**
                 * @brief Procédure de fermeture de la transaction.
                 * @param mdp Mot de passe de l'identité locale.
                 */
                virtual void fermeture(const std::string& mdp) = 0;

            public:
                /**
                 * @brief Indique si la transaction est ouverte à l'envoi d'un message.
                 * @return true La transaction est ouverte.
                 * @return false La transaction est fermée.
                 */
                inline const bool ouverte() const override { return this->_ouverte; }

                // TOTEST Ouverture
                /**
                 * @brief Ouvre la transaction et la connexion si elle est fermée.
                 * @param mdp Mot de passe de l'identité locale.
                 * 
                 * @throws BTTP::Erreur::Transactions::DejaOuverte La transaction est déjà ouverte.
                 */
                void ouvrir(const std::string mdp) override;

                // TOTEST Fermeture
                /**
                 * @brief Ferme la transaction.
                 * @note Ne ferme pas la connexion utilisée.
                 * @param mdp Mot de passe de l'identité locale.
                 * 
                 * @throws BTTP::Erreur::Transactions::DejaFermee La transaction est déjà fermée.
                 */
                void fermer(const std::string mdp) override;
            };

            // TOTEST
            /**
             * @brief Extraction de l'entête d'un message de contrôle sérialisé.
             * @param message Message de contrôle sérialisé.
             * @return const std::string Entête extraite.
             */
            inline const std::string extraire_entete(const std::string message)
            { return message.substr(0, message.find_last_of(BTTP_MESSAGE_CONTROLE_SEP)); }
      
            // TOTEST
            /**
             * @brief Suppression de l'entête d'un message de contrôle sérialisé.
             * @param message Message de contrôle sérialisé.
             * @return const std::string Message de contrôle sérialisé sans son entête (contenu).
             */
            inline const std::string retirer_entete(const std::string message)
            { return message.substr(message.find_last_of(BTTP_MESSAGE_CONTROLE_SEP) + 1); }
        }
    }
}

#endif