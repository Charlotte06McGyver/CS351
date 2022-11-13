/**
  * CS351 - Corrections de TP 2016-2017
  * Projet TP4-1
  * notes.c
  * Eva Gerbert-Gaillard
  */

#include <stdio.h>
#include <stdlib.h>

#include "fctNotes.h"


int main () {
        int choix =0;
        int n = 20;
        float notes [] = {0, 13.5, 8.5, 13.7, 20, 12, 8.5, 17, 11, 10, 9.5, 4, 14, 13.5, 12, 1, 15, 10.5, 7.5, 9.5 };
        float valeur = 0;
        
        printf("Bienvenue dans le programme d'etude statistique des notes des etudiants de l'ESISAR.\n");
        do {
                printf("Quitter : 0\nAfficher les notes : 1\nMinimum : 2\nMaximum : 3\nMoyenne : 4\nVariance : 5\nEcart-type : 6\nRechercher une valeur : 7\nAfficher un histogramme horizontal : 8\nAfficher un histogramme vertical : 9\n");
                scanf("%d", &choix);
                switch (choix) {
                        case 0 : break;
                        case 1 : afficherNotes(notes, n); break;
                        case 2 : printf("%3.1f\n", minimumNote(notes, n)); break;
                        case 3 : printf("%3.1f\n", maximumNote(notes, n)); break;
                        case 4 : printf("%6.2f\n", calculeMoyenne(notes, n)); break;
                        case 5 : printf("%6.2f\n", calculeVariance(notes, n)); break;
                        case 6 : printf("%6.2f\n", calculeEcartType(notes, n)); break;
                        case 7 : printf("Entrez la valeur a chercher\n");
                                scanf("%f", &valeur);
                                printf("La valeur demandee se trouve a l'indice %d\n", rechValeur(notes, n, valeur)); break;
                        case 8 : histoHorizontal(notes, n); break;
                        case 9 : histoVertical(notes, n); break;
                        default : choix=0; break;
                }
                printf("\n\n");
	}
        while (choix!=0);
        
	return 0;
}
