<!DOCTYPE>
<html lang="fr">
<head>
	<meta charset="utf-8"/>
</head>
<body>

<?php
function plusgrand($A, $B)
{
    if (A>B){echo "$A"; return $A;}
	else {echo "$B"; return $B;}
}
?>

<?php
function remplacerlettres($chaine)
{
str_replace ( 'o', 0, $chaine);
str_replace ( 'i', 1, $chaine);
str_replace ( 'e', 3, $chaine);
echo "$chaine";
}
?>

<form>
    <label for="entree">Entrez du texte : </label>
	<input type="text"  id="entree" name="texte"/>
</form>
<?php 
echo $_POST['entree'];
$value =  $_GET;
remplacerlettres($value); ?>

</body>
</html>
