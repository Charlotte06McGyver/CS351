#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#include <math.h>

/*Fonction qui convertit les paquets de 4 bits en puissances de 2*/
int binaryhexa(char mot[4]){
  int value = 0;
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

/*Fonction qui convertit en hexa tous les nombres entre 10 et 15*/
char tohexa(int value){
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
  return resultat;
}

/*Fonction qui convertit 32 bits en un tableau de 8 éléments (en hexadécimal)*/
void *gotohexa(char *code){
  int i = 0;
  int index = 0;
  char value[2];
  char *mot = ec_malloc(8); //tableau dans lequel on va stocker nos éléments
  char *mot1= ec_malloc(5);
  while(code[index] != '\0'){
    while((index+1)%4 != 0){
      mot1[i] = code[index];
      i++;
      index++;
    }
    mot1[i]=code[index];
    value[0] = tohexa(binaryhexa(mot1));
    value[1] = '\0';
    strcat(mot, value);
    binaryhexa(mot1);
    index++;
    i = 0;

}
  //printf("%s\n", mot);
  free(mot1);
  return mot;

}

/*Fonction qui cherche la puissance de 2 qui correspond à notre entier*/
int byte(int value){
  int i= 0;
  int a = 1;
  while(a == 1){
    if(pow(2,i)<= value){
      i++;
    }
    else{
      a = 0;
    }
  }
  i--;
  return i;
}

/*Fonction qui convertit un décimal en binaire*/
void *bit(int value, int size){
  int res = 0;
  char *tab = ec_malloc(size+1); //tableau de bit qui va être retourné (taille +1 pour la sentinelle)
  int i = 0;
  int index = 0;
  int index_of_1 = 0;
  int index_prec = 0;
  while(value != 0){
    index = byte(value);
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

  return tab;
}
