/**
  * CS351 - Corrections de TP 2016-2017
  * TP1-1_imb.c
  * Eva Gerbert-Gaillard
  */

#include <stdio.h>

int main() {
	char lettre = 'N';

	printf("Donner la lettre obtenue au devoir(en majuscule)\n");
	scanf("%c", &lettre);
	if (lettre == 'A') {
		printf("Très bien\n");
	} else {
			if (lettre == 'B') {
				printf("Bien\n");
			} else {
					if (lettre == 'C') {
						printf("Assez bien\n");
					} else {
							if (lettre == 'D') {
								printf("Passable\n");
							} else {
									if (lettre == 'E') {
										printf("Insuffisant\n");
									} else {
										printf("Pas d'appréciation\n");
									}
							}
					}
			}
	}
	
	return (0);
}
