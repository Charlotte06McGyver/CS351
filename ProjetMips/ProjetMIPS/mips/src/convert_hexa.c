#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/header.h"
#include <math.h>

int binaryhexa(char mot[4]){//Converti la veleur binaire en décimal
  int value = 0;
  //On a un tableau de bit, pour chaque bit du tableau qui vaut 1 on fait 2^(4-son rang)
  if(mot[0] == '1'){
    value = value + 8;
  }
  if(mot[1] == '1'){
    value = value + 4;
  }
  if(mot[2] == '1'){
    value = value + 2;
  }
  if(mot[3] == '1'){
    value = value + 1;
  }
  return value;
}

char tohexa(int value){//converti la valeur décimal en hexadécimal
  char resultat;
  if(value == 10){
    resultat = 'a';
  }else if(value == 11){
    resultat = 'b';
  }else if(value == 12){
    resultat = 'c';
  }else if(value == 13){
    resultat = 'd';
  }else if(value == 14){
    resultat = 'e';
  }else if(value == 15){
    resultat = 'f';
  }else{
    resultat = value + '0';
  }
  // on ne moddifie pas les valeurs qio sont comprise entre 0 et 9
  return resultat;
}

void gotohexa(char *code, char *mot){// converti 32 bit en hexadécimal
  int i = 0;
  int index = 0;
  char *value = malloc(sizeof(char)*2);
  char *mot1= (char*)malloc(5);

  while(code[index] != '\0'){// on parcourt tout notre tableau

    while((index+1)%4 != 0){// fait des paquets de 4 bits
      mot1[i] = code[index];
      i++;
      index++;
    }

    mot1[i]=code[index];
    value[0] = tohexa(binaryhexa(mot1));//converti le paquet de 4 bit en héxa
    value[1] = '\0';
    strcat(mot, value);
    index++;
    i = 0;

  }
  mot[8] = '\0';
  free(mot1);
  free(value);

}

int byte(int value){//Calcule le nombre de bit nécessaire pour coder notre décimal en binaire
  int i= 0;
  int a = 1;
  while(a == 1){
    if(pow(2,i)<= value){
      i++;
    }else{
      a = 0;
    }
  }
  i--;
  return i;
}

void bit(int value, int size, char *tab){//Converti un décimal en binaire sur size bit
  int res = 0;
  int i = 0;
  int index = 0;
  int index_of_1 = 0;
  int index_prec = 0;
  int flag =1;

  if(value>=0){
    while(value != 0){
      index = byte(value);//Nous donne le nombre de bit nécessaire pour coder notre nombre
      index_of_1 = size - index - 1;
      res = (int)(pow(2, index));
      value = value - res;
      for(index_prec; index_prec < index_of_1; index_prec ++){
        tab[index_prec] = '0';
      }
      index_prec ++;
      tab[index_of_1] = '1';
    }
    if(index_of_1 != size){
      i = index_of_1 +1;
      for(i; i<size; i++){
        tab[i] = '0';
      }
    }
    tab[size] = '\0';
  }else{
    value = 0 - value;
    while(value != 0){
      index = byte(value);//Nous donne le nombre de bit nécessaire pour coder notre nombre
      index_of_1 = size - index - 1;
      res = (int)(pow(2, index));
      value = value - res;
      for(index_prec; index_prec < index_of_1; index_prec ++){
        tab[index_prec] = '0';
      }
      index_prec ++;
      tab[index_of_1] = '1';
    }
    if(index_of_1 != size){
      i = index_of_1 +1;
      for(i; i<size; i++){
        tab[i] = '0';
      }
    }
    tab[size] = '\0';
    i = 0;
    for(i;i<size; i++){
      if(tab[i] == '0'){
        tab[i] ='1';
      }else{
        tab[i] = '0';
      }
    }
    i = size -1;
    for(i;i>=0;i--){
      if((flag == 1) && (tab[i] =='0')){
        tab[i] = '1';
        flag = 0;
        i = -1;
      }else{
        tab[i] = '0';
        flag = 1;
      }
    }
    tab[size] = '\0';
    
  }
}
