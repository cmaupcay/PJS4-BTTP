#ifndef H_BTTP_CLIENT_IDENTITES_META_INCORRECTES
#define H_BTTP_CLIENT_IDENTITES_META_INCORRECTES

#include "../../Racine.h"

#define BTTP_CLIENT_IDENTITES_META_INCORRECTES -1300

namespace BTTP
{
    namespace Client
    {
        namespace Erreur
        {
            namespace Identites
            {
                class MetaIncorrectes : public Erreur
                {
                private:
                    const Protocole::Meta& _meta_attendues;
                    const Protocole::Meta& _meta_importees;

                public:
                    MetaIncorrectes(const Protocole::Meta& meta_attendues, const Protocole::Meta& meta_importees)
                        : Erreur("Client/Identites/MetaIncorrectes", "Les metadonnees de l'identite importees sont incorrectes.", BTTP_CLIENT_IDENTITES_META_INCORRECTES),
                        _meta_attendues{ meta_attendues }, _meta_importees{ meta_importees }
                    {}

                    inline const Protocole::Meta& meta_attendues() const { return this->_meta_attendues; }
                    inline const Protocole::Meta& meta_importees() const { return this->_meta_importees; }
                };
            }
        }
    }
}
#endif