#ifndef H_BTTP_SERVEUR_SESSION_INTERFACE
#define H_BTTP_SERVEUR_SESSION_INTERFACE

#include "../data/terminal/Client.h"

#define BTTP_SERVEUR_COMPOSANT_SESSIONS "Sessions/"

namespace BTTP
{
    namespace Serveur
    {
        namespace Sessions
        {
            template<class _Type>
            class TSession
            {
            public:
                virtual const _Type& type() const = 0;
                virtual std::thread& thread() = 0;
                virtual const std::unique_ptr<Data::Terminal::Client>& client() const = 0;
            };

            enum class Type
            {
                NON_DEFINI = 0,
                INITIALISATION = 1,
                CLIENT = 2,
                DISTANT = 3
            };

            class ISession : public TSession<Type> {};

            class _Session : public ISession
            {
            private:
                std::unique_ptr<Data::Terminal::Client> _terminal;
                std::shared_ptr<Client::Connexion> _connexion;

                std::unique_ptr<Data::Source>& _source;
                std::thread _thread;

                Type _type;

            protected:
                const std::unique_ptr<Client::Contexte>& contexte;
                inline std::unique_ptr<Data::Terminal::Client>& terminal() { return this->_terminal; }
                inline std::shared_ptr<Client::Connexion>& connexion() { return this->_connexion; }
                inline std::unique_ptr<Data::Source>& source() { return this->_source; }
                virtual void lancer() = 0;

                inline void definir_type(const Type type) { this->_type = type; }

            public:
                _Session(const std::unique_ptr<Client::Contexte>& contexte, std::unique_ptr<Data::Source>& source, std::shared_ptr<Client::Connexion> connexion)
                    : contexte{ contexte }, _connexion{ connexion }, _source{ source }, _thread{ [this]{ this->lancer(); } }, _type{ Type::NON_DEFINI }
                {}
                
                inline const Type& type() const override { return this->_type; }
                inline std::thread& thread() override { return this->_thread; }

                inline const std::unique_ptr<Data::Terminal::Client>& client() const override { return this->_terminal; }
            };
        }
    }
}

#endif