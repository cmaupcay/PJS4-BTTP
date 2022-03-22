#ifndef H_BTTP_MESSAGE_OUVERTURE
#define H_BTTP_MESSAGE_OUVERTURE

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
             * @brief Message demandant l'ouverture d'une transaction avec le terminal cible.
             * @note Même si ce message équivaut à un message de type ClePublique, une classe dédiée
             * permet une cohérence avec les autres types de messages (unicité des classes) et une plus
             * grande flexibilité à l'avenir, en cas d'ajout de vérification par exemple.
             */
            class Ouverture : public Message
            {
            private:
                /**
                 * @brief Clé publique du terminal distant cible.
                 */
                std::string _cible;

                /**
                 * @brief Retourne le contenu du message.
                 * @return const std::string Clé publique du terminal distant cible.
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
                 * @brief Retourne la clé publique contenue par le message.
                 * @return const Cle::Publique Clé publique du terminal distant cible.
                 */
                const Cle::Publique cible() const;
            };
        }
    }
}

#endif