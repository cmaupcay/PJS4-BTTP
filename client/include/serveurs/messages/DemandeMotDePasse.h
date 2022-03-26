#ifndef H_BTTP_CLIENT_SERVEUR_MESSAGE_DEMANDE_MOT_DE_PASSE
#define H_BTTP_CLIENT_SERVEUR_MESSAGE_DEMANDE_MOT_DE_PASSE

#include "DemandeUtilisateur.h"

/** Champs de demande correspondant à un mot de passe. */
#define BTTP_DEMANDE_MOT_DE_PASSE "id.mdp"

namespace BTTP
{
    namespace Client
    {
        namespace Serveurs
        {
            namespace Messages
            {
                class DemandeMotDePasse : public Protocole::Messages::Demande
                {
                public:
                    DemandeMotDePasse(const std::string utilisateur)
                        : Protocole::Messages::Demande(
                            BTTP_DEMANDE_MOT_DE_PASSE,
                            { { BTTP_DEMANDE_UTILISATEUR, utilisateur } }
                        )
                    {}

                    inline static const std::string extraire_utilisateur(const Protocole::Messages::Demande* demande) { return demande->args()[0].valeur; }
                    inline const std::string utilisateur() const { return extraire_utilisateur(this); }
                };
            }
        }
    }
}

#endif