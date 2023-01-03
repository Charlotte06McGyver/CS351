#include <stdio.h>
#include <stdlib.h>

typedef struct ADRESSE{
    char *instruction;
    long adresse;
    struct ADRESSE *link;
}Adresse;

void insertionTete(Adresse **ph, char *data, long add);
void renverse_(Adresse **ph, Adresse *ph2);
void suppressionTete(Adresse **ph);
void listeAffiche(Adresse **ph);

void get_commande(char *mot_bit, char *commande);
void application(char *mot_bit,long int *registre, int *init_registre,int mode,Adresse **, Adresse *);

void add(char *rs,char *rd, char *rt,long int* registre,int *init_registre);
void sub(char *rs,char *rt, char *rd,long int* registre,int *init_registre);
void div_(char *rs, char*rt, long int* registre,int *init_registre);
void mult_(char *rs, char*rt, long int* registre,int *init_registre);
void mfhi(char *rd, long int* registre,int *init_registre);
void mflo(char *rd, long int* registre,int *init_registre);
void and_(char *rs,char *rt, char *rd,long int* registre,int *init_registre);
void or_(char *rs,char *rt, char *rd,long int* registre,int *init_registre);
void xor_(char *rs,char *rt, char *rd,long int* registre,int *init_registre);
void slt(char *rs,char *rt, char *rd,long int* registre,int *init_registre);
void sll(char *sa,char *rt, char *rd,long int* registre,int *init_registre);
void srl(char *sa,char *rt, char *rd,long int* registre,int *init_registre);
void rotr(char *sa,char *rt, char *rd,long int* registre,int *init_registre);
void bgtz(char *rs,char *offset, long int* registre,int *init_registre,Adresse **tete_index, Adresse *tete);

void addi(char *rs,char *rt, char *imm,long int* registre, int *init_registre);