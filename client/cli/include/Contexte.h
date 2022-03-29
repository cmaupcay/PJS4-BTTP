#ifndef H_BTTP_CLIENT_CLI_CONTEXTE
#define H_BTTP_CLIENT_CLI_CONTEXTE

#include "Racine.h"

namespace BTTP
{
    namespace Client 
    {
        namespace CLI
        {
            class Contexte : public Protocole::Contexte
            {
            private:
                static std::unique_ptr<Client::Contexte> _contexte;

            public:
                static void initialiser(const int& argc, const char** argv);
                static inline std::unique_ptr<Client::Contexte>& client() { return _contexte; }
            };
        }
    }
}


#endif