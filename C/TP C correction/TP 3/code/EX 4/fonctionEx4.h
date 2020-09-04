#pragma once

void bye(void);														//boucle jusqu'a ce que l'utilisateur apuie sur Q

void affichebin(unsigned n);										//permet d'afficher le code binaire d'un nombre non signer sur 32 bits (debogage)

void affichAdress(unsigned int adress);								//decompresse une adresse créer par la fonction si desssou 

unsigned int creatAdress(int w, int x, int y, int z);				//retourne une unique valeur qui contient les 4 valeurs saisie sur 4 octets

unsigned int maskadress(unsigned int adresse, unsigned int mask);	//fonction très sale qui renvoie l'adresse réseau après aplication du mask

unsigned int broacastAdress(unsigned int adresse, unsigned int mask);//retourne l'adresse de broadcast du réseau  