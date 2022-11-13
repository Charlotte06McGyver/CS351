#include <stdio.h>
#include "pgcd.h"
#include "quotient.h"
#include "valeurAbsolue.h"
#include "reste.h"
#include "sommeDesImpairs.h"
#include "estUneDecompositionDe.h"
#include "ppm.h"
#include "puissanceMB.h"
int testBibliotheque(int a,int b){
	printf("Test de la fonction PGCD\n");
	pgcd(a,b);
	pgcd(b,a);
	pgcd(0,a);
	pgcd(a,0);
	printf("Test de la fonction QUOTIENT\n");
	quotient(a,b);
	quotient(b,a);
	quotient(a,0);
	quotient(0,a);
	printf("Test de la fonction VALEURABSOLUE\n");
	valeur_absolue(a);
	valeur_absolue(0);
	printf("Test de la fonction RESTE\n");
	reste(a,b);
	reste(b,a);
	reste(0,a);
	reste(a,0);
	printf("Test de la fonction sommeDesImpairs\n");
	sommeDesImpairs(a,b);
	sommeDesImpairs(b,a);
	sommeDesImpairs(a,0);
	sommeDesImpairs(0,a);
	printf("Test de estUneDecompositionDe\n");
	estUneDecompositionDe(a,b);
	estUneDecompositionDe(b,a);
	estUneDecompositionDe(0,a);
	estUneDecompositionDe(a,0);
	printf("Test de puissanceMB\n");
	puissanceMB(a,b);
	puissanceMB(b,a);
	puissanceMB(a,0);
	puissanceMB(0,a);

	return 0;
}
	


void main(){
	testBibliotheque(10,12);
}