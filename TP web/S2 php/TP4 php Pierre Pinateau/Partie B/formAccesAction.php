<?php
 // Démarre une nouvelle session ou reprend une session existante
  session_start();
  // recuperation des valeurs du formulaire
  $login = $_POST["login"] ;
   $mdp = $_POST["mdp"]  ;
   if ($login == "cir1" && $mdp == "isen" )
    // authentification réussie
     {
       echo "isok tu es connect";
    // création des variables de sessions + auth et nom avec les "bonnes valeurs"
    $_SESSION["auth"] = 1 ; $_SESSION["nom"] = "isen" ; }
     else // echec à l'authentification
      {
        echo "Nan faux mdp/login";
        // création des variables de sessions - auth et nom avec les "mauvaises valeurs"
         $_SESSION["auth"] = 0 ; $_SESSION["nom"] = "inconnu" ; }
          ?>
