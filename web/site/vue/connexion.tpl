<!doctype html>
<html lang="fr">

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
    <title>Connexion</title>
    <link rel="stylesheet" type="text/css" href="style.css">
</head>

<body>   
    
    <div><a href="?controle=visiteurs&action=accueil" class="nav-link text-uppercase font-weight-bold"> BTTP </a></div>

    <div class="login-form">
        <br><br>


            <!-- lorsqu'on envoie le formulaire on va vouloir traiter ces données, donc on va san doute vouloir faire une fonction js pour les traiter on submit
            du coup il faut pas oublier de changer ca-->

            <form action="?controle=abonnes&action=accueil" method="post">

                <h2 class="text-center"> Connexion </h2>
                <div class="form-group">
                    <p><input name="pseudo" type="text" class="form-control" placeholder="Email" autocomplete="off"
                            required><br /></p>
                </div>
                <div class="form-group">
                    <p><input name="mdp" type="password" class="form-control" placeholder="Mot de passe"
                            autocomplete="off" required><br /></p>
                </div>
                <div class="form-group">
                    <input type="submit" value="Se connecter" class="btn btn-primary btn-block">
                </div>
            </form>

            <a href="?controle=visiteurs&action=inscription"> Inscrivez-vous </a>
    </div>


</body>

</html>