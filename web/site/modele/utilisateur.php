<?php


    //TODO
    function getNom($pseudo) {
        
    }

    //renvoie la liste des appareils d'un utilisateur à partir de son id 
    //TOTEST
    function getAppareils($id_proprietaire, &$resultat) {

        require 'connectBD.php';

        $sql = "SELECT * FROM `terminal_client` WHERE id_proprietaire=:id_propritaire";

        try {
            $commande = $pdo->prepare($sql);
            $commande->bindParam(":id_proprietaire", $id_prorprietaire);
            $bool = $commande->execute();

            if($bool)
                $resultat = $scommande->fetchAll(PDO::FETCH_ASSOC);
        } catch(PDOException $e) {
            $msg = "Echec de select : " . $e->getMessage() . "\n";
            die($msg);
        }
    }

    

?>