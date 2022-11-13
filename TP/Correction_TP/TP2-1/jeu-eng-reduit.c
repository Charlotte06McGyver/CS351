void gameMultiPoints () {

	int n = 2, i, ans, errors = 0;

    printf("enter a value between 2 and 9: ");
    scanf("%d", &n);	
	i = 1;
	while (i <= 10 && errors == 0) {
		printf("%d x %d = ", i, n);
		scanf("%d", &ans);
		if (ans != (i * n)) {
			printf("Error ! %d x %d = %d and not %d \n", i, n, i*n, ans);
			errors++;
		}
		i++;
	}
	if (errors == 0) {
		printf("Congrats!\n");
	} else {
		printf("You made %d errors\n\n", errors);
	}
}


