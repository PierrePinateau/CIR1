#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define TAILLETAB 1024

void bye() { char saisie = ' '; do { saisie = (char)_getch(); } while (saisie != 'q'&&saisie != 'Q'); }

int compteMot(char *tab)
{
	int taille = strlen(tab);
	int nbEspace= 0;
	for (int i = 0; i < taille+1; i++)
	{
		if ((tab[i] == ' ' || tab[i]== '\0' )&& i>0)
		{
			if (isalnum(tab[i-1])) nbEspace++;
		}
	}
	return nbEspace;
}

float moyenneMot(char *tab)
{
	int taille = strlen(tab), nbMot = compteMot(tab, taille), nbLettres=0;
	
	for (int i = 0; i < taille; i++)
	{
		if (isalnum(tab[i])) nbLettres++;
	}
	return nbLettres / nbMot;
}

int main()
{
	char phrase[TAILLETAB];

	fflush(stdin);
	printf("saisir une phrase :\n");
	gets_s(phrase, TAILLETAB,stdin);
	
	printf("\nil y a %d mots dans la phrase et il y a %.2f lettre par mot ", compteMot(phrase,TAILLETAB),moyenneMot(phrase,TAILLETAB));

	bye();
}