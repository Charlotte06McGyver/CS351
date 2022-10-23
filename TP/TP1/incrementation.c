#include <stdio.h>

int main(){
    int i, j, k, l;

    i = j = k = l = 0;

    while(i<9){
        printf("i++ = %d, ++j = %d, k-- = %d, --l = %d\n", i++, ++j, k--, --l);
    }
    printf("i = %d, j = %d, k = %d, l = %d\n", i, j, k, l);

    return(0);
}

/* 
++j et --l incrementent le parametre j ou l avant d'affecter la valeur a la variable j ou l
C'est la pre-incrementation

i++ et k-- va incrementer le parametre i ou k apres l'affectation de la valeur a la variable i ou k
Lorsque l'on retournera la valeur de i ou de k, ce sera la valeur d'origine et non la valeur modifiee.
C'est la post-incrementation

*/
