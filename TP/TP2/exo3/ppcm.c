#include <stdio.h>
#include <stdlib.h>

int ppcm(int a, int b){

    int ppcm;

    if (pgcd(a,b)==0){ //on specifie le cas quand le pgcd est nul, on ne peut pas calculer le ppcm
        printf("Division par 0 impossible !");
        ppcm = 0;
    }

    ppcm = quotient(valeurAbsolue(a*b), pgcd(a,b));

    return ppcm;

}
