<?php

    function getId() {
        $RACINE = "C:\wamp64\www\PJS4\web\site";
        require $RACINE . '/modele/connectBD.php';

        $sql = "SELECT id FROM `utilisateur` WHERE pseudo=:pseudo";

        $resultat = array();

        try {
            $commande = $pdo->prepare($sql);
            $commande->bindParam(':pseudo', $_SESSION['pseudo']);
            $bool = $commande->execute();
            if($bool) {
                $resultat = $commande->fetchAll(PDO::FETCH_ASSOC)[0];
            }
        } catch(PDOException $e) {
            $msg = utf8_encode("Echec de select : " . $e->getMessage() . "\n");
            die($msg);
        }
        return $resultat['id'];
    }

    function getAppareils(){
        $RACINE = "C:\wamp64\www\PJS4\web\site";
        require $RACINE . '/modele/connectBD.php';

        $id_proprietaire = getId();

        $resultat = array();

        $sql = "SELECT cle_publique, nom, ajout, derniere_connexion, id FROM `terminal_client` WHERE id_proprietaire=:id_proprietaire";
         try {
             $commande = $pdo->prepare($sql);
             $commande->bindParam(':id_proprietaire', $id_proprietaire);
             $bool = $commande->execute();
             if($bool) {
                 $resultat = $commande->fetchAll(PDO::FETCH_ASSOC);
             return $resultat;
            }
         } catch(PDOException $e) {
             $msg = utf8_encode("Echec de select : " . $e->getMessage() . "\n");
             die($msg);
         }
    }

    //TODO : changer le mot de passe d'un utilisateur
    function setMdp($pseudo) {

    }

    function nb_apapreils($id_proprietaire) {
        $RACINE = "C:\wamp64\www\PJS4\web\site";
        require $RACINE . '/modele/connectBD.php';

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
