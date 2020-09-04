<!DOCTYPE html>
<html>
<head>
	<title>Exemple</title>
	<meta charset="utf-8">
</head>
<body>
	<?php
	include("connexion.php");
	$requete = "SELECT fournisseur.societe as nom, sum(prixunitaire*unitesstock) as total FROM produit inner join fournisseur on produit.numfournisseur = fournisseur.numfournisseur inner join categorie on produit.codecategorie = categorie.codecategorie WHERE categorie.Nomcategorie='Boissons' GROUP BY fournisseur.societe";

	$resultat = mysqli_query($link, $requete);
	if($resultat == false){
		echo "Erreur d'exécution de la requete";
		die();
	}
	echo "<h1>Résultat tableau</h1>";
	?>

	<table border='1' align='center' cellpadding='5' >
		<tr>
			<th>Fournisseur</th>
			<th>Coût</th>
		</tr>

	<?php
	$coutStock = 0;
	if ( mysqli_num_rows($resultat) > 0){
		while ($row = mysqli_fetch_assoc($resultat)){
			echo "<tr>";
			echo "<td>" .$row["nom"]. "</td>";
			echo "<td>" .$row["total"]. "</td>";
			echo "</tr>";
			$coutStock += $row["total"];
		}
			echo "<tr>";
			echo "<td><b>Total</td>";
			echo "<td><b>" .$coutStock. "</td>";
			echo "</tr>";
	}
	else{
		echo "<tr>";
		echo "<td colspan='2'>La requête ne renvoie pas de résultat !</td>";
		echo "</tr>";
	}
	?>

	<table border='1' align='center' cellpadding='5' >
		<tr>
			<th>Fournisseur</th>
			<th>Coût</th>
		</tr>

	<?php
	$coutStock2 = 0;
	if ( mysqli_num_rows($resultat) > 0){
		while ($row2 = mysqli_fetch_assoc($resultat)){
			echo "<tr>";
			echo "<td>" .$row2["nom"]. "</td>";
			echo "<td>" .$row2["total"]. "</td>";
			echo "</tr>";
			$coutStock += $row2["total"];
		}
			echo "<tr>";
			echo "<td><b>Total</td>";
			echo "<td><b>" .$coutStock. "</td>";
			echo "</tr>";
	}
	else{
		echo "<tr>";
		echo "<td colspan='2'>La requête ne renvoie pas de résultat !</td>";
		echo "</tr>";
	}
	?>

</body>
</html>
