/**
  * CS351 - Corrections de TP 2016-2017
  * Projet TP5-1
  * fctTri.c
  * Eva Gerbert-Gaillard
  */

#include "fctTri.h"

int lireDonnees(char nomFichier[], int T[]) {
	int i=0;
	FILE * donnees;

	/*Ouverture en lecture*/
	printf("nomFichier = %s\n", nomFichier);
	donnees = fopen(nomFichier , "r");		

	/*Gestion d'erreurs à l'ouverture*/
	if (donnees == NULL)  {
		perror("Probleme lors de l'ouverture du fichier pour la lecture\n");
		exit(EXIT_FAILURE);
	}
	
	/*Lecture jusqu'à la fin du fichier*/
	while(!feof(donnees)) {
		fscanf(donnees, "%d", &T[i]);
		i++;
	}

	/*Fermeture*/
	fclose(donnees);

	return (i-1); 
	/*i-1 car feof devient vrai qu'une fois qu'on a essayé de lire au-delà de la fin du fichier*/
}


void afficherTableau(int T[], int nb) {
	int i;
	printf("Contenu du tableau (de N = %d valeurs) :\n", nb);

	for (i=0; i<nb; i++) {
		printf("%4d", T[i]);
	}
	printf("\n");
}


void triABulles (int T[], int nb) {
	int i,j,t; /*t variable tamporaire de transfert*/


	/*Pour faire "remonter" les éléments les plus "légers"(faible valeur) vers la "surface"(début du tableau)*/
	for (i=0; i<nb; i++) {		
		/*Il faut faire nb passage dans le tableau*/
		/*Chaque itération de cette boucle correspond à la remontée de la valeur la plus légère*/
		/*Tous les éléments avant le i-ème ont déjà été triés, on compare 2 éléments successifs*/
		for (j=(nb-1); j>i; j--) {	
				if (T[j]<T[j-1]) {	/*Si T[j+1] est plus "léger" que T[j]*/
					t = T[j-1];		/*Permutation locale de 2 valeurs*/
					T[j-1] = T[j];
					T[j] = t;
				}
		}
	}
}


void enregistrerDonnees(char nomFichier[], int T[], int nb) {
	int i;
	FILE * resultats;
	
	/*Ouverture en écriture*/
	resultats = fopen( nomFichier, "w");

	/*Gestion d'erreurs à l'ouverture*/
	if (resultats == NULL)  {
		perror("Probleme lors de l'ouverture du fichier pour l'écriture\n");
		exit(EXIT_FAILURE);
	}

	/*Ecriture du tableau dans le fichier*/
	for (i=0; i<nb; i++) {
		fprintf(resultats, "%d\n", T[i]);
	}

	/*Fermeture*/
	fclose(resultats);
}
