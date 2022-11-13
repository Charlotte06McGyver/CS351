/**
  * CS351 - Corrections de TP 2016-2017
  * TP2-2.c
  * Eva Gerbert-Gaillard
  */

#include <stdio.h>

int pgcd (int a, int b) {
	int r;

	while (b != 0) {
		r = a%b;
		a = b;
		b = r;
	}
	
	return a;
}

int main () {
	int a, b, resultat;

	printf("Pour calculer le PGCD de a et b, entrez a:\n");
	scanf("%d", &a);
	printf("Entrez b:\n");
	scanf("%d", &b);
	resultat = pgcd(a,b);
	printf("Le pgcd de %d et de %d vaut %d.\n", a, b, resultat);

	return 0;
}
