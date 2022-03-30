#ifndef H_BTTP_CLIENT_CONTEXTE_VARIABLE_INEXISTANTE
#define H_BTTP_CLIENT_CONTEXTE_VARIABLE_INEXISTANTE

#include "../../Racine.h"

#define H_BTTP_CLIENT_CONTEXTE_VARIABLE_INEXISTANTE_CODE -1400

namespace BTTP
{
    namespace Client
    {
        namespace Erreur
        {
            namespace Contexte
            {
                class VariableInexistante : public Erreur
                {
                private:
                    const std::string _variable;

                public:
                    VariableInexistante(const std::string variable)
                        : Erreur("Client/Contexte/VariableNonTrouvee", "La variable de contexte \"" + variable + "\" est inexistante.", H_BTTP_CLIENT_CONTEXTE_VARIABLE_INEXISTANTE_CODE),
                        _variable{ variable }
                    {}

                    inline const std::string& variable() const { return this->_variable; }
                };
            }
        }
    }
}
#endif