#include "../include/Contexte.h"

namespace BTTP
{

    namespace Client 
    {

        namespace Coeur 
        {

            std::string Contexte::_dossier = COEUR_CONTEXTE_DEFAUT;

            void Contexte::initialiser(const std::string dossier){

                Contexte::_dossier = dossier;

            }


        }


    }


}