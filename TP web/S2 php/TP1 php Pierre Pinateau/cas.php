<!DOCTYPE html>
<html>
  <head>
    <title>Exemple</title>
    <meta charset="UTF-8" />
  </head>

  <body>
    <h1>La casse en PHP</h1>
    <?php
    /* ici pas de problème sur la casse */
    ECHO "<h1>Bonjour les CIR1</h1>";
    EchO "<h1>Bonjour les CIR1</h1>";
    eCHO "<h1>Bonjour les CIR1</h1>";
    /* ici, sur les variables, ATTENTION à la casse ! */
    $maCouleur = "Rouge" ;
    echo "sa voiture est " . $maCouleur . "<br/>" ; /* syntaxe OK */
    echo "sa maison est " . $MACOULEUR . "<br/>" ; /* erreur */
    echo "son avion est " . $macouleur . "<br/>" ; /* erreur */
    echo "sa moto est " . $MaCouleur . "<br/>" ; /* erreur */
    ?>
  </body>
</html>
