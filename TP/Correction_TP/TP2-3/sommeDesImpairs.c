#include <stdio.h>
int sommeDesImpairs(int d,int f){
	int resultat=0;
	while (d <= f){
		resultat = resultat + d;
		d += 2;
	}
	return resultat;
}
