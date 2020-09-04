#include <stdio.h>
#include <stdlib.h>

#define TAILLETAB 10
#define TAILLEAJOUT 5

typedef	struct heure { int heure; int minute; }HEURE;

int valdieTailleBagage(float dim1, float dim2, float dim3)
{
	float volumeMax = 55*35*25;
	if ((dim1<=150 && dim1>0)&&(dim2 <= 150 && dim2>0)&&(dim3 <= 150 && dim3>0)&&(dim1*dim2*dim3 <= volumeMax) )
	{
		return 1;
	}
	else return 0;
}

unsigned short int somme(unsigned short int n)
{
	unsigned short int somme=0;
	if (n > 361)return 0;

	for (unsigned int i = 1; i <= n; i++)
	{
		somme += i;
	}
	return somme;
}

unsigned short int sommeRecurs(unsigned short int n)
{
	if (n <= 0 || n > 361) return 0;
	return n + sommeRecurs(n - 1);
}
 
void permuter(int *a, int *b)
{
	if (a != NULL && b != NULL)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}
}


void AfficheHeure(HEURE * UneHeure)
{
	printf("%d:%d\n", UneHeure->heure, UneHeure->minute);
}

int initTab1(int * tab)
{
	if (tab == NULL) return 0;
	int *tmp = tab, tailletableau = 0;
	for(int i = 0; i<10;i++)
	{
		*tmp = 0;
		tmp++;
		tailletableau++;
	}
	return tailletableau;
}

int afficheTab1(int *tab)
{
	if (tab == NULL) return	0;
	int *tmp = tab;
	for (int i = 0; i<10; i++)
	{
		printf("%d ", *tmp);
		tmp++;
		
	}
	return 1;
}

void initTab2(int *tab, int Size)
{
	int *tmp = tab;
	for (int i = 0; i < Size; i++)
	{
		*tmp = 0;
		tmp++;
	}
}

void afficheTab2(int *tab, int NbElts)
{
	int *tmp = tab;
	for (int i = 0; i < NbElts; i++)
	{
		printf("%d ", *tmp);
		tmp++;
	}
}


int ajoutElementDansTableau(int **tab, int *Size, int *NbElements, int Element)
{
	if (*tab == NULL || *Size <= 0 ||*NbElements>*Size) return -1; 
	if (*NbElements == *Size)
	{
		*Size += TAILLEAJOUT;
		realloc(*tab, *Size * sizeof(int));
	}
	int *ptr = *tab;
	ptr += *NbElements;
	*ptr = Element; 
	*NbElements += 1;

	return *NbElements;

}






int main()
{	
	
	float longueur = 10, largueur = 15, hauteur = 2;
	int IsValideValise = valdieTailleBagage(longueur, largueur, hauteur);
	
	if (IsValideValise) printf_s("la taille de la valise est bonne\n");
	else printf_s("la taille de la valise n'est pas bonne\n");
	

	printf("%d\n",sommeRecurs(42));

	
	HEURE whattimeisit = { 12,45 };
	AfficheHeure(&whattimeisit);
	
	
	int *MyTab2 = malloc(10*sizeof(int));
	initTab2(MyTab2,10);
	afficheTab2(MyTab2, 10);
	free(MyTab2);
	


	int *unTableau = malloc(3*sizeof(int)), saTaille= 1, sonNombreDElement = 0;
	ajoutElementDansTableau(&unTableau, &saTaille, &sonNombreDElement, 12);
	ajoutElementDansTableau(&unTableau, &saTaille, &sonNombreDElement, 14);
	for (int i = 0; i < sonNombreDElement; i++)
	{
		printf("%d  ", unTableau[i]);
	}
	

	system("pause");
}