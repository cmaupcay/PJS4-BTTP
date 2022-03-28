<?php


    function supprimer_terminal($idTerminal) {

        require 'connectBD';

        $sql = "DELETE FROM `terminal_client` WHERE id=:idTerminal";
        
        try {
            $commande = $pdo->prepare($sql);
            $commande->bindParam(':idTerminal', $idTerminal);
            $bool = $commande->execute();
            if($bool)
                echo 'ça marche chacaaaal';
        }catch(PDOException $e) {
            $msg = utf8_encode('Echec de delete : ' . $e->getMessage() . "\n");
            die($msg);
        }
    }
?>