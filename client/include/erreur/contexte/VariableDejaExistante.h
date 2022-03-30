#ifndef H_BTTP_CLIENT_CONTEXTE_VARIABLE_DEJA_EXISTANTE
#define H_BTTP_CLIENT_CONTEXTE_VARIABLE_DEJA_EXISTANTE

#include "../../Racine.h"

#define H_BTTP_CLIENT_CONTEXTE_VARIABLE_DEJA_EXISTANTE_CODE -140

namespace BTTP
{
    namespace Client
    {
        namespace Erreur
        {
            namespace Contexte
            {
                class VariableDejaExistante : public Erreur
                {
                private:
                    const std::string& _variable;

                public:
                    VariableDejaExistante(const std::string& variable)
                        : Erreur("Client/Contexte/VariableDejaExistante", "La variable de contexte \"" + variable + "\" est deja existante.", H_BTTP_CLIENT_CONTEXTE_VARIABLE_DEJA_EXISTANTE_CODE),
                        _variable{ variable }
                    {}

                    inline const std::string& variable() const { return this->_variable; }
                };
            }
        }
    }
}
#endif