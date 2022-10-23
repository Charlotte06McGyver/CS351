#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int affiche_matrice (int n, int p, int tab[][8]){

    int i,j;
    for (i=0; i<n; i++){
        for (j=0; j<p; j++){
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
    return 0;

}

int additionner_matrice (int n, int p, int tab1[][8], int tab2[][8]){
// Il faut ques les matrices soient de taille égale
//Elle sera de taille 3x2
    int i, j;
    int matriceResult[8][8];

    for (i=0; i<n; i++){
        for (j=0; j<p; j++){
            matriceResult[i][j]=tab1[i][j]+tab2[i][j];
        }
    }
    printf("Matrice somme :\n");
    affiche_matrice(n, p, matriceResult);

    return 0;

}


int transposee(int n, int p, int tab[][8]){
//De la taille de A
    int i,j;
    int matriceTransposee[8][8];

    for (i=0; i<n; i++){
        for (j=0; j<p; j++){
            matriceTransposee[i][j]=tab[j][i];
        }
    }

    printf("Matrice transposee :\n");
    affiche_matrice(n, p, matriceTransposee);

    return 0;

}

int produitMatriciel(int n, int q, int p, int tab1[][8], int tab2[][8]){

    int i,j,k;
    int matriceResult[8][8];

    for (i=0; i<n; i++){
        for (j=0; j<p; j++){
            matriceResult[i][j]=0;
            for (k=0; k<q; k++){
                matriceResult[i][j] += tab1[i][k]*tab2[k][j];
            }
        }
    }

    printf("Matrice multiplication : \n");
    affiche_matrice(n,p, matriceResult);
    return 0;
}

int main(){

    //Creation des matrices

    int matriceA[8][8];
    int matriceB[8][8];
    int matriceC[8][8];

    //Initialisation des matrices

    matriceA[0][0] = 1;
    matriceA[0][1] = 0;
    matriceA[0][2] = 4;
    matriceA[1][0] = -1;
    matriceA[1][1] = 2;
    matriceA[1][2] = -5;

    matriceB[0][0] = 2;
    matriceB[0][1] = -3;
    matriceB[0][2] = 1;
    matriceB[1][0] = 5;
    matriceB[1][1] = 8;
    matriceB[1][2] = 2;

    matriceC[0][0] = 0;
    matriceC[0][1] = 1;
    matriceC[1][0] = 2;
    matriceC[1][1] = -1;
    matriceC[2][0] = 3;
    matriceC[2][1] = 4;

    printf("Matrice A : \n");
    affiche_matrice(2, 3, matriceA);
    printf("MatriceB : \n");
    affiche_matrice(2, 3, matriceB);
    printf("MatriceC : \n");
    affiche_matrice(3, 2, matriceC);

    additionner_matrice(2, 3, matriceA, matriceB);

    transposee(3, 2, matriceA);

    produitMatriciel(2, 3, 2, matriceA, matriceC);



}
