<?php
ob_start();

$RACINE = "C:\wamp64\www\PJS4\web\site";

if (isset($_GET["file"])) {
    $file = $_GET["file"];

    // Test whether the file name contains illegal characters

    if (preg_match('/^[^.][-a-z0-9_.]+[a-z]$/i', $file)) {
        $filepath = $RACINE . "/" .  $file;

        // Process download
        if (file_exists($filepath)) {
            $ostream = fopen($filepath, 'r');
            echo '<div class="container py-5 bg-light">';
            echo '<div class="row">';
            echo ('<div class="col-md-4 col-sm-4">');
            echo ('<div class="card mb-4 shadow-sm">');
            echo ('<div class="card-body">');
            echo '<p class="card-text">';
            do {
                $toRead = fgets($ostream);
                if ($toRead != false) {

                    echo (' Code source : <br>' . $toRead . '</p>');
                }
            } while ($toRead != false);
            echo '</p>';
            echo '</div>';
            echo '</div>';
            echo '</div>';
            echo '</div>';
            echo '</div>';
        } else {
            http_response_code(404);
            die();
        }
    } else {
        die("Download cannot be processed");
    }
}
