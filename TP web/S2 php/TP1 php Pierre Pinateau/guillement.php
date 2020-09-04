<!DOCTYPE html>
<html>
  <head>
    <title>Exemple</title>
    <meta charset="UTF-8" />
  </head>

  <body>
    <h1>Différence entre simple et double quotes</h1>
    <?php
    $nom1 = "HARLEY";
    $nom2 = 'DAVIDSON';
    echo "<h1>Utilisation des guillemets</h1>";
    echo "$nom1 $nom2" ;
    echo "<h1>Utilisation des apostrophes</h1>";
    echo '$nom1 $nom2' ;
    ?>
  </body>
</html>
