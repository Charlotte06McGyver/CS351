#include <stdio.h>


int hanoi(x, y, N){

    if (N==0){
        printf(" \n");
    }
    else {
        int z = 6-x-y;
        hanoi(x,z,N);
        printf("On déplace N de %d vers %d\n", x, z );
        hanoi(x, y, 1);
        printf
    }
}