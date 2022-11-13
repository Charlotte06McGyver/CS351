/**
  * CS351 - Corrections de TP 2016-2017
  * Projet TP3-1
  * TP2-4.c
  * Eva Gerbert-Gaillard
  */

#include <stdio.h>



void jeuMultiPoints () {
	int n = 2;
	int i;
	int rep;
	int erreurs = 0;

	do {
		if ( (n<2) || (n>9) ) {
			printf("Reessayez : la valeur doit etre comprise entre 2 et 9\n");
		}
		printf("Valeur de n : ");
		scanf("%d", &n);
	}
	while ( (n<2) || (n>9) );

	for (i=1; i<=12; i++) {
		printf("%d x %d = ", i, n);
		scanf("%d", &rep);
		if (rep != (i*n)) {
			printf("Erreur ! %d x %d = %d et non %d \n", i, n, i*n, rep);
			erreurs = erreurs + 1;
		}
	}

	if (erreurs == 0) {
		printf("Felicitations! Vous n'avez pas fait d'erreurs\n\n");
	} else {
		printf("Vous avez fait %d erreurs\n\n", erreurs);
	}
}
