/**
  * CS351 - Corrections de TP 2016-2017
  * Projet TP3-3
  * dessine.c
  * Eva Gerbert-Gaillard
  */
  
#include "dessine.h"

void dessineCarre(int posx, int posy, int taille){
  	line(posx, posy, posx - (taille/2), posy - (taille/2));
  	line(posx - (taille/2), posy - (taille/2), posx , posy - 2*(taille/2));
 	line(posx, posy - 2*(taille/2), posx + (taille/2), posy - (taille/2));
 	line(posx + (taille/2), posy - (taille/2), posx, posy);
}

void dessineCarreDiagonale(int posx, int posy, int taille){
  	dessineCarre(posx, posy, taille);
  	line(posx - (taille/2), posy - (taille/2), posx + (taille/2), posy -(taille/2));
  	line(posx, posy, posx, posy - 2*(taille/2));
}

void dessineMosaique(int posx, int posy, int taille, int hauteur, int largeur){
  	int i, j;
  
  	for (i=0; i<=(hauteur-1); i++) {
    		for (j=0; j<=(largeur-1); j++) {
      			dessineCarre(posx + (taille/2)*(1+2*j), posy - i*2*(taille/2), taille);
    		}
  	}
}

void dessineMosaiqueAvecSouris(int hauteur, int largeur){
	int posx, posy;
	int a, b;
	int taille;

	cliquer_xy(&posx,&posy);
	cliquer_xy(&a,&b);

	a = a - posx;
	if(a<0){a=-a;}
	b = b - posy;
	if(b<0){b=-b;}
	taille = (a + b) / 2;
	dessineMosaique(posx, posy, taille, hauteur, largeur);
}	


