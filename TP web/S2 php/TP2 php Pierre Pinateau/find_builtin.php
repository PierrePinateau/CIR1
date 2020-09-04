<?php
	function convertToShout($str1){
		echo (strtoupper($str1)." !");
	}
	function CalculateCircleArea($diametre){	
		$pi = pi();
		$surface = (($diametre / 2)*($diametre / 2)) * $pi;
		echo (" surface : ".$surface);
	}
	function verificationPassword($password){
		if (strlen($password) >= 8){
			for ($i = 0; $i <= 10 ; $i++){
				if (strrchr($password,"$i") != FALSE){
					if (strtolower($password) != $password){
						if (strtoupper($password) != $password){
							return TRUE;
							}
						else {
							return FALSE;
							}
						}
					else {
						return FALSE;
						}
					}
				else{
					return FALSE;
					}
				}
				return FALSE;
			}
		else{
			return FALSE;
		}
		return FALSE;
	}
?>
<!DOCTYPE html>
<html lang="fr">
	<head>
		<meta charset="utf-8">
		<title>Find builtin</title>
	</head>
	<body>
		<?php
			echo(convertToShout("je ne sais pas"));
			echo('<br>');
			echo (CalculateCircleArea(25));
			echo('<br>');
			echo (CalculateCircleArea(30));
			echo('<br>');
			echo (CalculateCircleArea(872));
			echo('<br>');
			echo (CalculateCircleArea(6));
			echo('<br>');
			echo (CalculateCircleArea(29));
			echo('<br>');
			if (empty($_POST['password'])) {
				$password = "password";
			}
			else {
				$password = $_POST['password'];
			}
			echo($password);
			echo('<br>');
			echo verificationPassword($password);
			
		?>
	</body>
</html>
