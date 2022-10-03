#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void afficherNotes(float *tab, int taille){

    int i = 0;
    for (i=0; i<taille; i++){
        printf("Note %d : %f\n", (i+1), tab[i]);
    }

}


float minimumNote(float *tab, int taille){

    int i = 0;
    int minimum = tab[0];

    for (i=0; i<taille; i++){

        if (tab[i]<minimum){

            minimum = tab[i];
        }
    }
    return minimum;

}

float maximumNote(float *tab, int taille){

    int i = 0;
    int maximum = tab[0];

    for (i=0; i<taille; i++){

        if (tab[i]>maximum){

            maximum = tab[i];
        }
    }
    return maximum;

}

float calculeMoyenne(float *tab, int taille){

    int i = 0;
    float moyenne = 0;

    for (i=0; i<taille; i++){
        moyenne = moyenne + tab[i];
    }

    moyenne = moyenne / taille;
    return moyenne;

}

float calculeVariance(float *tab, int taille){

    int i = 0;
    float variance = 0;

    for (i=0; i<taille; i++){

        variance = variance + (pow((tab[i]-calculeMoyenne(tab, taille)), 2)/taille);
    }
    return variance;
}

float calculeEcartType(float *tab, int taille){

    int ecart_type = sqrt(calculeVariance(tab, taille));

    return ecart_type;

}

int rechercherValeur(float *tab, int taille, float valeur){

    int i = 0;
    int position = -1;
    
    while ((i<taille) && (position==-1)){ //on utilise une boucle while pour sortir de la boucle des qu'on a trouve la position de la valeur
        if(tab[i]==valeur){
            position = i;
            i = taille;
        }
        i++;
    }

    return position;

}



int main(){

    float tab_test[5] = {12.0, 13.5, 8.5, 14.7, 6.0};


    afficherNotes(tab_test, 5);

    printf("Note la plus basse obtenue a l'examen : %f\n", minimumNote(tab_test, 5));
    printf("Note la plus elevee obtenue a l'examen : %f\n", maximumNote(tab_test, 5));
    printf("Moyenne des notes obtenues a l'examen : %f\n", calculeMoyenne(tab_test, 5));
    printf("Variance des notes obtenues a l'examen : %f\n", calculeVariance(tab_test, 5));
    printf("Ecart-Type des notes obtenues a l'examen : %f\n", calculeEcartType(tab_test, 5));
    printf("Valeur %f dans le tableau :%d\n", 7.0, rechercherValeur(tab_test, 5, 7.0));

}