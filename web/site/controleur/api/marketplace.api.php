
<?php
function marketplace_json(&$resultat = array())
{
    header("Content-type: application/json;");

    $RACINE = "C:/xampp/htdocs/pjs4/site";
    require $RACINE . '/modele/connectBD.php';

    $sql = " SELECT nom, publication, `version`, chemin_code_source FROM `script_publique`";
    try {

        $commande = $pdo->prepare($sql);
        $bool = $commande->execute();
        if ($bool)
            $resultat = $commande->fetchAll(PDO::FETCH_ASSOC);
        echo json_encode($resultat);
    } catch (PDOException $e) {

        $msg = utf8_encode("Echec de select : " . $e->getMessage() . "\n");
        die($msg);
    }
}
?>