#include "../include/Contexte.h"

namespace BTTP
{
    namespace Client 
    {
        std::string Contexte::_dossier = "";
        std::shared_ptr<Protocole::Identite> Contexte::_id = nullptr;

        void Contexte::initialiser(const std::string dossier)
        {
            Protocole::Contexte::initialiser();
            if (std::filesystem::is_directory(dossier)) _dossier = dossier;
            // else throw // TODO Classe d'erreur DossierInexistant, super classe ElementInexistant ?
        }
    }
}