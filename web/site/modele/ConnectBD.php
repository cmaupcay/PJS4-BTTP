<?php

    $hostname="localhost";
    $base="pjs4";
    $loginBD="root";
    $passBD = "root";

    try {
        $pdo = new PDO("mysql:server=$hostname; dbname=$base", "$loginBD", "$passBD");
    } catch(PDOException $e) {
        die("Echec de connexion : " . utf8_encode($e->getMessage()) . "\n");
    }
