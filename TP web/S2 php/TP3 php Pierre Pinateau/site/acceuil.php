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
				@setlocale(LC_TIME, 'fr_FR');
				echo "<p> Au moment de l'exécution de ce script PHP, nous sommes le ".strftime('%A %d %B %Y et %Hh%Mm et %Ss').".</p>";

				if (strftime("%H")>7 and strftime("%H")<12) {
				  echo "Bonne matinée, tel le pays du printemps se couchant sur le continent du soleil levant";
				}
				if (strftime("%H")>12 and strftime("%H")<20) {
				  echo "Bonne aprèm en cette douce soirée d'été";
				}
				if (strftime("%H")>20) {
				  echo "Bonne soirée, les pommes tombent seulement le vendredi midi";
				}

			?>
			</div>

			<?php 	include 'pieddepage.php'; ?>

		  </body>
		</html>
