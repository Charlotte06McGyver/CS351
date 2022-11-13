/**
  * CS351 - Corrections de TP 2016-2017
  * TP2-4.c
  * Eva Gerbert-Gaillard
  */

#include <stdio.h>

void jeuMulti () {
	int n = 2;
	int i;
	int rep;
	int erreur = 0;

	do {
        printf("Entrer une valeur  comprise entre 2 et 9\n");
		scanf("%d", &n);
	}
	while ( (n<2) || (n>9) );

	for (i=1; (i<=10) && (!erreur); i++) {
		printf("%d x %d = ", i, n);
		scanf("%d", &rep);
		if (rep != (i*n)) {
		    printf("Erreur ! %d x %d = %d et non %d \n\n", i, n, i*n, rep);
			erreur = 1;
		}
	}
	if (!erreur) printf("Félicitations! Vous n'avez pas fait d'erreurs\n\n");
}

void jeuMultiPoints () {
	int n = 2;
	int i;
	int rep;
	int erreurs;

	do {
        printf("Entrer une valeur  comprise entre 2 et 9\n");
		scanf("%d", &n);
	}
	while ( (n<2) || (n>9) );

	for (i=1; i<=10; i++) {
		printf("%d x %d = ", i, n);
		scanf("%d", &rep);
		if (rep != (i*n)) {
			printf("Erreur ! %d x %d = %d et non %d \n", i, n, i*n, rep);
			erreurs = erreurs + 1;
		}
	}

	if (erreurs == 0) {
		printf("Félicitations! Vous n'avez pas fait d'erreurs\n\n");
	} else {
		printf("Vous avez fait %d erreurs\n\n", erreurs);
	}
}


int main () {
	int choix;

	do {
		printf("Jeux des multiplications !\nSi vous voulez jouez sans compter les points : entrez 1\nSi vous voulez jouez avec les points : entrez 2\nSi vous voulez quitter : entrez 0\n");
		scanf("%d", &choix);
		if (choix == 1) {
			jeuMulti();
		}
		if (choix == 2) {
			jeuMultiPoints ();
		}
	}
	while (choix != 0);

	return 0;
}
