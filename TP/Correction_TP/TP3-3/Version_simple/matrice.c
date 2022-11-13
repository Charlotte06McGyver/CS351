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
	int A[M][M] = {{1, 0, 4}, {-1, 2, -5}};
	int B[M][M] = {{2, -3, 1}, {5, 8, 2}};
	int C[M][M] = {{0, 1}, {2, -1}, {3, 4}};

	afficherMatrice (A, 2, 3);
	printf("\n");
	additionnerMatrice (A, B, 2, 3);
	printf("\n");
	transposee (A, 2, 3);
	printf("\n");
	produitMatriciel (A, 2, 3, C, 2);
	printf("\n");

	return 0;
}
