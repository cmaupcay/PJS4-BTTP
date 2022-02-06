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
            class ClePublique : public Message
            {
            private:
                std::string _cle;

                inline const std::string contenu() const override { return this->_cle; }
                inline void construction(const std::string contenu) override { this->_cle = contenu; }

            public:
                ClePublique(Cle::Publique cle)
                    : BTTP::Protocole::Messages::Message(Type::CLE_PUBLIQUE),
                    _cle{ cle.write(OpenPGP::PGP::Armored::NO) }
                {}
                ClePublique()
                    : BTTP::Protocole::Messages::Message(Type::CLE_PUBLIQUE),
                    _cle{ BTTP_MESSAGE_CLE_PUBLIQUE_VIDE }
                {}
                ClePublique(const std::string paquet)
                    : BTTP::Protocole::Messages::Message(Type::CLE_PUBLIQUE),
                    _cle{ BTTP_MESSAGE_CLE_PUBLIQUE_VIDE }
                { this->deconstruire(paquet); }

                const Cle::Publique cle() const;
            };
        }
    }
}

#endif