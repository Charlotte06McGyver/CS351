/**
  * CS351 - Corrections de TP 2016-2017
  * Projet TP4-1
  * monProgramme.c
  * Eva Gerbert-Gaillard
  */

#include <stdio.h>

int main(int argc, char * argv[]) {
	int i;
	
	printf("Nombres d'arguments : %d\n", argc);
	for (i=argc-1; i>0; i--) {
		printf("%s\n", argv[i]);
	}
	return 0;
}

/**
* Avec la commande :
* 	>./monProgramme 12 toto 20.5
* Le programme affiche :
* 	Nombre d'arguments : 4
*	20.5
*	toto
*	12
* Ce programme affiche le nombre d'arguments de la fonction main, 
* c'est-à-dire le nom du programme (1 argument) + le nombre de paramètre entrés dans la ligne de commande (3 dans l'exemple du TP).
* Puis à chaque ligne sont affichés les paramètres qui ont été passés dans la ligne de commande (dans l'ordre inverse).
* Les paramètres sont stockés dans un tableau sous forme de chaînes de caractères.
*/
