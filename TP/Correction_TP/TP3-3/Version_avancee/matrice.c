/**
  * CS351 - Corrections de TP 2016-2017
  * Projet TP4-3
  * matrice.c
  * Eva Gerbert-Gaillard
  */
  
#include <stdio.h>
#include <stdlib.h>

#include "fctMatrice.h"

int main () {
	/*Exemple d'implementation "felxible" sans structure et sans pointeurs */
	/* (sauf pour la taille du résultat, avec une utilisation à peine plus compliquée qu'un scanf) */
	int A[DIM_MAX][DIM_MAX]; 
	int lignes_a, colonnes_a;
	int B[DIM_MAX][DIM_MAX];
	int lignes_b, colonnes_b;
	int C[DIM_MAX][DIM_MAX];
	int lignes_c, colonnes_c;
	int RES[DIM_MAX][DIM_MAX];
	int lignes_res, colonnes_res;
	
	initMatrice(A);
	initMatrice(B);
	initMatrice(C);
	initMatrice(RES);
	
	lignes_a = 2;
	colonnes_a = 3;
	A[0][0] = 1; A[0][1] = 0; A[0][2] = 4;
	A[1][0] = -1; A[1][1] = 2; A[1][2] = -5;

	lignes_b = 2;
	colonnes_b = 3;
	B[0][0] = 2; B[0][1] = -3; B[0][2] = 1;
	B[1][0] = 5; B[1][1] = 8; B[1][2] = 2;
	
	lignes_c = 3;
	colonnes_c = 2;
	C[0][0] = 0; C[0][1] = 1; 
	C[1][0] = 2; C[1][1] = -1; 
	C[2][0] = 3; C[2][1] = 4; 
	
	lignes_res = 0;
	colonnes_res = 0;

	
	printf("Matrice A :\n");
	afficherMatrice (A, lignes_a, colonnes_a);
	
	printf("Matrice B :\n");
	afficherMatrice (B, lignes_b, colonnes_b);
	
	printf("Matrice C :\n");
	afficherMatrice (C, lignes_c, colonnes_c);
	
	printf("Matrice A + B :\n");
	additionnerMatrice (A, lignes_a, colonnes_a, B, lignes_b, colonnes_b, RES, &lignes_res, &colonnes_res);
	afficherMatrice (RES, lignes_res, colonnes_res);
	
	printf("Matrice transposee de A :\n");
	transposee (A, lignes_a, colonnes_a, RES, &lignes_res, &colonnes_res);
	afficherMatrice (RES, lignes_res, colonnes_res);

	printf("Matrice produit de A*C :\n");
	produitMatriciel (A, lignes_a, colonnes_a, C, lignes_c, colonnes_c, RES, &lignes_res, &colonnes_res);
	afficherMatrice (RES, lignes_res, colonnes_res);
	
	return 0;
}
