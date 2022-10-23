#include <stdio.h>

int main(){
    int n=0;
    int mult = 1;
    int value =0;
    int error = 0;
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

        }else{
            printf("Erreur ! %d x %d = %d et non %d \n", mult, n, mult*n, value);
            error++;
        }
        mult++;
    }
    if(value != 0)
        printf("Vous avez fait %d error\n", error);
    printf("Bravo, vous avez fini\n");
}
/*
Nous avons effectué des test basqiue comme rentrer un valeur supérieur à 9 au début.
Insérer autre chose que des chiffes (ce qui fait planter le code).
*/
