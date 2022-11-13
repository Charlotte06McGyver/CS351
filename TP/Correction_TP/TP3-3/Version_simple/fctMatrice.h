/**
  * CS351 - Corrections de TP 2016-2017
  * Projet TP4-3
  * fctMatrice.h
  * Eva Gerbert-Gaillard
  */

#ifndef __FCTMATRICE_H__
#define __FCTMATRICE_H__

#include <stdio.h>
#include <stdlib.h>

#define M 20


void afficherMatrice(int A[M][M], int n, int m);
void additionnerMatrice(int A[M][M], int B [M][M], int n, int m);
void transposee(int A[M][M], int n, int m);
void produitMatriciel(int A[M][M], int na, int MANB, int C [M][M], int mb);

#endif
