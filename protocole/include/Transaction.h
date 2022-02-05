#ifndef H_BTTP_TRANSACTION
#define H_BTTP_TRANSACTION

#include "identite/Meta.h"
#include "message/Messages.h"
#include "message/controle/Messages.h"

namespace BTTP
{
    namespace Protocole
    {
        class ITransaction
        {
        public:
            virtual void initialiser() = 0;
            virtual void fermer() = 0;

            virtual const std::string preparer(const Messages::IMessage& message) const = 0;
            virtual const std::string preparer(const Messages::Controle::Message& message_controle) const = 0;

            // TODO Voir si des méthodes manques
        };

        class Transaction : public ITransaction
        {
        private:
            const Identite& _identite;
            const Identite::ClePublique& _destinataire;
            const Identite::ClePublique& _controleur;

        public:
            // TODO Implémentation
            Transaction(const Identite& identite, const Identite::ClePublique& destinataire, const Identite::ClePublique& controleur);

            // TODO Implémentation
            void initialiser() override;
            // TODO Implémentation
            void fermer() override;

            // TODO Implémentation
            const std::string preparer(const Messages::IMessage& message) const override;
            // TODO Implémentation
            const std::string preparer(const Messages::Controle::Message& message_controle) const override;
        };
    }
}

#endif