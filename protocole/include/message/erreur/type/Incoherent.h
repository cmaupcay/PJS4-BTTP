#ifndef H_BTTP_MESSAGE_TYPE_INCOHERENT
#define H_BTTP_MESSAGE_TYPE_INCOHERENT

#include "../../../Erreur.h"

#define BTTP_MESSAGE_TYPE_INCOHERENT_CODE -111

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
                     * @brief Erreur de type non cohérent entre un paquet et une classe de message.
                     */
                    class Incoherent : public Erreur
                    {
                    private:
                        /**
                         * @brief Type sérialisé du message ayant levé l'erreur.
                         */
                        const char _type_c;
                        /**
                         * @brief Paquet à l'origine de l'erreur.
                         */
                        const std::string& _paquet;

                    public:
                        /**
                         * @param type_c Type du message ayant levé l'erreur.
                         * @param paquet Paquet à l'origine de l'erreur.
                         */
                        Incoherent(const char type_c, const std::string& paquet)
                            : Erreur("Messages/Type/Incohérent", "Le type du paquet n'est pas cohérent avec le type du message.", BTTP_MESSAGE_TYPE_INCOHERENT_CODE),
                            _type_c{ type_c }, _paquet{ paquet }
                        {}

                        /**
                         * @brief Retourne le type du message ayant levé l'erreur.
                         * @return const char& Type sérialisé du message.
                         */
                        inline const char& type_c() const { return this->_type_c; }
                        /**
                         * @brief Retourne le paquet à l'origine de l'erreur.
                         * @return const std::string& Paquet dont le type était incohérent.
                         */
                        inline const std::string& paquet() const { return this->_paquet; }
                    };
                }
            }
        }
    }
}
#endif