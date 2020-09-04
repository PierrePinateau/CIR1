<html>
<body>
<?php
/* ************************************************** */
/* Connexion à la base de données */
/* ************************************************** */
      include 'connexion.php';

/* ************************************************** */
/* Envoi d'une requete au serveur */
/* ************************************************** */
$requete = "select id as I, prenom as P from realisateur" ;
$result = mysqli_query($link,$requete);
if ( $result == FALSE )
{
echo "Erreur d'exécution de la requete" ;
die();
}
?>
<form method="POST" action="suites.php">
<select name="ID">
<?php
/* ************************************************** */
/* Extraction des résultats de la requete */
/* ajout des lignes <option> de la balise <select> */
/* la liste déroulante doit afficher le nom de la société */
/* la liste déroulante renvoie le Numfournisseur (clé primaire) */
/* ************************************************** */
if ( mysqli_num_rows($result) > 0)
{
while ($row = mysqli_fetch_assoc($result))
{
echo "<option value='" . $row['I'] . "'>" . $row["P"]. "</option>" ;
}
}
      mysqli_close($link);

?>
</select>
  <input type="submit" value="Bouton de validation quinefériendutou"/>

</form>
</body>
</html>
<!-- ******************************************************************** -->
<!-- ******************************************************************** -->
<!-- R E M A R Q U E -->
<!-- ******************************************************************** -->
<!-- ******************************************************************** -->
<!-- En ajoutant un bouton de validation au formulaire -->
<!-- le fichier cible 'suite.php' recevra ici -->
<!-- la variable $_POST["ID"] ayant pour valeur le choix de l'option -->
<!-- ******************************************************************** -->
