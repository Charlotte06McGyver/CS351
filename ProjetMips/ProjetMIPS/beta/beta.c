#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "header.h"
#include "convert_hexa.h"
#include "lecture_instructions.h"

int commande_in(char * ligne, char *com){// Teste si nous somme à la bonne ligne
    char *commande = malloc(sizeof(char)*9);
    int i =0;
    while((ligne[i]!=':') && (ligne[i]!='\0')){
        commande[i] = ligne[i];
        i++;
    }
    commande[i] = '\0';
    if(!strcmp(commande, com)){
        i = 1;
    }else{
        i = 0;
    }
    free(commande);
    return i;
}
char type(char *ligne){// permet d'avoir le type
    int i = 0;
    while(ligne[i] != ':'){
        i++;
    }
    return ligne[i+1];

}
void get_op(char *ligne, char *op){// permet d'obtenir l'opcode
    int i = 0;
    int j = 0;
    while(ligne[i] != ':'){
        
        i++;
    }
    i = i+3;
    while(ligne[i] != ':'){
        op[j] = ligne[i];
        j++;
        i++;
    }
    op[6] = '\0';
}
int get_param(char *ligne,int *tab){//Pour connaitre les param   
    int i =0;
    int j = 0;
    while(ligne[i] != ':'){
        i++;
    }
    i = i+3;
    while(ligne[i] != ':'){
        i++;
    }
    i++;
    while(ligne[i] != '\0'){
       
        if(ligne[i] != ','){
            tab[j] = ligne[i] - 48;
            j++;
        }
        i++;
        
    }
    return j;
}
int nb_op_good(int nb_op_fonc, int tab[3]){
    int resultat = 0;
    int nb =0;

    for(int i =0; i<3; i++){
        if(tab[i] != 65536 ){
            nb++;
        }
    }
    if(nb == nb_op_fonc){
        resultat =1;
    }
    return resultat;
}
int is_in(int *tab, int value){//Pour savoir si je dois mettre la valeur dedans
    int in = 0;
    for(int i = 0; i<4; i++){
        if(tab[i] == value){
            i = 3;
            in = 1;
        }
    }
    return in;
}
void concat_R(char *mot,int tab[3], int *tab_file, char *opcode, char * fonction){
    char *rs = (char *)malloc(sizeof(char)*6);
    char *rt = (char *)malloc(sizeof(char)*6);
    char *rd = (char *)malloc(sizeof(char)*6);
    char *sa = (char *)malloc(sizeof(char)*6);
    char * mot_hexa = (char*)malloc(sizeof(char)*9);
    int index_param = 0;// Pour savoir ou je le trouve dans tab
    mot_hexa[0] = '\0';

    strcpy(rs, "00000");
    rs[5] = '\0';
    strcpy(rt, "00000");
    rt[5] = '\0';
    strcpy(rd, "00000");
    rd[5] = '\0';
    strcpy(sa, "00000");
    sa[5] = '\0';

    if(is_in(tab_file,3)){
        bit(tab[index_param], 5, rd);
        index_param++;
    }
    if(is_in(tab_file,1)){
        bit(tab[index_param], 5, rs);
        index_param++;
    } 
    if(is_in(tab_file,2)){
        bit(tab[index_param], 5, rt);
        index_param++;
    } 
    if(is_in(tab_file,4)){
        bit(tab[index_param], 5, sa);
        index_param++;
    }
    

    mot = strcat(mot,opcode);
    mot[6] = '\0';
    mot = strcat(mot,rs);
    mot[6+5] = '\0';
    mot = strcat(mot,rt);
    mot[6+6+6] = '\0';
    mot = strcat(mot,rd);
    mot[6+5+5+5] = '\0';
    mot = strcat(mot,sa);
    mot[6+5+5+5+5] = '\0';
    mot = strcat(mot,fonction);
    mot[32] = '\0';
   
    gotohexa(mot, mot_hexa);
    printf("%s\n", mot_hexa);
    free(mot_hexa);
    free(sa);
    free(rd);
    free(rt);
    free(rs);
    
}
void fonctions(char *commande){
    FILE *fp = fopen("dico.txt", "r");

    char *ligne = (char *)malloc(sizeof(char)*100);
    char *opcode = (char *)malloc(sizeof(char)*7);
    char *prec_ligne = (char *)malloc(sizeof(char)*100);

    char* operateur = (char*)malloc(sizeof(char)*8);
    int *tab = malloc(sizeof(int)*3);

    operateur[0] = '\0';
    tab[0] = 65536;
    tab[1] = 65536;
    tab[2] = 65536;
    
    char *fonction = (char *)malloc(sizeof(char)*7);
    int *tab_file = (int *)malloc(24);
    char *mot = (char*)malloc(sizeof(char)*33);
    int exit = 0;
    int in = 1;
    int nb_op = 0;

    prec_ligne[0] = '\0';
    mot[0] = '\0';
    strcpy(fonction, "000000");
    fonction[6] = '\0';

    tab_file[0] = 0;
    tab_file[1] = 0;
    tab_file[2] = 0;
    tab_file[3] = 0;
    lecture_operateur(commande,operateur);

    if(fp == NULL){
        perror("Probleme ouverture fichier ");
    }
    while((exit !=1) && (in ==1)){
        fscanf(fp,"%s",ligne);
        if(strcmp(prec_ligne,ligne)){
            exit = commande_in(ligne, operateur);
            strcpy(prec_ligne,ligne);
            in = 1;
        }else{
            in = 0;
        }
    }
    if(in == 1){
        get_op(ligne, opcode);
        nb_op = get_param(ligne,tab_file);
        if(type(ligne) == 'R'){
            lecture_operandeR(commande,tab);
            if(nb_op_good(nb_op,tab) == 1){
                strcpy(fonction, opcode);
                fonction[6] = '\0';
                strcpy(opcode, "000000");
                opcode[6] = '\0';
                concat_R(mot,tab,tab_file,opcode,fonction);
            }else{
                printf("Trop peut d'argument ou format incorrect: commande $a, $b, $c\n");
            }
        }else if(type(ligne) == 'I'){
            lecture_operandeI(commande,tab);
            printf("%d\n", tab[0]);
            printf("%d\n", tab[1]);
            printf("%d\n", tab[2]);
            printf("%s\n", opcode);
            
        }
    }else{
        printf("Commande incorrecte ou non présente dans la librairie\n");
    }
    free(prec_ligne);
    free(operateur);
    free(tab);
    free(mot);
    free(tab_file);
    free(fonction);
    free(opcode);
    free(ligne);
    fclose(fp);
}
