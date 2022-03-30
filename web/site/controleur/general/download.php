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
            header('Content-Description: File Transfer');
            header('Content-Type: application/octet-stream');
            header('Content-Disposition: attachment; filename="' . basename($filepath) . '"');
            header('Expires: 0');
            header('Cache-Control: must-revalidate');
            header('Pragma: public');
            header('Content-Length: ' . filesize($filepath));
            // Flush system output buffer

            flush();
            readfile($filepath);
            die();
        } else {
            http_response_code(404);
            die();
        }
    } else {
        die("Download cannot be processed");
    }
}
