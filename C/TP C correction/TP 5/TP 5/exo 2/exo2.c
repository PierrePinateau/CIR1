#include <stdio.h>
#include <stdlib.h>

typedef struct Tableau {
	int *elt; // le tableau d’entiers
	int size; // la taille de ce tableau d’entiers
	int eltsCount; // le nombre d’éléments dans le tableau
} TABLEAU;


// renvoie une structure TABLEAU, avec un pointeur Elt = NULL si allocation a échoué.
TABLEAU NewArray()
{
	TABLEAU mylittleponey;
	mylittleponey.size = 1;
	mylittleponey.elt = malloc(mylittleponey.size * sizeof(int));
	return mylittleponey;
}

// renvoie 0 si erreur, ou la nouvelle taille si OK
int IncrementArraySize(TABLEAU * tab, int IncrementValue)
{
	if (tab == NULL) return 0;
	tab->size += IncrementValue;
	realloc(tab->elt, tab->size * sizeof(int));
	return tab->size;

}


// renvoie 0 si erreur, sinon position de l’élément inséré
int SetElement(TABLEAU * tab, int pos, int Element)
{
	if (tab == NULL) return 0; 
	if (pos > tab->size) IncrementArraySize(tab, pos - tab->size);
	tab->elt[pos-1] = Element;
	if (pos>tab->eltsCount)tab->eltsCount = pos;
	return pos;
}

// renvoie 0 si erreur, sinon 1
int DisplayElements(TABLEAU *tab, int StartPos, int EndPos)
{
	if (tab == NULL || StartPos > tab->eltsCount || EndPos > tab->eltsCount) return 0;
	for (int i = StartPos - 1; i < EndPos; i++)
	{
		printf("%d ", tab->elt[i]);
	}
	return 1;
}

// renvoie 0 si erreur, sinon nouvelle taille du tableau
int DeleteElements(TABLEAU *tab, int StartPos, int EndPos)
{
	if (tab == NULL || StartPos > tab->eltsCount || EndPos > tab->eltsCount ) return 0;
	int i = StartPos;
	int j = EndPos -1 ;
	while (j < tab->size )
	{
		tab->elt[i-1] = tab->elt[j];
		i++; j++;
	}
	tab->eltsCount = tab->eltsCount - (EndPos-StartPos);

	return tab->eltsCount;
}





int main()   //Certaines fonction s'appellent entre elles
{
	TABLEAU applejack = NewArray();

	for (int i = 1; i <= 10; i++)
	{
		SetElement(&applejack, i, i);
	}
	printf("nb element: %d     size :%d \n", applejack.eltsCount, applejack.size);

	int test = 0;

	test = DisplayElements(&applejack, 1, 10);
	printf("\nl'affichage est bon : %d \n", test);
	
	test = DeleteElements(&applejack, 3, 5);
	printf("on a reussi a suprimer : %d \n",test);

	test = DisplayElements(&applejack, 1,test);
	printf("\nl'affichage est bon : %d \n", test);
	system("pause");
}