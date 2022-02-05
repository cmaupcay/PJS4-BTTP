#ifndef H_BTTP_IDENTITE_CHIFFREMENT
#define H_BTTP_IDENTITE_CHIFFREMENT

#include "../../Erreur.h"

#ifndef BTTP_IDENTITE_CHIFFREMENT_CODE
    #define BTTP_IDENTITE_CHIFFREMENT_CODE -201
#endif

namespace BTTP
{
    namespace Protocole
    {
        namespace Erreur
        {
            namespace Identite
            {
                class Chiffrement : public Erreur
                {
                private:
                    const std::string& _message_echec;
                public:
                    Chiffrement(const std::string details, const std::string& message_echec)
                        : Erreur("Identite/Chiffrement", "Le chiffrement du message a échoué.\n\tDetails : " + details, BTTP_IDENTITE_CHIFFREMENT_CODE),
                        _message_echec{ message_echec }
                    {}

                    inline const std::string& message_echec() const { return this->_message_echec; }
                };
            }
        }
    }
}
#endif