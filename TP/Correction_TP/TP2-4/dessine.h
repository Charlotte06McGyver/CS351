/**
  * CS351 - Corrections de TP 2016-2017
  * Projet TP3-3
  * dessine.h
  * Eva Gerbert-Gaillard
  */

#ifndef __DESSINE_H__
#define __DESSINE_H__

#include <stdio.h>

#include "graphlib.h"

/*prototypes*/
void dessineCarre(int posx, int posy, int taille);
void dessineCarreDiagonale(int posx, int posy, int taille);
void dessineMosaique(int posx, int posy, int taille, int hauteur, int largeur);
void dessineMosaiqueAvecSouris(int hauteur, int largeur); 

#endif
