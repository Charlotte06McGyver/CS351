/**
  * CS351 - Corrections de TP 2016-2017
  * TP1-1_seq.c
  * Eva Gerbert-Gaillard
  */

#include <stdio.h>

int main() {
	char lettre = 'N';

	printf("Donner la lettre obtenue au devoir(en majuscule)\n");
	scanf("%c", &lettre);
	if (lettre == 'A') {
		printf("Très bien\n");
	}
	if (lettre == 'B') {
		printf("Bien\n");
	}
	if (lettre == 'C') {
		printf("Assez bien\n");
	}
	if (lettre == 'D') {
		printf("Passable\n");
	}
	if (lettre == 'E') {
		printf("Insuffisant\n");
	}
	if ((lettre != 'A') && (lettre != 'B') && (lettre != 'C') 
		&& (lettre != 'D') && (lettre!= 'E')) {		
			printf("Pas d'appréciation\n");
	}

	return (0);
}
