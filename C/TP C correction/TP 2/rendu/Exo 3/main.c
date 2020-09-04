#include <stdio.h>
#include <locale.h> // les bon accents 

int main()
{
	setlocale(LC_ALL, "fr-FR"); //afficher les accents dans la console

	int annee;

	do
	{
		printf("saisir une année : ");
		scanf_s("%d", &annee);
	} while (annee > 10000);

	//première solution (elle est bien)
	if (annee % 400 == 0 || (annee % 4 == 0 && annee % 100 != 0)) 
	{
		printf("l'année est bisextile\n");
	}
	else
	{
		printf("l'année n'est pas bisextile\n");
	}

	//solution relou et beaucoup trop longue
	if (annee % 4 == 0)
	{
		if (annee % 100 == 0)
		{
			if (annee % 400 != 0)
			{
				printf("l'année n'est pas bisextile\n");
			}
		}
		else
		{
			printf("l'année est bisextile\n");
		}
		
	}
	else
	{
		printf("l'année n'est pas bisextile\n");
	}

	//fin de la solution longue


	system("pause");
}
