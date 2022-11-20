#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"
#include "convert_hexa.h"
#include "header.h"
#include "lecture_instructions.h"

int main(){
  /*
  char *commande = ec_malloc(sizeof(char)*20);
  char *code = ec_malloc(33);
  char *mot = ec_malloc(9);
  code = bit(543293640,32);
  printf("%s\n", code);
  mot = gotohexa(code);
  printf("%s\n", mot);*/
  /*int exit =0;
  while(exit != 1){
    scanf("%[^\n]%*c", commande); /*prend en compte les espaces (limite du scanf)
    printf("%s\n", commande);
  }*/

  printf("Instruction : %s\n", "ADDI $5, $0, 5");
  char operateur[5];                                  //Vérifier valeur
  lecture_operateur("ADDI $5, $0, 5", operateur);
  printf("Opérateur : %s\n", operateur);
  int operande[3] = {-1,-1,-1};                       //Attention pour la suite si y a besoin de moins de 3 opérandes
  lecture_operandeI("ADDI $5, $0, 5", operande);
  

  //printf("Instruction : %s\n", "ADD $7, $15, $2");
  //lecture_operandeR("ADD $7, $15, $2", operande);

  int i = 0;
  for(i=0; i<3; i++){
    printf("%d ", operande[i]);
  }
  printf("\n");


}
