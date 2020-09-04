<!DOCTYPE html>
<html>
  <head>
    <title>Exemple boucle for</title>
    <meta charset="UTF-8" />
  </head>
  <body>
    <h1>Structures de contrôle</h1>
    <?php
    echo "<h2>Table de multiplication de 7 : </h2>";
    for ($cpt = 1 ; $cpt <= 100 ; $cpt++ )
    {
    echo "<ul>7 x " . $cpt . " = " . ($cpt * 7) ;
    echo "</ul><br/>";
    }
    ?>
  </body>
</html>
