<?php
    

    function scripts_publiques(&$resultat){

        require('connectBD.php');

        $sql = " SELECT nom, publication, `version` FROM `script_publique`";

        $resultat = array();

        try {

            $commande = $pdo->prepare($sql);
            $bool = $commande->execute();
            if($bool)
                $resultat = $commande->fetchAll(PDO::FETCH_ASSOC);

        } catch(PDOException $e) {

            $msg = utf8_encode("Echec de select : " . $e->getMessage() . "\n");
            die($msg);
        }
    }

    //TODO : afficher le code source d'un script sur lequel on a cliqué
    function code_source() {

    }


?>
