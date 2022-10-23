#include <stdio.h>
#include <stdlib.h>

int quotient (int a, int b){

    int quotient = 0;
    int division = a;

    if (b == 0){ //traite le cas de la division par 0
        quotient = -1; //division par 0 impossible, on renvoie -1 pour signifier qu'il y a une erreur
    }

    while ((division >= b) && (b!=0)){  //tant qu'on peut encore diviser a par b, on soustrait b a a et on incremente notre quotient
        division = division - b;
        quotient++;
    }

    return quotient;
}
