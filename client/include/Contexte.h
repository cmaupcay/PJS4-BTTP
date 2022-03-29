#ifndef H_BTTP_CLIENT_CONTEXTE
#define H_BTTP_CLIENT_CONTEXTE

#include "Racine.h"
#include <asio.hpp>

namespace BTTP
{
    namespace Client 
    {
        class Contexte : public Protocole::Contexte
        {
        public:
            typedef Protocole::Messages::Argument Variable;

        private:
            const std::string _dossier;
            std::unique_ptr<Protocole::Identite> _id;
            std::vector<Variable> _variables;

            const size_t index_variable(const std::string nom) const;
            const size_t index_variable(const Variable variable) const;

        public:
            Contexte(const std::string dossier = "");
            inline const std::string& dossier() const {return this->_dossier;}

            inline const std::unique_ptr<Protocole::Identite>& identite() { return this->_id; }
            inline void modifier_identite(const Protocole::Identite& id) 
            { this->_id = std::make_unique<Protocole::Identite>(id); }

            const Variable& variable(const std::string nom_variable) const;
            void ajouter_variable(const Variable variable);
            inline const bool verifier_variable(const std::string nom_variable) const
            { return this->index_variable(nom_variable) < this->_variables.size(); }
            const bool verifier_variable(const Variable variable) const
            { return this->index_variable(variable) < this->_variables.size(); }
        };
    }
}


#endif