/**
  * CS351 - Corrections de TP 2016-2017
  * TP1-4.c
  * Eva Gerbert-Gaillard
  */

#include <stdio.h>

int main() {
	int i, j, k, l;

	i = j = k = l = 0;

	while (i<9) {
		printf("i++ = %d, ++j = %d, k-- = %d, --l = %d\n", i++, ++j, k--, --l);
	}

	printf ("i = %d, j=%d, k=%d, l=%d\n", i, j, k, l);
	
	return (0);
}


/* Afficahge lors de l'exécution :

i++ = 0, ++j = 1, k-- = 0, --l = -1
i++ = 1, ++j = 2, k-- = -1, --l = -2
i++ = 2, ++j = 3, k-- = -2, --l = -3
i++ = 3, ++j = 4, k-- = -3, --l = -4
i++ = 4, ++j = 5, k-- = -4, --l = -5
i++ = 5, ++j = 6, k-- = -5, --l = -6
i++ = 6, ++j = 7, k-- = -6, --l = -7
i++ = 7, ++j = 8, k-- = -7, --l = -8
i++ = 8, ++j = 9, k-- = -8, --l = -9	
i = 9, j = 9, k = -9, l = -9	

Dans tous les cas il y a un évaluation (observation de la valeur de la variable) 
et une opération d'incrémentation ou de décrémentation.
Lorsque l'opérateur est avant la variable, l'évaluation se fait après l'opération.
Lorsque l'opérateur est après la variable, l'évaluation se fait avant l'opération.	

*/