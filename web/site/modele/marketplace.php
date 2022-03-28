<?php

    function scripts_publiques(&$resultat = array()){
        $RACINE = "C:\wamp64\www\PJS4\web\site";
        require $RACINE . '/modele/connectBD.php';

        $sql = " SELECT nom, publication, `version`, chemin_code_source FROM `script_publique`";
        try {

            $commande = $pdo->prepare($sql);
            $bool = $commande->execute();
            if($bool)
                $resultat = $commande->fetchAll(PDO::FETCH_ASSOC);
            return $resultat;
        } catch(PDOException $e) {

            $msg = utf8_encode("Echec de select : " . $e->getMessage() . "\n");
            die($msg);
        }
    }

    //TODO : afficher le code source d'un script sur lequel on a cliqué
    function code_source() {

    }
