#include "../include/Fichiers.h"

namespace BTTP
{
    namespace Client
    {
        namespace Fichiers
        {
            const std::string chemin(const std::string fichier, const std::string dossier, const bool utiliser_contexte)
            { return (utiliser_contexte ? Contexte::dossier() + '/' : "") + dossier + '/' + fichier; }
        }
    }
}