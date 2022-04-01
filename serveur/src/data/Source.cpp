#include "../../include/data/Source.h"

namespace BTTP
{
    namespace Serveur
    {
        namespace Data
        {

            const std::string url = "tcp://" + std::string(BTTP_DATA_SQL_HOTE) + ":" + std::to_string(BTTP_DATA_SQL_PORT);

            Source::Source(const std::unique_ptr<Client::Contexte>& contexte)
                    : _contexte{ contexte }
            {

                sql::Driver *driver = get_driver_instance();
                this->_connexion = driver->connect(url, BTTP_DATA_SQL_UTILISATEUR, BTTP_DATA_SQL_MDP);
                this->_connexion->setSchema(BTTP_DATA_SQL_BASE);
                
            } 


            const std::vector<std::vector<Argument>> Source::selectionner(const std::string table, const std::vector<Argument>& selection, const std::vector<Argument>& conditions) 
            {

                sql::PreparedStatement* declaration;
                sql::ResultSet* resultat;

                std::string requete = "SELECT ";

                //if(selection.size() == 0) //TODO erreur associée
                
                for (Argument arg : selection)
                {

                    requete += arg.nom;
                    if(selection.back().nom != arg.nom)
                        requete += ",";
                    
                }

                requete += " FROM " + table;

                if(conditions.size() > 0)
                    requete += " WHERE ";


                for(Argument arg : conditions)
                {
                
                    requete += arg.nom + "=" + "? ";
                    
                    if(conditions.back().nom != arg.nom)
                        requete += "AND ";


                }

                requete += ";";

                declaration = this->_connexion->prepareStatement(requete);

                for(int i = 0 ; i < conditions.size() ; i++)
                {
                    Argument condition = conditions.at(i);

                    if(condition.type == Type::NOMBRE)
                        declaration->setInt(i+1, stoi(condition.valeur));
                    else if (condition.type == Type::TEXTE)
                        declaration->setString(i+1, condition.valeur);


                }

                resultat = declaration->executeQuery();

                std::vector<std::vector<Argument>> reponse;

                while(resultat->next())
                {

                    std::vector<Argument> args;

                    for(int i = 0 ; i < selection.size() ; i++)
                    {
                        Argument arg = selection.at(i);

                        if(arg.type == Type::NOMBRE)
                            arg.valeur = std::to_string(resultat->getInt(i+1));
                        else if (arg.type == Type::TEXTE)
                            arg.valeur = resultat->getString(i+1);
                        
                        args.push_back(arg);
                        
                    }

                    reponse.push_back(args);

                }

                return reponse;

            }

            void Source::inserer(const std::string table, const std::vector<Argument>& selection) 
            {

                sql::PreparedStatement* declaration;

                std::string requete = "INSERT INTO " + table + " (";  

                for (Argument arg : selection)
                {

                    requete += arg.nom;
                    if(selection.back().nom != arg.nom)
                        requete += ",";
                    
                }

                requete += ") VALUES (";

                for(int i = 0 ; i < selection.size() ; i++)
                {

                    requete += "?";
                    if(i < (selection.size() - 1))
                        requete += ", ";

                }

                requete += ");";

                declaration = this->_connexion->prepareStatement(requete);

                for(int i = 0 ; i < selection.size() ; i++)
                {
                    Argument arg = selection.at(i);

                    if(arg.type == Type::NOMBRE)
                        declaration->setInt(i+1, stoi(arg.valeur));
                    else if (arg.type == Type::TEXTE)
                        declaration->setString(i+1, arg.valeur);

                }

                declaration->execute();


            }

        }
    }
}