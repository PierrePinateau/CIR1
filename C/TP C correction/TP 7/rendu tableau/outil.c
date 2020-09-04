#include "rep.h"
/**************************************************************************/
/* Compléter votre nom ici                                                */
/*   Nom : DESPREZ                 Prénom :THIBAULT       CIR1 2015-2016  */
/**************************************************************************/


/**********************************************************************/
/*  Ajout d'un contact dans le répertoire stocké en mémoire           */
/**********************************************************************/

int ajouter_un_contact_dans_rep(Repertoire *rep, Enregistrement enr)
{
#ifdef IMPL_TAB
	// ajouter code ici pour tableau
	rep->tab[rep->nb_elts] = enr;
	compact(rep->tab[rep->nb_elts].tel);
	rep->nb_elts++;
	modif = VRAI;
	rep->est_trie = FAUX;
	trier(rep);
	return(OK);
#else
#ifdef IMPL_LIST
	// ajouter code ici pour Liste

#endif
#endif



	return(OK);
} /* fin ajout */
  /**********************************************************************/
  /* supprime du répertoire l'enregistrement dont l'indice est donné en */
  /*   paramètre       et place modif = VRAI                            */
  /**********************************************************************/

void supprimer_un_contact_dans_rep(Repertoire *rep, int indice)
{
#ifdef IMPL_TAB
	if (indice >= rep->nb_elts)
		return;
	for (size_t i = indice; i < rep->nb_elts; i++)
	{
		rep->tab[i] = rep->tab[i + 1];
	}
	rep->nb_elts--;
	modif = VRAI;


#else
#ifdef IMPL_LIST
	// ajouter code ici pour Liste
#endif
#endif
	return;
} /* fin supprimer */


  /**********************************************************************/
  /*  fonction d'affichage d'un enregistrement sur une ligne à l'écran  */
  /* ex Dupont, Jean                 0320304050                         */
  /**********************************************************************/
void affichage_enreg(Enregistrement enr)
{
	printf("%25s,%25s\t\t %s\n\n", enr.nom, enr.prenom, enr.tel);
} /* fin affichage_enreg */


  /**********************************************************************/
  /*  fonction d'affichage d'un enregistrement  avec alignement         */
  /* pour les listes                                                    */
  /* ex | Dupont                |Jean                  |0320304050      */
  /**********************************************************************/
void affichage_enreg_frmt(Enregistrement enr)
{
	printf("nom    : %s\n\
prenom : %s\n\
tel    : %s\n\
--------------------------------\n", enr.nom, enr.prenom, enr.tel);
} /* fin affichage_enreg */


  /**********************************************************************/
  /* test si dans l'ordre alphabetique, un enregistrement est apres     */
  /* un autre                                                           */
  /**********************************************************************/
int est_sup(Enregistrement enr1, Enregistrement enr2)
{
	int test = strcmp(enr1.nom, enr2.nom);
	if (test == 0 || test > 0)
		return(FAUX);
	else
		return(VRAI);

}

/*********************************************************************/
/*   Tri Alphabetique du tableau d'enregistrements					 */
/*********************************************************************/
void permutEnr(Enregistrement tableau[], int a, int b)
{
	Enregistrement tmp = tableau[a];
	tableau[a] = tableau[b];
	tableau[b] = tmp;
}

void trier(Repertoire *rep)
{

#ifdef IMPL_TAB
	// ajouter code ici pour tableau
	int pos = 0;
	while ((rep->est_trie == FAUX) && (pos < rep->nb_elts - 1))
	{
		if (est_sup(rep->tab[pos+1], rep->tab[pos])) {
			permutEnr(rep->tab, pos, pos + 1);
			pos = 0;
			continue;
		}
		pos++;
	}
	
#else
#ifdef IMPL_LIST
	// ajouter code ici pour Liste
#endif
#endif


	rep->est_trie = VRAI;

}/* fin trier */ 
 /*cette fonciton de tri n'est pas très économe en ressource et en temps
 mais elle est simple et elle marche */

  /**********************************************************************/
  /* recherche dans le répertoire d'un enregistrement correspondant au  */
  /*   nom à partir de l'indice ind                                     */
  /*   retourne l'indice de l'enregistrement correspondant au critère ou*/
  /*   un entier négatif si la recherche est négative				    */
  /**********************************************************************/

