#include <stdio.h>
int quotient(int a,int b){
	int z = 0;
	int signe = 1;
	if (a < 0){
		a = -a;
		signe = -1;
	}
	if (b < 0){
		b = -b;
		signe = -signe;
	}
	/* on suppose b != 0, sinon boucle infinie */
	while (a >= b){
		a -= b;
		z += 1;
	}
	return signe * z;
}