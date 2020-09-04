<!DOCTYPE html>
<html>
  <head>
    <title>Exemple</title>
    <meta charset="UTF-8" />
  </head>
  <body>
    <h1>Les tableaux multidimensionnels</h1>
    <?php
    // on peut imaginer un tableau à deux entrées
    // la première colonne contient une liste d'article
    // la deuxième colonne contient le prix unitaire
    // la troisième colonne contient le stock
    // chaque ligne est un article
    $article = array(
    array("biscuits",2.30,710),
    array("chocolat",1.90,250),
    array("noisettes",2.70,251),
    array("sucre",2.0,370),
    array("oeufs",0.24,100),
    array("farine",0.95,150),
    );
    // affichage ci-dessous (un peu brutal !!!)
    // il est préférable d'utiliser des boucles imbriquées et de faire une présentation en table
    echo $article[0][0] . ": PU: " . $article[0][1] . "€, stock: ".$article[0][2]. "<br/>";
    echo $article[1][0] . ": PU: " . $article[1][1] . "€, stock: ".$article[1][2]. "<br/>";
    echo $article[2][0] . ": PU: " . $article[2][1] . "€, stock: ".$article[2][2]. "<br/>";
    echo $article[3][0] . ": PU: " . $article[3][1] . "€, stock: ".$article[3][2]. "<br/>";
    echo $article[4][0] . ": PU: " . $article[4][1] . "€, stock: ".$article[4][2]. "<br/>";
    echo $article[5][0] . ": PU: " . $article[5][1] . "€, stock: ".$article[5][2]. "<br/>";
    // ci-dessous l’affichage conseillé
    echo "<table border='1' cellpadding='5'>" ;
    for ($ligne=0 ; $ligne < count($article) ; $ligne++)
    {
    echo "<tr>";
    for ($colonne=0 ; $colonne < count($article[$ligne])/*3*/ ; $colonne++)
    {
    echo "<td>" ;
    echo $article[$ligne][$colonne] ;
    echo "</td>" ;
    }
    echo "</tr>";
    }
    echo "</table>";
    ?>
  </body>
</html>
