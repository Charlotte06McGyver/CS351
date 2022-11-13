/**
  * CS351 - Corrections de TP 2016-2017
  * Projet TP5-2
  * chaines.c
  * Eva Gerbert-Gaillard
  */

#include <stdio.h>

#include "fctChaines.h"

int main(int argc, char * argv[]){
	char m_slt[] = {'S', 'a', 'l', 'u', 't', ',', ' ', 's', 'a', 'l', 'u', 't', '!', '\0'};
	char m_palind[] = {'e', 'l', 'u', 'p', 'a', 'r', 'c', 'e', 't', 't', 'e', 'c', 'r', 'a', 'p', 'u', 'l', 'e', '\0'};
	char m_titi[] = {'t', 'i', 't', 'i', '\0'};
	char m_toto[] = {'t', 'o', 't', 'o', '\0'};
	char resultat[50];

	printf("Il y a %d caractere(s) dans : ", compterCaractere(m_slt));
	afficherMot(m_slt);
	printf("\n");

	printf("Il y a %d caractere(s) dans : ", compterCaractere(m_titi));
	afficherMot(m_titi);
	printf("\n\n");


	printf("Le mot :\n");
	afficherMot(m_slt);
	printf("\n");
	printf("En hexadecimal :\n");
	afficherEnHexadecimal(m_slt);
	printf("\n");
	printf("En decimal :\n");
	afficherEnDecimal(m_slt);
	printf("\n\n");

	mettreEnMajuscule(m_slt, resultat);
	printf("En majuscules :\n");
	afficherMot(resultat);
	printf("\n");
	mettreEnMinuscule(m_slt, resultat);
	printf("En minuscules :\n");
	afficherMot(resultat);
	printf("\n");
	transformerMinMaj(m_slt, resultat);
	printf("En inversé :\n");
	afficherMot(resultat);
	printf("\n");
	retournerMot(m_slt, resultat);
	printf("En retourné :\n");
	afficherMot(resultat);
	printf("\n\n");

	printf("Pour le mot :");
	afficherMot(m_titi);
	printf("\n");
	printf("Le premier caractere %c en partant de la gauche est à l'indice %d \n", 'a', rechercherCaractereG(m_titi, 'a'));
	printf("Le premier caractere %c en partant de la gauche est à l'indice %d \n", 'i', rechercherCaractereG(m_titi, 'i'));
	printf("Le premier caractere %c en partant de la droite est à l'indice %d \n", 'a', rechercherCaractereD(m_titi, 'a'));
	printf("Le premier caractere %c en partant de la droite est à l'indice %d \n", 'i', rechercherCaractereD(m_titi, 'i'));
	printf("\n");

	afficherMot(m_slt);
	printf("\n est palindrome ? : %d\n", estPalindrome(m_slt));
	printf("\n");
	afficherMot(m_palind);
	printf("\n est palindrome ? : %d\n", estPalindrome(m_palind));
	printf("\n\n");


	printf("Comparaison entre : \n");
	afficherMot(m_titi);
	printf("\n et :\n");
	afficherMot(m_titi);
	printf("\nresultat : %d\n\n", comparerChaine(m_titi, m_titi));

	printf("Comparaison entre : \n");
	afficherMot(m_titi);
	printf("\n et :\n");
	afficherMot(m_toto);
	printf("\nresultat : %d\n\n", comparerChaine(m_titi, m_toto));

	printf("Comparaison entre : \n");
	afficherMot(m_slt);
	printf("\n et :\n");
	afficherMot(m_titi);
	printf("\nresultat : %d\n\n", comparerChaine(m_slt, m_titi));

	return 0;
}
