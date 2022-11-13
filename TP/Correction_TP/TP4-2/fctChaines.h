/**
  * CS351 - Corrections de TP 2016-2017
  * Projet TP5-2
  * fctChaines.h
  * Eva Gerbert-Gaillard
  */

#ifndef __FCTCHAINES_H__
#define __FCTCHAINES_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*Verifier si il ne manque pas "[]" derriere le char de la déclaration de fonction*/

void afficherMot(char mot[]);
int  compterCaractere(char mot[]);
void afficherEnHexadecimal(char mot[]);
void afficherEnDecimal(char mot[]);
void mettreEnMajuscule(char mot[], char res[]);
void mettreEnMinuscule(char mot[], char res[]);
void transformerMinMaj(char mot[], char res[]);
void retournerMot(char mot[], char res[]);
int  rechercherCaractereG(char mot[], char caractere);
int  rechercherCaractereD(char mot[], char caractere);
int  estPalindrome(char mot[]);
int  comparerChaine(char mot1[], char mot2[]);


#endif
