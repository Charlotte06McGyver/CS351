/**
  * CS351 - Corrections de TP 2016-2017
  * Projet TP3-1
  * TP2-4.c
  * Eva Gerbert-Gaillard
  */

#include <stdio.h>



void gameMultiPoints () {
	int n = 2;
	int i;
	int ans;
	int errors = 0;

	do {
        printf("enter a value between 2 and 9: ");
        scanf("%d", &n);
	}
	while ((n < 2) || (n > 9));

	for (i = 1; i <= 10; i++) {
		printf("%d x %d = ", i, n);
		scanf("%d", &ans);
		if (ans != (i * n)) {
			printf("Error ! %d x %d = %d and not %d \n", i, n, i*n, ans);
			errors++;
		}
	}

	if (errors == 0) {
		printf("Congrats!\n");
	} else {
		printf("You made %d errors\n\n", errors);
	}
}


