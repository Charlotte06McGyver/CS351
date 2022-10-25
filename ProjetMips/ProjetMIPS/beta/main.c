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
  printf("Opérateur : %s\n", lecture_operateur("ADDI $5, $0, 5"));

  printf("Instruction : %s\n", "ADD $7, $15, $2");
  int* result = lecture_operandeR("ADD $7, $15, $2");

  int i = 0;
  for(i=0; i<3; i++){
    printf("%d ", result[i]);
  }
  printf("\n");


}
