#ifndef H_BTTP_CLIENT
#define H_BTTP_CLIENT

#include "Racine.h"
#include <fstream>
#include <filesystem>

namespace BTTP 
{

    namespace Client 
    {

        namespace Coeur
        {

            void ecrireCle(
                const std::string cle_privee, const std::string nom,
                const std::string chemin = BTTP_IDENTITE_CHEMIN_DEFAUT, const bool creer_chemin = BTTP_IDENTITE_CHEMIN_CREER,
                const bool dossier_contexte = BTTP_IDENTITE_CHEMIN_BTTP_DEFAUT
            );

            const std::string lireCle(
                const std::string nom, const std::string chemin = BTTP_IDENTITE_CHEMIN_DEFAUT,
                const bool dossier_contexte = BTTP_IDENTITE_CHEMIN_BTTP_DEFAUT
            );


        }


    }


}


#endif