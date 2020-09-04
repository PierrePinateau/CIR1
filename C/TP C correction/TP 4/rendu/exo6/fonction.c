#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "fonction.h"


void bye() { char saisie = ' '; do { saisie = (char)_getch(); } while (saisie != 'q'&&saisie != 'Q'); }


void initialiseTableau(int * tab, int taille)
{
	srand(time(NULL));

	for (int i = 0; i < taille; i++)
	{
		tab[i] = rand() % 20;
	}
}
