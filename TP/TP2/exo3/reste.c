#include <stdio.h>
#include <stdlib.h>

int reste (int a, int b){

    int reste;

    reste = a - b*quotient(a,b);

    if (b == 0){ //division par 0 impossible, on renvoie -1 pour signifier qu'il y a une erreur
        reste = -1;
    }

    return reste;
}
