#include <stdio.h>
#include "quotient.h"

int reste(int a,int b){
	return a-quotient(a,b)*b;
}
