#ifndef H_BTTP_MESSAGE_CLE_PUBLIQUE
#define H_BTTP_MESSAGE_CLE_PUBLIQUE

#include "Message.h"
#include "../identite/Identite.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            class ClePublique : public Message
            {
            private:
                std::string _cle;
                inline const std::string contenu() const override { return this->_cle; }

            public:
                ClePublique(Identite::ClePublique cle)
                    : BTTP::Protocole::Messages::Message(Type::CLE_PUBLIQUE),
                    _cle{ cle.write(OpenPGP::PGP::Armored::NO) }
                {}

                inline void construction(const std::string contenu) override { this->_cle = contenu; }
                inline const Identite::ClePublique cle() const { return Identite::ClePublique(this->_cle); }
            };
        }
    }
}

#endif