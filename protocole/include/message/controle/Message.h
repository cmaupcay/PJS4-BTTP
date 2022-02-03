#ifndef H_BTTP_MESSAGE_CONTROLE
#define H_BTTP_MESSAGE_CONTROLE

#include "../Message.h"
#include "../../identite/Identite.h"

#ifndef BTTP_MESSAGE_CONTROLE_SEP
    #define BTTP_MESSAGE_CONTROLE_SEP '@'
#endif

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            namespace Controle
            {
                template<class T>
                class TMessage : public Protocole::Messages::TMessage<T>
                {
                private:
                    std::string _contenu;
                    std::string _destinataire;

                    inline const std::string contenu() const override
                    { return this->_contenu; }

                protected:
                    TMessage(
                        const T type, 
                        const std::string contenu, const Identite::ClePublique destinataire,
                        const Identite* signataire = nullptr, const std::string mdp = ""
                    );    
                    TMessage(
                        const T type, 
                        const IMessage* message, const Identite::ClePublique destinataire,
                        const Identite* signataire = nullptr, const std::string mdp = ""
                    );                
                    inline void initialiser(
                        const std::string contenu, const Identite::ClePublique destinataire,
                        const Identite* signataire, const std::string mdp = ""
                    );

                    virtual const std::string entete() const = 0;
                    virtual void lire_entete(const std::string entete) = 0;

                    void construction(const std::string contenu) override;

                public:
                    const std::string construire() const override;

                    inline const std::string& message() const { return this->_contenu; }
                    inline const std::string& destinataire() const { return this->_destinataire; }
                };

                enum class Type
                {
                    EXECUTION = '>'
                };

                class Message : public TMessage<Type>
                {
                protected:
                    Message(
                        const Type type, 
                        const IMessage* message, const Identite::ClePublique destinataire,
                        const Identite* signataire = nullptr, const std::string mdp = ""
                    ) : TMessage<Type>(type, message, destinataire, signataire, mdp)
                    {}
                };
            }
        }
    }
}

#endif