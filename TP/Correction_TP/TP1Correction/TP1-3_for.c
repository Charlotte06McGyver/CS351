/**
  * CS351 - Corrections de TP 2016-2017
  * TP1-3_for.c
  * Eva Gerbert-Gaillard
  */

#include <stdio.h>

int main() {
	int i = 0;
	int n = 0;
	int somme = 0;

	printf("Entrez un entier :\n");
	scanf("%d", &n);
	for (i=0; i<=n; ++i) {
		somme = somme + i;
	}
	printf("La somme des entiers jusqu'à %d vaut %d. \n", n, somme);

	return (0);
}
