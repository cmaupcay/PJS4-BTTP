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
    <title>identification</title>
    <link rel="stylesheet" type="text/css" href="./style.css">
</head>

<body>
    
    <nav class="navbar navbar-expand-lg navbar-light" style="background-color: rgb(141, 202, 243)">

        <div class="collapse navbar-collapse" id="navbarNav">
          <ul class="navbar-nav">
            <li class="nav-item active">
              <a href="?controle=visiteurs&action=accueil" class="nav-link text-uppercase font-weight-bold" >ACCUEIL <span class="sr-only">(current)</span></a>
            </li>
            <li class="nav-item">
              <a href="?controle=visiteurs&action=connexion" class="nav-link text-uppercase font-weight-bold">CONNEXION</a>
            </li>
            <li class="nav-item">
              <a href="?visiterus=visiteurs&action=inscription" class="nav-link text-uppercase font-weight-bold">INSCRIPTION</a>
            </li>
          </ul>
        </div>

      </nav>
    
    <!--
        <nav class="navbar navbar-light" style="background-color: #47acf5;">
            <div class="container">                    <button type="button" data-toggle="collapse" data-target="#navbarSupportedContent"
                          aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation"
                          class="navbar-toggler navbar-toggler-right"><i class="fa fa-bars"></i></button>

                        <div id="navbarSupportedContent" class="collapse navbar-collapse">
                        <ul class="navbar-nav ml-auto">
                            <li class="nav-item active"><a href="?controle=visiteurs&action=accueil"
                                    class="nav-link text-uppercase font-weight-bold">ACCUEIL</a></li>
                            <li class="nav-item"><a href="?controle=visiteurs&action=connexion"
                                    class="nav-link text-uppercase font-weight-bold">CONNEXION</a></li>
                            <li class="nav-item"><a href="?controle=visiteurs&action=inscription"
                                    class="nav-link text-uppercase font-weight-bold">INSCRIPTION</a></li>
                        </ul>
                         </div>
                      </div>                
                </nav>
        -->






    <div class="login-form">
        <br><br>

        <form action="?controle=abonnes&action=accueil" method="post">

            <!-- lorsqu'on envoie le formulaire on va vouloir traiter ces données, donc on va san doute vouloir faire une fonction js pour les traiter on submit
            du coup il faut pas oublier de changer ca-->

            <form action="?controle=abonnes&action=accueil" method="post">

                <h2 class="text-center"> Connexion </h2>
                <div class="form-group">
                    <p><input name="email" type="text" class="form-control" placeholder="Email" autocomplete="off"
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
    </div>


</body>

</html>