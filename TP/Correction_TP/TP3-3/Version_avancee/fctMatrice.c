/**
  * CS351 - Corrections de TP 2016-2017
  * Projet TP4-3
  * fctMatrice.c
  * Eva Gerbert-Gaillard
  */

#include "fctMatrice.h"

void initMatrice(int A[DIM_MAX][DIM_MAX]){
	int i, j;
	for (i=0; i<DIM_MAX; i++) {
		for (j=0; j<DIM_MAX; j++) {
			matrice [i][j] = 0;
		}
	}
}

int checkDimensions (int lignes, int colonnes){
	int ok = 0;
	if (lignes>0 && lignes<=DIM_MAX && colonnes>0 && colonnes<=DIM_MAX){
		ok = MATRICE_OK;
	}
	return ok;
}


int afficherMatrice(int A[DIM_MAX][DIM_MAX], int lignes_a, int colonnes_a) {
	int i, j;
	int ok = 0;
	
	/*Check taille matrice*/
	ok = checkDimensions(lignes_a, colonnes_a);
	
	/*Affichage*/
	if(ok == MATRICE_OK) {
		for (i=0; i<lignes_a; i++) {
			for (j=0; j<colonnes_a; j++) {
				printf("%d\t", A [i][j]);
			}
			printf("\n\n");
		}
	} 
	
	return ok;
}

/*Contrainte : mêmes dimensions*/
/*Résultat attendu pour l'exemple tp : {{3 -3 5}{4 10 -3}}*/
/*Taille de la matrice résultats : mêmes dimensions*/
int additionnerMatrice(int A[DIM_MAX][DIM_MAX], int lignes_a, int colonnes_a, int B[DIM_MAX][DIM_MAX],  int lignes_b, int colonnes_b, int RES[DIM_MAX][DIM_MAX], int* lignes_res, int* colonnes_res) {
	int i, j;
	int ok, ok_a, ok_b;
	ok = MATRICE_OK;
	/*Check taille matrices*/
	ok_a = checkDimensions(lignes_a, colonnes_a);
	if(ok_a != MATRICE_OK){
		ok = ok_a;
	}
	ok_b = checkDimensions(lignes_b, colonnes_b);
	if(ok_b != MATRICE_OK){
		ok = ok_b;
	}
	
	/*Check possibilité de somme*/
	if(lignes_a != lignes_b && colonnes_a != colonnes_b){
		ok = SOMME_IMPOSSIBLE;
	}
	
	/*Addition*/
	*lignes_res = lignes_a;
	*colonnes_res = colonnes_a;
	if(ok == MATRICE_OK) {
		for (i=0; i<lignes_a; i++) {
			for (j=0; j<colonnes_a; j++) {
				RES [i][j] = A[i][j] + B[i][j];
			}
		}
	}
	
	return ok;
}

/*Taille de la matrice résultat pour l'exmeple TP : 2 colonnes par 3 lignes*/
/*Taille des lignes et des colonnes inversées*/
int transposee(int A[DIM_MAX][DIM_MAX], int lignes_a, int colonnes_a, int RES[DIM_MAX][DIM_MAX], int* lignes_res, int* colonnes_res) {
	int i, j;
	int ok = 0;
	
	/*Check taille matrice*/
	ok = checkDimensions(lignes_a, colonnes_a);
	
	/*Transposée*/
	*lignes_res = colonnes_a;
	*colonnes_res = lignes_a;
	if(ok == MATRICE_OK) {
		for (i=0; i<lignes_a; i++) {
			for (j=0; j<colonnes_a; j++) {
				RES [j][i] = A[i][j];
			}
		}
	}
	
	return ok;
}

/*Contrainte : nombre de colonnes de la 1ère matrice = nombre de lignes de la 2ème matrice */
/*Taille de la matrice résultat pour l'exemple TP : 2 colonnes par 2 lignes*/
/*Taille de la matrice résultats : */
/*	nombre de lignes du résultat = nombre de ligne de la 1ère matrice*/
/*	nombre de colonnes du résultat = nombre de colonnes de la 2ème matrice*/
int produitMatriciel(int A[DIM_MAX][DIM_MAX], int lignes_a, int colonnes_a, int C[DIM_MAX][DIM_MAX], int lignes_c, int colonnes_c, int RES[DIM_MAX][DIM_MAX], int* lignes_res, int* colonnes_res) {
	int i,j,k;
	int ok, ok_a, ok_c;
	ok = MATRICE_OK;
	
	/*Check taille matrices*/
	ok_a = checkDimensions(lignes_a, colonnes_a);
	if(ok_a != MATRICE_OK){
		ok = ok_a;
	}
	ok_c = checkDimensions(lignes_c, colonnes_c);
	if(ok_c != MATRICE_OK){
		ok = ok_c;
	}
	
	/*Check possibilité de produit*/
	if(colonnes_a != lignes_c){
		ok = PRODUIT_IMPOSSIBLE;
	}
	
	/*Produit*/
	*lignes_res = lignes_a;
	*colonnes_res = colonnes_c;
	if(ok == MATRICE_OK) {
		/*colonnes_a = lignes_c*/
		for (i=0; i<lignes_a; i++) {
			for (j=0; j<colonnes_c; j++) {
				RES [i][j] = 0;
				for (k=0; k<colonnes_a; k++) {	
					RES [i][j] = RES[i][j] + A[i][k]*C[k][j];
				}
			}
		}
	}
	
	return ok;
}
