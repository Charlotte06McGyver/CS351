#include <stdio.h>
	
int puissance_MB(int x, int n) {
    int Ntmp, N = n, Y = 1, Z = x;

    while (N != 0) {
        Ntmp = N;
		N = quotient (N, 2);
        if (Ntmp % 2 != 0) {
             Y = Z * Y;
        }
        Z *= Z;
    }

    return(Y);
}