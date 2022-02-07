#include "../include/Contexte.h"

namespace BTTP
{
    namespace Client 
    {
        std::string Contexte::_dossier = "";

        void Contexte::initialiser(const std::string dossier)
        {
            Protocole::Contexte::initialiser();
            Contexte::_dossier = dossier;
        }
    }
}