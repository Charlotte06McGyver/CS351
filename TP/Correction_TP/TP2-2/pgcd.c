#include<stdio.h>

int pgcd(int a,int b){
	int r;
	while (b!=0){
#ifdef MISEAUPOINT
		printf("valeur courante de b=%d\n",b );
#endif
		r=a%b;
		a=b;
		b=r;
		}

	return(a);
}
