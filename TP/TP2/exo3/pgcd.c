#include <stdio.h>
#include <stdlib.h>

int pgcd(int a , int b){
    int r =0;
    while((b != 0)){
        r = a%b;
#ifdef MISEAUPOINT
    printf("valeur courante de b =  %d \n", b);
#endif
        a=b;
        b=r;
    }
    return a;
}
