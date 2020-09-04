#include <stdio.h>
#include <stdlib.h>
#include "grandEntier.h"

static unsigned long long Produit=0;			/*  la valeur du dernier factoriel calculé. Elle est globale*/
static unsigned long long N=1;			/*  la variable qui contrôle le début de la boucle. Elle est globale*/


/*LA VALEUR DE N EST FAUSSE A PARTIR DE 13 IL FAUT METTRE N EN UNSIGNED LONG LONG POUR AUGMENTER LA VALEUR MAX */


unsigned long long factorielle(unsigned int n)
{
	unsigned short nbBoucle = 0;
	if (Produit == n)
	{
		printf("nombre de boucle :%d\n", nbBoucle);
		return N;
	}
	else if (Produit < n)
	{
		for (unsigned int i = n; i > Produit ; i--)
		{
			N *= i;
			nbBoucle++;
		}
		Produit = n;
		printf("nombre de boucle :%d\n", nbBoucle);
		return N;
	}
	else
	{
		N = 1;
		for (unsigned int i = 1; i <= n; i++)
		{
			N *= i;
			nbBoucle++;
		}
		Produit = n;
		printf("nombre de boucle :%d\n", nbBoucle);
		return N;
	}
}


int main()
{
	/*int n;
	unsigned long long factor;
	do
	{
		scanf_s("%d", &n);
		factor = factorielle(n);
		printf("le factoriel de %d est : %llu \n", n, N);
	} while (factor != 0);
	*/
	GrandEntier nb1;
	GrandEntier Result;

	Initialise(nb1);
	Initialise(Result);

	AjouteADroite(nb1,1);
	AjouteADroite(Result, 1);
	for (long int i = 2; i < 12; i++)
	{
		Multiplication(nb1, i, Result);
	}

	Affiche(Result);
	
	system("pause");
	return 0;
}