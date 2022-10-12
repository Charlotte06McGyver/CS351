#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "fonctions.h"

int main(){

    liste *L = NULL;

    /*InsertionTete(&L, 3);
    InsertionMilieu(&L, 0);
    afficherListe(L);
    InsertionTete(&L, 5);
    
    afficherListe(L);
    InsertionTete(&L, 1);
    printf("milieux\n");
    InsertionMilieu(&L, 4);
    afficherListe(L);
    InsertionTete(&L, 2);
    afficherListe(L);
    InsertionQueue(&L, 6);
    afficherListe(L);
    suppressionQueue(&L);
    afficherListe(L);
    //suppressionTete(&L);
    //afficherListe(L);
    printf("Taille = %d\n", Taille_liste(L));
    afficherListe(L);
    InsertionMilieu(&L, 13);
    afficherListe(L);
    InsertionMilieu(&L, 4);
    afficherListe(L);*/
    InsertionTete(&L, 12);
    InsertionTete(&L, 7);
    InsertionTete(&L, 5);
    InsertionTete(&L, 3);
    
    
    
    afficherListe(L);


}