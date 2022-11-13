#include<stdio.h>
#include "sommeDesImpairs.h"

int estUneDecompositionDe(int d,int f){
	int entier=0;
	int sommeimpairs=0;
	int resultat=-1;
	sommeimpairs=sommeDesImpairs(d,f);
	while((entier<=sommeimpairs) &&(entier*entier*entier!=sommeimpairs)){
		entier = entier + 1;
	}  
	if (entier <= sommeimpairs){
			resultat=entier;
		}
	return resultat;
	
}
