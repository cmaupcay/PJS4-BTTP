#ifndef H_BTTP_CLIENT_CONTEXTE
#define H_BTTP_CLIENT_CONTEXTE

#include "Racine.h"

namespace BTTP
{
    namespace Client 
    {
        class Contexte
        {
        private:
            static std::string _dossier;
        public:
            static void initialiser(const std::string dossier = BTTP_DOSSIER);
            inline static const std::string& dossier() {return _dossier;}

        };
    }
}


#endif