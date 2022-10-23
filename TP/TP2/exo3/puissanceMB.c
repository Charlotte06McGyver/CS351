#include <stdio.h>
#include <stdlib.h>

int puissanceMB(int x, int n){

    int y = 1;
    int z = x;

    while (n!=0){

        if ((reste(n, 2)) ==0){ //si la puissance n est paire
            z = z * z;
            n = quotient(n,2);
        }

        y = z * y;
        z = z*z;
        n = quotient(n,2);
    }

    return y;
}
