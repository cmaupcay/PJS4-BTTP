#ifndef H_BTTP_SERVEUR_DATA_SCRIPT
#define H_BTTP_SERVEUR_DATA_SCRIPT

#include "terminal/Client.h"

#define BTTP_DATA_SCRIPT_REF "bttp.script"

namespace BTTP
{
    namespace Serveur
    {
        namespace Data
        {
            // TODO Implémentation
            class Script : public Modele
            {
            private:
                const std::shared_ptr<Terminal::Client>& _hote;
                std::string _nom;

            protected:
                const bool existe_sans_id() const override;
                const bool existe_depuis_id() const override;

                const bool mettre_a_jour_sans_id() override;
                const bool mettre_a_jour_depuis_id() override;

            public:
                Script(std::unique_ptr<Source>& source, const std::shared_ptr<Terminal::Client>& hote, const uint32_t id)
                    : Modele(source, BTTP_DATA_SCRIPT_REF, id), _hote { hote }
                {}
                Script(std::unique_ptr<Source>& source, const std::shared_ptr<Terminal::Client>& hote, const std::string nom)
                    : Modele(source, BTTP_DATA_SCRIPT_REF), _hote { hote }, _nom{ nom }
                {}

                // TODO Verifier l'acces en execution d'un utilisateur (s'il est proprietaire de l'hôte).
                const bool verifier_acces(const Utilisateur& utilisateur) const;

                inline const std::string& nom() const { return this->_nom; }
            };
        }
    }
}

#endif