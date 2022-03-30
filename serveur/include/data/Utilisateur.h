#ifndef H_BTTP_SERVEUR_DATA_UTILISATEUR
#define H_BTTP_SERVEUR_DATA_UTILISATEUR

#include "Modele.h"

#define BTTP_DATA_UTILISATEUR_REF "bttp.utilisateur"

namespace BTTP
{
    namespace Serveur
    {
        namespace Data
        {
            // TODO Implémentation
            class Utilisateur : public Modele
            {
            private:
                std::string _pseudo;

            protected:
                const bool existe_sans_id() const override;
                const bool existe_depuis_id() const override;

                const bool mettre_a_jour_sans_id() override;
                const bool mettre_a_jour_depuis_id() override;

            public:
                Utilisateur(std::unique_ptr<Source>& source, const std::string pseudo)
                    : Modele(source, BTTP_DATA_UTILISATEUR_REF), _pseudo { pseudo }
                {}

                // TODO Authentification
                const bool authentification(const std::string mdp);
            };
        }
    }
}

#endif