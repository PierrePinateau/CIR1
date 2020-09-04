#include <stdio.h>
#include <locale.h>
#include "fonctionEx4.h"


int main()
{	
	setlocale(LC_CTYPE, "fr-FR");

	unsigned int MyAdress,masque, MyAdress_w, MyAdress_x, MyAdress_y, MyAdress_z, IPv4MaskLength=0;
	MyAdress_w = 1;
	MyAdress_x = 1; 
	MyAdress_y = 1;  
	MyAdress_z = 1;
	IPv4MaskLength = 8;

	//lecture des valeurs de l'adresse
	printf("saisir votre adresse IPv4: ");

	scanf_s("%d", &MyAdress_w);
	printf("%d.",MyAdress_w);
	scanf_s("%d", &MyAdress_x);
	printf("%d.%d.",MyAdress_w,MyAdress_x);
	scanf_s("%d", &MyAdress_y);
	printf("%d.%d.%d.",MyAdress_w,MyAdress_x,MyAdress_y);
	scanf_s("%d", &MyAdress_z);
	printf("\n");
	
	MyAdress = creatAdress(MyAdress_w, MyAdress_x, MyAdress_y, MyAdress_z);

	//lecture des valeurs du masque
	do {
		printf("longueur du masque réseau :");
		scanf_s("%d", &IPv4MaskLength);
	} while (IPv4MaskLength < 0 || IPv4MaskLength > 32);

	//affichage des 3 adresses
	printf("adresse	     IPv4 = ");
	affichAdress(MyAdress);
	printf(" / %d \n", IPv4MaskLength);


	printf("adresse du reseau = ");
	affichAdress(maskadress(MyAdress, IPv4MaskLength));
	printf(" / %d \n", IPv4MaskLength);

	printf("adresse broadcast = ");
	affichAdress(broacastAdress(MyAdress, IPv4MaskLength));

	

	bye();
}