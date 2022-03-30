#ifndef H_BTTP_SERVEUR_DATA_TERMINAL_DISTANT
#define H_BTTP_SERVEUR_DATA_TERMINAL_DISTANT

#include "Client.h"
#include "../Script.h"

namespace BTTP
{
    namespace Serveur
    {
        namespace Data
        {
            namespace Terminal
            {
                // TODO Implémentation
                class Distant : public Client
                {
                public:
                    Distant(std::unique_ptr<Source>& source, Utilisateur proprietaire, Protocole::Cle::Publique& cle)
                        : Client(source, proprietaire, cle)
                    {} 
                    Distant(std::unique_ptr<Source>& source, const std::string empreinte)
                        : Client(source, empreinte)
                    {}

                    const std::vector<Script> scripts() const;
                    inline void mettre_a_jour_disponibilite(const bool disponible) override { this->_disponible = disponible; }
                };
            }
        }
    }
}

#endif