#include <stdio.h>   /* pour les entr�es-sorties */
#include <string.h>  /* pour les manipulations de cha�nes de caract�res */
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>

#ifndef REPERTOIRE

#define IMPL_TAB  // si d�fini, on compile pour une impl�mentation tableau du r�pertoire
#define IMPL_LIST // si d�fini, on compile pour un impl�mentation Liste Cha�n�e du r�pertoire

#ifdef IMPL_LIST
#undef IMPL_TAB
#endif

#define MAX_ENREG 1000  /* nbre max d'enregistrements */
#define MAX_SAISIE 1024 /* longueur max pour la saisie d'une cha�ne
ATTENTION, il faut que MAX_SAISIE > MAX_NOM et
MAX_SAISIE > MAX_TEL */
#define MAX_NOM 128     /* longueur maximale d'un nom */
#define MAX_TEL 20      /* longueur maximale d'un num�ro de t�l. */

#define OK    1
#define ERROR 0

#define VRAI  1
#define FAUX  0

#define SEPARATEUR ';'
#define LIGNES_PAR_PAGE 10
#define MAX_NOM_FICHIER 80

extern int modif;

/**********************************************************************/
/*** D�clarations des types                                         ***/
/***                                                                ***/
/**********************************************************************/

/* Enregistrement : structure d'un contact dans le tableau de contacts */
/* le type enregistrement contient 3 champs :                          */
/*  - nom, prenom et tel qui sont tous les trois des cha�nes de        */
/*  caract�res (tableaux de char)                                      */
typedef struct enreg
{
	char nom[MAX_NOM], prenom[MAX_NOM], tel[MAX_TEL];
} Enregistrement;

typedef struct _listChaine
{
	Enregistrement enr;
	struct LinkedList * next;
}LinkedList;

/* Repertoire : structure qui contient :                         */
/* le nombre de contacts                                         */
/* le tableau de contacts,                                       */
/* est_trie : qui vaut VRAI si le tableau est tri� et FAUX sinon */
typedef struct rept
{
	int nb_elts;
#ifdef IMPL_TAB
	Enregistrement *tab;
#else
#ifdef IMPL_LIST
	LinkedList *Liste;   //pointe vers la premi�re structure
#endif
#endif
	int est_trie;
} Repertoire;


int init_rep(Repertoire *rep);			// cr�e une structure de r�pertoire et fait appel � charger() pour charger le fichier de contact
int charger(Repertoire *rep, char nom_fichier[]); // lit les lignes dans le fichier et les analyse avec la fonction lire_champ_suivant
void afficher_menu_principal();
void option_ajouter(Repertoire *rep); // Traitement de l'option ajout d'un contact depuis le menu principal
int ajouter_un_contact_dans_rep(Repertoire *rep, Enregistrement enr); // Ajout d'un contact dans le r�pertoire stock� en m�moire
void supprimer_un_contact_dans_rep(Repertoire *rep, int indice); // utilis� notamment par traiter_recherche() afin de supprimer un contact recherch� et trouv�
void trier(Repertoire *rep); // tri du r�pertoire en m�moire

int saisie_chaine(char c[], int max);  // entree d'une chaine de caract�res quelconque au clavier, un nom par exemple
int saisie_enreg(Enregistrement *enr); // fait appel � saisie_chaine pour l'entree d'un nouveau contact
void affichage_enreg(Enregistrement enr); // affiche un seul enregistrement sur une ligne
void affichage_enreg_frmt(Enregistrement enr); // affiche un seul enregistrement avec des largeurs de colonnes fixes
void affichage_repertoire(Repertoire *rep); // affichage de tout le r�pertoire en paginant les lignes � la fa�on d'un 'more'
int est_sup(Enregistrement enr1, Enregistrement enr2); // test si un contact se trouve apr�s dans l'ordre alphab�tique par rapport � un autre contact
void trier(Repertoire *rep);  // tri des contacts du r�pertoire en m�moire

void compact(char *s); // suppression de tous les carat�res non num�riques dans une chaine (0..9) afin de faciliter la recherche par no de tel par ex.
int lire_champ_suivant(char *ligne, int *idx, char *champ, int taille_champ, char separateur); // analyse d'une ligne lue dans le fichier et stock�e dans le buffer 'ligne' 

void option_rechercher(Repertoire *rep); //traitement de l'option de recherche du menu principal
void afficher_menu_recherche();  //affiche un menu afin de proposer une recherche par nom ou par no tel ou, d'abandonner la recherche
int rechercher_nom(Repertoire *rep, char nom[], int ind); // recherche l'existance d'un contact et renvoie l'indice de sa position si trouv� ou -1 sinon
int rechercher_tel(Repertoire *rep, char tel[], int ind); // recherche l'existance d'un contact par no tel et renvoie l'indice de sa position si trouv� ou -1 sinon
int traiter_recherche(Repertoire *rep, int pos); // menu qui propose de supprimer le contact trouv�, de poursuivre la recherche ou de s'arreter 

int Saisir_chemin(char *message, char *buffer); // demande de saisie au clavier d'un chemin pour un fichier de sauvegarde, fait appel � saisie_chaine()
int sauvegarder(Repertoire *rep, char nom_fichier[]); // sauvegarde tout le r�pertoire en m�moire vers un fichier en rempla�ant l'ancien fichier




#define REPERTOIRE
#endif