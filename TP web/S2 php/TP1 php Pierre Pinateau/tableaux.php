<!DOCTYPE html>
<html>
  <head>
    <title>Exemple</title>
    <meta charset="UTF-8" />
  </head>
  <body>
  <h1>Les tableaux indéxés</h1>
    <?php
    // ***************************************************************
    // Attribution automatique de l'index dans la déclaration suivante
    // Automatiquement le premier élément du tableau a pour index 0
    // ***************************************************************
    $motos = array("Harley","Yamaha","Honda","Kawazaki") ;
    // *************************************************************
    // Attribution manuelle de l'index dans la déclaration suivante :
    // ***************************************************************
    $voitures[0] = "Aston martin" ;
    $voitures[1] = "Bugatti";
    $voitures[2] = "Rolls Royce";
    // **********************************************
    // affichage du contenu du tableau moto
    // la fonction count renvoie la taille du tableau
    // **********************************************
    $taille = count($motos);
    for($x = 0; $x < $taille; $x++)
    {
    echo $motos[$x];
    echo "<br/>";
    }

    $voiture = array("Aston martin","Bugatti","Rolls Royce","Dogde charger") ;
    $taille = count($voiture);
    for($x = 0; $x < $taille; $x++)
     {
     echo $voiture[$x];
     echo "<br/>";
     }
    ?>
  </body>
</html>
