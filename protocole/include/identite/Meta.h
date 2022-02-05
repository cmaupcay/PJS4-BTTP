#ifndef H_BTTP_UTILISATEUR
#define H_BTTP_UTILISATEUR

#include "Identite.h"

namespace BTTP
{
    namespace Protocole
    {
        // TOCOMMENT
        struct Meta
        // Basé sur les UID de OpenPGP
        {
        private:
            std::string _nom;
            std::string _contact;
            std::string _commentaire;
            
        public:
            Meta(const Identite::ClePublique cle_publique);

            // Constructeur tile pour créer une fonction de type : const Identite nouvelle_identite(const Meta meta, const std::strind mdp);
            Meta(const std::string nom, const std::string contact, const std::string commentaire = BTTP_IDENTITE_COMMENTAIRE)
                : _nom{ nom }, _contact{ contact }, _commentaire{ commentaire }
            {}

            inline const std::string& nom() const { return this->_nom; }
            inline const std::string& contact() const { return this->_contact; }
            inline const std::string& commentaire() const { return this->_commentaire; }

            const std::string lire() const
            { return this->_nom + " <" + this->_contact + "> (" + this->_commentaire + ')'; }
            inline friend std::ostream& operator<<(std::ostream& os, const Meta& u)
            { return os << u.lire(); }
        };
    }
}

#endif