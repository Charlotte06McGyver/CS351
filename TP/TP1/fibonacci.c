#include <stdio.h>

int fibonacci (int n){

    int result;
    int a = 0; //il s'agit du terme u(n-2)
    int b = 1; //il s'agit du terme u(n-1)
    int i;

    if (n == 0){ //cas particulier quand n = 0
        result = 0;
    }
    if (n == 1){ //cas particulier quand n = 1
        result = 1;
    }
    
    for (i = 2; i<=n; i ++){  //cas general
        result = a + b;
        a = b;
        b = result;
    }
    
    return result;
    
}

int main(){

    int rang;
    printf("Entrez un nombre : ");
    scanf("%d", &rang); 
    int test = fibonacci(rang);
    printf("La suite de fibonacci de rang %d est : %d\n", rang, test);

}
// Si l'utilisateur rentre des n négatif le code ne fonctionnera pas, il ne prend que des valeurs >=0
