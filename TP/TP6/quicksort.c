#include <stdio.h>
#include <stdlib.h>


void affiche(int* a, int n){ //fonction qui affiche les elements du tableau, prend en argument le tableau et sa taille
	int i;
	for (i = 0 ; i < n ; i++){
		printf("%d ", a[i]);
	}
	printf("\n\n");
}


void swap(int* a, int* b) //fonction qui echange les valeurs dans un tableau
{
	int va, vb;
	va = *a; //va prend la valeur a l'adresse a
	vb = *b;
	*a = vb;
	*b = va;
}

void quicksort (int tab[], int premier, int dernier){  //on prend en parametre le tableau, le premier et le dernier element du tableau
    
    int pivot, droite, gauche; //on declare le pivot, l'element a droite et l'element a gauche du tableau

    if (premier<dernier) {
        pivot = premier; //on prend le pivot de façon aleatoire, soit le premier element du tableau
        gauche = premier;
        droite = dernier;
        while (gauche<droite){
            while (tab[gauche]<=tab[pivot] && gauche<dernier){
                gauche++;
            }
            while (tab[droite]>tab[pivot]){
                droite--;
            }
            if (gauche<droite){
                swap(&tab[gauche], &tab[droite]);
                gauche++;
                droite--;
            }
        }
        swap(&tab[pivot], &tab[droite]);
        quicksort(tab, premier, droite-1);
        quicksort(tab, droite+1, dernier);

    }
}

int main(){

    int tab1[8] = {5, 2, 1, 6, 7, 3, 9, 4};

    printf("Tableau non trie :\n");
    affiche(tab1, 8);

    quicksort(tab1, 0, 7);
    printf("Tableau trie :\n");
    affiche(tab1, 8);

}