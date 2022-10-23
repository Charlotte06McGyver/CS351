#include <stdio.h>
#include <stdlib.h>


int estUneDecompositionDe(int d, int f){

    int x = 1;
    int result = -1;
    int somme = sommeDesImpairs(d,f);

    while (x != f && result == -1){

        if (somme == puissanceMB(x,3)){
           result = x;
        }
        x++;
    }
    return result;
}
