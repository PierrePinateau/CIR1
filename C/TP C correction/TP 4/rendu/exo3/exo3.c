#include <stdio.h>
#include <stdlib.h>
#include <conio.h>



#define TAILLENOM 20

void bye() { char saisie = ' '; do { saisie = (char)_getch(); } while (saisie != 'q'&&saisie != 'Q'); }

int main()
{
	char sexe = 'e';
	char nom[TAILLENOM], prenom[TAILLENOM];
	printf_s("saisisez votre genre (H ou F)");
	
	do
	{
		sexe = (char) _getch();
	} while( sexe !='H' && sexe != 'F');

	printf_s("\nsaisisez votre nom :");
	scanf_s("%19s", nom, _countof(nom));

	printf_s("saisisez votre prenom :");
	scanf_s("%19s", prenom, _countof(prenom));

	if (sexe == 'H') printf_s("Monsieur %s %s", nom, prenom);
	else	printf_s("Madame %s %s", nom, prenom);

	bye();
}