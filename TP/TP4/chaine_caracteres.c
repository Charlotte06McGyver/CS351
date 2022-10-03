#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int affichageEnDecimal(char *mot){

    int i = 0;

    for (i=0; i<strlen(mot); i++){
        printf("%d ", mot[i]);
    }

    return 0;
}

int mettreEnMajuscule(char *mot){

    int i = 0;

    for (i=0; i<strlen(mot); i++){
        printf("%c", toupper(mot[i]));
    }

    return 0;

}

int mettreEnMinuscule(char *mot){

    int i = 0;

    for (i=0; i<strlen(mot); i++){
        printf("%c", tolower(mot[i]));
    }

    return 0;

}

int transformerMinMaj(char *mot){

    int i = 0;

    for (i=0; i<strlen(mot); i++){
        if (islower(mot[i]) > 0){
            printf("%c", toupper(mot[i]));
        }
        if (isupper(mot[i])>0){
            printf("%c", tolower(mot[i]));
        }
    }

    return 0;
}

char* retournerMot(char *mot){

    int i = strlen(mot);
    int j = 0;
    char *nv_mot [i]; //possible aussi avec un malloc

    for (i = strlen(mot); i>0; i--){
        for (j=0; j<strlen(mot); j++){
            nv_mot[j] = mot[i];
        }
    }
    return nv_mot;

}


int rechercherCaractereG(char *mot, char caractere){

    int i = 0;
    int position = -1;

    while (position == -1){
        if (mot[i] == caractere){
            position = i;
        }
        i++;
    }
    return position;

}

int rechercherCaractereD(char *mot, char caractere){

    int i = strlen(mot);
    int position = -1;

    while (position == -1){
        if (mot[i] == caractere){
            position = i;
        }
        i--;
    }
    return position;

}

int estPalindrome (char *mot, int d, int f){


}

int main(){

    /*
    affichageEnDecimal("caca");
    printf("\n");
    mettreEnMajuscule("caca");
    printf("\n");
    mettreEnMajuscule("CacA");
    printf("\n");

    mettreEnMinuscule("CACA");
    printf("\n");
    mettreEnMinuscule("caCA");
    printf("\n");

    transformerMinMaj("CaCa");
    printf("\n");
    transformerMinMaj("cACA");
    */

    printf("%*c", retournerMot("oiseau") ); //pb avec le test de cette fonction

    printf("%d\n", rechercherCaractereG("coucou c'est moi moumou", 'e'));
    printf("%d\n", rechercherCaractereD("coucou c'est moi moumou", 'e'));

}