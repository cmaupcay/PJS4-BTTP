#ifndef H_BTTP_CLIENT_SCRIPTS_MESSAGE_DEMANDE_AJOUT
#define H_BTTP_CLIENT_SCRIPTS_MESSAGE_DEMANDE_AJOUT

#include "../../Racine.h"

/** Champs de demande correspondant à un ajout de script. */
#define BTTP_DEMANDE_SCRIPT_AJOUT "src.ajout"
/** Nom de l'argument indiquant le nom du script à ajouter. */
#define BTTP_DEMANDE_SCRIPT_AJOUT_NOM "nom"

namespace BTTP
{
    namespace Client
    {
        namespace Scripts
        {
            namespace Messages
            {
                class DemandeAjout : public Protocole::Messages::Demande
                {
                public:
                    DemandeAjout(const std::string nom)
                        : Protocole::Messages::Demande(
                            BTTP_DEMANDE_SCRIPT_AJOUT,
                            { { BTTP_DEMANDE_SCRIPT_AJOUT_NOM, nom } }
                        )
                    {}
                };
            }
        }
    }
}

#endif