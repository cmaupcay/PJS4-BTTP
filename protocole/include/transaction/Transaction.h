#ifndef H_BTTP_TRANSACTION
#define H_BTTP_TRANSACTION

#include "../identite/Meta.h"
#include "../message/Messages.h"
#include "../message/controle/Messages.h"
#include "../Connexion.h"

#include "Mode.h" // Temporaire, sera inclus par le message Ouverture

#include "erreur/DejaFermee.h"
#include "erreur/DejaOuverte.h"
#include "erreur/Fermee.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Transaction
        {
            // TOCOMMENT
            class ITransaction
            {
            public:
                virtual const Mode mode() const = 0;

                virtual const bool ouverte() const = 0;
                virtual void ouvrir(const std::string mdp) = 0;
                virtual void fermer(const std::string mdp) = 0;

                virtual void envoyer(const Messages::IMessage& message, const std::string mdp) = 0;
                virtual const Messages::IMessage* recevoir(const std::string mdp) = 0;
            };

            // TOCOMMENT
            class _Transaction : public ITransaction
            {
            private:
                bool _ouverte;
                const Mode _mode;
                IConnexion& _connexion;
                const Identite& _identite;

            protected:
                _Transaction(const Mode mode, IConnexion& connexion, const Identite& identite);

                inline const Identite& identite() const { return this->_identite; }
                inline IConnexion& connexion() const { return this->_connexion; }

                virtual const std::string preparer(const Messages::IMessage& message, const std::string& mdp) const = 0;
                virtual inline const Messages::IMessage* resoudre(const std::string& message, const std::string& mdp) = 0;

                virtual void ouverture(const std::string& mdp) = 0;
                virtual void fermeture(const std::string& mdp) = 0;

            public:
                inline const Mode mode() const override { return this->_mode; }

                inline const bool ouverte() const override { return this->_ouverte; }
                // TOTEST Ouverture
                void ouvrir(const std::string mdp) override;
                // TOTEST Fermeture
                void fermer(const std::string mdp) override;

                // TOTEST Envoi de message
                void envoyer(const Messages::IMessage& message, const std::string mdp) override;
                // TOTEST Réception de message
                const Messages::IMessage* recevoir(const std::string mdp) override;
            };
        }
    }
}

#endif