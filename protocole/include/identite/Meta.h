#ifndef H_BTTP_META
#define H_BTTP_META

#include "Identite.h"

namespace BTTP
{
    namespace Protocole
    {
        /**
         * @brief Méta-données relatives à une identité.
         * @details Les métadonnées sont basées sur les UID des clés OpenPGP.
         */
        struct Meta
        {
        private:
            /**
             * @brief Nom du propriétaire de la clé.
             */
            std::string _nom;
            /**
             * @brief Contact identifiant le propriétaire.
             */
            std::string _contact;
            /**
             * @brief Commentaire associé aux clés.
             */
            std::string _commentaire;
            
        public:
            /**
             * @brief Construction depuis une clé publique avec récupération des métadonnées.
             * @param cle_publique Clé publique cible.
             */
            Meta(const Cle::Publique cle_publique);

            /**
             * @brief Construction depuis les métadonnées.
             * @note Utile pour créer une fonction de type : const Identite nouvelle_identite(const Meta meta, const std::strind mdp);
             * @param nom Nom du propriétaire de la clé.
             * @param contact Contact identifiant le propriétaire.
             * @param commentaire Commentaire à associer aux clés.
             */
            Meta(const std::string nom, const std::string contact, const std::string commentaire = BTTP_IDENTITE_COMMENTAIRE)
                : _nom{ nom }, _contact{ contact }, _commentaire{ commentaire }
            {}

            /**
             * @brief Retourne le nom du propriétaire des clés.
             * @return const std::string& Nom du propriétaire.
             */
            inline const std::string& nom() const { return this->_nom; }
            /**
             * @brief Retourne le contact du propriétaire des clés.
             * @return const std::string& Contact identifiant le propriétaire.
             */
            inline const std::string& contact() const { return this->_contact; }
            /**
             * @brief Retourne le commentaire associé aux clés.
             * @return const std::string& Commentaire des clés.
             */
            inline const std::string& commentaire() const { return this->_commentaire; }

            /**
             * @brief Linéarise les métadonnées pour l'affichage.
             * @return const std::string au format nom <contact> (commentaire)
             */
            const std::string afficher() const
            { return this->_nom + " <" + this->_contact + "> (" + this->_commentaire + ')'; }

            /**
             * @brief Envoie les métadonnées au format d'affichage dans le flux de sortie. 
             * @see BTTP::Meta::afficher()
             * @param os Flux de sortie.
             * @param err Erreur à afficher.
             * @return std::ostream& Flux de sortie mis à jour.
             */
            inline friend std::ostream& operator<<(std::ostream& os, const Meta& u)
            { return os << u.afficher(); }

            /**
             * @brief Comparaison de deux objets de métadonnées.
             */
            inline friend const bool operator==(const Meta& a, const Meta& b)
            { return (
              a.nom() == b.nom() && a.contact() == b.contact() && a.commentaire() == b.commentaire()  
            ); }
        };
    }
}

#endif