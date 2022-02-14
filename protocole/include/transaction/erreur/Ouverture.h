#ifndef H_BTTP_TRANSACTION_OUVERTURE
#define H_BTTP_TRANSACTION_OUVERTURE

#include "../../erreur/Erreur.h"

#define BTTP_TRANSACTION_OUVERTURE_CODE -303
#define BTTP_TRANSACTION_OUVERTURE_MSG "L'ouverture de la transaction a échoué."

namespace BTTP
{
    namespace Protocole
    {
        namespace Erreur
        {
            namespace Transaction
            {
                /**
                 * @brief Erreur survenant lorsqu'une transaction n'a pas pu être initialisée.
                 */
                class Ouverture : public Erreur
                {
                private:
                    /**
                     * @brief Défini si l'erreur est survenue du côté client (true) ou du côté distant (false).
                     */
                    const bool _client;

                protected:
                    Ouverture(const bool client, const std::string nom, const std::string message, const int code)
                        : Erreur("Transaction/" + nom, std::string(BTTP_TRANSACTION_OUVERTURE_MSG).append("\n\tDetails : " + message), code),
                        _client{ client }
                    {}

                public:
                    Ouverture(const bool client)
                        : Erreur("Transaction/Ouverture", BTTP_TRANSACTION_OUVERTURE_MSG, BTTP_TRANSACTION_OUVERTURE_CODE),
                        _client{ client }
                    {}

                    /**
                     * @brief Retourne l'indicateur définissant si l'erreur est survenue côté client ou distant.
                     * @return true Erreur survenue du côté client.
                     * @return false Erreur survenue du côté distant.
                     */
                    inline const bool& client() const { return this->_client; }
                };
            }
        }
    }
}
#endif