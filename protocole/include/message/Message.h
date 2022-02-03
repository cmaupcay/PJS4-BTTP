#ifndef H_BTTP_MESSAGE
#define H_BTTP_MESSAGE

#include "../Racine.h"

#include <iomanip>

#include "erreur/type/Incoherent.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            class IMessage
            {
            public:
                virtual const std::string construire() const = 0;
                virtual void deconstruire(const std::string paquet) = 0;
                virtual const char type_c() const = 0;

                inline friend std::ostream& operator<<(std::ostream& os, const IMessage& msg) { return (os << msg.construire()); }
            };

            template <class T>
            class TMessage : public IMessage
            {
            private:
                const T _type;
            protected:
                TMessage(const T type) : _type{ type } {}

                virtual const std::string contenu() const = 0;
                virtual void construction(const std::string contenu) = 0;

            public:
                inline const T& type() const { return this->_type; }
                inline const char type_c() const override { return static_cast<char>(this->_type); }

                inline const std::string construire() const override
                { return this->type_c() + this->contenu(); }
                void deconstruire(const std::string paquet) override
                {
                    if (paquet.length() > 0 && paquet[0] == this->type_c())
                        this->construction(paquet.substr(1));
                    else throw Erreur::Messages_Type_Incoherent(this->type_c(), paquet);
                }
            };

            enum class Type
            {
                CLE_PUBLIQUE = '!',
                EXECUTION = '>',
                RESULTAT = '<'
            };

            class Message : public TMessage<Type>
            {
            protected:
                Message(const Type type) : TMessage(type) {}
            };
        }
    }
}

#endif