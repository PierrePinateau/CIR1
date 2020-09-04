#include "fonctionEx4.h"
#include <conio.h>
#include <stdio.h>


void bye(void)
{
	printf("\nPresser Q pour quiter");
	char test;
	do { test = (char)_getch(); } while ((test != 'Q') && (test != 'q'));	//presser Q pour quitter
}

void affichebin(unsigned n)
{
	unsigned bit = 0;
	unsigned mask = 1;
	for (int i = 0; i < 32; ++i)
	{
		bit = (n & mask) >> i;
		printf("%d", bit);
		mask <<= 1;
	}
	printf("\n");
}

unsigned int creatAdress(int w, int x, int y, int z)
{
	unsigned int adresse = w;
	adresse <<= 8;
	adresse += x;
	adresse <<= 8;
	adresse += y;
	adresse <<= 8;
	adresse += z;

	return adresse;
}

void affichAdress(unsigned int adress)
{
	unsigned int w, x, y, z;
	w = adress;
	w >>= 24;

	x = adress;
	x <<= 8;
	x >>= 24;

	y = adress;
	y <<= 16;
	y >>= 24;

	z = adress;
	z <<= 24;
	z >>= 24;
	printf("%d.%d.%d.%d",w,x,y,z);
	
}

unsigned int maskadress(unsigned int adresse, unsigned int mask)
{
	adresse >>= 32 - mask;
	adresse <<= 32 - mask;

	return adresse;
}

unsigned int broacastAdress(unsigned int adresse, unsigned int mask)
{
	adresse >>= 32 - mask;
	for (int i = 0; i < 32-mask; i++)
	{
		adresse <<= 1;
		adresse++;
	}
	return adresse;
}

