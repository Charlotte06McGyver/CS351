#include<stdio.h>
#include "valeurAbsolue.h"
#include "pgcd.h"
int ppcm(int a, int b){
	return valeur_absolue(a*b)/pgcd(a,b);
}
