#include<stdio.h>
#include<string.h>
struct entite // Entité Principale
{
	int code;
	char nom[100];
	float valeur;
};
void nouveau(struct entite E[], int N) // Initialiser les éléments de la liste
{
	int i;
	for(i=0; i<N; i++)
	{
		E[i].code = 0;
		strcpy(E[i].nom,"");
		E[i].valeur = 0;
	}
}
int rechercher(struct entite E[], int N, int code) // Rechercher un élément par attribut clé
{
	int i;
	for(i=0; i<N; i++)
	{
		if(code == E[i].code)
		{
			return i;
		}
	}
	return -1;
}
int rechercheAV(struct entite E[], int N, char* nom) // Rechercher des éléments par un attribut non-clé
{
	int i;
	for(i=0; i<N; i++)
	{
		if(strcmp(nom,E[i].nom) == 0)
		{
			return i;
		}
	}
	return -1;
}
void afficher(struct entite E) // Afficher un élément de type entité
{
	printf("%d \t\t| %s \t\t| %.2f\n", E.code,E.nom,E.valeur);
}
void afficher_liste(struct entite E[], int N) // Afficher tous les éléments de la liste
{
	int i;
	printf("-------------------------------------------------\n");
	printf("Code \t\t| Nom \t\t| Valeur\n");
	printf("-------------------------------------------------\n");
	for(i=0; i<N; i++)
	{
		afficher(E[i]);
	}
	printf("-------------------------------------------------\n");
}
void lire(struct entite E[], int N, struct entite* e) // Lire un élément pour l'ajouter à la liste
{
	int code, p;
		do
		{
			printf("\tEntrer code: "); scanf("%d",&code);
			p = rechercher(E,N,code);
			if(p != -1) printf("Code exite deja!\n");
		} while(p != -1);
		e->code = code;
		printf("\tEntrer nom: "); fflush(stdin); gets(e->nom); 
		printf("\tEntrer valeur: "); scanf("%f",&(*e).valeur);	
}
void lire_liste(struct entite E[], int* N) // Créer une liste et lire ses éléments à ajouter
{
	printf("---> Entrer taille liste: "); scanf("%d",&(*N));
	int i;
	for(i=0; i<*N; i++)
	{
		printf("[*] Entrer entite %d:\n", i+1);
		lire(E, *N, &E[i]);
	}
}
void ajouter(struct entite E[], int* N) // Insérer un nouveau élément dans la liste
{
	int i, p;
	do
	{
		printf("---> Entrer position [1,%d]: ", *N); scanf("%d",&p); 
		p--;
		if(p < 0 || p > *N-1) printf("Position invalide!\n");
	} while(p < 0 || p > *N-1);
	for(i=*N; i>p; i--)
	{
		E[i] = E[i-1];
	}
	(*N)++;
	printf("[*] Entrer entite %d:\n", p+1);	
	lire(E, *N, &E[p]);
}
void modifier(struct entite E[], int N) // Modifier un élément existant dans la liste
{
	int code, p, c;
	printf("\tEntrer code: "); scanf("%d",&code);
	p = rechercher(E,N,code);
	if(p == -1) printf("Code introuvable!\n");
	else
	{
	 	do
	 	{
		  	afficher(E[p]);
		  	printf("\t*--------------------*\n");
			printf("\t| 1. Modifier nom    |\n");
			printf("\t| 2. Modifier valeur |\n");
			printf("\t| 3. Retour          |\n");
			printf("\t*--------------------*\n");
			printf("=> Entrer choix: "); scanf("%d",&c);
			switch(c)
			{
				case 1: printf("\tEntrer nom: "); scanf("%s", E[p].nom); break;
				case 2: printf("\tEntrer valeur: "); scanf("%f", &E[p].valeur); break;
				case 3: break;
				default: printf("Choix invalide!\n");
			}
 		} while(c != 3);
	}
}
void supprimer(struct entite E[], int* N) // Supprimer un élément existant dans la liste
{
	int i, code, p;
	printf("\tEntrer code: "); scanf("%d", &code);
	p = rechercher(E,*N,code);
	if(p == -1) printf("Code introuvable!\n");
	else
	{
		for(i=p; i<*N; i++)
		{
			E[i] = E[i+1];
		}
		(*N)--;
	}
}
void trier(struct entite E[], int N, int ordre) // Trier les éléments par un attribut clé
{
	int i, j;
	struct entite tmp;
	for(i=0; i<N; i++)
	{
		for(j=i+1; j<N-1; j++)
		{
			if(ordre == 0) // Ordre croissant
			{
				if(E[i].code > E[j].code)
				{
					tmp = E[i];
					E[i] = E[j];
					E[j] = tmp;
				}
			} 
			else // Ordre décroissant
			{
				if(E[i].code < E[j].code)
				{
					tmp = E[i];
					E[i] = E[j];
					E[j] = tmp;
				}
			}
		}
	}
}
void triAV(struct entite E[], int N, int ordre) // Trier les éléments par un attribut non-clé
{
	int i, j;
	struct entite tmp;
	for(i=0; i<N; i++)
	{
		for(j=i+1; j<N-1; j++)
		{
			if(ordre == 0) // Ordre croissant
			{
				if(strcmp(E[i].nom,E[j].nom) > 0)
				{
					tmp = E[i];
					E[i] = E[j];
					E[j] = tmp;
				}
			} 
			else // Ordre décroissant
			{
				if(strcmp(E[i].nom,E[j].nom) < 0)
				{
					tmp = E[i];
					E[i] = E[j];
					E[j] = tmp;
				}
			}
		}
	}
}
void sauvegarder(struct entite E[], int N, char* nom_fichier) // Enregistrer la liste dans un fichier
{
	FILE* fichier = NULL;
	fichier = fopen(nom_fichier,"w");
	if(fichier == NULL)
	{
		printf("Fichier inaccessible!\n");
	}
	else
	{
		int i;
		for(i=0; i<N; i++)
		{
			fprintf(fichier,"%d,%s,%f\n",E[i].code,E[i].nom,E[i].valeur);
		}
		fclose(fichier);
	}
}
void charger(struct entite E[], int* N, char* nom_fichier) // Récupérer la liste depuis un fichier
{
	FILE* fichier = NULL;
	fichier = fopen(nom_fichier,"r");
	if(fichier == NULL)
	{
		printf("Fichier inaccessible!\n");
	}
	else
	{
		(*N) = 0;
		while(!feof(fichier))
		{
			fscanf(fichier,"%d,%s,%f\n",&E[*N].code,E[*N].nom,&E[*N].valeur);
			(*N)++;
		}
		(*N)--;
		fclose(fichier);
	}
}
