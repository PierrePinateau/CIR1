/**********************************************************************/
/* rep.c  ****  CIR  1              *****  Répertoire téléphonique  ***/
/**********************************************************************/
/*                                                                    */
/*                                                                    */
/*                                                                    */
/*                                                                    */
/*                                                                    */
/**********************************************************************/
/* REMARQUE: le fichier de donnees est au format suivant :            */
/*      nom;prenom;no_de_telephone1                                   */
/*      nom2;prenom2;no_de_telephone2                                 */
/*      ...                                                           */
/* soit un enregistrement de 3 champs separe par ';' par ligne        */
/* si on utilise un autre fichier de donnees que rep.txt, il faut     */
/* passer son nom en parametre à l'appel du programme                 */
/**********************************************************************/

#include "rep.h"


/* flag de modification du répertoire : indique si le tableau de contacts été modifié     */
/* Permet notamment de décider s'il sauvegarder le répertoire dans un fichier             */
int modif = FAUX;

/* fichier texte de sauvegarde des contacts */
char nom_fichier[MAX_NOM_FICHIER];

/* messages à l'intention de l'utilisateur  */
char mess1[] = "\nn'existe pas dans le repertoire.\n";
char mess2[] = "\nPlus d'autre %s dans le repertoire\n";


/*****************************************************************************/
/*                        programme principal : main                         */
/*****************************************************************************/

void main(int argc, char *argv[])
{

	char choix;						/* caractere de l'option choisie dans menu */
	Repertoire repertoire;			/* le repertoire en memoire */

	if (argc == 1)
	{
		strcpy_s(nom_fichier, _countof(nom_fichier), "rep.txt");	/* nom du fichier par defaut */
	}
	else
	{
		strcpy_s(nom_fichier, _countof(nom_fichier), (char *)argv[1]);	/* nom du fichier utilisateur */
	}
	if (init_rep(&repertoire) <0) return;
	/* intialise le nombre d’éléments à zéro, alloue la mémoire du répertoire, charge le fichier et le trie */

	afficher_menu_principal();

	do								/* lecture menu principal */
	{							/* tant que pas demande pour Quitter */
		do
		{						/* lecture touche frappee au clavier */
			choix = (char)toupper(_getch());
		} while ((choix != 'A') && (choix != 'X') && (choix != 'J') && (choix != 'R'));

		switch (choix)
		{
		case 'A':
			affichage_repertoire(&repertoire);
			break;
		case 'J':
			option_ajouter(&repertoire);
			break;
		case 'R':
			option_rechercher(&repertoire);
			break;
		}
		afficher_menu_principal();
	} while (choix != 'X');

	if (modif)					/* Si modification apportee au repertoire */
	{						/* on propose une sauvegarde */
		printf("\n Enregistrer modification ? O/N");
		do
		{
			choix = (char)toupper(_getch());
		} while ((choix != 'O') && (choix != 'N'));

		if (choix == 'O')
		{
			printf("\n Enregistrer sous %s ? O/N", nom_fichier);
			do
			{
				choix = (char)toupper(_getch());
			} while ((choix != 'O') && (choix != 'N'));

			if (choix == 'N') Saisir_chemin("Nom du fichier: ?", nom_fichier);
			sauvegarder(&repertoire, nom_fichier);
		}
	}
	printf("\nBye !\n\n");


	return;
}
/*****************************FIN du programme principal*********************/


/********************************************************************************/
/* initialisation d'un répertoire                                               */
/* prend en paramètre un pointeur vers le répertoire à initialiser              */
/* intialise le nombre d’éléments à zéro, charge le fichier et le trie          */
/********************************************************************************/

int init_rep(Repertoire *rep)
{
	/* fonction complète : ne pas modifier pour implémentation en tableau*/
	int errno;
	void * tmpPtr;
	rep->nb_elts = 0;
	rep->est_trie = VRAI; /* un répertoire vide est trié :-) */
#ifdef IMPL_TAB
						  // code pour tableau

	tmpPtr = (void *)malloc(MAX_ENREG * sizeof(Enregistrement));
	if (tmpPtr != NULL) {
		rep->tab = (Enregistrement *)tmpPtr;
	}
	else return(-1);
#else
#ifdef IMPL_LIST
						  // ajouter code ici pour Liste
	tmpPtr = (void *)malloc(sizeof(LinkedList));
	rep->Liste = (LinkedList *)tmpPtr;
#endif
#endif
	errno = charger(rep, nom_fichier);

	if ((errno == OK) && (rep->nb_elts > 0))
	{
		rep->est_trie = FAUX;
		trier(rep);
	}
	return(0);
} /* fin init_rep */

  /**************************************************************************/
  /*  Lecture d'une chaîne de caractères depuis le clavier.                 */
  /*  Elle est stockée dans le tableau de char passé en paramètre           */
  /*   La longueur max à lire est donnée en second paramètre                */
  /*   Elle renvoie la longueur de la chaine et une longueur négative s'il  */
  /*   y a eu un problème                                                   */
  /**************************************************************************/
