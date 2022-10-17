#include <stdio.h>
#include <stdlib.h>

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

void affiche_tab(int* a, int n){ //fonction qui affiche les elements du tableau, prend en argument le tableau et sa taille
	int i;
	for (i = 0 ; i < n ; i++){
		printf("%d ", a[i]);
	}
	printf("\n\n");
}


void elements_non_nuls(int n, int p, int tab[][8]){

    int A[64];
    int i,j;
    int k=0;
    for (i=0; i<n; i++){
        for(j=0; j<p; j++){
            if(tab[i][j] != 0){
                A[k] = tab[i][j];
                k++;
            }
        }
    }
    affiche_tab(A, 6);

}



int main(){

    int matriceA[8][8];

    matriceA[0][0] = 1;
    matriceA[0][1] = 2;
    matriceA[0][2] = 0;
    matriceA[0][3] = 0;
    matriceA[0][4] = 0;
    matriceA[0][5] = 0;
    matriceA[0][6] = 0;
    matriceA[0][7] = 0;

    matriceA[1][0] = 0;
    matriceA[1][1] = 3;
    matriceA[1][2] = 0;
    matriceA[1][3] = 0;
    matriceA[1][4] = 0;
    matriceA[1][5] = 0;
    matriceA[1][6] = 9;
    matriceA[1][7] = 0;

    matriceA[2][0] = 0;
    matriceA[2][1] = 0;
    matriceA[2][2] = 0;
    matriceA[2][3] = 0;
    matriceA[2][4] = 0;
    matriceA[2][5] = 0;
    matriceA[2][6] = 0;
    matriceA[2][7] = 0;

    matriceA[3][0] = 0;
    matriceA[3][1] = 0;
    matriceA[3][2] = 1;
    matriceA[3][3] = 0;
    matriceA[3][4] = 0;
    matriceA[3][5] = 0;
    matriceA[3][6] = 0;
    matriceA[3][7] = 4;

    printf("Matrice creuse :\n");
    affiche_matrice(4, 8, matriceA);
    printf("------------------------------------------\n");

    printf("Elements non nuls de la matrice creuse :\n");
    elements_non_nuls(4, 8, matriceA);

    

}