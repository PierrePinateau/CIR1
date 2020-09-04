#include "fonction.h"
#include <stdio.h>
#include <locale.h>
#define TAILLETAB 20


int main()
{
	setlocale(LC_ALL, "fr-FR");
	int tableau[TAILLETAB], toFind = 0, occurence = 0, *ptr = tableau;
	initialiseTableau(ptr, TAILLETAB);

	printf("la valeur a trouvé est : ");
	scanf_s("%d", &toFind);
	for (int  i = 0; i < TAILLETAB; i++)
	{
		printf("%d | ", tableau[i]);
	}
	printf("\nLa valeur %d a été trouvée en ", toFind);
	for (int i = 1; i <= TAILLETAB; i++)
	{
		if (*ptr == toFind)
		{
			if (!occurence ) { printf("%d", i); }
			else { printf(", puis en %d", i); }
			occurence = 1;
		}
		ptr++;
	}
	if (!occurence) printf("nul part");
	bye();
}