INSERT INTO bttp.categorie_script(nom) VALUES ("Téléchargement");
INSERT INTO bttp.categorie_script(nom) VALUES ("Notification");
INSERT INTO bttp.categorie_script(nom) VALUES ("Raccourci");

INSERT INTO bttp.format_script(extension) VALUES ("sh");    /* Script shell Linux */
INSERT INTO bttp.format_script(extension) VALUES ("bat");   /* Script shell Windows */
INSERT INTO bttp.format_script(extension) VALUES ("bin");   /* Binaire Linux */
INSERT INTO bttp.format_script(extension) VALUES ("exe");   /* Binaire Windows */

INSERT INTO `format_script` (`id`, `extension`) VALUES
(2, 'jar'),
(1, 'txt'),
(3, 'zip');

INSERT INTO `categorie_script` (`id`, `nom`) VALUES
(1, 'Essai'),
(3, 'notification'),
(4, 'raccourci'),
(2, 'télechargement');

INSERT INTO `script_publique` (`id`, `nom`, `version`, `id_auteur`, `publication`, `verifie`, `id_categorie`, `id_format`, `telechargements`, `somme`, `chemin_code_source`) VALUES
(1, 'Script de test', '0.0.1', 10, '2022-03-25 21:56:34', 0, 1, 1, 0, 123, 'Bureau/test.txt'),
(2, 'Script de test 2', '1.0.2', 7, '2022-03-28 14:25:11', 0, 2, 2, 13, 123, 'Bureau/test2.jar'),
(3, 'un script', '2.0.1', 11, '2022-03-28 14:48:06', 1, 3, 3, 2, 123, 'Bureau/un_script.zip');

INSERT INTO `terminal` (`id`, `cle_publique`, `empreinte_cle_publique`, `nom`, `disponible`, `id_proprietaire`, `ajout`, `derniere_connexion`, `favori`, `meta`, `distant` ) VALUES
(1, 'Exc12hszdvci12BCcvey1236', 'ci12BCcvey1', 'PC 1 - Home', 0, 1, '2022-03-25 21:56:34', '2022-03-28 14:25:11', 0, 'Mon PC distant à domicile', 0);

INSERT INTO `utilisateur` (`id`, `pseudo`, `mdp`) VALUES 
(1, 'likir09', '3a6d64c24cf80b69ccda37650406467e8266667b50cfd0b984beb3651b129ed7');


COMMIT;