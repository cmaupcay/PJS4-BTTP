#include "../include/Contexte.h"

namespace BTTP
{
    namespace Client 
    {
        Contexte::Contexte(const std::string dossier)
            : _dossier{ dossier }
        {
            if (!Protocole::Contexte::initialise()) Protocole::Contexte::initialiser();
        }

        const size_t Contexte::index_variable(const std::string nom_variable) const
        {
            const size_t n = this->_variables.size();
            for (size_t v = 0; v < n; v++)
                if (this->_variables[v].nom == nom_variable) return v;
            return n;
        }

        const size_t Contexte::index_variable(const Contexte::Variable variable) const
        {
            const size_t n = this->_variables.size();
            const size_t v = this->index_variable(variable.nom);
            if (n < v && this->_variables[v].valeur == variable.valeur) return v;
            else return n;
        }

        const Contexte::Variable& Contexte::variable(const std::string nom_variable) const
        {
            const size_t v = this->index_variable(nom_variable);
            if (v < this->_variables.size()) return this->_variables[v];
            // else throw // TODO Erreur dédiée.
        }

        void Contexte::ajouter_variable(const Contexte::Variable variable)
        {
            if (this->verifier_variable(variable.nom)) { /** throw .. */ } // TODO Erreur DejaExistante;
            else this->_variables.push_back(variable);
        }

    }
}