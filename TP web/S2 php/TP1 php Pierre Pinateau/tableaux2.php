<!DOCTYPE html>
<html>
  <head>
    <title>Exemple</title>
    <meta charset="UTF-8" />
  </head>
  <body>
    <h1>Les tableaux associatifs</h1>
    <?php
    // ***************************************************
    // 1ère méthode de déclaration d'un tableau associatif
    // ***************************************************
    $point = array("Dad"=>"305", "Sam"=>"1437", "Gilou"=>"1209");
    // *****************************************************************************
    // 2ème méthode de déclaration d'un tableau associatif équivalente à la première
    // *****************************************************************************
    $point["Dad"] = "305" ;
    $point["Sam"] = "1437" ;
    $point["Gilou"] = "1209";
    // **********************************************
    // affichage du contenu du tableau associatif
    // **********************************************
    foreach ( $point as $indice => $valeur )
    {
    echo "clé : " . $indice . " , contenu = ". $valeur ;
    echo "<br/>";
    }
    ?>
  </body>
</html>
