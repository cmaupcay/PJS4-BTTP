#ifndef H_BTTP_IDENTITE_CHIFFREMENT
#define H_BTTP_IDENTITE_CHIFFREMENT

#include "../../Erreur.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Erreur
        {
            class Identite_Chiffrement : public Erreur
            {
            private:
                const std::string& _message_echec;
            public:
                Identite_Chiffrement(const std::string& message_echec)
                    : Erreur("Identite/Chiffrement", "Le chiffrement du message a échoué."),
                    _message_echec{ message_echec }
                {}

                inline const std::string& message_echec() const { return this->_message_echec; }
            };
        }
    }
}
#endif