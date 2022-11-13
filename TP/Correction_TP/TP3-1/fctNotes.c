/**
  * CS351 - Corrections de TP 2016-2017
  * Projet TP4-1
  * fctNotes.c
  * Eva Gerbert-Gaillard
  */

#include "fctNotes.h"


void afficherNotes(float notes[], int n) {
	int i;

	for (i=0; i<n; i++) {
		printf(" %3.1f ", notes[i]);
	}
	printf("\n");
}

float minimumNote(float notes[], int n) {
	int i, j;
	j=0 ;

	for (i=0; i<n; i++) {
		if (notes[i]<notes[j]) {
			j=i;
		}
	}

	return notes[j];
}

float maximumNote(float notes[], int n) {
	int i, j;
	j=0 ;

	for (i=0; i<n; i++) {
		if (notes[i]>notes[j]) {
			j=i;
		}
	}

	return notes[j];
}

float calculeMoyenne(float notes[], int n) {
	int i;
	float somme = 0;

	for (i=0; i<n; i++) {
		somme = somme + notes[i];
	}

	return (somme/n);
}

float calculeVariance(float notes[], int n) {
	int i;
	float moy, nvar;
	nvar = 0;

	moy = calculeMoyenne(notes, n);
	for (i=0; i<n; i++) {
		nvar = nvar + pow((notes[i]-moy),2);
	}

	return (nvar/n);
}

float calculeEcartType(float notes[], int n) {
	return sqrt(calculeVariance(notes, n));
}

int rechValeur(float notes[], int n, float v) {
	int i=0, trouve = -1;

	while (i<n && trouve == -1) {
		if (notes[i] == v) {
			trouve = i;
		}
	}
	return (trouve);
}


void histoHorizontal(float notes[], int n) {
        int i;

        printf("[ 0 ; 2 ] :\t");
        for (i=0; i<n; i++) {
                if  ((notes[i]>=0)&&(notes [i]<=2)) {
                        printf("*\t");
                }
        }
        printf("\n");

        printf("] 2 ; 4 ] :\t");
        for (i=0; i<n; i++) {
                if  ((notes[i]>2)&&(notes [i]<=4)) {
                        printf("*\t");
                }
        }
        printf("\n");

        printf("] 4 ; 6 ] :\t");
        for (i=0; i<n; i++) {
                if  ((notes[i]>4)&&(notes[i]<=6)) {
                        printf("*\t");
                }
        }
        printf("\n");

        printf("] 6 ; 8 ] :\t");
        for (i=0; i<n; i++) {
                if  ((notes[i]>6)&&(notes[i]<=8)) {
                        printf("*\t");
                }
        }
        printf("\n");

        printf("] 8 ; 10 ] :\t");
        for (i=0; i<n; i++) {
                if  ((notes[i]>8)&&(notes[i]<=10)) {
                        printf("*\t");
                }
        }
        printf("\n");

        printf("] 10 ; 12 ] :\t");
        for (i=0; i<n; i++) {
                if  ((notes[i]>10)&&(notes[i]<=12)) {
                        printf("*\t");
                }
        }
        printf("\n");

        printf("] 12 ; 14 ] :\t");
        for (i=0; i<n; i++) {
                if  ((notes[i]>12)&&(notes[i]<=14)) {
                        printf("*\t");
                }
        }
        printf("\n");

        printf("] 14 ; 16 ] :\t");
        for (i=0; i<n; i++) {
                if  ((notes[i]>14)&&(notes[i]<=16)) {
                        printf("*\t");
                }
        }
        printf("\n");

        printf("] 16 ; 18 ] :\t");
        for (i=0; i<n; i++) {
                if  ((notes[i]>16)&&(notes[i]<=18)) {
                        printf("*\t");
                }
        }
        printf("\n");

        printf("] 18 ; 20 ] :\t");
        for (i=0; i<n; i++) {
                if  ((notes[i]>18)&&(notes[i]<=20)) {
                        printf("*\t");
                }
        }
        printf("\n");
}

void histoVertical(float notes[], int n) {
        int i, j, max;
        int tableau [10]; /*Ce tableau va compter le nombre de notes dans chaque intervalle*/
        max = 0;

        for (i=0; i<10; i++) {
                tableau [i] = 0;
        }

        for (i=0; i<n; i++) {
                if  ((notes[i]>=0)&&(notes[i]<=2)) {
                        tableau[0]++;
                }
        }
        for (j=1; j<10; j++) {
                for (i=0; i<n; i++) {
                        if  ((notes[i]>(2*j))&&(notes[i]<=(2*(j+1)))) {
                                tableau[j]++;
                        }
                }
        }

        for (i=0; i<10; i++) {
		if (tableau[i]>max) {
			max = tableau [i];
		}
	}

        for (i=max; i>0; i--) {
		printf("\t");
                for (j=0; j<10; j++) {
                        if (tableau[j]>=i){
                                printf("*\t\t");
                        } else {
                                printf("\t\t");
                        }
		}
                printf("\n");
        }
        printf("------------------------------------------------------------------------------------------------------------------\n");
        printf("\t [ 0; 2] \t ] 2; 4] \t ] 4; 6] \t ] 6; 8] \t ] 8; 10] \t ] 10; 12] \t ] 12; 14] \t ] 14; 16] \t ] 16; 18] \t ] 18; 20]\n");
}
