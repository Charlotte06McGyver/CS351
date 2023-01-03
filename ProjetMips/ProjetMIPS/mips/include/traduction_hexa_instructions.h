#include <stdio.h>
#include <stdlib.h>

void fonctions(char *commande,int mode,char *sortie_assemblage,char *mot_en_hexa);
void concat_R(char *mot,int tab[3], int *tab_file, char *opcode, char * fonction,char *operateur);
void concat_I(char *mot,int tab[3], int *tab_file, char *opcode);
void concat_J(char *mot,int add, char *opcode);
int is_in(int *tab, int value);
int get_param(char *ligne,int *tab);
void get_op(char *ligne, char *op);
char type(char *ligne);
int commande_in(char * ligne, char *com);
int nb_op_good(int nb_op_fonc, int tab[3]);