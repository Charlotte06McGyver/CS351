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

/*Dimensions maximales des matrices*/
#define DIM_MAX 5

/*Retour des fonctions matrices*/
#define MATRICE_OK 1
#define MAUVAISE_DIMENSION -1
#define SOMME_IMPOSSIBLE -2
#define PRODUIT_IMPOSSIBLE -3

void initMatrice(int A[DIM_MAX][DIM_MAX]);

int afficherMatrice(int A[DIM_MAX][DIM_MAX], int lignes_a, int colonnes_a);
int additionnerMatrice(int A[DIM_MAX][DIM_MAX], int lignes_a, int colonnes_a, int B[DIM_MAX][DIM_MAX],   int lignes_b, int colonnes_b, int RES[DIM_MAX][DIM_MAX], int* lignes_res, int* colonnes_res);
int transposee(int A[DIM_MAX][DIM_MAX], int lignes_a, int colonnes_a, int RES[DIM_MAX][DIM_MAX], int* lignes_res, int* colonnes_res);
int produitMatriciel(int A[DIM_MAX][DIM_MAX], int lignes_a, int colonnes_a, int C[DIM_MAX][DIM_MAX], int lignes_c, int colonnes_c, int RES[DIM_MAX][DIM_MAX], int* lignes_res, int* colonnes_res);

#endif
