#ifndef H_BTTP_MESSAGE_EXECUTION
#define H_BTTP_MESSAGE_EXECUTION

#include "Message.h"
#include "erreur/deconstruction/Incomplet.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            // TOTEST
            // TOCOMMENT
            class Execution : public Message
            {
            private:
                uint32_t* _id;
                uint32_t* _id_script;
                std::vector<std::string> _args;

                const std::string contenu() const override;
                void deconstruction(const std::string contenu) override;

            public:
                Execution(const uint32_t id_script);
                Execution();
                Execution(const std::string paquet);

                ~Execution();

                inline const uint32_t& id() const { return *this->_id; }
                inline const uint32_t& id_script() const { return *this->_id_script; }
                inline const std::vector<std::string>& args() const { return this->_args; }

                inline void ajouter_argument(const std::string arg) { this->_args.push_back(arg); }
                inline void supprimer_dernier_argument() { this->_args.pop_back(); }
            };
        }
    }
}

#endif