#include <stdio.h>
#include <math.h>

int main()
{
	int n = 100;
	int i=0;
	unsigned short int somme=0;
	
	
	while (i < n)														//boucle tant que, sortie de l'incrément 100
	{
		i++;
		somme += i;
	}
	printf(" la somme est : %d \n l'increment est :%d\n", somme, i);

	i = 0; somme = 0;
	do																	//boucle do while, sortie de l'incrément 100
	{
		i++;
		somme += i;
	} while (i < n);
	printf(" la somme est : %d \n l'increment est :%d\n",somme, i);


	somme = 0;
	for (i = 0; i <= n; i++)											//boucle pour, sortie de l'incrément 101
	{
		somme += i;
	}
    printf(" la somme est : %d \n l'increment est :%d\n", somme, i);

	printf("\n\n"); //double retour a la ligne 

	n = 1; somme = 0; 


	while (pow(2,8*sizeof(unsigned short int))-somme >= n)				//on calcule la taille d'un unsigned short int pour la comparer et ne pas dépasser l'alocation mémoire.
	{
		somme += n;
		n++;
	}
	printf(" \n fin de la boucle n:%d\n somme :%d\n ", n,somme);






	do   //on vérifie que la saisie de n est valide 
	{	
		printf("saisir une valeur de n :");
		scanf_s("%hu", &n);
	} while (n > 362);

	somme = 0;

	for (i = 0; i <= n; i++)
	{
		somme += i;
	}
	printf("somme de 1 a %d : %d\n", n, somme);



	system("pause");
}