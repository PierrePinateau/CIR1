	#include <stdio.h>
#include <conio.h>
#include <locale.h> // les bon accents 
#include "fonction.h"

#define NBMAXNOTES 30

int main()
{
	setlocale(LC_CTYPE, "fr-FR"); //afficher les accents dans la console
	float notes[NBMAXNOTES], toSort[NBMAXNOTES] ,sort[NBMAXNOTES];
	float saisie, moy = 0, min = 20, max = 0;
	double ecart=0;
	unsigned int nbNotes=0,absents=0,continuer,  position[NBMAXNOTES];
	char test = 'B'; //valeur par défaut 

	initialiseTab(notes, NBMAXNOTES);
	do
	{	do
		{	printf("saisir la note n°%d:",nbNotes+1);
			scanf_s("%f", &saisie);
			if (saisie <= 20 && saisie >= 0){notes[nbNotes] = saisie;	nbNotes++;}
		} while ((saisie <= 20 && saisie >= 0)&& nbNotes<NBMAXNOTES); //on test pour continuer a saisir des notes 
		if (nbNotes < NBMAXNOTES)
		{
			printf("Elève absent ? ou voulez-vous arrêter la saisie des notes ? A/O/N\n");
			do //boucle pour récuperer le char de sortie 
			{
				test = (char)_getch();
			} while ((test != 'A') && (test != 'O') && (test != 'N'));
		}
		if (test == 'A' || test == 'N') continuer = 1;		//on test si on doit continuer a demander des notes
		if (test == 'A') { notes[nbNotes] = -1; nbNotes++;} //on note si l'éléve est absent
		if (test == 'O'|| nbNotes>29) continuer = 0;		//on sort de la boucle de demande de note
	} while (continuer);


	moy = moyenne(notes, NBMAXNOTES);						//moyenne
	absents = maisTPasLaMaisTOu(notes, NBMAXNOTES);			//nombre d'absents	
	ecart = ecartType(notes, NBMAXNOTES, moy);				//ecart type


	//affichage des valeurs demandées 
	printf("\n\nil y a eu %d notes valides \nle nombre d'éléve absents est %d \nla moyenne est %.2f\nl'écart type est :%f\n", 
			              nbNotes - absents,                               absents,            moy,                    ecart);

	printf("\naffichage du tableau : \n\n"); //affichage du tableau des notes
	for (int i = 0; i < NBMAXNOTES; i++) 
	{
		if(notes[i]>=0)printf(" %.2f |", notes[i]);
	}	 	
	printf(" \n\n");
	
	//tri du tableau de notes 
	sortTab(notes, sort, toSort, position, NBMAXNOTES);
	printf("note min :%.2f \nnote max :%.2f\n\n",minTab(notes, NBMAXNOTES),maxTab(notes,NBMAXNOTES));	//on affiche le min et le max
	afficherTab(sort, position, nbNotes - absents);
	bye();
}