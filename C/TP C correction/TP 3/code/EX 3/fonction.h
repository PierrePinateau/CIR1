#pragma once


void initialiseTab(float *tab, int taille);											//initialise le tableau en paramettre a -2

float moyenne(float *tab, int taille);												//retourne la moyenne d'un tableau de flotant

double ecartType(float *tab, int tailleTab, float moyenne);							//retourne l'écart type d'un tableau de flotant 

int maisTPasLaMaisTOu(float *tab, int taille);										//retourne le nombre de -1 dans un tableau 

void sortTab(float *tab1, float *tab2, float *tmp, int *position, int taille);		//On copier le premier tableau dans le deuxième et on tri le deuxième, on retourne aussi le tableau de position

float minTab(float *tab, int taille);												//retourne le min d'un tableau

float maxTab(float *tab, int taille);												//retourne le max d'un tableau

void afficherTab(float *tab, int *position, int taille);							//affiche un tableau de valeur trier ainsi que les position initiales

void bye(void);																		//permet de quiter quand on appuie sur q ou Q