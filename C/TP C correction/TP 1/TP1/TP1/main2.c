#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main()
{
	//nombres de 0 a 100 inclus
	for (int i = 0; i <= 100; i++)
	{
		printf("%d ", i);
	}
	printf("\n\n");
	//table asci de 32 a 121
	int j = 0;
	for (int i = 32; i <= 121; i++)
	{
		if (j==15)
		{
			printf("\n");
			j = 1;
		}
		else
		{
			j++;
		}
		printf("%c ", i);
	}

	printf("\n\n");

	//nombres de 20 à 0 pas 0.5
	for (float h = 20; h >= 0; h -= 0.5)
	{
		printf("%.1f ", h);
	}
	
	printf("\n\n");

	for (int i = 0; i <= 90; i+=10)
	{
		printf("%f ", sin(i*0.0174533));
	}
	printf("\n\n");








	system("pause");
}