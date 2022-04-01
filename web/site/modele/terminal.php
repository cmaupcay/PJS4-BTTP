<?php


function supprimer_terminal($idTerminal)
{
    $RACINE = ".";
    require $RACINE . '/modele/connectBD.php';

    $sql = "DELETE FROM `terminal` WHERE id=:idTerminal";

    try {
        $commande = $pdo->prepare($sql);
        $commande->bindParam(':idTerminal', $idTerminal);
        $bool = $commande->execute();
        if ($bool)
            echo 'ça marche chacaaaal';
    } catch (PDOException $e) {
        $msg = utf8_encode('Echec de delete : ' . $e->getMessage() . "\n");
        die($msg);
    }
}
