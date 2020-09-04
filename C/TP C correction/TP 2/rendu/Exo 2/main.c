#include <stdio.h>

#define TailleTab 3

int main()
{
	float volume;
	float dimention[TailleTab];  //hauteur, largeur, profondeure,
	int continuer = 0;			 //tant que continuer différent de 0 on continue a analyse les bagages

	do {															//boucle pour continuer a saisir des valises
		
		do															//boucle dans la quelle on ajoute une valise et on la vérifie
		{
			volume = 1;
			printf("saisir les dimentions :");

			for (int i = 0; i < TailleTab; i++)	
			{
				scanf_s("%f", &dimention[i]);	

				while (dimention[i] > 150 || dimention < 1)			//on vérifie que la taille de la valise soit légale
				{													//si elle ne l'est pas on la redemande 
					printf("saisir une valeur entre 1 et 150 :");
					scanf_s("%f", &dimention[i]);
				}

				volume *= dimention[i]; //on multiplie la valeur recue au volume
			}
			printf("le volume de la valise est %.2f\n", volume);
			if (volume > 55 * 35 * 25)
			{
				printf("la taille de la valise n'est PAS VALIDE\n ");
			}

		} while (volume > 55 * 35 * 25);

		printf("le volume de la valise est VALIDE\n");
	
		printf("continuer avec un autre bagage ? (oui=1, non=0)");
		scanf_s("%d", &continuer);

	} while (!continuer);



}