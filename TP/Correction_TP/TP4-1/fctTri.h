/**
  * CS351 - Corrections de TP 2016-2017
  * Projet TP5-1
  * fctTri.h
  * Eva Gerbert-Gaillard
  */
  
#ifndef __FCTTRI_H__
#define __FCTTRI_H__

#include <stdio.h>
#include <stdlib.h>

/*prototypes*/
int lireDonnees(char nomFichier[], int T[]);
void afficherTableau(int T[], int nb);
void triABulles (int T[], int nb);
void enregistrerDonnees(char nomFichier[], int T[], int nb);

#endif
