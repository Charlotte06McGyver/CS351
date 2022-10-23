#include <stdio.h>

int main(){
    int nb = 0;
    int nb_test = 0;
    int somme =0;
    printf("entrez un nb\n");
    scanf("%d", &nb);
    
    while(nb_test!= nb){
        nb_test++;
        somme = somme + nb_test;
    }
    printf("La somme des nb premier entier avec while donne : %d\n", somme);
    nb_test = 0;
    somme = 0;
    do{
        nb_test++;
        somme = somme + nb_test; 
    }while(nb_test != nb);

    printf("La somme des nb premier entier avec do while donne : %d\n", somme);
}