#include <stdio.h>
#include <stdlib.h>
#include "fonctions3.h"

void testBibliotheque(){

    //Test fonction quotient

    printf("-------------Test fonction quotient-------------\n");
    printf("Le quotient de 15 et de 3  est : %d\n", quotient(15,3));
    printf("Le quotient de 24 et de 7  est : %d\n", quotient(24,7));
    printf("Le quotient de 15 et de 0  est : %d\n", quotient(15,0)); //on teste la division par 0
    printf("Le quotient de 5 et de 23  est : %d\n", quotient(5,23)); //on teste le cas ou b>a

    //Test fonction reste

    printf("-------------Test fonction reste-------------\n");
    printf("Le reste de la division de 15 par 3 est : %d\n", reste(15,3)); //quand le reste est nul
    printf("Le reste de la division de 24 par 7 est : %d\n", reste(24,7)); //quand le reste est non nul
    printf("Le reste de la division de 15 par 0 est : %d\n", reste(15,0)); //quand on divise par 0
    printf("Le reste de la division de 5 par 23 est : %d\n", reste(5,23)); //quand b>a

    //Test fonction valeurAbsolue

    printf("-------------Test fonction valeurAbsolue-------------\n");
    printf("Valeur absolue de 3 : %d\n", valeurAbsolue(3)); //cas d'un nombre positif
    printf("Valeur absolue de -15 : %d\n", valeurAbsolue(-15)); //cas d'un nombre negatif
    printf("Valeur absolue de 0 : %d\n", valeurAbsolue(0)); //cas de 0

    //Test fonction ppcm

    printf("-------------Test fonction ppcm-------------\n");
    printf(" Le ppcm de 15 et de 3 est : %d\n", ppcm(15,3));
    printf(" Le ppcm de 25 et de 56 est : %d\n", ppcm(25,56));


    //Test fonction puissanceMB

    printf("-------------Test fonction puissanceMB-------------\n");
    printf(" 2^3 = %d\n", puissanceMB(2,3)); //cas de la puissance impaire   
    printf(" 4^0 = %d\n", puissanceMB(4,0)); //cas de la puissance nulle
    printf(" 5^2 = %d\n", puissanceMB(5,2)); //cas de la puissance paire

    //Test fonction sommeDesImapairs

    printf("-------------Test fonction sommeDesImpairs-------------\n");   
    printf("Somme des nombres impairs entre 3 et 7 : %d\n", sommeDesImpairs(3,7)); 
    printf("Somme des nombres impairs entre 1 et 15 : %d\n", sommeDesImpairs(1,15));

    //Test fonction estUneDecompositionDe

    printf("-------------Test fonction estUneDecompositionDe-------------\n");
    printf("Decomposition de 7 et de 13 : %d\n", estUneDecompositionDe(7,13)); //si le cube n'existe pas
    printf("Decomposition de 7 et de 11 : %d\n", estUneDecompositionDe(7,11)); //si le cube existe

}

int main(){

    testBibliotheque(); 

}