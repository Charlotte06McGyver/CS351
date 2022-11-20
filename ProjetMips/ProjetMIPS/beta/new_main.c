#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "header.h"
#include "convert_hexa.h"
#include "lecture_instructions.h"
#include "beta.h"

int main(){
    
    char *commande = (char*)malloc(sizeof(char)*20);
    int exit = 0;
 
    commande[0] = '\0';
   
 

    while(exit == 0){
    scanf("%[^\n]%*c", commande);
    if(strcmp(commande, "\0")==0){
      fatal("Don't use double Enter");
      
    }else if((strcmp(commande, "EXIT")==0)){
        exit = 1;
    }else{
        fonctions(commande);       
    }
    }
    
    free(commande);
}