int saisie_chaine(char c[], int max)
{
	/* fonction complète : ne pas modifier */
	int l;

	/* saisie en rangeant dans tableau c */
	if (fgets(c, max, stdin) == NULL)                   /* lecture des caractères sur entrée standard= clavier */
		return -1;										/* s'il y a une erreur, on renvoie -1                  */

	l = strlen(c);									    /* calcul de la longueur de la chaine */

	if (c[l - 1] == '\n')								/* suppression du retour chariot            */
	{												    /* en fin de chaîne s'il est présent        */
		c[l - 1] = '\0';                                /* écriture d'un caractère de fin de chaine */
		l--;
	}
	return l;											/* on retourne la longueur */
} /* fin saisie_chaine */

  /**************************************************************************/
  /* saisie d'un enregistrement (contact)                                   */
  /* l'élément saisi est stocké dans l'enregistrement pointé par le         */
  /* parametre enr                                                          */
  /* la fonction renvoie OK si l'élément est correctement saisie et         */
  /* ERROR s'il y a eu un problème...                                       */
  /**************************************************************************/

int saisie_enreg(Enregistrement *enr)
{
	char tmp[MAX_SAISIE];
	int l;

	printf("Nom :");
	if ((l = saisie_chaine(tmp, MAX_SAISIE)) < 0)
		return ERROR;
	/* chaine vide ? */
	if (l == 0)
	{
		printf("nom vide...\n");
		return ERROR;
	}
	/* chaine trop longue ? */
	if (l >= MAX_NOM)
	{
		printf("nom trop long...\n");
		return ERROR;
	}
	/* on copie dans le champ nom... */
	strcpy_s(enr->nom, _countof(enr->nom),tmp);

	printf("Prenom :");
	if ((l = saisie_chaine(tmp, MAX_SAISIE)) < 0)
		return ERROR;
	/* chaine vide ? */
	if (l == 0)
	{
		printf("prenom vide...\n");
		return ERROR;
	}
	/* chaine trop longue ? */
	if (l >= MAX_NOM)
	{
		printf("prenom trop long...\n");
		return ERROR;
	}
	/* on copie dans le champ nom... */
	strcpy_s(enr->prenom,_countof(enr->prenom), tmp);

	printf("Telephone :");
	if ((l = saisie_chaine(tmp, MAX_SAISIE)) < 0)
		return ERROR;
	/* chaine vide ? */
	if (l == 0)
	{
		printf("telephone vide...\n");
		return ERROR;
	}
	/* chaine trop longue ? */
	if (l >= MAX_TEL)
	{
		printf("telephone trop long...\n");
		return ERROR;
	}
	/* on copie dans le champ nom... */
	strcpy_s(enr->tel, _countof(enr->tel), tmp);

	return OK;
} /* fin saisie_enreg */


  /********************************************************************************/
  /*  Affichage paginé du repertoire par façon 'more'                             */
  /********************************************************************************/
void affichage_repertoire(Repertoire *rep)
{
	int idx = 0;							/* Index sur enregistrement courant */
	int cpt = LIGNES_PAR_PAGE;				/* Compteur de ligne affichees */
	char key = 0;							/* Controle de l'affichage */
	

	trier(rep);


#ifdef IMPL_TAB
	while ((idx < rep->nb_elts) && (key != 'X'))
	{
		if (cpt > 0)						/* S'il reste des lignes a afficher */
		{								/* dans la page */
			affichage_enreg_frmt(rep->tab[idx]);	/* Affichage enrg courant */
			idx++;							/* On passe au suivant */
			cpt--;							/* Une ligne de moins a afficher */
		}
		else
		{	/* si page cplte affichee, on attend la suite */
			do
			{
				printf("\n\n_____________________________ entree/espace/x ___ :\n");
				key = (char)toupper(_getch());
				cpt = (key == 13) ? 1 : LIGNES_PAR_PAGE;
			} while ((key != ' ') && (key != 13) && (key != 'X'));
		}

	}
#else
#ifdef IMPL_LIST
	LinkedList *toPlot;
	toPlot = rep->Liste;
	while ((idx < rep->nb_elts) && (key != 'X'))
	{

		if (cpt > 0 && toPlot!=NULL)							/* S'il reste des lignes a afficher */
		{										/* dans la page */
			affichage_enreg_frmt(toPlot->enr);	/* Affichage enrg courant */
			toPlot = toPlot->next;
			idx++;							/* On passe au suivant */
			cpt--;							/* Une ligne de moins a afficher */
		}
		else
		{	/* si page cplte affichee, on attend la suite */
			do
			{
				printf("\n\n_____________________________ entree/espace/x ___ :\n");
				key = (char)toupper(_getch());
				cpt = (key == 13) ? 1 : LIGNES_PAR_PAGE;
			} while ((key != ' ') && (key != 13) && (key != 'X'));
		}
	}
#endif //IMPL_LIST
#endif // IMPL_TAB

	
} /* fin affichage_repertoire */


  /**********************************************************************/
  /* Recherche par no de telephone avec compactage du no                */
  /**********************************************************************/
