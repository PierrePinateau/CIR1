#include <stdio.h>
#include <conio.h>
#include <locale.h>

#define SEPARATEUR '/' 
#define TAILLETAB1 20 


void bye() { char saisie = ' '; do { saisie = (char)_getch(); } while (saisie != 'q'&&saisie != 'Q'); }


int main()
{
	int  MyTab1[TAILLETAB1];
	int *MyPtr1 = &MyTab1[TAILLETAB1-1];
	for (int i = 0; i < 20; i++)
	{
		MyTab1[i] = i+1;
		printf_s("%d %c ", MyTab1[i], SEPARATEUR);
	}

	printf_s("\n");
	while (MyPtr1 >= MyTab1)
	{
		printf_s("%d %c ", *MyPtr1, SEPARATEUR);
		MyPtr1--;
	}

	bye();
}