DROP TABLE Utilisateur CASCADE CONSTRAINT purge;
DROP TABLE TerminalClient CASCADE CONSTRAINT purge;
DROP TABLE TerminalDistant CASCADE CONSTRAINT purge;
DROP TABLE Script CASCADE CONSTRAINT purge;
DROP TABLE ScriptMarketPlace CASCADE CONSTRAINT purge;
DROP TABLE Categorie CASCADE CONSTRAINT purge;
DROP TABLE FormatScript CASCADE CONSTRAINT purge;

CREATE TABLE Utilisateur (
    idUtilisateur integer,
    pseudo varchar(20),
    mdp varchar(30)
);

CREATE TABLE TerminalClient (
    CléPubliqueTerminalC varchar(200),
    NomTerminalC varchar(20),
    favori number(1),
    OS varchar(15),
    DateAjout Date,
    idutilisateur integer
);

CREATE TABLE TerminalDistant (
    CléPubliqueTerminalD varchar(200),
    NomTerminalD varchar(20),
    favori number(1),
    OS varchar(15),
    DateAjout Date,
    Disponible number(1),
    idutilisateur integer
);

CREATE TABLE Script(
    idScript integer,
    NomScript varchar(30),
    CheckSum integer,
    Version number,
    CléPubliqueTerminalD integer CONSTRAINT fk_Script FOREIGN KEY REFERENCES TerminalDistant(CléPubliqueTerminalD)
);

CREATE TABLE ScriptMarketPlace (
    idScriptMP integer,
    NomScript varchar(30),
    Checksum integer,
    Version number,
    CodeSourceScript varchar(30), -- à réfléchir
    Vérifié number(1),
    NbTéléchargements number,
    DatePublication Date;
    NomCategorie varchar(30),
    NomFormat varchar(30);
    idScript integer; --à redéfinir, mauvaise conception
);

CREATE TABLE Categorie(
    NomCategorie varchar(30);
);

CREATE TABLE FormatScript(
    NomFormat varchar(30),
    Extension varchar(3);
);

-- CONTRAINTES PRIMARY ET FOREIGN KEY
ALTER TABLE Utilisateur ADD CONSTRAINT PK_UTILISATEUR PRIMARY KEY idUtilisateur;

ALTER TABLE TerminalClient ADD CONSTRAINT PK_TerminalClient PRIMARY KEY (CléPubliqueTerminalC, idUtilisateur);
ALTER TABLE TerminalClient ADD CONSTRAINT FK_TerminalClient FOREIGN KEY idUtilisateur REFERENCES Utilisateur(idUtilisateur);

ALTER TABLE TerminalDistant ADD CONSTRAINT PK_TerminalClient PRIMARY KEY (CléPubliqueTerminalD, idUtilisateur);
ALTER TABLE TerminalDistant ADD CONSTRAINT FK_TerminalClient FOREIGN KEY idUtilisateur REFERENCES Utilisateur(idUtilisateur);

ALTER TABLE Script ADD CONSTRAINT PK_SCRIPT PRIMARY KEY (idScript, CléPubliqueTerminalD);
ALTER TABLE Script ADD CONSTRAINT FK_Script FOREIGN KEY CléPubliqueTerminalD REFERENCES Utilisateur(CléPubliqueTerminalD);


ALTER TABLE ScriptMarketPlace ADD CONSTRAINT PK_ScriptMP PRIMARY KEY idScript;
ALTER TABLE ScriptMarketPlace ADD CONSTRAINT FK_Categorie FOREIGN KEY NomCategorie REFERENCES Categorie(NomCategorie);
ALTER TABLE ScriptMarketPlace ADD CONSTRAINT FK_Format FOREIGN KEY NomFormat REFERENCES FormatScript(NomFormat);
ALTER TABLE ScirptMarketPlace ADD CONSTRAINT FK_Script FOREIGN KEY idScirpt REFERENCES Script(idScirpt);

ALTER TABLE Categorie ADD CONSTRAINT PK_Categorie PRIMARY KEY NomCategorie;

ALTER TABLE FormatScript ADD CONSTRAINT PK_FormatScript PRIMARY KEY NomFormat;

-- CONTRAINTES UNIQUES et NOT NULL

ALTER TABLE FormatScript ADD CONSTRAINT Extension U_Extension UNIQUE(Extension);
ALTER TABLE FormatScript MODIFY(Extension NOT NULL);


-- CONTRAINTES CHECK


-- TRIGGERS
-- Trigger qui vérifie que l'utilisateur qu'on associe à un terminal existe bien

CREATE OR REPLACE TRIGGER TerminalD_idU
BEFORE INSERT ON TerminalDistant
DECLARE
int var;
BEGIN
SELECT idUtilisateur into var FROM utilisateur WHERE idUtilisateur = :NEW.idUtilisateur;
IF NO_DATA_FOUND THEN 
RAISE_APPLICATION_ERROR(-2001, 'Utilisateur inexistant');
ELSE
NULL;
END IF;
END;
/

CREATE OR REPLACE TRIGGER TerminalC_idU
BEFORE INSERT ON TerminalClient
DECLARE
int var;
BEGIN
SELECT idUtilisateur into var FROM utilisateur WHERE idUtilisateur = :NEW.idUtilisateur;
IF NO_DATA_FOUND THEN 
RAISE_APPLICATION_ERROR(-2001, 'Utilisateur inexistant');
ELSE
NULL;
END IF;
END;
/




-- INSERTION DANS LES TABLES

INSERT INTO Utilisateur(idUtilisateur, pseudo, mdp) VALUES(1, 'sara', 'okok');

INSERT INTO TerminalClient(CléPubliqueTerminalC,NomTerminalC, favori, OS, DateAjout, idutilisateur) VALUES ('maclepublique', 'terminalSara', 0, 'macOS', TO_DATE('01/01/2022', 'DD/MM/YYYY'), 1);
INSERT INTO TerminalClient(CléPubliqueTerminalC,NomTerminalC, favori, OS, DateAjout, idutilisateur) VALUES ('maclepublique', 'terminalSara', 0, 'macOS', TO_DATE('01/01/2022', 'DD/MM/YYYY'), 2);

INSERT INTO TerminalDistant(CléPubliqueTerminalD ,NomTerminalD, favori, OS, DateAjout, Disponible, idutilisateur) VALUES ('clepubliquetermd', 'terminalDistant', 1, 'Windows11', TO_DATE('02/03/2021', 'DD/MM/YYYY'), 0, 1);


-- AFFICHAGE DES TABLES

SELECT * FROM Utilisateur;
SELECT * FROM TerminalClient;
SELECT * FROM TerminalDistant;