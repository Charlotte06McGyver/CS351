#include <stdlib.h>
#include <stdio.h>
#include "graphlib.h"
// Nous avons un problème de compilation.
//void dessineCarre(float x1,float y1 , float taille);
//void dessineCarreDiagonale(float x1,float y2, float taille);

void dessineCarre(float x1, float y1 , float taille){
    float x2 = 0;
    float x3 = 0;
    float y2 = 0;
    float y3 = 0;

    x2 = x1 - (taille/2);
    x3 = x1 + (taille/2);
    y2 = y1 + (taille/2);
    y3 = y1 + taille;

   // printf("(x1,y1): (%f,%f)\n", x1,y1);
    //printf("(x2,y2): (%f,%f)\n", x2,y2);
    //printf("(x3,y2): (%f,%f)\n", x3,y2);
    //printf("(x4,y4): (%f,%f)\n", x1,y3);
    line(x1,y1,x2,y2);
    line(x2,y2,x1,y3);
    line(x1,y3,x3,y2);
    line(x3,y2,x1,y1);

}

void dessineCarreDiagonale(float x1,float y1, float taille){
  float x2 = 0;
  float y2 = 0;
  x2 = x1 - (taille/2);
  y2 = y1 + (taille/2);


  dessineCarre(x1,y2 , taille);
  line(x1,y1, x1, y1+taille);
  line(x2, y2, x2+taille, y2);

}
