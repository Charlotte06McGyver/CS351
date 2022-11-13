/**
  * CS351 - Corrections de TP 2016-2017
  * Projet TP4-1
  * fctNotes.h
  * Eva Gerbert-Gaillard
  */

#ifndef __FCTNOTES_H__
#define __FCTNOTES_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Partie obligatoire*/
void afficherNotes();
float minimumNote();
float maximumNote();
float calculeMoyenne();
float calculeVariance();
float calculeEcartType();
int rechValeur(float notes[], int n, float v);

/*Partie optionnelle*/
void histoHorizontal();
void histoVertical();

#endif
