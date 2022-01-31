#include "../include/Contexte.h"

namespace BTTP
{
    namespace Protocole
    {
        std::string Contexte::_dossier = BTTP_CONTEXTE_DEFAUT;

        void Contexte::initialiser(const std::string dossier)
        {
            // Définition du dossier de travail
            Contexte::_dossier = dossier;

            // Initialisation de la librairie Plaristote/segvcatch
            // Elle permet de transformer les signaux d'erreur de segmentation en exception.
            segvcatch::init_segv();
            segvcatch::init_fpe();
        }
    }
}