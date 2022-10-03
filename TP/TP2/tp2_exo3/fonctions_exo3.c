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

int reste (int a, int b){

    int reste;

    reste = a - b*quotient(a,b);

    if (b == 0){ //division par 0 impossible, on renvoie -1 pour signifier qu'il y a une erreur
        reste = -1;
    }

    return reste;
}

int valeurAbsolue (int a){

    if (a<0){
        a=-a;
    }
    return a;
}



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

int ppcm(int a, int b){

    int ppcm;

    if (pgcd(a,b)==0){ //on specifie le cas quand le pgcd est nul, on ne peut pas calculer le ppcm
        printf("Division par 0 impossible !");
        ppcm = 0;
    }

    ppcm = quotient(valeurAbsolue(a*b), pgcd(a,b));

    return ppcm;

}

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



