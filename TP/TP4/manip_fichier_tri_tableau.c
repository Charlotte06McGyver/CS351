#include <stdio.h>
#include <stdlib.h>

void afficherTableau( int T[], int nb){

     for(int a = 0; a<(nb-1);a++){
        printf("%d,", T[a]);
    }
    printf("%d\n", T[nb-1]);

}

void swap(int* a, int* b) 
{
	int va;
	va = *a; 
	*a = *b;
	*b = va;
}

int BubbleSort (int tab[], int n)  
{
	int i,j;
	int nb_compar=0;
	for (j=n; j>0; j--)
	{
		for (i=0; i<n-1; i++)
		{
			if (tab[i]>tab[i+1]) 
			{
				swap(&tab[i], &tab[i+1]);
			}
			nb_compar++;	s
		}
	
	}
	return nb_compar;
}

void enregistrerDonnees(char nomFichier[], int T[], int nb){
    FILE *fp = fopen(nomFichier, "w");
    int a = 0;
    if(fp == NULL){
        perror("Probleme ouverture fichier ");
    }
    for(a; a<nb;a++){
        fprintf(fp, "%d ", T[a]);
    }
    fprintf(fp,"\n");
    fclose(fp);
}

int lireDonnees(char nomFichier[], int T[]){
    FILE * file;
    int i = 0;
    int nb;
    file = fopen(nomFichier,"r");

    if(file == NULL){
        perror("Probleme ouverture fichier ");
    }
    while(!feof(file)){
        if(fscanf(file,"%d",&nb) != EOF){
            T[i] = nb;
            i++;
        }
    }
  
    //afficherTableau(T, i);

    fclose(file);

    return i;
}

int main(){
    int T[20];
    int a=0;
    a = lireDonnees("test.txt", T);
    BubbleSort(T, a);
    afficherTableau(T,a);
    enregistrerDonnees("tri.txt",T,a);
}