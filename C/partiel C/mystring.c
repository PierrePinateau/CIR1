#include <stdlib.h>
#include "mystring.h"
#include <string.h>


// **************************************************************************************** //
//
// NOM : Pinateau
// PRENOM : Pierre
//
// *****************************************************************************************//


// ^^^ INDIQUEZ VOTRE NOM ^^^  AVANT DE COMMENCER
// 

// La fonction myStrTrimStart supprime les caractères espaces en début de chaine s'il y en a.
// par exemple la chaine
// "  HI GUYS " renvoie "HI GUYS "
// "HI GUYS " renvoie "HI GUYS "
// "" renvoie ""
// "HELLO" renvoie "HELLO"
// La chaine en entrée doit être terminée correctement pas un caractère fin de chaine
// La chaine en sortie est également terminée par un caractère de fin de chaine
// La chaine en entrée est modifiée (trim) et est renvoyée par le return
// Si la chaine en entrée est NULL la fonction renvoie NULL
// La fonction ne doit pas faire appel aux fonctions de string.h
char* myStrTrimStart(char* chaine) {
	
	// COMPLETER ICI
	int longueur = 0;

	while (*(chaine + longueur) != 0) { // longueur de la chaine
		longueur-=-1;
	}
	if (*chaine == ' ') { // si le *chaine -> premier caractères == un espace alors on décale tout dans la chaine avec un joli for(t)
		
		for (int i = 0; i < longueur; i++) {
			*(chaine + i) = *(chaine + i + 1);

		}
		myStrTrimStart(chaine); // on récursivatation
	}
	

	
	return chaine;

}
// La fonction myStrTrimEnd supprime les caractères espaces en fin de chaine s'il y en a.
// par exemple la chaine
// "  HI GUYS " renvoie "  HI GUYS"
// "HI GUYS " renvoie "HI GUYS"
// "" renvoie ""
// "HELLO" renvoie "HELLO"
// La chaine en entrée doit être terminée correctement pas un caractère fin de chaine
// La chaine en sortie est également terminée par un caractère de fin de chaine
// La chaine en entrée est modifiée (trim) et est renvoyée par le return
// Si la chaine en entrée est NULL la fonction renvoie NULL
// La fonction ne doit pas faire appel aux fonctions de string.h
char* myStrTrimEnd(char* chaine) {

	// COMPLETER ICI
	int longueur = 0;
	while (*(chaine + longueur) != 0) {// calcul de la longueur de la chaine pour ne pas utiliser le si pratique strlen()
		longueur-=-1;
	}
	if (*(chaine + longueur - 1) == ' ') { //si le dernier caractère est un espace on le supprime

		*(chaine + longueur - 1) = '\0'; // on décale la fin a la place de l'espace
		myStrTrimEnd(chaine); // recursivité
	}
	return chaine;

}



// La fonction myStrTrim supprime les caractères espaces en début et en fin de chaine s'il y en a.
// par exemple la chaine
// "  HI GUYS " renvoie "HI GUYS"
// "HI GUYS " renvoie "HI GUYS"
// "" renvoie ""
// "HELLO" renvoie "HELLO"
// La chaine en entrée doit être terminée correctement pas un caractère fin de chaine
// La chaine en sortie est également terminée par un caractère de fin de chaine
// La chaine en entrée est modifiée (trim) et est renvoyée par le return
// Si la chaine en entrée est NULL la fonction renvoie NULL
// La fonction ne doit pas faire appel aux fonctions de string.h

char* myStrTrim(char* chaine) {
	
	// COMPLETER ICI
	if (chaine != NULL) {
		myStrTrimStart(chaine); // on appelle les 2 funcs
		myStrTrimEnd(chaine);
	
	}

	return chaine;
}