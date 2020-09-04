<?php
@setlocale(LC_TIME, 'fr_FR');
echo "<p> Au moment de l'exécution de ce script PHP, nous sommes le ".strftime('%A %d %B %Y et %Hh%Mm et %Ss').".</p>";
if (strftime("%H")>7 and strftime("%H")<12) {
  echo "Bonne matinée";
}
if (strftime("%H")>12 and strftime("%H")<20) {
  echo "Bonne aprèm";
}
if (strftime("%H")>20) {
  echo "Bonne soirée";
}

echo "<p>La fonction date() permet d'obtenir l'heure locale du serveur. La fonction strftime permet d'afficher une date selon un format donné</p>";

function laDateDuJour() {
  if (strftime("%H")>7 and strftime("%H")<12) {
    echo "Bonne matinée depuis la function laDateDuJour()";
  }
  if (strftime("%H")>12 and strftime("%H")<20) {
    echo "Bonne aprèm depuis la function laDateDuJour()";
  }
  if (strftime("%H")>20 and strftime("%H")<24) {
    echo "Bonne soirée depuis la function laDateDuJour()";
  }
  if (strftime("%H")>0 and strftime("%H")<7) {
    echo "Bonne soirée depuis la function laDateDuJour()";
  }
}
?>

<!DOCTYPE html>
<html lang="fr" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title></title>
  </head>
  <body>
    <br><br><br><br>
    <p>
      <?php
      laDateDuJour()
      ?>
    </p>
  </body>
</html>
