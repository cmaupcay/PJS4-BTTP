#ifndef H_BTTP_TRANSACTION_FERMEE
#define H_BTTP_TRANSACTION_FERMEE

#include "../../erreur/Erreur.h"

#define BTTP_TRANSACTION_FERMEE_CODE -300

namespace BTTP
{
    namespace Protocole
    {
        namespace Erreur
        {
            namespace Transactions
            {
                /**
                 * @brief Erreur survenant lorsqu'une transaction fermée a tenté d'être utilisée pour envoyer ou recevoir des données.
                 */
                class Fermee : public Erreur
                {
                private:
                    /**
                     * @brief Défini si l'erreur est survenue lors d'un envoi (true) ou d'une réception (false) de données.
                     */
                    const bool _envoi;
                public:
                    Fermee(const bool envoi)
                        : Erreur(
                            "Transaction/Fermee", "Tentative d'utilisation d'une transaction fermée.",
                            BTTP_TRANSACTION_FERMEE_CODE
                        ),
                        _envoi{ envoi }
                    {}

                    /**
                     * @brief Retourne l'indicateur définissant si l'erreur est survenue lors d'un envoi ou d'une réception.
                     * @return true Erreur survenue lors d'un envoi.
                     * @return false Erreur survenue lors d'une réception.
                     */
                    inline const bool& envoi() const { return this->_envoi; }
                };
            }
        }
    }
}
#endif