#ifndef H_BTTP_SERVEUR_DATA_TERMINAL_CLIENT
#define H_BTTP_SERVEUR_DATA_TERMINAL_CLIENT

#include "../Utilisateur.h"

#define BTTP_DATA_TERMINAL_REF "bttp.terminal"

namespace BTTP
{
    namespace Serveur
    {
        namespace Data
        {
            namespace Terminal
            {
                // TODO Implémentation
                class Client : public Modele
                {
                private:
                    std::unique_ptr<Utilisateur> _proprietaire;
                    std::unique_ptr<Protocole::Cle::Publique> _cle;
                    std::string _empreinte;

                protected:
                    bool _disponible;

                    const bool existe_sans_id() const override;
                    const bool existe_depuis_id() const override;

                    const bool mettre_a_jour_sans_id() override;
                    const bool mettre_a_jour_depuis_id() override;

                public:
                    Client(std::unique_ptr<Source>& source, Utilisateur proprietaire, Protocole::Cle::Publique& cle)
                        : Modele(source, BTTP_DATA_TERMINAL_REF), _proprietaire{ std::make_unique<Utilisateur>(proprietaire) },
                        _cle{ std::make_unique<Protocole::Cle::Publique>(cle) }, _empreinte{ cle.empreinte() }
                    {} 
                    Client(std::unique_ptr<Source>& source, const std::string empreinte)
                        : Modele(source, BTTP_DATA_TERMINAL_REF), _empreinte{ empreinte }, _disponible{ false }
                    {}

                    inline const std::unique_ptr<Utilisateur>& proprietaire() const { return this->_proprietaire; }

                    inline const std::unique_ptr<Protocole::Cle::Publique>& cle() const { return this->_cle; }
                    inline const std::string& empreinte() const { return this->_empreinte; }

                    inline const bool& disponibilite() const { return this->_disponible; }
                    virtual inline void mettre_a_jour_disponibilite(const bool disponible) { this->_disponible = false; }
                };
            }
        }
    }
}

#endif