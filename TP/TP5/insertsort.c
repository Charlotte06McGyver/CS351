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


int InsertSort (int *tab, int n){ //prend en argument le tableau et sa taille
	
	int i,j;
	int nb_compar=0;
	for (i=0; i<n-1; i++){
		if (tab[i]>tab[i+1]){
			j=i; //on cree une nouvelle variable j pour ne pas perdre l'indice i
			while (tab[j]>tab[j+1]){ //on compare maintenant la valeur associee a j avec la suivante dans le tableau
				swap (&tab[j],&tab[j+1]);
				nb_compar++;
				if (j != 0){
					j--;
				}				
			}
		}
		else {
			nb_compar++; // prend en compte la premiere comparaison
		}
	}
	return nb_compar;	
}

int main(){

    int tab1[8] = {5, 2, 1, 6, 7, 3, 9, 4};

    printf("Tableau non trie :\n");
    affiche(tab1, 8);

    int nb_compar = InsertSort(tab1, 8);
    printf("Tableau trie :\n");
    affiche(tab1, 8);
    printf("Nombre de comparaisons : %d\n", nb_compar);


}