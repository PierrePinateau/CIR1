<!DOCTYPE html>
<html>
  <head>
    <title>Exemple</title>
    <meta charset="UTF-8" />
  </head>
  
    <body>
    <h1>Structures de contrôle</h1>
    <?php
    $t = date("H"); // cette fonction avec ce paramètre renvoie l'heure du serveur
    if ($t < "20")
    { echo "Have a good day !"; }
    else
    { echo "Have a good night !"; }
    ?>
  </body>
</html>
