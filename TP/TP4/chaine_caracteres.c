#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int myStrlen(char *mot){
    int len =0;

    while(*(mot +len) != '\0'){
        len++;
    }
    return len;
}

void myStrcpy(char *mot1, char *mot2){
    int len = myStrlen(mot1);
    int i = 0;

    for(i; i<len; i++){
        mot2[i]= mot1[i];
    }
}

void affichagerHexadecimal(char *mot){
    int len = myStrlen(mot);
    int i = 0;
    for(i;i<len; i++){
         printf("0x%x ", mot[i]);
    }
    printf("\n");
}

int affichageEnDecimal(char *mot){

    int i = 0;

    for (i=0; i<strlen(mot); i++){
        printf("%d ", mot[i]);
    }

    return 0;
}

int mettreEnMajuscule(char *mot){

    int i = 0;

    for (i=0; i<strlen(mot); i++){
        printf("%c", toupper(mot[i]));
    }

    return 0;

}

int mettreEnMinuscule(char *mot){

    int i = 0;

    for (i=0; i<strlen(mot); i++){
        printf("%c", tolower(mot[i]));
    }

    return 0;

}

int transformerMinMaj(char *mot){

    int i = 0;

    for (i=0; i<strlen(mot); i++){
        if (islower(mot[i]) > 0){
            printf("%c", toupper(mot[i]));
        }
        if (isupper(mot[i])>0){
            printf("%c", tolower(mot[i]));
        }
    }

    return 0;
}

char* retournerMot(char *mot){

    int i = strlen(mot)-1;
    int j = 0;
    char *nv_mot = malloc(sizeof(char)*(strlen(mot)+1)); //possible aussi avec un malloc
    //strcpy(nv_mot,mot);
    for (i; i>=0; i--){
      nv_mot[i] = mot[j];
      j++;

    }

    return nv_mot;
}

int rechercherCaractereG(char *mot, char caractere){

    int i = 0;
    int position = -1;

    while (position == -1){
        if (mot[i] == caractere){
            position = i;
        }
        i++;
    }
    return position;

}

int rechercherCaractereD(char *mot, char caractere){

    int i = strlen(mot);
    int position = -1;

    while (position == -1){
        if (mot[i] == caractere){
            position = i;
        }
        i--;
    }
    return position;

}

int estPalindrome (char *mot, int d, int f){

    int result = 1;
    while ((result ==  1) && (d<f)) {
        if (mot[d] != mot[f]){
            result = 0;
        }
        d++;
        f--;
    }
    return result;

}

int comparerChaine(char *mot1, char *mot2){//J'ai supposé que les deux mot sont de taille égale
  int value= 0;
  int size1 = strlen(mot1);
  int i = 0;

  for(i; i<size1;i++){
    if(mot1[i]>mot2[i]){
      value = 1;
      i = size1;
    }else if(mot1[i]<mot2[i]){
      value = -1;
      i = size1;
    }
  }
  return value;
}

int valeurDecimal(char *mot){
  int len = strlen(mot)-1;
  int i = 0;
  int value = 0;
  for(i; i<=(strlen(mot)-1);i++){
    if(mot[0]=='\0'){
      value = 0;
      i = strlen(mot);
    }else{
    if(mot[i]=='0'){
        value = value + 0*pow(10,len);
    }else if(mot[i] == '1'){
        value = value + 1*pow(10,len);
    }else if(mot[i] == '2'){
        value = value + 2*pow(10,len);
    }else if(mot[i] == '3'){
        value = value + 3*pow(10,len);
    }else if(mot[i] == '4'){
        value = value + 4*pow(10,len);
    }else if(mot[i] == '5'){
        value = value + 5*pow(10,len);
    }else if(mot[i] == '6'){
        value = value + 6*pow(10,len);
    }else if(mot[i] == '7'){
        value = value + 7*pow(10,len);
    }else if(mot[i] == '8'){
        value = value + 8*pow(10,len);
    }else{
        value = value + 9*pow(10,len);
    }
    len--;
    }
  }
  return value;
}

int main(){
    char *mot = "test123123";
    char *mot1 = malloc(sizeof(char)*myStrlen(mot));
    printf("myStrlen de test123123 :%d\n",myStrlen(mot));
    myStrcpy(mot, mot1);
    printf("myStrcpy de test123123 : %s\n", mot1);
    printf("affichagerHexadecimal de test123123 : ");
    affichagerHexadecimal(mot);
    printf("affichageEnDecimal test: ");
    affichageEnDecimal("test");
    printf("\n");
    printf("mettreEnMajuscule test: ");
    mettreEnMajuscule("test");
    printf("\n");
    printf("mettreEnMinuscule TEST: ");
    mettreEnMinuscule("TEST");
    printf("\n");
    printf("transformerMinMaj TeSt: ");
    transformerMinMaj("TeSt");
    printf("\n");
    printf("retournerMot oiseau: ");
    printf("%s\n", retournerMot("oiseau"));
    printf("comparerChaine entre test et test: ");
    printf("%d\n", comparerChaine("test", "test"));
    printf("comparerChaine entre tast et test: ");
    printf("%d\n", comparerChaine("tast", "test"));
    printf("comparerChaine entre test et tast: ");
    printf("%d\n", comparerChaine("test", "tast"));
    printf("valeurDecimal de 1234 devient: %d\n", valeurDecimal("1234"));
    printf("rechercherCaractereG coucou c'est moi moumou , 'e' : %d\n", rechercherCaractereG("coucou c'est moi moumou", 'e'));
    printf("rechercherCaractereG coucou c'est moi moumou , 'p' : %d\n", rechercherCaractereD("coucou c'est moi moumou", 'p'));

}
