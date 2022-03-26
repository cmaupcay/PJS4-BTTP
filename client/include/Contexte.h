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
            static const Protocole::Identite* _id;

        public:
            static void initialiser(const std::string dossier = "");
            inline static const std::string& dossier() {return _dossier;}

            inline static const Protocole::Identite* identite() { return _id; }
            inline static void modifier_identite(const Protocole::Identite* id) { _id = id; }
        };
    }
}


#endif