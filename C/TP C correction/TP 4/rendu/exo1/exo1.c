#include "tp4.h"
#include <stdio.h>
#include <conio.h>
#include <locale.h>



void bye() { char saisie = ' '; do { saisie = (char) _getch(); } while (saisie != 'q'&&saisie != 'Q'); }


int main()
{
	setlocale(LC_CTYPE, "fr-FR");

	HEURE HeureDebut = { 12,30 }, Duree = { 0,35 }, HeureFin;
	HeureFin.heure = HeureDebut.heure + Duree.heure;
	HeureFin.minute = HeureDebut.minute + Duree.minute;
	if (HeureFin.minute > 59 )
	{
		HeureFin.heure += HeureFin.minute /60;
		HeureFin.minute %= 60;
	}
	printf_s("l'heure de début est : %d:%d \n", HeureDebut.heure, HeureDebut.minute);
	printf_s("la durée est         : %d:%d \n", Duree.heure, Duree.minute);
	printf_s("l'heure de fin est   : %d:%d \n", HeureFin.heure, HeureFin.minute);



	bye();
}