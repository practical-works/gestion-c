#include<stdio.h>
#include "Gestion.h"
int main() // Fonction principal
{
	struct entite liste[100];
	int taille = 0, choix;
	start:
	system("title Programme de Gestion"); system("color 17");
	printf("Gestion d'une liste d'elements:\n\n");
	printf("\t*--------------------------------------------------------*\n"); 
	printf("\t|  1. Nouveau    |  5. Rechercher    |  9. Afficher      |\n");
	printf("\t|  2. Ajouter    |  6. RechercheAV   |  10. Sauvegarder  |\n");
	printf("\t|  3. Modifier   |  7. Trier         |  11. Charger      |\n");
	printf("\t|  4. Supprimer  |  8. TriAV         |  12. Quitter      |\n");
	printf("\t*--------------------------------------------------------*\n\n");
	printf("=> Entrer choix: "); scanf("%d",&choix);
	switch(choix)
	{
		int code, p, ordre;
		char* nom, nom_fichier[100];
		case 1: // Créer une nouvelle liste d’éléments
	 		nouveau(liste,taille);
	 		lire_liste(liste, &taille);
			break;
		case 2: // Ajouter un nouvel élément à la liste
	 		ajouter(liste, &taille);
			break;
		case 3: // Modifier un élément existant dans la liste
	 		modifier(liste, taille);
			break;
		case 4: // Supprimer un élément existant dans la liste
	 		supprimer(liste, &taille);
			break;
		case 5: // Rechercher un élément par attribut clé
			
	 		printf("\tEntrer code: "); scanf("%d",&code);
	 		p = rechercher(liste,taille,code);
	 		if(p == -1) printf("Code introuvable!");
	 		else afficher(liste[p]);
			break;
		case 6: // Rechercher des éléments par un attribut non-clé
	 		
	 		printf("\tEntrer nom: "); scanf("%s",nom);
	 		p = rechercheAV(liste,taille,nom);
	 		if(p == -1) printf("Nom introuvable!");
	 		else afficher(liste[p]);
			break;
		case 7: // Trier les éléments par un attribut clé
			do
			{
				printf("Tri numerique par code:\n");
				printf("\t*----------------------*\n");
			  	printf("\t| 1. Ordre croissant   |\n");
				printf("\t| 2. Ordre decroissant |\n");
				printf("\t| 3. Retour            |\n");
				printf("\t*----------------------*\n");
				printf("=> Entrer choix: "); scanf("%d",&ordre);
				ordre--;
				switch(ordre)
				{
					case 0 || 1: trier(liste,taille,ordre); break;
					case 2: break;
					default: printf("Choix invalide!\n");
				}
			} while(ordre != 2);
			afficher_liste(liste,taille);
			break;
		case 8: // Trier les éléments par un attribut non-clé
			do
			{
				printf("Tri alphabetique par nom:\n");
				printf("\t*----------------------------*\n");				
			  	printf("\t| 1. Ordre croissant (A-Z)   |\n");
				printf("\t| 2. Ordre decroissant (Z-A) |\n");
				printf("\t| 3. Retour                  |");
				printf("\t|*---------------------------*\n");
				printf("=> Entrer choix: "); scanf("%d",&ordre);
				ordre--;
				switch(ordre)
				{
					case 0 || 1: triAV(liste,taille,ordre); break;
					case 2: break;
					default: printf("Choix invalide!\n");
				}
			} while(ordre != 2);
			afficher_liste(liste,taille);
			break;
		case 9: // Afficher un ou plusieurs éléments de la liste selon un filtre
	 		afficher_liste(liste,taille);
			break;
		case 10: // Enregistrer la liste dans un fichier
	 		if(nom_fichier == NULL)
	 		{
	 			printf("---> Entrer nom fichier: "); fflush(stdin); gets(nom_fichier);
			} 			
	 		sauvegarder(liste,taille,nom_fichier);
	 		printf("Liste sauvegardee.\n");
			break;
		case 11: // Récupérer la liste depuis un fichier
	 		if(nom_fichier == NULL)
	 		{
	 			printf("---> Entrer nom fichier: "); fflush(stdin); gets(nom_fichier);
			} 			 
	 		charger(liste,&taille,nom_fichier);
	 		printf("Liste chargee.\n");	 		
	 		afficher_liste(liste,taille);
			break;
		case 12: // Fermer l’application
			return 0;
		default: printf("Choix invalide!\n");
	}
	system("pause>null");
	system("cls");
	fflush(stdin);
	goto start;
}
