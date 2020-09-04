<?php
$nb = 12 ;
$ingredient = "oeufs" ;
$texte = "Achetez-moi ". $nb . " " . $ingredient . " frais" ;
// --> $texte contiendra la chaine "Achetez-moi 12 oeufs frais"
$annee = 1 ;
$cycle = "CIR" ;
echo "Bonjour les " . $cycle . $annee ; // affichera Bonjour les HEI3
echo " Bonjour les <b>" . $cycle . "</b>". $annee ; // affichera Bonjour les CIR1
// avec CIR en gras
echo ' Bonjour les <b>' . $cycle . "</b>". $annee ; // affichera Bonjour les CIR1
// avec CIR en gras
?>
