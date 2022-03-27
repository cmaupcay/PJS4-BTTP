#ifndef H_BTTP_CLIENT_SERVEURS_SCRIPT
#define H_BTTP_CLIENT_SERVEURS_SCRIPT

#include "Serialisable.h"
#include "../scripts/Script.h"

namespace BTTP
{
    namespace Client
    {
        namespace Serveurs
        {
            /**
             * @brief Représentation d'un script distant.
             */
            class Script : public ISerialisable
            {
            private:
                /** Nom d'affichage du script. */
                std::string _nom;
                /** Identifiant numérique unique du script. */
                uint64_t _id;

            public:
                /**
                 * @brief Construction d'un nouvel objet représentant un script distant.
                 * @param script Script local original.
                 */
                Script(const Scripts::Script& script)
                    : _nom{ script.nom() }, _id{ script.id() }
                {}
                // TOTEST
                /**
                 * @brief Construction d'un objet de script distant depuis un objet sérialisé.
                 * @param serialisation Informations sérialisées du script.
                 */
                Script(const std::string serialisation);

                /**
                 * @brief Retourne le nom d'affichage du script.
                 * @return const std::string& Nom d'affichage du script.
                 */
                inline const std::string& nom() const { return this->_nom; }
                
                /**
                 * @brief Retourne l'identifiant unique du script.
                 * @return const uint64_t& Identifiant numérique du script.
                 */
                inline const uint64_t& id() const { return this->_id; }

                /**
                 * @brief Sérialisation des informations du script.
                 * @return const std::string Informations sérialisées du script.
                 */
                inline const std::string serialiser() const override
                { return this->_nom + BTTP_MESSAGE_ARGS_SEP + std::to_string(this->_id); }
            };
        }
    }
}

#endif