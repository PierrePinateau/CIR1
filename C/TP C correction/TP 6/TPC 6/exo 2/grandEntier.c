#include <stdlib.h>
#include <stdio.h> 
#include <conio.h>
#include <ctype.h>  
#include "grandEntier.h"

  
// taille max pour representer un grand entier  typedef int GrandEntier[NbChiffresMax] ;  
/* representation des grands entiers � l'aide d'un tableau      */
/* les positions qui ne contiennent pas de chiffre significatif */
/* sont initialis�es � zero                                     */

/* Procedure d'initialisation d'un grand entier a zero*/
void Initialise(GrandEntier Nombre)
{
	for (int i = 0; i < NbChiffresMax; i++)
	{
		Nombre[i] = 0;
	}
}


/* Procedure d'affichage d'un grand entier � l'ecran           */
void Affiche(GrandEntier Nombre)
{
	/* affichage d'espace � la place des z�ros � gauche
	Sauf s'il s'agit du digit de droite, au cas ou GrandEntier vaut 0,
	il faut afficher 0 */
	int i = 0;
	while (Nombre[i] == 0 && i<NbChiffresMax-1)
	{
		i++;
		printf(" ");
		if (i % 3 == 0)
			printf(" ");
	}
	for (i; i < NbChiffresMax; i++)
	{
		printf("%d", Nombre[i]);
		if ((i + 1) % 3 == 0)
			printf(" ");
	}
}

/* Procedure  d'ajout d'un chiffre � droite dans un grand entier */
int AjouteADroite(GrandEntier Nb, int Chiffre) {
	boolean perte = false;
	if (Nb[0] != 0)
		perte = true;
	/* d�callage � gauche des chiffres */
	for (int i = 0; i < NbChiffresMax - 1; i++)
	{
		Nb[i] = Nb[i + 1];
	}
	//on met le chiffre dans la case de droite ainsi lib�r�e
	Nb[NbChiffresMax - 1] = Chiffre;

	//on dit si on a perdu un digit
	if (perte)
		return -1;
	else
		return 0;
}

/* Procedure de saisie d'un grand entier au clavier           */
int EntreeClavier(GrandEntier Nombre) {
	int NbChiffresLus = 0;  char car;				 // touche frapp�e en entr�e  
	char chiffre[2];								 // variable type chaine de caract�re pour   
													 // conversion de la variable car                   
													 // en type num�rique entier avec atoi() (ASCII to Int)  
	int EstUnChiffre = false;
	Initialise(Nombre);							     // Nombre prend la valeur zero  
	do {
		while ((car = (char)_getch()) == 0) {			// tant que     
			car = (char)_getch();						 // touche de fonction ou de direction enfonc�e    
		};										         // lire la touche frappee au clavier   
		if (EstUnChiffre = isdigit(car))				 // s'il s'agit bien d'un chiffre    
		{
			printf("%c", car);						   	 // echo ecran du chiffre valide    
			chiffre[0] = car;							 // conversion du caractere en chaine null                                                                                 // terminated pour utiliser atoi()    chiffre[1]=0;  
			AjouteADroite(Nombre, atoi(chiffre));		 // conversion du caractere                                                                                                                      // en valeur numerique et    NbChiffresLus++;                                   // affectation dans le tableau qui                                                                                                                  // contient le grand entier  
		}
		else {											 // s'il s'agit d'un caract�re de controle CLEAR (touche 'C' )    
			if ((car == 'C') || (car == 'c')) {
				Initialise(Nombre);						 // effacement des caract�res saisies     
				printf("\nClear\n");
				EstUnChiffre = true;					// pour continuer la saisie de ce nombre 
			}
		}
	} while (EstUnChiffre && (NbChiffresLus < NbChiffresMax));
	printf("\n");
	if ((car == 'X') || (car == 'x'))
		return -1;
	return 0;
}
//�criture du nouveau chiffre  


/* Procedure de calcul de la somme de deux grands entiers      */
int Addition(GrandEntier Nb1, GrandEntier Nb2, GrandEntier Result)
{
	Initialise(Result);
	for (int i = NbChiffresMax - 1; i >= 0; i--)
	{
		Result[i] += (Nb1[i] + Nb2[i]);
		if ( Result[i]>9 && i>0)
		{
			Result[i - 1] = 1;
			Result[i] %= 10;
		}
	}
	return 0;
}


/* Procedure de calcul de la somme de deux grands entiers      */
int Multiplication(GrandEntier Nb1, long int factor ,GrandEntier Result)
{
	Initialise(Result);
	for (int i = NbChiffresMax - 1; i >= 0; i--)
	{
		if (Result[i] == 0)
			Result[i] = 1;
		Result[i] *= (Nb1[i] * factor);
		if (Result[i]>9 && i>0)
		{
			Result[i - 1] = (int) Result[i] / 10;
			Result[i] %= 10;
		}
	}
	return 0;

}