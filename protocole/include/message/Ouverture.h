#ifndef H_BTTP_MESSAGE_OUVERTURE
#define H_BTTP_MESSAGE_OUVERTURE

#include "Message.h"
#include "../identite/Cles.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            /**
             * @brief Message demandant l'ouverture d'une transaction avec le terminal cible.
             */
            class Ouverture : public Message
            {
            private:
                /**
                 * @brief Empreinte de la clé publique du terminal distant cible.
                 */
                std::string _cible;

                /**
                 * @brief Retourne le contenu du message.
                 * @return const std::string Empreinte de la clé publique du terminal distant cible.
                 */
                inline const std::string contenu() const override { return this->_cible; }

                /**
                 * @brief Enregistrement du contenu d'un message similaire.
                 * @param contenu Clé publque du terminal distant cible.
                 */
                inline void deconstruction(const std::string contenu) override { this->_cible = contenu; }

            public:
                /**
                 * @brief Construction du message à partir d'une clé publique.
                 * @param cle Clé publique du terminal distant cible.
                 */
                Ouverture(const Cle::Publique cle);
                /**
                 * @brief Construction d'un message vide.
                 */
                Ouverture();
                /**
                 * @brief Construction d'un message vide, déconstruction d'un paquet et enregistrement de la clé publique du terminal distant cible.
                 * @param paquet Paquet à déconstruire.
                 */
                Ouverture(const std::string paquet);

                /**
                 * @brief Retourne l'empreinte de la clé publique du terminal cible.
                 * @return const std::string& Empreinte du terminal cible.
                 */
                inline const std::string& cible() const { return this->_cible; }
            };
        }
    }
}

#endif