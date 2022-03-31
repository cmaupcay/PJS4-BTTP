#ifndef H_BTTP_SERVEUR_DATA_SOURCE
#define H_BTTP_SERVEUR_DATA_SOURCE

#include "../Racine.h"
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

#define BTTP_DATA_SQL_BASE "bttp"
#define BTTP_DATA_SQL_HOTE "localhost"
#define BTTP_DATA_SQL_PORT 3306
#define BTTP_DATA_SQL_UTILISATEUR "root" // TODO Idenitifiant
#define BTTP_DATA_SQL_MDP "" // TODO Mot de passe (voir comment le masquer eventuellement, ou le demander au demarrage ?)

namespace BTTP
{
    namespace Serveur
    {
        namespace Data
        {
            enum Type { TEXTE, NOMBRE };

            struct Argument
            {
                std::string nom;
                std::string valeur;
                Type type;

            };

            // TODO Implémentation SQL
            class Source
            {
            private:
                const std::unique_ptr<Client::Contexte>& _contexte;
                sql::Connection* _connexion;

            public:
                Source(const std::unique_ptr<Client::Contexte>& contexte);
                /**
                 * @brief Récupérer des informations dans la base
                 * 
                 * @param table table concernée
                 * @param selection éléments à sélectionner
                 * @param conditions conditions de recherche
                 * @return //TODO à définir
                 */
                std::string selectionner(std::string table, std::vector<Argument> selection, std::vector<Argument> conditions);
                 
            };
        }
    }
}

#endif