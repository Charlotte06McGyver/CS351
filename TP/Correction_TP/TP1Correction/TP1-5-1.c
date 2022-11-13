/**
  * CS351 - Corrections de TP 2016-2017
  * TP2-1.c
  * Eva Gerbert-Gaillard
  */
  
#include <stdio.h>

/* fibonacci non recursive (pour la recursivite -> voir TP 7) */
int fibonacci (int n) {
	int u0, u1, u2, i;		/* notation u0 = u(i-0), u1 = u(i-1), u2 = u(i-2) */
	u2 = 0;
	u1 = 1;
	
	if (n>=2) {
		for (i=2; i<=n; i++)  {
			u0 = u1 + u2;
			u2 = u1;
			u1 = u0;
		}
	} else {
		u0 = n; /* En supposant n>=0 */
	}
	
	return u0;
}

int main () {
	int n, resultat;

	printf("Pour calculer la valeur de la suite de Fibonacci au rang n, entrez n:\n");
	scanf("%d", &n);
	resultat = fibonacci(n);
	printf("Le terme de rang %d de cette suite vaut %d.\n", n, resultat);
	
	return 0;
}
