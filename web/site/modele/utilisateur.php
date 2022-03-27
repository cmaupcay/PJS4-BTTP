<?php


    //TODO : récupère le pseudo de la personne connectée
    function getPseudo() {
        
        $pseudo = isset($_POST['pseudo'])?($_POST['pseudo']):'';

        return $pseudo;
    }

    //renvoie la liste des appareils d'un utilisateur à partir de son id 
    //TOTEST
    function getAppareils($id_proprietaire, &$resultat) {

        require 'connectBD.php';

        $sql = "SELECT * FROM `terminal_client` WHERE id_proprietaire=:id_propritaire";

        try {
            $commande = $pdo->prepare($sql);
            $commande->bindParam(":id_proprietaire", $id_proprietaire);
            $bool = $commande->execute();

            if($bool)
                $resultat = $commande->fetchAll(PDO::FETCH_ASSOC);
        } catch(PDOException $e) {
            $msg = "Echec de select : " . $e->getMessage() . "\n";
            die($msg);
        }
    }

    //TODO : changer le mot de passe d'un utilisateur
    function setMdp($pseudo) {

    }

    //TOTEST
    function nb_apapreils($id_proprietaire) {

        require 'connectBD.php';

        $sql = "SELECT COUNT(*) FROM `terminal_client` WHERE id_proprietaire=:id_proprietaire";

        try {
            $commande = $pdo->prepare($sql);
            $commande->bindParam(":id_proprietaire", $id_proprietaire);
            $bool = $commande->execute();

            if($bool) 
                return $bool;
        } catch(PDOException $e) {
            $msg = "Ecehc de select : " . $e->getMessage() . "\n";
            die($msg);
        }
    }
?>