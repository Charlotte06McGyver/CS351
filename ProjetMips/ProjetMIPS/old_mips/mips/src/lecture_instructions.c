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
        }else if((instruction[i] == '$') && ((instruction[i+3] == ' ') || (instruction[i+3] == '\0'))){
           fatal("Trop peut d'argument ou format incorrect: commande $a, $b, $c"); 
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

        /*Lecture de la valeur immediate codée sur 16 bits !*/
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
            while ((instruction[i+1] != '\0') && (instruction[i+1] != '(')){ //tant qu'on est pas arrivé à la fin de l'instruction, on lit la valeur de l'offset que l'on transforme en décimal
                i++;
                operande[c] = operande[c]*10 + signe*(instruction[i]-48);
            }

            if (instruction[i+1] == '('){
                operande[c+1] = operande[c]; //si on a une valeur d'offset, on la met à la fin du tableau résultat
                operande[c] = 0; //on remet operande[c] à 0
                i = i+3;
                while(instruction[i] != ')'){
                    operande[c] = operande[c]*10 + signe*(instruction[i]-48);
                    i++;
                }
            }
        }
        i++;
    }
}

/*Fonction qui récupère l'adresse de target des instructions de type J*/
void lecture_operandeJ (char* instruction, int* target) {

    int i = 0; //indice de l'instruction
    int c = 0; //indice de l'adresse target
    char *mot = (char *)malloc(sizeof(char)*27);
    mot[0] ='\0';
    

    while (instruction[i] != ' ' && instruction[i] != '\0'){ //on avance jusqu'au target
        i++;
    }
    while (instruction[i+1] != '\0'){
        mot[c] = instruction[i+1]; //on récupère le target
        if(mot[c] <48 || mot[c]>57){
            fatal("Trop peu d'argument ou format incorrect");
        }
        i++;
        c++;
    }
    mot[c] = '\0';
    target[0] = atoi(mot);
    if((target[0]< -33554431)|| (target[0]>67108863)){
        fatal("Insérer des adresses entre -33554431 et 67108863");
    }
    free(mot);
}