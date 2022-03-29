#include "../include/Contexte.h"

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            std::unique_ptr<Client::Contexte> Contexte::_contexte = nullptr;

            void Contexte::initialiser(const int& argc, const char** argv)
            {
                const std::string dossier = std::filesystem::canonical(Fichiers::dossier(argv[0])).string();
                _contexte = std::make_unique<Client::Contexte>(dossier);
            }
        }
    }
}