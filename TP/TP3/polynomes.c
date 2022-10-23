#include <stdlib.h>
#include <stdio.h>

float valeurPolynome(float A[], int N, float x0){
    float resultat = 0;
    int i =1;
    
    for(i; i < N; i++ ){
        resultat = x0*(A[N-i] + resultat) ;

    }
    resultat = resultat + A[0];


    return resultat;
}


int main(){
    float tab[] = {4.0,12.0,1.0,3.0};
    printf("la fonction 3x^3 + x^2 + 12*x + 4 en x0=3 donne %f\n", valeurPolynome(tab,4,2.0));

}