<!DOCTYPE html>

<html>

<head>
    <meta charset="utf-8">
    <link rel="stylesheet" type="text/css"
        href="https://cdnjs.cloudflare.com/ajax/libs/twitter-bootstrap/4.3.1/css/bootstrap.min.css">
    <link rel="stylesheet" type="text/css"
        href="https://stackpath.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/twitter-bootstrap/4.3.1/js/bootstrap.bundle.min.js"></script>
    <link href="https://cdnjs.cloudflare.com/ajax/libs/magnific-popup.js/1.1.0/magnific-popup.min.css"
        rel="stylesheet" />
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css">
    <title>Inscription</title>

    <link rel="stylesheet" type="text/css" href="./style.css">

</head>

<body>

<div class="container-fluid banner" style="background-color:#003459">
    <div><a href="?controle=visiteurs&action=accueil" class="nav-link text-uppercase font-weight-bold"><img alt="Brand" src="./vue/logo.png" style="width:140px"></a></div>

    <div class="login-form">
        <br><br>

        <form action="?controle=visiteurs&action=inscription" method="POST">
            <h2 class="text-center" style="color:#00171F"> Inscription </h2>

            <div class="form-group">
                <p><input name="pseudoInscription" type="text" placeholder="Pseudo" class="form-control" autocomplete="off"
                        required></p>
            </div>

            <div class="form-group">
                <p><input name="mdpInscription" type="password" placeholder="Mot de passe" class="form-control" autocomplete="off" required>
                </p>
            </div>
            <div class="form-group">
                <p><input name="mdp2Inscription" type="password" placeholder="Retapez votre mot de passe" class="form-control" autocomplete="off" required>
                </p>
            </div>
            
            <div class="form-group">
            <input type="submit" value="S'inscrire" class="btn btn-primary btn-block" style="background-color:#00A8E8">
            </div>

        </form>

        <p style="font-size:smaller; text-align:center; color:#f7f7f7">Vous possédez déjà un compte ? <a href="?controle=visiteurs&action=connexion" style="color:#00A8E8"> Connectez-vous </a>

    </div>

</div>

</body>

</html>