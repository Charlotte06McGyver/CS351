/**
  * CS351 - Corrections de TP 2016-2017
  * Projet TP3-1
  * TP2-4.c
  * Eva Gerbert-Gaillard
  */

#include <stdio.h>
#include "jeu.h"

int main () {
	int choix;

	do {
		printf("Jeux des multiplications !\nSi vous voulez jouez sans compter les points : entrez 1\nSi vous voulez jouez avec les points : entrez 2\nSi vous voulez quitter : entrez 0\n");
		scanf("%d", &choix);
		if (choix == 1) {
			jeuMulti();
		}
		if (choix == 2) {
			//jeuMultiPoints ();
			gameMultiPoints();
		}
	}
	while (choix != 0);

	return 0;
}
