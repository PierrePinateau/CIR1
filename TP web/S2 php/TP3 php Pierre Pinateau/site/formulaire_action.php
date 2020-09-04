<!DOCTYPE html>
<html lang="fr">
	<head>
		<meta charset="utf-8">
		<link rel="stylesheet" href="page.css">
		<title> Mon Site </title>
	</head>

	<body>

		<?php	include 'entete.php';?>

			<div id="navcorps">
				<?php
					if (empty($_POST['nom'])) {
						$nom = "???";
					}
					else {
						$nom = $_POST['nom'];
					}
					if (empty($_POST['prenom'])) {
						$prenom = "???";
					}
					else {
						$prenom = $_POST['prenom'];
					}
					if (empty($_POST['genre'])) {
						$genre = "???";
					}
					else {
						$genre = $_POST['genre'];
					}
					if (empty($_POST['sports'])) {
						$sports = [];
					}
					else {
						$sports = $_POST['sports'];
					}
					if (empty($_POST['couleur'])) {
						$couleur = "???";
					}
					else {
						$couleur = $_POST['couleur'];
					}



					echo "<p> Bonjour ";
					if($genre=="homme")
					echo "monsieur ";

					else if ($genre=="femme")
					echo "madame ";

					echo "$nom $prenom . Votre couleur préférée est le $couleur";

					if(count($sports)==0)
					echo " et vous ne pratiquez aucun sport.</p>";

					else {
						echo " et vous pratiquez le : ";


						foreach ($sports as $key => $entry )
							echo "$entry ";
							echo ".</p>";
					}
	 					?>
					</div>
					<?php 	include 'pieddepage.php'; ?>

		</body>
</html>
