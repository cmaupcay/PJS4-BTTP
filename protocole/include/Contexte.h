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

        public:
            static void initialiser();
        };
    }
}

#endif