#include "../include/Contexte.h"

namespace BTTP
{
    namespace Protocole
    {
        void Contexte::initialiser()
        {
            // Initialisation de la librairie Plaristote/segvcatch
            // Elle permet de transformer les signaux d'erreur de segmentation en exception.
            segvcatch::init_segv();
            segvcatch::init_fpe();
        }
    }
}