#ifndef H_BTTP_CONNEXION
#define H_BTTP_CONNEXION

#include "Racine.h"

namespace BTTP
{
    namespace Protocole
    {
        class IConnexion
        {
        public:
            virtual const bool ouverte() = 0;
            virtual void ouvrir() = 0;
            virtual void fermer() = 0;
            virtual void envoyer(const std::string message_prepare) = 0;
            virtual const std::string recevoir() = 0;
        };
    }
}

#endif