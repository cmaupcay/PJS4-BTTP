#ifndef H_BTTP_MESSAGE_CONTROLE
#define H_BTTP_MESSAGE_CONTROLE

#include "../Message.h"
#include "../../identite/Identite.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            namespace Controle
            {
                template<class T>
                class TMessage : public BTTP::Protocole::Messages::TMessage<T>
                {
                private:
                    std::string _contenu;

                    inline const std::string contenu() const override
                    { return this->_contenu; }

                protected:
                    TMessage(
                        T type, 
                        const IMessage& message, const Identite::ClePublique destinataire,
                        const Identite* sigantaire = nullptr, const std::string mdp = ""
                    );                
                    inline static const std::string charger_contenu(
                        const IMessage& message, const Identite::ClePublique destinataire,
                        const Identite* sigantaire, const std::string mdp = ""
                    );

                    virtual const std::string entete() const = 0;

                public:
                    const std::string construire() const override;
                };

                enum class Type
                {
                    
                };

                class Message : public TMessage<Type>
                {

                };
            }
        }
    }
}

#endif