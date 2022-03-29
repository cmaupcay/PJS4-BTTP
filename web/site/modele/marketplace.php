<?php
    

    function scripts_publiques(&$resultat = array()){

        $RACINE = "C:/xampp/htdocs/pjs4/site";
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

        ob_start();

        $RACINE = "C:/xampp/htdocs/pjs4/site";

        if (isset($_GET["file"])) {
            $file = $_GET["file"];
        
            // Test whether the file name contains illegal characters
        
            if (preg_match('/^[^.][-a-z0-9_.]+[a-z]$/i', $file)) {
                $filepath = $RACINE . "/" .  $file;
        
                // Process download
                if(file_exists($filepath)) {
                    $ostream = fopen($filepath, 'r');
                    do{
                        $toRead = fgets($ostream);
                        if($toRead != false){
                            echo $toRead . '<br>';
                        }
                    }while($toRead != false);
                    
                    die();
                } else {
                    http_response_code(404);
                die();
                }
            } else {
                die("Download cannot be processed");
            }
        }
        

       
    }

    //fonction de recherche de script (pas encore fonctionnelle)
    function recherche_scripts($recherche) {

        $RACINE = "C:/xampp/htdocs/pjs4/site";
        require $RACINE . '/modele/connectBD.php';

        $sql = "SELECT nom FROM `scripts_publiques` WHERE nom=:nom";

        $resultat = array();

        try {
            $commande = $pdo->prepare($sql);
            $commande->bindParam(":nom", $recherche);
            $bool = $commande->execute();
            if($bool)
                $resultat = $commande->fetchAll(PDO::FETCH_ASSOC);
            return $resultat;
        } catch(PDOException $e) {
            $msg = utf8_encode('Echec de select : ' . $e->getMessage() . "\n");
            die($msg);
        }
    }
