#include <stdio.h>
#define MISEAUPOINT



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
int main(){
    int a = 0;
    int b = 0;

    printf("donnez un nb a :\n");
    scanf("%d", &a);
    printf("donnez un nb b :\n");
    scanf("%d", &b);
    printf("leurs pgcd vaut = %d \n", pgcd(a, b));
}
