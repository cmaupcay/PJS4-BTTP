#ifndef H_BTTP_CONTEXTE
#define H_BTTP_CONTEXTE

#include <string>
#include <segvcatch.h>

#ifndef BTTP_CONTEXTE_DEFAUT
    #define BTTP_CONTEXTE_DEFAUT ""
#endif

namespace BTTP
{
    namespace Protocole
    {
        // TODO Le protocole doit-il s'occuper des fichiers ?
        class Contexte
        {
        private:
            static std::string _dossier;

        public:
            static void initialiser(const std::string dossier = BTTP_CONTEXTE_DEFAUT);
            inline static const std::string& dossier() { return Contexte::_dossier; }
        };
    }
}

#endif