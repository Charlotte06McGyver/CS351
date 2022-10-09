#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pile.h"


int calcul_notation_polonaise (char *operation){

    pileInt Pile_temp = creerPile(); //creation d'une pile temporaire pour stocker l'experssion arithmetique

    int i = 0;
    int temp_a, temp_b, result;
    for (i=0; i<strlen(operation); i++){
        if (operation[i]!='+' || operation[i]!='-' || operation[i]!='*' || operation[i]!='/'){
            empiler(Pile_temp, operation[i]); //si on a un nombre, on l'empile dans notre pile temporaire
        }
        else { //si on a un operateur, on depile les elements qu'on execute entre eux et on stocke le resultat obtenu dans la pile
            if (operation[i]=='+'){ 
                temp_a = depiler(Pile_temp);
                temp_b = depiler(Pile_temp);
                empiler(Pile_temp, (temp_a + temp_b));
            }
            if (operation[i]=='-'){
                temp_a = depiler(Pile_temp);
                temp_b = depiler(Pile_temp);
                empiler(Pile_temp, (temp_a - temp_b));
            }
            if (operation[i]=='*'){
                temp_a = depiler(Pile_temp);
                temp_b = depiler(Pile_temp);
                empiler(Pile_temp, (temp_a * temp_b));
            }
            if (operation[i]=='/'){
                temp_a = depiler(Pile_temp);
                temp_b = depiler(Pile_temp);
                empiler(Pile_temp, (temp_a / temp_b));
            }
        }
    }

    result = depiler(Pile_temp);
    return result;

}

int main()
{

   printf("Calcul en notation polonaise inversee : 42+5*67-/ =  ");
   printf("%d\n", calcul_notation_polonaise("42+5*67-/"));

}