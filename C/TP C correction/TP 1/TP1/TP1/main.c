#include <stdlib.h> 
#include <stdio.h>  
// définition de macros 
// #define DEBUG 
// programme principal  
// définition de type  

typedef unsigned char boolean; 
typedef unsigned char byte;

main()
{
	char OneLetter = 'A'; 
	char AnOtherLetter = 66; 
	byte toto = 0;
	unsigned char VerySmallCounter = 255;
	short SmallCounter = 32767; 
	int Counter = 0; 
	long LargeCounter = 2147483647;
	unsigned long FullRangeLargeCounter = 4294967295; 
	int ChienDeGarde = 0;  
	float Dim1 = 1.414F; 
	double Dim2 = .5L;
	boolean TestResult = 1;
	const double Pi = 3.14159265L;


	printf("\n");
	printf("exemple d'affichage d'un caractere %c, codage sur %d octets\n", OneLetter, sizeof(OneLetter));
	printf("exemple d'affichage d'un entier court %d, codage sur %d octets\n", Counter, sizeof(Counter));
	printf("%c et ma byte %c \n", OneLetter, AnOtherLetter);
	printf("le caractère byte est \"%c\"\n", toto);
	printf("le very small counter vaut %c et sa taille est %d \n", VerySmallCounter, sizeof(VerySmallCounter));


	printf("le float Dim1 vaut %f ,  et sa taille vaut  %d  \n", Dim1, sizeof(Dim1));
	
	
	system("pause");  
	return(EXIT_SUCCESS);
}
