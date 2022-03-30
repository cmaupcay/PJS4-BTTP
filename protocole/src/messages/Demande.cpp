#include "../../include/messages/Demande.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            Demande::Demande(const std::string champs, const std::vector<Argument> args)
                : BTTP::Protocole::Messages::Message(Type::DEMANDE),
                _champs{ champs }, _args{ args }
            {}

            Demande::Demande()
                : BTTP::Protocole::Messages::Message(Type::DEMANDE), 
                _champs{ "" }
            {}

            Demande::Demande(const std::string paquet)
                : BTTP::Protocole::Messages::Message(Type::DEMANDE), 
                _champs{ "" }
            { this->deconstruire(paquet); }

            const std::string Demande::contenu() const
            {
                std::string contenu = this->_champs + BTTP_MESSAGE_SEP;
                const std::vector<std::string> args = joindre_args(this->_args);
                contenu += joindre(args, BTTP_MESSAGE_SEP);
                return contenu;
            }

            void Demande::deconstruction(const std::string contenu)
            {
                // Découpage selon le séparateur des messages BTTP standards.
                const std::vector<std::string> elements = decouper(contenu, BTTP_MESSAGE_SEP);
                if (elements.size() < 1) throw Erreur::Messages::Deconstruction::Incomplet(contenu, elements.size(), 1);
                // Enregistrement des informations
                this->_champs = elements[0];
                std::vector<std::string> args = std::vector<std::string>(elements.begin() + 1, elements.end());
                this->_args = decouper_args(args);
            }
        }
    }
}