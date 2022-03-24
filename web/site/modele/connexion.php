<?php

function verif_utilisateur($pseudo, $mdp, &$resultat = array())
{
    require('connectBD.php');

    $sql = 'SELECT * FROM `bttp.utilisateur` WHERE `pseudo`=:pseudo AND `mdp`=:mdp';

    $mdp = hash('sha256', $mdp);
    
    try {
        $commande = $pdo->prepare($sql);
        $commande->bindParam(":pseudo", $pseudo);
        $commande->bindParam(":mdp", $mdp);
        $bool = $commande->execute();
        if ($bool)
            $resultat = $commande->fetchAll(PDO::FETCH_ASSOC);
            echo(count($resultat) . "\n");
        return (count($resultat) > 0);
    } catch (PDOException $e) {
        echo utf8_encode("Echec de select : " . $e->getMessage() . "\n");
        die();
    }
}

function inserer_cookie_bd($tokan, $date, $id)
{
}
