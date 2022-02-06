#ifndef H_COEUR_CONTEXTE
#define H_COEUR_CONTEXTE

#include <string>

#ifndef COEUR_CONTEXTE_DEFAUT
    #define COEUR_CONTEXTE_DEFAUT ""
#endif

namespace BTTP
{

    namespace Client {

        namespace Coeur {


            class Contexte
            {
                private:
                    static std::string _dossier;

                public:
                    static void initialiser(const std::string dossier = COEUR_CONTEXTE_DEFAUT);
                    inline static const std::string& dossier() {return Contexte::_dossier;}

            };

        }

    }

}


#endif