#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"


/*Fonction qui lit une instruction MIPS et qui renvoie l'opérateur de la fonction dans un tableau de char */
void lecture_operateur (char* instruction, char * operateur){

    //on cree notre tableau contenant notre operateur
    /*on constate que nos opérateurs sont codes au plus sur 7 caractères, le 8e caractere est pour la sentinelle*/
    int i = 0;

    while (instruction[i] != ' '&& instruction[i] != '\0'){
        operateur[i] = instruction[i];
        i++;
    }
    operateur[i] = '\0'; //on rajoute manuellement la sentinelle

}

/*On fait le choix de réaliser une fonction par type d'instruction pour la lecture des opérandes*/


/*Fonction qui récupère les registres (les opérandes) des instructions de type R*/
void lecture_operandeR (char* instruction, int* operande){

    int i = 0;
    int c = 0;

    while (instruction[i] != '\0'){
        if ((instruction[i] == '$') && ((instruction[i+2] == ',') || (instruction[i+2] == '\0'))){ //si le registre est entre 0 et 9
            operande[c] = instruction[i+1] -48;
            if((operande[c]<0) || (operande[c]>31)){//Pour savoir si les registre donnés sont valide
                fatal("Insérer des registres entre 0 et 31");
            }
            c++;
        }
        else if((instruction[i] == '$') && ((instruction[i+3] == ',') || (instruction[i+3] == '\0'))){ //si le registre est superieur a 10 
            operande[c] = (instruction[i+1] - 48)*10 + (instruction[i+2] - 48);
            if((operande[c]<0) || (operande[c]>31)){//Pour savoir si les registre donnés sont valide
                fatal("Insérer des registres entre 0 et 31");
            }
            c++;
        } 
        i++;
    }
}

/*Fonction qui récupère les registres (les opérandes) des instructions de type I ainsi que la valeur immédiate de l'offset*/
void lecture_operandeI (char* instruction, int* operande){

    int i = 0; //indice de l'instruction
    int c = 0; //indice de l'operande


    while (instruction[i] != '\0'){

        /*Lecture des registres*/
        if ((instruction[i] == '$') && ((instruction[i+2] == ','))){ //si le registre est entre 0 et 9
            operande[c] = instruction[i+1] -48;
            c++;
        }
        else if((instruction[i] == '$') && (instruction[i+3] == ',')){ //si le registre est superieur a 10 
            operande[c] = (instruction[i+1] - 48)*10 + (instruction[i+2] - 48);
            c++;
        }

        /*Lecture de la valeur immediate codée sur 16 bits ! (offset)*/
        else if((instruction[i] == ' ') && (instruction[i+1] != '$')){
            int signe;
            i++;
            if (instruction[i] == '-'){  //si la valeur de l'offset est négative
                signe = -1;
                operande[c] = -(instruction[i+1]-48);
                i++;
            }
            else{                       //si la valeur de l'offset est positive
                signe = 1;
                operande[c] = instruction[i]-48;
            }
            while (instruction[i+1] != '\0'){ //tant qu'on est pas arrivé à la fin de l'instruction, on lit la valeur de l'offset que l'on transforme en décimal
                i++;
                operande[c] = operande[c]*10 + signe*(instruction[i]-48);
            }
        }

        i++;
    }
}

/*Fonction qui récupère l'adresse de target des instructions de type J*/
void lecture_operandeJ (char* instruction, char* target) {

    int i = 0; //indice de l'instruction
    int c = 0; //indice de l'adresse target

    while (instruction[i] != ' ' && instruction[i] != '\0'){ //on avance jusqu'au target
        i++;
    }
    while (instruction[i+1] != '\0'){
        target[c] = instruction[i+1]; //on récupère le target
        i++;
        c++;
    }
}
