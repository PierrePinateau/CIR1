<!DOCTYPE html>
<html>
  <head>
    <title>Exemple</title>
    <meta charset="UTF-8" />
  </head>
  
  <body>
    <h1>Voici ma premi&egrave;re page PHP</h1>
    <?php
    // je suis un commentaire sur une seule ligne
    echo "<h3>Bonjour les <b>CIR1</b> !</h3>" ;
    echo "<p>une premi&egrave;re page avec du PHP.</p>" ;
    ?>
    <p>Cette page est une page dynamique avec l'extension .php</p>
    <?php
    $nombre = 3 ;
    echo "<p>Je suis encore du texte</p>";
    /* je suis un commentaire sur plusieurs lignes afin d'expliquer longuement ce que fait la suite pour
    me permettre de comprendre dans 10 ans ce que j'avais fait !
    le nombre 10 ci-dessous est commenté lui aussi */
    echo $nombre + /* 10 */ 100 ;
    ?>
  </body>
</html>
