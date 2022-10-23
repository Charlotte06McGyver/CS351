#include <stdio.h>
#include <stdlib.h>

int sommeDesImpairs(int d, int f){

    int result = d;
    int i = 2;
    int compteur = d;


    while (compteur!=f){
        result = result + (d+i);
        i = i + 2;
        compteur = compteur + 2;
    }

    return result;

}
