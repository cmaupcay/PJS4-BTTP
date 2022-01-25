#include <string>

namespace BTTP
{
    namespace Protocole
    {
        class Message
        {
        public:
            enum class Type
            {
                EXECUTION
            };

        private:
            const Type _type;

        protected:
            Message(Type type);

            virtual std::string construire_contenu() = 0;
            virtual bool traduire_contenu() = 0;

        public:
            Message(const std::string message);
            
            inline const Type type() { return this->_type; }

            // @brief Construction du message depuis l'objet.
            const std::string construire();

            // @brief Traduction d'un message en objet.
            bool traduire(const std::string message);
        };
    }
}