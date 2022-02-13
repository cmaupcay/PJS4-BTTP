DELIMITER $$

/* Incrément le nombre de téléchargement d'un script publique lorsqu'un nouveau script privé est créé à partir de celui ci */
CREATE OR REPLACE TRIGGER bttp.T_telechargement_script
AFTER INSERT ON bttp.script
FOR EACH ROW
BEGIN
    IF NEW.id_script_publique IS NOT NULL
    THEN
        UPDATE bttp.script_publique SET telechargements = telechargements + 1
        WHERE id = NEW.id_script_publique;
    END IF;
END$$

DELIMITER ;

COMMIT;