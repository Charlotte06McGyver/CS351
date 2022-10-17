#include <stdio.h>


int hanoi(int x, int y, int N){

    int z = 0;

    if (N==0){
        printf(" \n");
    }
    else {
        z = 6-x-y;
        hanoi(x,z,N-1);
        printf("On déplace %d de %d vers %d\n", N, x, z );
        printf("On deplace 1 de %d vers %d", x, y);
        hanoi(z, y, N-1);
    }
    return 0;
}

int main(){
    hanoi(1, 2, 3);
}