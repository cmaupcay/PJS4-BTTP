#ifndef H_BTTP_MESSAGE_CLE_PUBLIQUE
#define H_BTTP_MESSAGE_CLE_PUBLIQUE

#include "Message.h"
#include "../identite/Cles.h"

#include "erreur/ClePubliqueVide.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            /**
             * @brief Message contenant une clé publique.
             */
            class ClePublique : public Message
            {
            private:
                /**
                 * @brief Clé publique contenue.
                 */
                std::string _cle;

                /**
                 * @brief Retourne le contenu du message.
                 * @return const std::string Clé publique.
                 */
                inline const std::string contenu() const override { return this->_cle; }

                /**
                 * @brief Enregistrement du contenu d'un message similaire.
                 * @param contenu Clé publque.
                 */
                inline void deconstruction(const std::string contenu) override { this->_cle = contenu; }

            public:
                /**
                 * @brief Construction du message à partir d'une clé publique.
                 * @param cle Clé publique.
                 */
                ClePublique(const Cle::Publique cle);
                /**
                 * @brief Construction d'un message vide.
                 */
                ClePublique();
                /**
                 * @brief Construction d'un message vide, déconstruction d'un paquet et enregistrement de la clé publique.
                 * @param paquet Paquet à déconstruire.
                 */
                ClePublique(const std::string paquet);

                /**
                 * @brief Retourne la clé publique contenue par le message.
                 * @return const Cle::Publique Clé publique contenue.
                 */
                const Cle::Publique cle() const;
            };
        }
    }
}

#endif