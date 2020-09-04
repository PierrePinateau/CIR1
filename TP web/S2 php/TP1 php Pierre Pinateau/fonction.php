<?php
/* ************************************************ */
/* affichage d'un message de bienvenue avec la date */
/* ************************************************ */
function message() {
echo "<h3>Good Morning and Welcome</h3>" ;
echo "<h4>Today is " ;
echo date("l d F Y") ;
echo "</h4>";
}
/* ************************************************ */
/* Calcul du cout TTC à partir des valeurs HT et TVA */
/* ************************************************ */
function coutTTC ( $prixHT, $TVA ) {
return ( $prixHT * (1+$TVA) ) ;
}
?>
<!DOCTYPE html>
<html>
  <head>
  <title>Exemple</title>
  <meta charset="UTF-8" />
  </head>
  <body>
  <h1>fonction en PHP</h1>
  <?php
  message() ; // appel de la fonction
  ?>
  <p> Prix TTC d’un PC : <?php echo coutTTC(812,0.2) ; ?> euros </p>
  </body>
</html>
