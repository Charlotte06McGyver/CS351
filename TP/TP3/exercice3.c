#include <stdio.h>

int main(int argc, char* argv[]) {

    int i;
    printf("Nombre d'arguments : %d\n", argc);
    for (i=argc-1; i>0; i--){
        printf("%s\n", argv[i]);
    }
    return 0;
}

/*
Lorsque l'on execute le programme avec la seule instruction "./exo3", le programme retourne qu'il n'y a qu'un argument
Si on l'execute avec "./exo3 5", il renverra qu'il y a 2 arguments et affichera l'argument 5
Si on l'execute avec plus d'arguments, il renverra le nombre d'arguments et ensuite la valeur de ces arguments dans l'ordre inverse ou on les a rentres.
Par exemple : "./exo3 5 6 3 2 1", il renverra qu'il y a 6 arguments et affichera 1 puis 2 puis 3 puis 6 puis 5

*/