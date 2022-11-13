/**
  * CS351 - Corrections de TP 2016-2017
  * Projet TP5-2
  * fctChaines.c
  * Eva Gerbert-Gaillard
  */

#include "fctChaines.h"

/*Lorsqu'on veut retourner un tableau, on ajoute ce tableau en parametre et on le modifie à l'interieur de la boucle*/

void afficherMot(char mot[]){
	int i = 0;

	while(mot[i] != '\0'){
		printf("%c", mot[i]);
		i++;
	}
}


int myStrlen(char mot[]){
	int i = 0;

	while(mot[i] != '\0'){
		i++;
	}
	return (i);
}

char * myStrcpy(char dest[], char orig[]){
	int i;

	do{
	    dest[i] = orig[i];
	} while(orig[i++] != '\0' ){

	return dest;
}

void afficherEnHexadecimal(char mot[]){
	int i = 0;

	while(mot[i] != '\0'){
		printf("%#x\t", mot[i]);
		i++;
	}
}


void afficherEnDecimal(char mot[]){
	int i = 0;

	while(mot[i] != '\0'){
		printf("%d\t", mot[i]);
		i++;
	}
}

/*Voir table ASCII en hexadecimal p175 du document Introduction_ANSI_C.pdf*/
void mettreEnMajuscule(char mot[], char res[]){
	int i = 0;

	while(mot[i] != '\0'){
		if ((mot[i] >= 0x61) && (mot[i] <= 0x7a)){
			res[i] = mot[i] - 0x20;
		} else {
			res[i] = mot[i];
		}
		i++;
	}
	res[i] = mot[i];
}

/*Voir table ASCII en hexadecimal p175 du document Introduction_ANSI_C.pdf*/
void mettreEnMinuscule(char mot[], char res[]){
	int i = 0;

	while(mot[i] != '\0'){
		if ((mot[i] >= 0x41) && (mot[i] <= 0x5a)){
			res[i] = mot[i] + 0x20;
		} else {
			res[i] = mot[i];
		}
		i++;
	}
	res[i] = mot[i];
}

/*Voir table ASCII en hexadecimal p175 du document Introduction_ANSI_C.pdf*/
void transformerMinMaj(char mot[], char res[]){
	int i = 0;

	while(mot[i] != '\0'){
		if ((mot[i] >= 0x41) && (mot[i] <= 0x5a)){
			res[i] = mot[i] + 0x20;
		} else if ((mot[i] >= 0x61) && (mot[i] <= 0x7a)) {
			res[i] = mot[i] - 0x20;
		}else {
			res[i] = mot[i];
		}
		i++;
	}
	res[i] = mot[i];
}


void retournerMot(char mot[], char res[]){
	int i, n;
	n = myStrlen(mot);

	for (i=0; i<n; i++){
		res[i] = mot[n-1-i];
	}

	res[i] = '\0';
}

/*Dans cette fonction, on différencie les majuscules des minuscules*/
/*On pourrait faire autrement en utilisant la fonction mettreEnMinuscule() comme pré-traitement*/
int rechercherCaractereG(char mot[], char caractere){
	int i = 0;

    while ((mot[i] != '\0') && (mot[i] != caractere)) {
		i++;
	}
	if (mot[i] == '\0') {
		i = -1;
	}

	return i;
}

/*Dans cette fonction, on différencie les majuscules des minuscules*/
/*On pourrait faire autrement en utilisant la fonction mettreEnMinuscule() comme pré-traitement*/
int rechercherCaractereD(char mot[], char caractere){
	int i = myStrlen(mot) - 1;

	while ((i >= 0) && (mot[i] != caractere)) {
		i--;
	}

	return i;
}

/*Dans cette fonction, on différencie les majuscules des minuscules*/
/*On pourrait faire autrement en utilisant la fonction mettreEnMinuscule() comme pré-traitement*/
int estPalindrome(char mot[]){
	int i, j;
	i = 0;
	j = myStrlen(mot) - 1;

	while ((i < j) && (mot[i] == mot[j])) {
		i++;
		j--;
	}

	return i>=j?0:-1; /*Condition sur un return*/
}

int comparerChaine(char mot1[], char mot2[]){
	int i = 0;

	while((mot1[i]!='\0') && (mot2[i]!='\0') && (mot1[i] == mot2[i])){
		i++;
	}

	return mot1[i]-mot2[i];
}
