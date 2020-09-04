#include <stdio.h>
#include <stdlib.h>


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
	int n;
	unsigned long long factor;
	do
	{
		scanf_s("%d", &n);
		factor = factorielle(n);
		printf("le factoriel de %d est : %llu \n", n, N);
	} while (factor != 0);

	
	system("pause");
	return 0;
}