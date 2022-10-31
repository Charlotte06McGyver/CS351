#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"


/*Fonction qui lit une instruction MIPS et qui renvoie l'opérateur de la fonction dans un tableau de char */
void lecture_operateur (char* instruction, char * operateur){

     //on cree notre tableau contenant notre operateur
    /*on constate que nos opérateur sont codes au plus sur 7 caractères, le 8e caractere est pour la sentinelle*/
    int i = 0;

    while (instruction[i] != ' '&& instruction[i] != '\0'){
        operateur[i] = instruction[i];
        i++;
    }
    operateur[i] = '\0'; //on rajoute manuellement la sentinelle

}

/*On fait le choix de réaliser une fonction par type d'instruction pour la lecture des opérandes*/

//ADD $7, $5, $2

void lecture_operandeR (char* instruction, int* operande){

    int i = 0;
    int c = 0;

    while (instruction[i] != '\0'){
        if ((instruction[i] == '$') && ((instruction[i+2] == ',') || (instruction[i+2] == '\0'))){ //si le registre est entre 0 et 9
            operande[c] = instruction[i+1] -48;
            c++;
        }
        else if((instruction[i] == '$') && ((instruction[i+3] == ',') || (instruction[i+3] == '\0'))){ //si le registre est superieur a 10 
            operande[c] = (instruction[i+1] - 48)*10 + (instruction[i+2] - 48);
            c++;
        } 
        i++;
    }
}

int* lecture_operandeI (char* instruction){

    int* operande = ec_malloc(sizeof(int)*3);
    int i = 0;
    int c = 0;

    while (instruction[i] != '\0'){
        if ((instruction[i] == '$') && ((instruction[i+2] == ',') || (instruction[i+2] == '\0'))){ //si le registre est entre 0 et 9
            operande[c] = instruction[i+1] -48;
            c++;
        }
        else if((instruction[i] == '$') && ((instruction[i+3] == ',') || (instruction[i+3] == '\0'))){ //si le registre est superieur a 10 
            operande[c] = (instruction[i+1] - 48)*10 + (instruction[i+2] - 48);
            c++;
        } 
        /* else if{
            
        }*/
        i++;
    }
    return operande;
}
