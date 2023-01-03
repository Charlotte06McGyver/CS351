#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../include/header.h"
#include "../include/convert_hexa.h"
#include "../include/lecture_instructions.h"


int commande_in(char * ligne, char *com){// Teste si nous somme à la bonne ligne ou si la commande est bien dans le fichier dico.txt
    char *commande = malloc(sizeof(char)*9);
    int i =0;
    while((ligne[i]!=':') && (ligne[i]!='\0')){// On prend le nom de la commande
        commande[i] = ligne[i];
        i++;
    }
    commande[i] = '\0';
    if(!strcmp(commande, com)){// On compare le nom de la commande avec notre commande
        i = 1;
    }else{
        i = 0;
    }
    free(commande);
    return i;// renvoi 1 si elle y est et 0 sinon
}
char type(char *ligne){// permet d'avoir le type de notre commande
    int i = 0;
    while(ligne[i] != ':'){
        i++;
    }
    return ligne[i+1];

}
void get_op(char *ligne, char *op){// permet d'obtenir l'opcode de notre commande dans la ligne qu'on a récupéré avant
    int i = 0;
    int j = 0;
    while(ligne[i] != ':'){// On se décale dans notre ligne pour prendre que l'opcode
        
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
int get_param(char *ligne,int *tab){//Pour connaitre les param de notre commande 
    int i =0;
    int j = 0;
    while(ligne[i] != ':'){
        i++;
    }
    i = i+3;
    while(ligne[i] != ':'){//On se décale dans notre ligne pour prendre que les argements de notre commande
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
    return j;// retourne le nombre d'arguemnt que prend notre commande
}
int nb_op_good(int nb_op_fonc, int tab[3]){// Teste si nous avons bien le bon nombre de paramètre dans notre fonction
    int resultat = 0;
    int nb =0;

    for(int i =0; i<3; i++){
        if(tab[i] != 65536 ){//Si une valeur tableau est diférent de 65536 alors ça veut dire qu'on a bien donné un argument
            nb++;
        }
    }
    if(nb == nb_op_fonc){// SI on a bien le bon nombre d'argument dans notre tab qui est différent de 65536 alors le format de notre commande est bon
        resultat =1;
    }
    return resultat;
}
int is_in(int *tab, int value){//Pour savoir si je dois mettre la valeur dans notre tableau de 32bits
    int in = 0;
    for(int i = 0; i<4; i++){
        if(tab[i] == value){
            i = 3;
            in = 1;
        }
    }
    return in;
}
void concat_R(char *mot,int tab[3], int *tab_file, char *opcode, char * fonction,char *operateur){//Créer les instructions de type R
    char *rs = (char *)malloc(sizeof(char)*6);
    char *rt = (char *)malloc(sizeof(char)*6);
    char *rd = (char *)malloc(sizeof(char)*6);
    char *sa = (char *)malloc(sizeof(char)*6);
    int index_param = 0;// Pour savoir ou je le trouve dans tab
   

    strcpy(rs, "00000");//On initialise nos rgistre avec la valeur 0
    rs[5] = '\0';
    strcpy(rt, "00000");
    rt[5] = '\0';
    strcpy(rd, "00000");
    rd[5] = '\0';
    strcpy(sa, "00000");
    sa[5] = '\0';

    if(is_in(tab_file,3)){// Teste si on doit moddifier nos registre avec les valeurs donné en paramètre
        bit(tab[index_param], 5, rd);//On convertit la valeur donné en paramètre qui correspond en binaire
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
    if(!strcmp("ROTR",operateur)){// cas spéciale pour la commande ROTR
        strcpy(rs,"00001");
    }

    mot = strcat(mot,opcode);// On concatène dans le bonne ordre nos registre avec l'opcode
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
    free(sa);
    free(rd);
    free(rt);
    free(rs);
    
}
void concat_I(char *mot,int tab[3], int *tab_file, char *opcode){//Créer les instructions de type I
    char *rs = (char *)malloc(sizeof(char)*6);
    char *rt = (char *)malloc(sizeof(char)*6);
    char *imm = (char *)malloc(sizeof(char)*17);
    int index_param = 0;// Pour savoir ou je le trouve dans tab
   
    
    strcpy(rs, "00000");//On initialise nos rgistre avec la valeur 0
    rs[5] = '\0';
    strcpy(rt, "00000");
    rt[5] = '\0';
    strcpy(imm, "0000000000000000");
    imm[16] = '\0';
    if(is_in(tab_file,2)){// Teste si on doit moddifier nos registre avec les valeurs donné en paramètre
        bit(tab[index_param], 5, rt);//On convertit la valeur donné en paramètre qui correspond en binaire
        index_param++;
    }if(is_in(tab_file,1)){
        bit(tab[index_param], 5, rs);
        index_param++;
    }if(is_in(tab_file,3)){
        bit(tab[index_param], 16, imm);
        index_param++;
    }
    mot = strcat(mot,opcode);// On concatène dans le bonne ordre nos registre avec l'opcode
    mot[6] = '\0';
    mot = strcat(mot,rs);
    mot[6+5] = '\0';
    mot = strcat(mot,rt);
    mot[6+6+6] = '\0';
    mot = strcat(mot,imm);
    mot[32] = '\0';
   
    free(imm);
    free(rt);
    free(rs);

}
void concat_J(char *mot,int add, char *opcode){//Créer les instructions de type J
    char *adresse = (char *)malloc(sizeof(char)*27);
    
   
    adresse[0] = '\0';//On initialise notre registre 
    if(add == 0){
        strcpy(adresse,"00000000000000000000000000");
        adresse[26] = '\0';
    }else{
        bit(add, 26,adresse);//On convertit la valeur donné en paramètre qui correspond en binaire
    }
    mot = strcat(mot,opcode);// On concatène dans le bonne ordre nos registre avec l'opcode
    mot[6] = '\0';
    mot = strcat(mot,adresse);
    mot[32] = '\0';
    
    
    free(adresse);


}
void fonctions(char *commande,int mode,char *assemblage_sortie, char *mot_hexa){
    FILE *fp = fopen("dico.txt", "r");
    FILE *sortie_assemblage;
    if((mode == 2) || (mode == 1)){
        sortie_assemblage = fopen( assemblage_sortie, "a" );
    }
    char *ligne = (char *)malloc(sizeof(char)*100);
    char *opcode = (char *)malloc(sizeof(char)*7);
    char *prec_ligne = (char *)malloc(sizeof(char)*100);

    char* operateur = (char*)malloc(sizeof(char)*8);
    int *tab = malloc(sizeof(int)*3);
    
    mot_hexa[0] = '\0';

    operateur[0] = '\0';
    tab[0] = 65536;//Initialise notre tableau qui contient les paramètre de notre fonctions avec des valeurs qui ne sont pas possible d'ateindre pour le type I et R
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
    strcpy(fonction, "000000");// On initialise la valeur dans le registre à 0 (utile que pour le type R)
    fonction[6] = '\0';

    tab_file[0] = 0;
    tab_file[1] = 0;
    tab_file[2] = 0;
    tab_file[3] = 0;
   
    lecture_operateur(commande,operateur);// On lis l'opérateur de notre commande

    if(fp == NULL){
        perror("Probleme ouverture fichier ");
    }
    while((exit !=1) && (in ==1)){// teste si notre opérateur se trouve bien dans notre fichier dico.txt
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
        get_op(ligne, opcode);// On récupère l'opcode de notre commande
        nb_op = get_param(ligne,tab_file);//On récupère le nombre d'argument que prend notre commande
        if(type(ligne) == 'R'){//teste si c'est un type R
            lecture_operandeR(commande,tab,operateur);// On lis les argument qui nous son donné
            if(nb_op_good(nb_op,tab) == 1){// teste si on a bien le bon nombre d'argument 
                strcpy(fonction, opcode);//Pour le type R on doit inverser la valeur présente dans le registre fonction avec celle du registre opcode
                fonction[6] = '\0';
                strcpy(opcode, "000000");// Met 0 dans le registre Opcode
                opcode[6] = '\0';
                concat_R(mot,tab,tab_file,opcode,fonction,operateur);
                gotohexa(mot, mot_hexa);
                
                if((mode == 2) || (mode == 1)){// SI c'est le mode automatique on doit mettre la sortis dans un fichier
                    fputs(mot_hexa,sortie_assemblage);
                    fputc('\n',sortie_assemblage);
                }else{
                    printf("%s\n", mot_hexa);
                }
            }else{
                fatal("Trop peut d'argument ou format incorrect: commande $a, $b, $c\n");//Erreur s'il n'y a pas assez d'argument
            }
        }else if(type(ligne) == 'I'){//teste si c'est un type I
            lecture_operandeI(commande,tab);//On lis les argument qui nous son donné
            if(tab[2] != 65536){
            if((tab[0]<0) || (tab[1]<0) || (tab[0]>31) || (tab[1]>31)){// Teste si les valeurs des registres donnés ne sont aps trop grand/petit
                fatal("Insérer des registres entre 0 et 31");
            }
            if((tab[2]>32767) || (tab[2]< -32768 || (tab[2] == -48))){// teste si la valeur imédiate n'est pas trop grande ou trop petite
                fatal("Insérer une valeur imédiate entre -32768 et 32767");
            }
            }else{
                if((tab[0]<0) ||(tab[0]>31)){// Teste si les valeurs des registres donnés ne sont aps trop grand/petit
                fatal("Insérer des registres entre 0 et 31");
            }
                if((tab[1]>32767) || (tab[1]< -32768 || (tab[1] == -48))){// teste si la valeur imédiate n'est pas trop grande ou trop petite
                fatal("Insérer une valeur imédiate entre -32768 et 32767");
            }
            }
            if(nb_op_good(nb_op,tab) == 1){// teste si on a bien le bon nombre d'argument
                concat_I(mot,tab,tab_file,opcode);
                gotohexa(mot, mot_hexa);
                
                if((mode == 2) || (mode == 1)){// SI c'est le mode automatique on doit mettre la sortis dans un fichier
                    fputs(mot_hexa,sortie_assemblage);
                    fputc('\n',sortie_assemblage);
                }else{
                    printf("%s\n", mot_hexa);
                }
            }else{
                fatal("Trop peut d'argument ou format incorrect: commande $a, $b, c\n");//Erreur s'il n'y a pas assez d'argument
            }
        }else{
            tab[0] = 67108864;// Comme l'imédiat du type I est  sur 26bit on doit moddifier la valeur par défaut
            lecture_operandeJ(commande,tab);//On lis les argument qui nous son donné
            if((tab[0]<67108864) || (tab[0]>=0)){// teste si on a bien le bon nombre d'argument 
                concat_J(mot,tab[0],opcode);
                gotohexa(mot, mot_hexa);
                
                if(mode == 2){// SI c'est le mode automatique on doit mettre la sortis dans un fichier
                    fputs(mot_hexa,sortie_assemblage);
                    fputc('\n',sortie_assemblage);
                }else{
                    printf("%s\n", mot_hexa);
                }
            }else{
                fatal("Trop peut d'argument ou format incorrect: commande a\n");//Erreur s'il n'y a pas assez d'argument
            }
            
        }
    }else{
        fatal("Commande incorrecte ou non présente dans la librairie\n");
    }
    if(mode == 2){
        fclose(sortie_assemblage);
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
