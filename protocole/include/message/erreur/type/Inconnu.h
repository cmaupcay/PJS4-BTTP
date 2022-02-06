#ifndef H_BTTP_MESSAGE_TYPE_INCONNU
#define H_BTTP_MESSAGE_TYPE_INCONNU

#include "../../../Erreur.h"

#ifndef BTTP_MESSAGE_TYPE_INCONNU_CODE
    #define BTTP_MESSAGE_TYPE_INCONNU_CODE -110
#endif

namespace BTTP
{
    namespace Protocole
    {
        namespace Erreur
        {
            namespace Messages
            {
                namespace Type
                {
                    /**
                     * @brief Erreur de résolution de type de message.
                     */
                    class Inconnu : public Erreur
                    {
                    private:
                        /**
                         * @brief Paquet à l'origine de l'erreur.
                         */
                        const std::string& _paquet;

                    public:
                        /**
                         * @param paquet Paquet dont le type est incconu de la fonction de résolution.
                         */
                        Inconnu(const std::string& paquet)
                            : Erreur("Messages/Type/Inconnu", "Impossible de résoudre le type du message.", BTTP_MESSAGE_TYPE_INCONNU_CODE),
                            _paquet{ paquet }
                        {}

                        /**
                         * @brief Retourne le paquet à l'origine de l'erreur.
                         * @return const std::string& Paquet dont le type était inconnu.
                         */
                        inline const std::string& paquet() const { return this->_paquet; }
                    };
                }
            }
        }
    }
}
#endif