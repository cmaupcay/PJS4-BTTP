#ifndef H_BTTP_IDENTITE_DECHIFFREMENT
#define H_BTTP_IDENTITE_DECHIFFREMENT

#include "../../Erreur.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Erreur
        {
            class Identite_Dechiffrement : public Erreur
            {
            public:
                Identite_Dechiffrement(const std::string details)
                    : Erreur("Identite/Dechiffrement", "Le déchiffrement du message à donné un résultat invalide.\n\tDétails : " + details) {}
            };
        }
    }
}
#endif