/**
  * CS351 - Corrections de TP 2016-2017
  * TP2-3.c
  * Eva Gerbert-Gaillard
  */

#include <stdio.h>

int factorielle (int n) {
	int res = 1;

	while (n>1) {
		res = res*n;
		n--;
	}
	return res;
}

int factorielleBis (int m) {
	int n, fac;

	fac = 1;
	n = 1;
	while (m>=fac) {
		n++;
		fac = fac*(n+1);	
	}
	
	return n;
}

int main () {
	int n, resultat;

	printf("Pour calculer le factoriel de n, entrez n:\n");
	scanf("%d", &n);
	resultat = factorielle(n);
	printf("Le factoriel de %d vaut %d.\n", n, resultat);
	printf("Entrez un entier m:\n");
	scanf("%d", &n);
	resultat = factorielleBis(n);
	printf("Le plus petit nombre dont le factoriel est supérieur à %d est %d.\n", n, resultat);

	return 0;
}
