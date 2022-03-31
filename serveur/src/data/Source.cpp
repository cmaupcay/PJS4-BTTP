#include "../../include/data/Source.h"

namespace BTTP
{
    namespace Serveur
    {
        namespace Data
        {

            Source::Source(const std::unique_ptr<Client::Contexte>& contexte)
                    : _contexte{ contexte }
            {

                sql::Driver *driver = get_driver_instance();
                std::string adresse = "tcp://";
                adresse.append(BTTP_DATA_SQL_HOTE);
                adresse.append(":");
                adresse.append(std::to_string(BTTP_DATA_SQL_PORT));
                this->_connexion = driver->connect(adresse, BTTP_DATA_SQL_UTILISATEUR, BTTP_DATA_SQL_MDP);
                this->_connexion->setSchema(BTTP_DATA_SQL_BASE);
                
            } 


            std::string Source::selectionner(std::string table, std::vector<Argument> selection, std::vector<Argument> conditions) 
            {

                sql::PreparedStatement* declaration;
                sql::ResultSet* resultat;

                std::string requete = "SELECT ";
                
                for (Argument arg : selection)
                {

                    requete.append(arg.nom);
                    if(selection.back().nom != arg.nom)
                        requete.append(",");
                    
                }

                requete.append(" FROM ");
                requete.append(table);
                requete.append(";");

                declaration = this->_connexion->prepareStatement(requete);

                resultat = declaration->executeQuery();

                std::string res = "";

                while(resultat->next())
                    res = "Id : " + std::to_string(resultat->getInt(1)) + " | Nom : " + resultat->getString(2);

                return res;
                


            }

        }
    }
}