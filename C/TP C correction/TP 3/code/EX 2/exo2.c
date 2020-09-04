#include <stdio.h>


int main()
{
	unsigned int x = 0xAAFF0000; //le nombre en hexa
	
	printf("le nombre d'octets de %u est :%d\n", x, sizeof(x));			//4
	printf("le nombre de bits de 2868838400 est :%d \n", 8*sizeof(x));	//32
	for (int i = 1; i <= 32; i++) //on parcourt chaque bit
	{
		if(i<10) printf("bit  %d :", i);	//juste pour faire de jolis espaces
		else printf("bit %d :", i);

		if (x & 1)							//on compare le bit de point faible
		{
			printf("ON");
		}
		else
		{
			printf("OFF");
		}
		printf("\n");

		x >>= 1;
	}
	printf("\n\ndes bisous <3 \nBye !\n");		//parce que l'amour c'est beau
	system("pause");

}