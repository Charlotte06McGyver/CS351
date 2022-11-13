/**
  * CS351 - Corrections de TP 2016-2017
  * TP1-2.c
  * Eva Gerbert-Gaillard
  */

#include <stdio.h>

int main() {
	int annee = 0;
	printf("Entrez l'année :\n");
	scanf("%d", &annee);
	if ((annee%4==0) && (annee%100!=0) || (annee%400==0)) {
        printf("L'année %d est bissextile\n", annee);
    } else {
        printf("L'année %d n'est pas bissextile\n", annee);
    }
	return (0);
}

