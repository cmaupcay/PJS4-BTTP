#ifndef H_BTTP_CONTEXTE
#define H_BTTP_CONTEXTE

#include "Racine.h"

#include <string>
#include <segvcatch.h>

namespace BTTP
{
    namespace Protocole
    {
        class Contexte
        {
        private:
            static bool _initialise;

        public:
            static void initialiser();
            static const bool& initialise() { return _initialise; }
        };
    }
}

#endif