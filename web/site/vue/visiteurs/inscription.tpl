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

    <link rel="stylesheet" type="text/css" href="../style.css">
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
              <a href="?visiteurs=visiteurs&action=inscription" class="nav-link text-uppercase font-weight-bold">INSCRIPTION</a>
            </li>
          </ul>
        </div>
      </nav>

    <div class="login-form">
        <br><br>
        <form action="?controle=visiteurs&action=inscription" method="POST">
            <h2 class="text-center"> Inscription </h2>

            <div class="form-group">
                <p><input name="Pseudo" type="text" placeholder="Pseudo" class="form-control" autocomplete="off"
                        required></p>
            </div>

            <div class="form-group">
                <p><input name="Mdp" type="password" placeholder="Mdp" class="form-control" autocomplete="off" required>
                </p>
            </div>

            <div class="form-group">
                <input type="submit" class="btn-primary btn-block" value="S'inscrire !">
            </div>

        </form>

    </div>

</body>

</html>