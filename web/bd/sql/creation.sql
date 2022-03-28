/* TODO Mettre a jour le MLD */
/* Suppression des tables existantes */
DROP TABLE IF EXISTS bttp.script;
DROP TABLE IF EXISTS bttp.script_publique;
DROP TABLE IF EXISTS bttp.categorie_script;
DROP TABLE IF EXISTS bttp.format_script;
DROP TABLE IF EXISTS bttp.terminal_distant;
DROP TABLE IF EXISTS bttp.terminal_client;
DROP TABLE IF EXISTS bttp.utilisateur;
/* Suppression de la base existante */
DROP DATABASE IF EXISTS bttp;

/* Création de la base */
CREATE DATABASE bttp CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
/* Création des tables */
CREATE TABLE bttp.utilisateur (
    id INT AUTO_INCREMENT, /* Identifiant numérique unique de l'utilisateur */
    pseudo VARCHAR(32) NOT NULL, /* Pseudonyme de l'utilisateur */
    mdp VARCHAR(512) NOT NULL, /* Hash du mot de passe */
    PRIMARY KEY(id),
    UNIQUE(pseudo),
    CHECK(pseudo=LOWER(pseudo))
) ENGINE=InnoDB AUTO_INCREMENT=1;

CREATE TABLE bttp.terminal_client (
    id INT AUTO_INCREMENT, /* Identifiant numérique unique du terminal */
    cle_publique VARCHAR(512) NOT NULL, /* Clé publique propre au terminal */
    nom VARCHAR(64) NOT NULL, /* Nom du terminal */
    disponible BOOLEAN NOT NULL DEFAULT 0, /* Indique si le terminal est disponible pour une transaction */
    id_proprietaire INT NOT NULL, /* Identifiant numérique unique du proprietaire */
    ajout DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP, /* Date et heure d'ajout du terminal */
    derniere_connexion DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP, /* Date et heure de la dernière connexion avec le terminal */
    favori BOOLEAN NOT NULL DEFAULT 0, /* Indique si l'utilisateur a ajouté le terminal à ses favoris */
    meta VARCHAR(512) NOT NULL, /* Meta données du terminal au format JSON */
    PRIMARY KEY(id),
    UNIQUE(cle_publique),
    FOREIGN KEY(id_proprietaire) REFERENCES bttp.utilisateur(id) ON DELETE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=1;

CREATE TABLE bttp.categorie_script (
    id INT AUTO_INCREMENT, /* Identifiant numérique unique de la catégorie */
    nom VARCHAR(64) NOT NULL, /* Nom de la catégorie */
    PRIMARY KEY(id),
    UNIQUE(nom)
) ENGINE=InnoDB AUTO_INCREMENT=1;

CREATE TABLE bttp.format_script (
    id INT AUTO_INCREMENT, /* Identifiant numérique unique du format de script */
    extension VARCHAR(8) NOT NULL, /* Extension de fichier du script */
    PRIMARY KEY(id),
    UNIQUE(extension)
) ENGINE=InnoDB AUTO_INCREMENT=1;

CREATE TABLE bttp.script_publique (
    id INT AUTO_INCREMENT, /* Identifiant numérique unique du script publique */
    nom VARCHAR(64) NOT NULL, /* Nom du script publique */
    version VARCHAR(16) NOT NULL, /* Version du script publique */ /* TODO Externaliser les versions dans un table */
    id_auteur INT, /* Idenitifiant numérique unique de l'utilisateur ayant publié le script */
    publication DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP, /* Date et heure de publication du script */
    verifie BOOLEAN NOT NULL DEFAULT 0, /* Indique si le code source du script a été verifié par un tiers */
    id_categorie INT NOT NULL, /* Identifiant numérique unique de la catégorie à laquelle appartient le script */
    id_format INT NOT NULL, /* Identifiant numérique unique du format du script */
    telechargements INT NOT NULL DEFAULT 0, /* Nombre total de téléchargement du script (ajout dans les scripts privés) */ 
    somme INT NOT NULL, /* Somme de contrôle du code source */
    chemin_code_source VARCHAR(256), /* Chemin du code source sur le serveur */
    PRIMARY KEY(id),
    UNIQUE(nom, id_auteur, id_format), /* Un même utilisateur ne peut pas publier deux scripts ayant le même nom et le même format */
    FOREIGN KEY(id_auteur) REFERENCES bttp.utilisateur(id) ON DELETE SET NULL, /* Les scripts publiques persistent même si leur auteur n'existe plus */
    FOREIGN KEY(id_categorie) REFERENCES bttp.categorie_script(id) ON DELETE CASCADE,
    FOREIGN KEY(id_format) REFERENCES bttp.format_script(id) ON DELETE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=1;

CREATE TABLE bttp.script (
    id INT AUTO_INCREMENT, /* Identifiant numérique unique du script */
    id_hote INT NOT NULL, /* Identifiant numérique du terminal distant hébergeant ce script */
    nom VARCHAR(64) NOT NULL, /* Nom du script */
    ajout DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP, /* Date et heure d'ajout du script */
    somme INT NOT NULL, /* Somme de contrôle du code source hébergé localement */
    id_script_publique INT, /* Identifiant numérique du script publique auquel est lié ce script (peu être nul) */
    PRIMARY KEY(id),
    FOREIGN KEY(id_hote) REFERENCES bttp.terminal_distant(id) ON DELETE CASCADE,
    FOREIGN KEY(id_script_publique) REFERENCES bttp.script_publique(id) ON DELETE SET NULL
) ENGINE=InnoDB AUTO_INCREMENT=1;

COMMIT;