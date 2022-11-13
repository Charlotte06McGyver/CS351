/**
  * CS351 - Corrections de TP 2016-2017
  * Projet TP3-2
  * bib_maths.c
  * Eva Gerbert-Gaillard
  */
  
#include "bib_maths.h"

int quotient (int a, int b) {
	int i=0;
	
	while (a>=b) {
		a = a - b;
		i++;
	}
	return (i);
}

int reste (int a, int b) {
	return ( a-b*quotient(a,b));
}

int valeurAbsolue(int a) {
	return (abs (a));
}

int pgcd (int a, int b) {
	int r;

	while (b !=0) {
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int ppcm (int a, int b) {
	return (valeurAbsolue(a*b)/pgcd(a,b));
}
