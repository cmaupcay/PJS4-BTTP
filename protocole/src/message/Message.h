#include <string>

namespace BTTP
{
    namespace Protocole
    {
        class Message
        {
        private:
            const char _type;

        protected:
            Message(char type) : _type{ type } {}

            virtual std::string construire_contenu() const = 0;

        public:
            inline const char type() const { return this->_type; }

            // @brief Construction du message depuis l'objet.
            inline const std::string construire() const
            { return this->_type + this->construire_contenu(); }
        };
    }
}