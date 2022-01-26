#ifndef H_BTTP_MESSAGE
#define H_BTTP_MESSAGE

#include "../Racine.h"

#include <iomanip>

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

            public:
                inline const T& type() const { return this->_type; }

                const std::string construire() const override;
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