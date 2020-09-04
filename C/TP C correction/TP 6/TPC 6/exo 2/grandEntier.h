#pragma once

#define NbChiffresMax 30 

typedef enum { false, true } boolean;


typedef  int GrandEntier[NbChiffresMax];


void Initialise(GrandEntier Nombre);

void Affiche(GrandEntier Nombre);

int AjouteADroite(GrandEntier Nb, int Chiffre);

int EntreeClavier(GrandEntier Nombre);

int Addition(GrandEntier Nb1, GrandEntier Nb2, GrandEntier Result);

int Multiplication(GrandEntier Nb1, long int, GrandEntier Result);

