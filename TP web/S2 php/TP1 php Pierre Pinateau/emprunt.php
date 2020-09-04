<!DOCTYPE html>
<html>
  <head>
    <title>Exemple</title>
    <meta charset="UTF-8" />
  </head>
  <body>
    <h1>Quelques affichages de variables</h1>
    
    <?php
    // chaine de caractères
    $txt = "les CIR1" ;
    echo "Bienvenue " . $txt ."!" ;
    ?>
    <div align='center'><img src="pics/emprunt.jpg" /></div>
    <?php
    // calcul
    echo "<h1>Pret</h1>";
    $capital = 200000.0 ;
    $taux = 1.9 / 100 ;
    $duree = 240 ;
    $mensualite = $capital * ($taux/12) / ( 1 - pow(1+($taux/12),-$duree)) ;
    echo "Pour un capital de " . $capital . " euros<br/>";
    echo "emprunté sur une durée de " . $duree . " mois<br/>";
    echo "à un taux de " . (100 * $taux) . " %<br/>";
    echo "vous payerez une mensualité de " . round($mensualite,2) . " euros<br/>";
    $cout = $duree * $mensualite - $capital ;
    echo "le coût de votre prêt s'élève à " . round($cout,2) . " euros<br/>";
    ?>
  </body>
</html>
