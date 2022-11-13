/**
  * CS351 - Corrections de TP 2016-2017
  * Projet TP3-3
  * main_mosaic.c
  * Eva Gerbert-Gaillard
  */
  
#include <stdio.h>
#include <stdlib.h>

#include "graphlib.h"
#include "dessine.h"

#define LARG 800
#define HAUT 600
#define TITRE "TP3 - Trace de mosaiques"


int main () {
  	int choix = 0;
  	int couleur = 0;
  	int posx, posy, taille, hauteur, largeur;

	posx = posy = taille = hauteur = largeur = 0;
  
  	gr_inits_w(LARG, HAUT, TITRE);
  
  	printf("Bienvenue dans le programme de creation de mosaiques  \
		\nLes hateurs, largeurs et tailles des traces sont donnes en pixels (donc en entiers) \
		\nLa fenêtre qui a ete cree fait %d x %d pixels \
		\nLes positions sont decrites depuis le haut gauche de la fenetre\n", LARG, HAUT);
  	
	do {
    		printf("Pour  quitter : entrez 0 \
				\nPour effacer les traces : entrez 1 \
				\nPour choisir une couleur de trace : entrez 2 \
				\nPour tracer un carre : entrez 3 \
				\nPour tracer un carre avec ses diagonales : entrez 4 \
				\nPour tracer une mosaique : entrez 5 \
				\nPour tracer une mosaique avec la souris : entrez 6\n");
    		scanf("%d", &choix);
    
    		switch (choix) {
      			case 0 : break;
     			case 1 : clear_screen(); break;
      			case 2 : /*choix de la couleur*/
        			printf("Choix de la couleur du trace :\nNoir : 0\nBleu : 1\nRouge : 2\nVert : 3\nJaune : 4\n");
        			scanf("%d", &couleur);
        			switch (couleur) {
          				case 0 : set_black(); break;
          				case 1 : set_blue(); break;
          				case 2 : set_red(); break;
          				case 3 : set_green(); break;
          				case 4 : set_yellow(); break;
          				default : break;
        			} break;
      			case 3 : /*trace un carré*/
        			printf("Entrez la position du carre (x puis y):\n");
        			scanf("%d", &posx);
        			scanf("%d", &posy);
        			printf("Entrez la taille du carre: ");
        			scanf("%d", &taille);
        			dessineCarre(posx, posy, taille); 
				break;
        
      			case 4 : /*trace un carré avec diagonales*/
        			printf("Entrez la position du carre (x puis y):\n");
        			scanf("%d", &posx);
        			scanf("%d", &posy);
        			printf("Entrez la taille du carre: ");
        			scanf("%d", &taille);
        			dessineCarreDiagonale(posx, posy, taille); 
				break;
        
      			case 5 : /*trace une mosaique*/
        			printf("Entrez la position de la mosaique (coin bas gauche x puis y):\n");
        			scanf("%d", &posx);
       				scanf("%d", &posy);
        			printf("Entrez la taille du carre: ");
        			scanf("%d", &taille);
        			printf("Entrez la largeur puis la hauteur de la mosaique (en nombre de carres) :\n");
        			scanf("%d", &largeur);
        			scanf("%d", &hauteur);
        			dessineMosaique(posx, posy, taille, hauteur, largeur); 
				break;
			case 6 : /*trace une mosaique avec la souris*/
        			printf("Entrez la largeur puis la hauteur de la mosaique (en nombre de carres) :\n");
        			scanf("%d", &largeur);
        			scanf("%d", &hauteur);
				printf("Cliquer pour definir la position de la mosaique \
					\nPuis cliquer pour definir la taille d'un carre\n");
        			dessineMosaiqueAvecSouris(hauteur, largeur); 
				break;
        
      			default : choix = 0; break;
      			}
		point(-1,-1); /*Instruction graphique nulle a cause de problemes d'affichage*/
      		printf("\n");
    	}

  	while (choix != 0);
  
  
  	return 0;
}
