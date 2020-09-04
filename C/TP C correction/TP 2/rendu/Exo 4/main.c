#include <stdio.h>
#include <time.h>


int main() 
{
	srand(time(0));		//initialisation de la fonction aléatoire
	int x = rand() % 100;// le nombre aléatoire que l'on doit deviner
	int trouve = 0,		//on regarde si le joueur a trouver pour quiter la boucle
		saisie,			//on récupère la saisie au clavier
		essaye=0;		//le nombre d'essaies


	printf("trouver le nombre entre 0 et 100\n\n");
	do
	{	
		printf("votre proposition :");
		scanf_s("%d",&saisie);
		if (saisie == x)
		{
			trouve = 1;
		}
		else
		{
			if (x < saisie)
			{
				printf("trop grand, essaye encore \n");
			}
			else
			{
				printf("trop petit, essaye encore \n");
			}
		}
		essaye++; //on incrémente le nombre d'essaye

	} while (!trouve);

	printf("\n\nVous avez trouver le chiffre %d en %d coups\n", x, essaye);
	
	system("pause");
	
}