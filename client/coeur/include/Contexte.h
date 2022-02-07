#ifndef H_BTTP_COEUR_CONTEXTE
#define H_BTTP_COEUR_CONTEXTE

#include "Racine.h"

namespace BTTP
{
    namespace Client 
    {
        namespace Coeur 
        {
            class Contexte
            {
            private:
                static std::string _dossier;
            public:
                static void initialiser(const std::string dossier = BTTP_DOSSIER);
                inline static const std::string& dossier() {return Contexte::_dossier;}

            };
        }
    }
}


#endif