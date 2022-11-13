/**
  * CS351 - Corrections de TP 2016-2017
  * TP1-1_swi.c
  * Eva Gerbert-Gaillard
  */

#include <stdio.h>

int main() {
	char lettre = 'N';

	printf("Donner la lettre obtenue au devoir(en majuscule)\n");
	scanf("%c", &lettre);
	switch (lettre) {
		case 'A' : printf("Très bien\n"); break;
		case 'B' : printf("Bien\n"); break;
		case 'C' : printf("Assez bien\n"); break;
		case 'D' : printf("Passable\n"); break;
		case 'E' : printf("Insuffisant\n"); break;
		default  : printf("Pas d'appréciation\n");
	}

	return (0);
}
