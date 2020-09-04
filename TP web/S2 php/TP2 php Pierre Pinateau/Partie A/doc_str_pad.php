<!DOCTYPE html>
<html lang="fr" dir="ltr">
	<head>
		<meta charset="utf-8">
		<title></title>
	</head>
	<body style="text-align:center;">

		<?php
		$var1 = 29;// car il y a 29 caractères
		$var2 = "You did it!";
		$var3 = STR_PAD_BOTH;
		$var4 = "*~*";
		echo str_pad($var2, $var1, $var4, $var3);
		?>
	</body>
</html
