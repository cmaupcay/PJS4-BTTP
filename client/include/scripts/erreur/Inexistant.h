#ifndef H_BTTP_CLIENT_SCRIPT_INEXISTANT
#define H_BTTP_CLIENT_SCRIPT_INEXISTANT

#include "../Script.h"

#define BTTP_CLIENT_SCRIPT_INEXISTANT_CODE -2002

namespace BTTP
{
    namespace Client
    {
        namespace Erreur
        {
            namespace Scripts
            {
                class Inexistant : public Erreur
                {
                private:
                    const Client::Scripts::Script& _script;
                public:
                    Inexistant(const Client::Scripts::Script& script)
                        : Erreur("Client/Scripts/Inexistant", "Le script " + script.nom() + "n'existe pas.", BTTP_CLIENT_SCRIPT_INEXISTANT_CODE),
                        _script{ script }
                    {}

                    inline const Client::Scripts::Script& script() const { return this->_script; }
                };
            }
        }
    }
}
#endif