int rechercher_tel(Repertoire *rep, char tel[], int ind)
{
#ifdef IMPL_TAB
	int i = ind;
	int ind_fin;

	char tmp_tel[MAX_TEL];
	char tmp_tel2[MAX_TEL];
	int trouve = FAUX;

	ind_fin = rep->nb_elts - 1;
	strcpy_s(tmp_tel, _countof(tmp_tel), tel);
	compact(tmp_tel);

	while ((i <= ind_fin) && (!trouve))
	{
		strcpy_s(tmp_tel2, _countof(tmp_tel2), rep->tab[i].tel);
		compact(tmp_tel2);
		if (strcmp(tmp_tel, tmp_tel2) == 0)
			trouve = VRAI;
		else
			i++;
	}

	return((trouve) ? i : -1);
#else
#ifdef IMPL_LIST
	int i = ind;
	int ind_fin;

	LinkedList *toCompart = rep->Liste;

	char tmp_tel[MAX_TEL];
	char tmp_tel2[MAX_TEL];
	int trouve = FAUX;

	ind_fin = rep->nb_elts - 1;
	strcpy_s(tmp_tel, _countof(tmp_tel), tel);
	compact(tmp_tel);

	while ((i <= ind_fin) && (!trouve))
	{
		strcpy_s(tmp_tel2, _countof(tmp_tel2), toCompart->enr.tel);
		compact(tmp_tel2);
		if (strcmp(tmp_tel, tmp_tel2) == 0)
			trouve = VRAI;
		else
			i++;
		toCompart = toCompart->next;
	}

	return((trouve) ? i : -1);


#endif // IMPL_LIST
#endif // IMPL_TAB

	
} /* fin rechercher_tel */


  /***********************************************************************************************************/
  /*                                                                                                         */
  /*  Lecture de champs contenus dans les lignes du fichier                                                  */
  /*  - ligne: pointeur sur un buffer qui contient la ligne lue dans le fichier et terminée par une zéro     */
  /*  - idx: pointeur sur un entier qui indique la position courante de la recherche dans la ligne           */
  /*  - champ: pointeur sur la variable à renseigner avec les informations trouvées entre deux séparateurs   */
  /*  - taille_champ : la taille du champ à ne pas dépasser                                                  */
  /*  - separateur : le caractère utilisé comme séparateur                                                   */
  /***********************************************************************************************************/

int lire_champ_suivant(char *ligne, int *idx, char *champ, int taille_champ,
	char separateur)
{

	int idx2 = 0;

	while ((idx2 < (taille_champ - 2)) && (ligne[*idx] != separateur)
		&& (ligne[*idx] != '\0'))
	{
		champ[idx2] = ligne[*idx];
		idx2 += 1;
		*idx += 1;
	}
	if ((ligne[*idx] == separateur) || (ligne[*idx] == '\0'))
	{
		champ[idx2] = 0;	/* fin de chaine sur caractere suivant */
		return(OK);
	}
	else return(ERROR);		/* fin de ligne ou séparateur non atteints */

} /* fin lire_champ_suivant() */


  /**********************************************************************/
  /*    Affichage du sous menu rechercher                               */
  /**********************************************************************/

void afficher_menu_recherche()
{
	printf("\n\n Recherche :\n\n");
	printf("\n\t par (N)om");
	printf("\n\t par (T)elephone");
	printf("\n\t\te(X)it\n");
	return;
}
/**********************************************************************/
/*                                                                    */
/* traiter_rechercher proposer de supprimer l element trouve          */
/* et demande s'il faut poursuivre ou  non la recherche               */
/**********************************************************************/