int rechercher_nom(Repertoire *rep, char nom[], int ind)
{
	int i = ind;		    /* position (indice) de début de recherche dans tableau/liste rep */
	int ind_fin;			/* position (indice) de fin de tableau/liste rep */

	char tmp_nom[MAX_NOM];	/* 2 variables temporaires dans lesquelles */
	char tmp_nom2[MAX_NOM];	/* on place la chaine recherchee et la chaine lue dans le */
	int trouve = FAUX;		/* tableau, afin de les convertir en majuscules et les comparer */


#ifdef IMPL_TAB
							// ajouter code ici pour tableau
	strcpy_s(tmp_nom, MAX_NOM, nom);
	toupper(tmp_nom);
	for (size_t i = 0; i < rep->nb_elts; i++)
	{
		strcpy_s(tmp_nom2, MAX_NOM, rep->tab[i].nom);
		toupper(tmp_nom2);
		if (strcmp(tmp_nom, tmp_nom2) == 0)
		{
			return i;
		}
	}

#else
#ifdef IMPL_LIST
							// ajouter code ici pour Liste
#endif
#endif

	return((trouve) ? i : -1);
} /* fin rechercher_nom */

  /*********************************************************************/
  /* Supprimer tous les caracteres non numériques de la chaines        */
  /*********************************************************************/
void compact(char *s)
{
	for (size_t i = 0; i < strlen(s); i++)
	{
		if (!isdigit(s[i]))
		{
			for (size_t j = i; j < strlen(s); j++)
				s[j] = s[j + 1];
			i--;
		}
	}

	return;
}

/**********************************************************************/
/* sauvegarde le répertoire dans le fichier dont le nom est passé en  */
/* argument                                                           */
/* retourne OK si la sauvegarde a fonctionné ou ERROR sinon           */
/**********************************************************************/
int sauvegarder(Repertoire *rep, char nom_fichier[])
{
	FILE *fic_rep;					/* le fichier */
#ifdef IMPL_TAB
	// ajouter code ici pour tableau
	trier(rep);
	char *tmp = malloc(sizeof(char)*sizeof(Enregistrement));
	int openSucces = fopen_s(&fic_rep, nom_fichier, "w");
	if(!openSucces)
		for (size_t i = 0; i < rep->nb_elts; i++)
		{
			sprintf_s(tmp, MAX_NOM + MAX_NOM + MAX_TEL, "%s%c%s%c%s%c\n",
				rep->tab[i].nom, 
				SEPARATEUR,
				rep->tab[i].prenom,
				SEPARATEUR,
				rep->tab[i].tel,SEPARATEUR);
			fputs(tmp, fic_rep);
		}
	fclose(fic_rep);

#else
#ifdef IMPL_LIST
	// ajouter code ici pour Liste
#endif
#endif

	return(OK);
} /* fin sauvegarder */


  /**********************************************************************/
  /*   charge dans le répertoire le contenu du fichier dont le nom est  */
  /*   passé en argument                                                */
  /*   retourne OK si le chargement a fonctionné et ERROR sinon         */
  /**********************************************************************/

int charger(Repertoire *rep, char nom_fichier[])
{
	FILE *fic_rep;					/* le fichier */
	errno_t err;
	int num_rec = 0;						/* index sur enregistrements */
	int long_max_rec = sizeof(Enregistrement);
	char buffer[sizeof(Enregistrement) + 1];
	int idx = 0;

	char *char_nw_line;

	_set_errno(0);
	if ((err = fopen_s(&fic_rep, nom_fichier, "r")) != 0)
	{
		return(err);
	}
	else
	{
		while (!feof(fic_rep) && (rep->nb_elts < MAX_ENREG))
		{
			if (fgets(buffer, long_max_rec, fic_rep) != NULL)
			{
				/* memorisation de l'enregistrement lu dans le tableau */
				buffer[long_max_rec] = 0;			/* en principe il y a deja un fin_de_chaine, cf fgets */

				if ((char_nw_line = strchr(buffer, '\n')) != NULL)
					*char_nw_line = '\0';			/* suppression du fin_de_ligne eventuel */

				idx = 0;								/* analyse depuis le debut de la ligne */
#ifdef IMPL_TAB
				if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].nom, MAX_NOM, SEPARATEUR) == OK)
				{
					idx++;							/* on saute le separateur */
					if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].prenom, MAX_NOM, SEPARATEUR) == OK)
					{
						idx++;
						if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].tel, MAX_TEL, SEPARATEUR) == OK)
							num_rec++;		/* element à priori correct, on le comptabilise */
					}
				}
#else
#ifdef IMPL_LIST
														// ajouter code implemention liste
#endif
#endif




			}

		}
		rep->nb_elts = num_rec;
		fclose(fic_rep);
		return(OK);
	}


} /* fin charger */