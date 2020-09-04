<!DOCTYPE html>
<html lang="fr" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title></title>
  </head>
  <body>
    <?php
  $link = mysqli_connect("localhost", "root", "" , "tp4") ;
    if ($link == false)
    {
      echo "Erreur de connexion : " . mysqli_connect_errno() ;
      die();
    }
    else
    {
      echo "<p>connexion r&eacute;ussie</p>" ;
  }
  ?>
  </body>
</html>
