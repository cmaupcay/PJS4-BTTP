<?php
ob_start();

$RACINE = "C:\wamp64\www\PJS4\web\site";

if (isset($_GET["file"])) {
    $file = $_GET["file"];

    // Test whether the file name contains illegal characters

    if (preg_match('/^[^.][-a-z0-9_.]+[a-z]$/i', $file)) {
        $filepath = $RACINE . "/" .  $file;

        // Process download
        if(file_exists($filepath)) {
        $ostream = fopen($filepath, 'r');
        do{
            $toRead = fgets($ostream);
            if($toRead != false){
                echo $toRead . '<br>';
            }
        }while($toRead != false);
        
        die();
        } else {
            http_response_code(404);
           die();
        }
    } else {
        die("Download cannot be processed");
    }
}
