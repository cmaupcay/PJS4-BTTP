<?php



/**
 * Vérifie s'il n'y a pas déjà un utilisateur avec le même pseudo
 */
function verif_inscription($pseudo)
{
    $RACINE = "C:\wamp64\www\PJS4\web\site";
    require $RACINE . '/modele/connectBD.php';

    $sql = "SELECT id FROM `utilisateur` WHERE pseudo=:pseudo";

    try {

        $commande = $pdo->prepare($sql);
        $commande->bindParam(':pseudo', $pseudo);
        $bool = $commande->execute();

        if ($bool)

            $resultat = $commande->fetchAll(PDO::FETCH_ASSOC);

        return (count($resultat) > 0);
    } catch (PDOException $e) {
        echo utf8_encode("Echec de select : " . $e->getMessage() . "\n");
        die();
    }
}

/**
 * insert dans la bd le nouvel utilisateur
 */
function insertion_bd($pseudo, $mdp)
{
    $RACINE = "C:\wamp64\www\PJS4\web\site";
    require $RACINE . '/modele/connectBD.php';

    $sql = "INSERT INTO `utilisateur` (pseudo, mdp) VALUES (:pseudo, :mdp)";

    $mdp = hash('sha256', $mdp);

    try {
        $commande = $pdo->prepare($sql);

        //id utilisateur auto incrémenté ?
        $commande->bindParam(":pseudo", $pseudo);
        $commande->bindParam(":mdp", $mdp);

        return $commande->execute();
    } catch (PDOException $e) {
        echo utf8_encode("Echec d'insertion : " . $e->getMessage() . "\n");
        die();
    }
}
