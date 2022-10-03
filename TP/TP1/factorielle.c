#include<stdio.h>

int factorielle(int n){
    
    int result = n;

    while (n>1){
        result = result*(n-1);
        n--;
    }
    
    return result;
}

int factorielleBis (int m){
    
    int n = 1;
    int result = n;

    while (result<m){
        n++;
        result = result*n;        
    }

    return n;

}


/*Tests effectues
Test factorielle : rang = 3, rang = 5
Test factorielleBis : rang = 5, rang = 100

*/

int main(){

    int rang;
    printf("Entrez un nombre : "); //on demande a l'utilisateur un nombre
    scanf("%d", &rang);
    printf("%d! = %d\n", rang, factorielle(rang));
    printf("factorielleBis %d : %d\n",rang, factorielleBis(rang));
}