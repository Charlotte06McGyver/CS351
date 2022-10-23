#include <stdio.h>

int main(){
	int annee = 0;
	printf("Entrez une année: ");
	scanf("%d", &annee);
       	if(annee%100 == 0){
			if(annee%4==0)
				printf("L'annee %d est bissextile\n", annee);
			else
				printf("L'annee %d n'est pas bissextile\n", annee);		
	}else if(annee%4 == 0)
		printf("L'annee %d est bissextile\n", annee);
	else
		printf("L'annee %d n'est pas bissextile\n", annee); 
}
/* Il faut tester 4 cas : une année qui n'est pas divisble par 100 mais bissextile donc <100
une année divisible par 100 mais pas par 4
une année divisible par 100 et par 4
une année pas divisible par 4 et par 100
