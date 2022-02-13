INSERT INTO bttp.categorie_script(nom) VALUES ("Téléchargement");
INSERT INTO bttp.categorie_script(nom) VALUES ("Notification");
INSERT INTO bttp.categorie_script(nom) VALUES ("Raccourci");

INSERT INTO bttp.format_script(extension) VALUES ("sh");    /* Script shell Linux */
INSERT INTO bttp.format_script(extension) VALUES ("bat");   /* Script shell Windows */
INSERT INTO bttp.format_script(extension) VALUES ("bin");   /* Binaire Linux */
INSERT INTO bttp.format_script(extension) VALUES ("exe");   /* Binaire Windows */

COMMIT;