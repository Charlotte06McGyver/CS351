/**
  * CS351 - Corrections de TP 2016-2017
  * Projet TP5-1
  * tri.c
  * Eva Gerbert-Gaillard
  */

#include <stdio.h>
#include <stdlib.h>

#include "fctTri.h"

#define TMAX 50

int main (int argc, char * argv[]) {
/*L'execution de main prend en parametre le nom de fichier pour la lecture et celui pour l'écriture*/
/*argv[1] correspond au nom du fichier de donnees*/
/*argv[2] correspond au nom du fichier de resultats*/

	int tdonnees;
	int buffer[TMAX];

	/*On suppose la taille du tableau suffisante pour contenir tous les entiers*/
	tdonnees = lireDonnees(argv[1], buffer);
	afficherTableau(buffer, tdonnees);
	triABulles(buffer, tdonnees);
	enregistrerDonnees(argv[2], buffer, tdonnees);
	afficherTableau(buffer, tdonnees);
	
	return EXIT_SUCCESS;
}

