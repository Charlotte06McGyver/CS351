/**
  * CS351 - Corrections de TP 2016-2017
  * Projet TP3-2
  * main_maths.c
  * Eva Gerbert-Gaillard
  */
  
#include <stdio.h>
#include "bib_maths.h"

int main () {
	int a = 0;
	int b = 0;
	int choix = 0;
	int res = 0;
	
	do {
		printf("\nCalculs mathematiques !\n"
			"Pour calculer un quotient : entrez 1\n"
			"Pour calculer un reste de division : entrez 2\n"
			"Pour calculer une valeur absolue : entrez 3\n"
			"Pour calculer un ppcm : entrez 4\n"
			"Pour quitter : entrez 0\n"
		);
		scanf("%d", &choix);
		
		if (choix == 1) {
			printf("Entrez un premier entier positif :\n");
			scanf("%d", &a);
			printf("Entrez un deuxième entier positif :\n");
			scanf("%d", &b);
			
			res = quotient(a,b);
			printf("Le quotient de %d par %d est : %d \n", a, b, res);
		}
		
		if (choix == 2) {
			printf("Entrez un premier entier positif :\n");
			scanf("%d", &a);
			printf("Entrez un deuxième entier positif :\n");
			scanf("%d", &b);
			
			res = reste(a,b);
			printf("Le reste de la division de %d par %d est : %d \n", a, b, res);
		}
		
		if (choix == 3) {
			printf("Entrez un entier relatif :\n");
			scanf("%d", &a);
			
			res = valeurAbsolue(a);
			printf("La valeur absolue de %d est : %d \n", a, res);
		} 
		
		if (choix == 4) {
			printf("Entrez un premier entier relatif :\n");
			scanf("%d", &a);
			printf("Entrez un deuxième entier relatif :\n");
			scanf("%d", &b);
			
			res = ppcm(a,b);
			printf("Le ppcm de %d et %d est : %d \n", a, b, res);
		}
	}
	while (choix != 0);
		
	return 0;
} 
