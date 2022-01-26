#ifndef H_BTTP_IDENTITE_SIGNATURE
#define H_BTTP_IDENTITE_SIGNATURE

#include "../../Erreur.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Erreur
        {
            class Identite_Signature : public Erreur
            {
            private:
                const std::string& _message_echec;
            public:
                Identite_Signature(const std::string& message_echec)
                    : Erreur("Identite/Signature", "La vérification de la signature du message a échoué."),
                    _message_echec{ message_echec }
                {}

                inline const std::string& message_echec() const { return this->_message_echec; }
            };
        }
    }
}
#endif