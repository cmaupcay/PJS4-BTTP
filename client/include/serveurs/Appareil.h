#ifndef H_BTTP_CLIENT_APPAREIL
#define H_BTTP_CLIENT_APPAREIL

#include "Serialisable.h"

namespace BTTP
{
    namespace Client
    {
        /**
         * @brief Représentation d'un appareil BTTP.
         */
        class Appareil : public ISerialisable
        {
        private:
            /** Nom d'affichage de l'appareil. */
            std::string _nom;
            /** Clé publique de l'appareil. */
            const Protocole::Cle::Publique* _cle;

        public:
            /**
             * @brief Construction d'un nouvel objet représentant un appareil BTTP.
             * @param cle Cle publique de l'appareil.
             */
            Appareil(const Protocole::Cle::Publique& cle)
                : _nom{ Protocole::Meta(cle).nom() }, _cle{ &cle }
            {}
            // TOTEST
            /**
             * @brief Construction d'un objet appareil depuis un objet appareil sérialisé.
             * @param serialisation Informations sérialisées de l'appareil.
             */
            Appareil(const std::string serialisation);

            /**
             * @brief Retourne le nom d'affichage de l'appareil.
             * @return const std::string& Nom d'affichage de l'appareil.
             */
            inline const std::string& nom() const { return this->_nom; }

            /**
             * @brief Retourne la clé publique de l'appareil.
             * @return const Cle::Publique& Clé publique de l'appareil.
             */
            inline const Protocole::Cle::Publique& cle() const { return *this->_cle; }

            /**
             * @brief Sérialisation des informations de l'appareil.
             * @return const std::string Informations sérialisées de l'appareil.
             */
            inline const std::string serialiser() const override
            { return this->_nom + BTTP_MESSAGE_ARGS_SEP + this->_cle->exporter(false); }

            inline const std::string informations() const
            { return this->_nom + " (" + this->_cle->empreinte(); + ')'; }

            inline friend std::ostream& operator<<(std::ostream& os, const Appareil& app) 
            { return (os << app.informations()); }
        };
    }
}

#endif