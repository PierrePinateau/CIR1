#include "fonction.h"
#include <stdio.h>
#include <math.h>
#include <conio.h>

void initialiseTab(float *tab, int taille)
{
	for (int i = 0; i < taille; i++)
	{
		tab[i] = -2;
	}
}

float moyenne(float *TAB, int taille)
{
	float moyenne = 0;
	int nbValid = 0;
	for (int i = 0; i < taille; i++)
	{
		if (TAB[i] >= 0) 
		{
			moyenne += TAB[i];
			nbValid++;
		}
	}
	moyenne /= nbValid;
	return moyenne;
}

double ecartType(float * tab, int tailleTab, float moyenne)
{
	double ecart = 0;
	int nbValid = 0;
	for (int i = 0; i < tailleTab; i++)
	{
		if (tab[i] >= 0)
		{
			nbValid++;
		}
	}

	for (int i = 0; i<nbValid; i++)
	{
		if (tab[i] >= 0) { ecart += (tab[i] - moyenne)*(tab[i] - moyenne); }
	}
	ecart = sqrt((ecart / nbValid));

	return ecart;
}

int maisTPasLaMaisTOu(float *TAB, int taille)
{
	int absent = 0;
	for (int i = 0; i < taille; i++)
	{
		if (TAB[i] == -1) absent++;
	}
	return absent;
}

void sortTab(float *original, float *trier,float *aTrier, int *position, int taille)
{
	float tmpmax = 0;
	int index = 0;
	for (int i = 0; i < taille; i++)  // on copier l'original
	{
		aTrier[i] = original[i];
	}

	for (int i = 0; i<taille; i++)
	{
		for (int j = 0; j < taille; j++)
		{
			if (aTrier[j]>tmpmax)					//on test le maximum 
			{
				tmpmax = aTrier[j];		
				index = j;
			}
		}
		tmpmax = 0;					//on réintialise la valeur de test
		position[i] = index + 1;	//on stock la position de la valeur dans la liste initiale 
		trier[i] = aTrier[index];	//on met dans la case la plus haute(non remplie) la valeur la plus grande trouvé dans le tableau a trier 
		aTrier[index] = 0;			//on vide la case ou l'on viens de trouver la valeur la plus grande
	}

}

float minTab(float * tab, int taille)
{
	float min=20;
	for (int i = 0; i < taille; i++)
	{
		if (tab[i] < min && tab[i]>=0) min = tab[i];
	}
	return min;
}

float maxTab(float * tab, int taille)
{
	float max = 0;
	for (int i = 0; i < taille; i++)
	{
		if (tab[i] > max) max = tab[i];
	}
	return max;
}

void afficherTab(float * tab, int * position, int taille)
{
	printf("\nrang :      n° note :     note:\n");//on affiche les notes (sans les absents =-1)
	for (int i = 0; i < taille; i++)
	{
		printf("%d", i + 1);
		if (i + 1 < 10) { printf("           "); }
		else { printf("          "); }

		printf("%d", position[i]);
		if (position[i] < 10) { printf("             "); }
		else { printf("            "); }

		printf("%.2f\n", tab[i]);
	}
}

void bye(void)
{
	printf("\nPresser Q pour fermer");
	char test;
	do { test = (char)_getch(); } while ((test != 'Q') && (test != 'q'));	//presser Q pour quitter
}




