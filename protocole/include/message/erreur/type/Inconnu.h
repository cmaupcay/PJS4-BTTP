#ifndef H_BTTP_MESSAGE_TYPE_INCONNU
#define H_BTTP_MESSAGE_TYPE_INCONNU

#include "../../../Erreur.h"

#ifndef BTTP_MESSAGE_TYPE_INCONNU_CODE
    #define BTTP_MESSAGE_TYPE_INCONNU_CODE -110
#endif

namespace BTTP
{
    namespace Protocole
    {
        namespace Erreur
        {
            class Messages_Type_Inconnu : public Erreur
            {
            private:
                const std::string& _paquet;
            public:
                Messages_Type_Inconnu(const std::string& paquet)
                    : Erreur("Messages/Type/Inconnu", "Impossible de résoudre le type du message.", BTTP_MESSAGE_TYPE_INCONNU_CODE),
                    _paquet{ paquet }
                {}

                inline const std::string& paquet() const { return this->_paquet; }
            };
        }
    }
}
#endif