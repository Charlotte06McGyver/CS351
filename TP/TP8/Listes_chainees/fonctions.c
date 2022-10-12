#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "fonctions.h"

/*fonctions qui affiche tous les elements de la liste dans l'ordre*/
void afficherListe(liste *l){ 
    if (l == NULL){ //cas d'une liste vide
        printf("La liste est vide !");
    }
    else {
        while (l != NULL){
            printf("%d ", l->valeur);
            l = l->suivant;
        }
        printf("\n");
    }
}

void InsertionTete (liste **l, int x){
    /*Creation du nouvel element*/
    liste *nv_element = (liste*) malloc(sizeof(liste));
    if (l == NULL || nv_element ==NULL){ /*verifie si on peut encore allouer de la memoire*/
        exit(EXIT_FAILURE);
    }
    nv_element->valeur = x;

    /*Insertion de l'element en tete de liste*/
    nv_element->suivant = *l;
    *l = nv_element;
}

void InsertionQueue (liste **l, int x){

	if (*l == NULL){ /*si la liste est vide*/
		InsertionTete(l,x);
	}
	else {
		liste *nv_element = (liste*) malloc(sizeof(liste));
		nv_element->valeur = x;
		nv_element->suivant = NULL; /*élément suivant est NULL*/
		liste *p = *l; /*avec p un pointeur*/
		while (p->suivant != NULL) { /*tant que p ne pointe pas vers le dernier élément de la liste*/
			p = p->suivant;
		}
		p->suivant = nv_element; /*ensuite on fait pointer p vers node qui sera donc le derner élément de la liste*/
	}
}

/* Suppression en "tete de liste" */
void suppressionTete(liste **l){

	if (l == NULL){ /*si l'élément est le dernier de la liste, on s'arrete*/
		exit(EXIT_FAILURE);
	}
    else{
        liste *aSupprimer = *l;
	    *l = (*l)->suivant;
		free(aSupprimer); 
    }
}

/* Suppression en "Queue" de liste" */
void suppressionQueue(liste **l){
	liste *dernier_element;
	liste *avant_dernier_element;

	if(*l != NULL){
		dernier_element = *l;
		avant_dernier_element = dernier_element->suivant; //un element dans la liste pointe vers le suivant
		while (dernier_element->suivant != NULL){ //tant qu'on arrive pas au dernier element de la liste
			avant_dernier_element = dernier_element; //le pointeur de l'element devient le pointeur de l'element suivant
			dernier_element = dernier_element->suivant; //on pointe donc maintenant vers l'element suivant dans la liste
		}
		avant_dernier_element->suivant=NULL; //on supprime donc le dernier element
		//printf("%c\n", dernier_element->data);
		free(dernier_element);
		//printf("%c\n", dernier_element->data);

	}

}

int Taille_liste(liste *l){
    int taille = 0;
    while (l != NULL){
        taille++;
        l = l->suivant;
    }
    //afficherListe(l);
    return taille;
}

void InsertionMilieu(liste **l, int x){

    int position = (Taille_liste(*l))/2;
    int compteur = 0;

    if (*l == NULL){ /*si la liste est vide*/
		InsertionTete(l,x);
	}
	else {
		liste *nv_element = (liste*) malloc(sizeof(liste));
		nv_element->valeur = x;
		 /*élément suivant est NULL*/
		liste *p = *l; /*avec p un pointeur*/
        liste *p2 = (liste *)malloc(sizeof(liste));
        p2 ->suivant = nv_element;
        if(position == 0){
            InsertionTete(l,x);

        }
        else if (position == 1){
            p=(*l)->suivant;
            nv_element->suivant = p;
            (*l)->suivant = nv_element;
        }else{
        nv_element->suivant = *l;
		while (compteur<position ) { /*tant que p ne pointe pas vers le dernier élément de la liste*/
			p2=p2->suivant;
            nv_element->suivant = p;
            p = p->suivant;
            compteur++;
		}
		nv_element->suivant = p; /*ensuite on fait pointer p vers node qui sera donc le derner élément de la liste*/
        p2 = p2->suivant;
        p2->suivant = nv_element;
        }
    }


}

/*fonction qui, en supposant la liste triee, insere l'element x en maintenant la liste triee*/
void insererElement(int x, liste **l){
    if(*l == NULL){
        InsertionTete(l,x);
    }else{
        liste *nv_element = (liste*) malloc(sizeof(liste));
		nv_element->valeur = x;
        *p =  *l
        while((nv_element->valeur)>(p->valeur))//parcour la liste chainée tant que x > au élémd e la liste chainée
    }

}

/*fonction qui supprime le ieme element de l*/
void supprimerElement(int i, liste *l){

}