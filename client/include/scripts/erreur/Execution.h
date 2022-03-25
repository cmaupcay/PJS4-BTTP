#ifndef H_BTTP_CLIENT_SCRIPTS_EXECUTION
#define H_BTTP_CLIENT_SCRIPTS_EXECUTION

#include "../Script.h"

#define BTTP_CLIENT_SCRIPTS_EXECUTION_CODE -2000

namespace BTTP
{
    namespace Client
    {
        namespace Erreur
        {
            namespace Scripts
            {
                class Execution : public Erreur
                {
                private:
                    const Client::Scripts::Script& _script;

                public:
                    Execution(const Client::Scripts::Script& script)
                        : Erreur("Client/Scripts/Execution", "L'exécution du script '" + script.nom() + "' a engendré une erreur.", BTTP_CLIENT_SCRIPTS_EXECUTION_CODE),
                        _script{ script }
                    {}

                    inline const Client::Scripts::Script& script() const { return this->_script; }
                };
            }
        }
    }
}
#endif