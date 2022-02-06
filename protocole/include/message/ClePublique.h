#ifndef H_BTTP_MESSAGE_CLE_PUBLIQUE
#define H_BTTP_MESSAGE_CLE_PUBLIQUE

#include "Message.h"
#include "../identite/Identite.h"

#include "erreur/ClePubliqueVide.h"

#ifndef BTTP_MESSAGE_CLE_PUBLIQUE_VIDE
    #define BTTP_MESSAGE_CLE_PUBLIQUE_VIDE ""
#endif

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
                ClePublique(Cle::Publique cle)
                    : BTTP::Protocole::Messages::Message(Type::CLE_PUBLIQUE),
                    _cle{ cle.write(OpenPGP::PGP::Armored::NO) }
                {}
                /**
                 * @brief Construction d'un message vide.
                 */
                ClePublique()
                    : BTTP::Protocole::Messages::Message(Type::CLE_PUBLIQUE),
                    _cle{ BTTP_MESSAGE_CLE_PUBLIQUE_VIDE }
                {}
                /**
                 * @brief Construction d'un message vide, déconstruction d'un paquet et enregistrement de la clé publique.
                 * @param paquet Paquet à déconstruire.
                 */
                ClePublique(const std::string paquet)
                    : BTTP::Protocole::Messages::Message(Type::CLE_PUBLIQUE),
                    _cle{ BTTP_MESSAGE_CLE_PUBLIQUE_VIDE }
                { this->deconstruire(paquet); }

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