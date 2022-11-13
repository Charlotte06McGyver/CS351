/**
  * CS351 - Corrections de TP 2016-2017
  * Projet TP4-3
  * fctMatrice.c
  * Eva Gerbert-Gaillard
  */

#include "fctMatrice.h"

void afficherMatrice(int A[M][M], int n, int m) {
	int i, j;

	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			printf("%d\t", A [i][j]);
		}
		printf("\n");
	}
}

/*Contrainte : mêmes dimensions*/
/*Résultat attendu pour l'exemple tp : {{3 -3 5}{4 10 -3}}*/
void additionnerMatrice(int A[M][M], int B [M][M], int n, int m) {
	int RES [M][M];
	int i, j;

	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			RES [i][j] = A[i][j] + B[i][j];
		}
	}
	for (i=0; i<2; i++) {
		for (j=0; j<3; j++) {
			printf("%d\t", RES [i][j]);
		}
		printf("\n");
	}
}

/*Taille de la matrice résultat pour l'exmeple TP : 2 colonnes par 3 lignes*/
void transposee(int A[M][M], int n, int m) {
	int RES [M][M];
	int i, j;

	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			RES [j][i] = A[i][j];
		}
	}
	for (i=0; i<3; i++) {
		for (j=0; j<2; j++) {
			printf("%d\t", RES [i][j]);
		}
		printf("\n");
	}
}

/*Pour faire le produit AB il faut que le nombre de colonnes de A soit égale au nombre de lignes de C => MANB */
/*RES aura na lignes et mb colonnes*/
void produitMatriciel(int A[M][M], int na, int MANB, int C [M][M], int mb) {
	int RES [M][M];
	int i,j,k;
	int somme;

	for (i=0; i<na; i++) {
		for (j=0; j<mb; j++) {
			RES [i][j] = 0;
			for (k=0; k<MANB; k++) {
				RES [i][j] = RES[i][j] + A[i][k]*C[k][j];
			}
		}
	}
	for (i=0; i<2; i++) {
		for (j=0; j<2; j++) {
			printf("%d\t", RES [i][j]);
		}
		printf("\n");
	}
}
