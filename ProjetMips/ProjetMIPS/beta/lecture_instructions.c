#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"


/*Fonction qui lit une instruction MIPS et qui renvoie l'opérateur de la fonction dans un tableau de char */
char* lecture_operateur (char* instruction){

    char* operateur = ec_malloc(8); //on cree notre tableau contenant notre operateur
    /*on constate que nos opérateur sont codes au plus sur 7 caractères, le 8e caractere est pour la sentinelle*/
    int i = 0;

    while (instruction[i] != ' '&& instruction[i] != '\0'){
        operateur[i] = instruction[i];
        i++;
    }
    operateur[8] = '\0'; //on rajoute manuellement la sentinelle

    return operateur;
}

int* lecture_operande_old (char* instruction){

    int* operande = ec_malloc(sizeof(int)*3); //tableau contenant les operandes de l'instruction
    /*on constate qu'il y a au plus 3 opérandes pour chaque instruction*/

    int i = 0; //compteur d'instruction
    int c = 0; //compteur du tableau operande

    while (instruction[i]!="$"){
        i++;
    }
    while (c <= 3){
        if (instruction[i]=='$'){
            operande[c] = instruction[i+1];
            c++;
        }
        i++;
    }

    return 

}

int* lecture_operande (char* instruction){

    int* operande = ec_malloc(sizeof(int)*3);
    int i = 0;

    while (instruction[i] ! = '\0'){



    }
}
