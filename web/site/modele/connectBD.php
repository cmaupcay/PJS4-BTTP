<?php

    $hostname="localhost";
    $base="bttp";
    $loginBD="root";
    $passBD = "JFBrette2022KFLeS";

    try {
        $pdo = new PDO("mysql:server=$hostname; dbname=$base", "$loginBD", "$passBD");
    } catch(PDOException $e) {
        die("Echec de connexion : " . utf8_encode($e->getMessage()) . "\n");
    }
