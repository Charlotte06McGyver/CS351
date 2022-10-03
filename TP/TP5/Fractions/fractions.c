#include <stdlib.h>
#include <stdio.h>
#include "fractions.h"

int pgcd(int a , int b){
    int r =0;
    while((b != 0)){
        r = a%b;
        a=b;
        b=r;
    }
    return a;
}
/*int ppcm(int a, int b){

    int ppcm;

    if (pgcd(a,b)==0){ //on specifie le cas quand le pgcd est nul, on ne peut pas calculer le ppcm
        printf("Division par 0 impossible !");
        ppcm = 0;
    }

    ppcm = quotient(valeurAbsolue(a*b), pgcd(a,b));

    return ppcm;

}*/

Fraction reduire(Fraction f){
    int nume = f.num;
    f.num = f.num/(pgcd(f.num,f.den));
    f.den = f.den/(pgcd(nume,f.den));

    return f;
}

int icm(int b, int d){
    int value = 0;
    value = (b/(pgcd(b,d)))*d;

    return value;
}

void addFraction(Fraction f1, Fraction f2){
    Fraction f;
    int e =0;
    
    e = icm(f1.den, f2.den);
    f1 = reduire(f1);
    f2 = reduire(f2);
    f.den = e;
    f.num = (f1.num*e)/f1.den + (f2.num*e)/f2.den ; 
    f = reduire(f);
    printf("L'addition donne: %d/%d \n", f.num, f.den);

}

void subFraction(Fraction f1, Fraction f2){
    Fraction f;
    int e =0;
    
    e = icm(f1.den, f2.den);
    f1 = reduire(f1);
    f2 = reduire(f2);
    printf("%d/%d\n", f1.num, f1.den);
    printf("%d/%d\n", f2.num, f2.den);
    f.den = e;
    f.num = (f1.num*e)/f1.den - (f2.num*e)/f2.den ; 
    f = reduire(f);
    printf("La substraction donne:%d/%d \n", f.num, f.den);

}

void mulFraction(Fraction f1, Fraction f2){
    Fraction f;

    f1 = reduire(f1);
    f2 = reduire(f2);
 
    f.num = f1.num * f2.num;
    f.den = f1.den * f2.den;
    f =reduire(f);
    printf("La multiplication donne:%d/%d \n", f.num, f.den);

}

void divFraction(Fraction f1, Fraction f2){
    Fraction f;
    int nume = 0;

    f1 = reduire(f1);
    f2 = reduire(f2);
    nume = f2.den;
    f2.den = f2.num;
    f2.num = nume;

    f.num = f1.num * f2.num;
    f.den = f1.den * f2.den;
    f =reduire(f);
    printf("La division donne:%d/%d \n", f.num, f.den);
    

}