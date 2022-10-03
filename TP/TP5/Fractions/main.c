#include <stdlib.h>
#include <stdio.h>
#include "fractions.h"

int main(int argc, char* argv[]){
    Fraction fa;
    Fraction fb;
    printf("Entrer deux fractions :");
    scanf("%d/%d %d/%d", &fa.num, &fa.den, &fb.num, &fb.den);
    printf("%d/%d %d/%d \n",fa.num, fa.den, fb.num, fb.den);
    addFraction(fa,fb);
    subFraction(fa,fb);
    mulFraction(fa,fb);
    divFraction(fa,fb);

}