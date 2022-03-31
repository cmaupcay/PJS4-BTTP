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
            enum class Type { TEXTE, NOMBRE };

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
                 * @return renvoie un vecteur de vecteurs d'arguments (chaque vecteur d'arguments représentant une entrée)
                 */
                const std::vector<std::vector<Argument>> selectionner(const std::string table, const std::vector<Argument>& selection, const std::vector<Argument>& conditions);
                
                /**
                 * @brief Insérer des informations dans la base
                 * 
                 * @param table table concernée
                 * @param selection éléments à insérer
                 */
                void inserer(const std::string table, const std::vector<Argument>& selection);

                 
            };
        }
    }
}

#endif