int traiter_recherche(Repertoire *rep, int pos)
{
	char key = 0;
#ifdef IMPL_TAB
	affichage_enreg(rep->tab[pos]);
	do
	{
		printf("\n\n_____________________________ /espace/(D)elete/e(X)it ___ :\n");
		key = (char)toupper(_getch());
	} while ((key != ' ') && (key != 'D') && (key != 'X'));

	switch (key)
	{
	case ' ':
		return(VRAI);
		break;
	case 'X':
		return(FAUX);
		break;
	case 'D':
		supprimer_un_contact_dans_rep(rep, pos);

		break;
	}
	return(FAUX);
#else
#ifdef IMPL_LIST
	LinkedList *list = rep->Liste;
	for (size_t i = 0; i < pos; i++)
	{
		list = list->next ;
	}
	affichage_enreg(list->enr);
	do
	{
		printf("\n\n_____________________________ /espace/(D)elete/e(X)it ___ :\n");
		key = (char)toupper(_getch());
	} while ((key != ' ') && (key != 'D') && (key != 'X'));

	switch (key)
	{
	case ' ':
		return(VRAI);
		break;
	case 'X':
		return(FAUX);
		break;
	case 'D':
		supprimer_un_contact_dans_rep(rep, pos);

		break;
	}
	return(FAUX);
#endif // IMPL_LIST


#endif



}
/**********************************************************************/
/*  Traite l'option rechercher du menu principal                      */
/**********************************************************************/


void option_rechercher(Repertoire *rep)
{
	char choix;

	int ind;			/* Indice de debut de la recherche ds tableau */
	int pos;			/* Position ds le tableau ou l'element a ete trouve */
	char nom[MAX_NOM];	/* Les chaines recherchees */
	char tel[MAX_TEL];
	int suite = FAUX;			/* VRAI si recherche du suivant, FAUX si on arrete*/

	if (rep->nb_elts <= 0)
	{
		printf("\nRepertoire vide ...\n");
		return;
	}
	afficher_menu_recherche();
	do
	{

		ind = 0;						/* la recherche reprend depuis le debut du tableau */
		suite = FAUX;				/**/
		do
		{						/* lecture touche frappee au clavier */
			choix = (char)toupper(_getch());
		} while ((choix != 'N') && (choix != 'T') && (choix != 'X'));

		switch (choix)
		{
		case 'N':
			printf("\nNom ? :");
			saisie_chaine(nom, MAX_NOM);


			do
			{
				pos = rechercher_nom(rep, nom, ind);

				if (pos >= 0)
				{
					ind = pos + 1;
					suite = traiter_recherche(rep, pos);
				}
				else
				{
					if (suite == VRAI) printf(mess2, nom);	/* Plus de nouvelle occurence */
					else printf(mess1);						/* Pas d'occurence trouvee la premiere fois*/
					suite = FAUX;								/* On arrete la recherche */
				}

			} while (suite);
			break;
		case 'T':
			printf("\nTel ? :");
			saisie_chaine(tel, MAX_TEL);

			do
			{
				pos = rechercher_tel(rep, tel, ind);

				if (pos >= 0)
				{
					ind = pos + 1;
					suite = traiter_recherche(rep, pos);
				}
				else
				{
					if (suite == VRAI) printf(mess2, tel);	/* Plus de nouvelle occurence */
					else printf(mess1);						/* Pas d'occurence trouvee la premiere fois*/
					suite = FAUX;								/* On arrete la recherche */
				}
			} while (suite);
			break;
		}
		afficher_menu_recherche();
	} while (choix != 'X');

	return;
}

/**********************************************************************/
/* ajoute  un contact au répertoire                                   */
/**********************************************************************/

void option_ajouter(Repertoire *rep)
{
	Enregistrement tmpenr;
	if (saisie_enreg(&tmpenr))
		if (!ajouter_un_contact_dans_rep(rep, tmpenr))
			printf("\nAjout impossible !! \n");

	return;
}
/**********************************************************************/
/*  Demande de saisie d'un chemin de fichier						  */
/**********************************************************************/

int Saisir_chemin(char *message, char *buffer)
{
	printf("\n%s\n", message);
	saisie_chaine(buffer, MAX_NOM_FICHIER);
	printf("\n");
	return(OK);
}



/**********************************************************************/
/* Affichage du menu principal                                        */
/**********************************************************************/

void afficher_menu_principal()
{
	printf("\n\n Repertoire :");
	printf("\n\n\t(A)fficher tout");
	printf("\n\ta(J)outer une personne");
	printf("\n\trecherche(R)e une personne");
	printf("\n\n\t\te(X)it\n");
}

/**********************************************************************/


