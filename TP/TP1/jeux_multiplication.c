#include <stdio.h>

int main(){
    int n=0;
    int mult = 1;
    int value =0;
    printf("Valeur de n : \n");
    scanf("%d", &n);
    while((2>n) || (9<n) ){

        printf("Réessayez : la valeur doit être comprise entre 2 et 9\n");
        scanf("%d", &n);
    }
    printf("Valeur de n : %d\n", n);
    while(mult != 11){
        printf("%d x %d = ", mult,n);
        scanf("%d", &value);
        if((n*mult) == value){
            printf("\n");
            mult++;
        }else{
            printf("Erreur ! %d x %d = %d et non %d \n", mult, n, mult*n, value);
            mult = 11;
        }
    }
}