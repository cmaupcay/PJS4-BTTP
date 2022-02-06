#ifndef H_BTTP_IDENTITE_CHIFFREMENT
#define H_BTTP_IDENTITE_CHIFFREMENT

#include "../../Erreur.h"

#ifndef BTTP_IDENTITE_CHIFFREMENT_CODE
    #define BTTP_IDENTITE_CHIFFREMENT_CODE -201
#endif

namespace BTTP
{
    namespace Protocole
    {
        namespace Erreur
        {
            namespace Identite
            {
                /**
                 * @brief Erreur survenue lors du chiffrement ou de la signature d'un message.
                 */
                class Chiffrement : public Erreur
                {
                private:
                    /**
                     * @brief Message dont le chiffrement ou la signature a échoué.
                     */
                    const std::string& _message_echec;

                public:
                    /**
                     * @param details Détails de l'erreur.
                     * @param message_echec Message dont le chiffrement ou la signature a échoué.
                     */
                    Chiffrement(const std::string details, const std::string& message_echec)
                        : Erreur("Identite/Chiffrement", "Le chiffrement du message a échoué.\n\tDetails : " + details, BTTP_IDENTITE_CHIFFREMENT_CODE),
                        _message_echec{ message_echec }
                    {}

                    /**
                     * @brief Retourne le message dont le chiffrement ou la signature a échoué.
                     * @return const std::string& Message à l'origine de l'erreur.
                     */
                    inline const std::string& message_echec() const { return this->_message_echec; }
                };
            }
        }
    }
}
#endif