#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../include/header.h"
#include "../include/convert_hexa.h"
#include "../include/instructions.h"

void insertionTete(Adresse **ph, char *data, long add){
    Adresse *nouveau = malloc(sizeof(Adresse));
    nouveau->instruction = malloc(sizeof(char)*9);
    strcpy(nouveau->instruction, data);
    nouveau->adresse = add;
    
    if(*ph == NULL){
        nouveau->link = NULL;
        *ph=nouveau;
    }else{
        nouveau->link = *ph;
        *ph=nouveau;
    }
}
void renverse_(Adresse **ph, Adresse *ph2){
    while(ph2!=NULL){
        insertionTete(ph,ph2->instruction, ph2->adresse);
        ph2 = ph2->link;
    }
}
void suppressionTete(Adresse **ph){
    Adresse *new;
    new=*ph;
    *ph= (*ph)->link;
    free(new->instruction);
    free(new);
}
void listeAffiche(Adresse **ph){
    Adresse *new;
    new = *ph;
    if(new == NULL){
        printf("Liste vide!\n");
    }else{
        while(new != NULL){
            printf("%s,%ld\n", new->instruction,new->adresse);
            new=new->link;
        }
    }
}
void parcourirListe(Adresse **tete_index, Adresse *tete, long add_tamp){
    while((tete!= NULL) &&(tete->adresse!=add_tamp)){
        tete=tete->link;
    }
 
    if(tete==NULL){
        fatal("L'adresse ciblée est incorecte");
    }else{
        (*tete_index) = tete;
    }
}

void get_commande(char *mot_bit, char *commande){
    char *opcode = (char *)malloc(sizeof(char)*7);
    FILE *fp = fopen("dico.txt", "r");
    char *ligne = (char *)malloc(sizeof(char)*80);
    int exit = 0;
    char *current_op = (char *)malloc(sizeof(char)*7);
    int indice_ligne = 0;
    char char_ligne;
    char type = 'I';
    for(int i =0;i<6;i++){//On récupère l'opcode que notre instruction
        opcode[i] = mot_bit[i];
    }
    opcode[6] = '\0';
    if(!strcmp(opcode,"000000")){//Si c'est un type R on doit prendre les dernier bit et pas les premiers comme opcode
        for(int i =26;i<32;i++){
            type ='R';
            opcode[i- 26] = mot_bit[i];
        }
        opcode[6] = '\0';
    }

    if(fp == NULL){
        perror("Probleme ouverture fichier ");
    }

    while(exit == 0){
        fgets(ligne,80,fp);
        char_ligne = ligne[indice_ligne];
        while(char_ligne != ':'){
            indice_ligne++;
            char_ligne = ligne[indice_ligne];
        }
        indice_ligne++;
        if((ligne[indice_ligne] == type) ||(ligne[indice_ligne] == 'J')){
            indice_ligne++;
            indice_ligne++;
            for(int i=0;i<6;i++){
                current_op[i] = ligne[indice_ligne];
                indice_ligne++;
            }
            current_op[6] = '\0';
            if(!strcmp(opcode,current_op)){
                exit =1;
            }
        }
        indice_ligne=0;
    }
    while(ligne[indice_ligne] != ':'){
        commande[indice_ligne] = ligne[indice_ligne];
        indice_ligne++;
    }
    commande[indice_ligne] = '\0';
    if(!strcmp(commande,"SRL") || !strcmp(commande,"ROTR")){
        if(mot_bit[10] == '1'){
            strcpy(commande,"ROTR");
        }else{
            strcpy(commande,"SRL");
        }
    }
    free(current_op);
    free(ligne);
    fclose(fp);
    free(opcode);
}
void copy_value(char *mot, char * value,int indice){
    for(int i= 0;i<32;i++){
        value[i] = mot[i+indice];
    }
    value[32] = '\0';
}

void addi(char *rs,char *rt, char *imm,long int* registre,int *init_registre){
    int rs_d;
    int rt_d;
    int imm_d;
    int signe = 0;
    if(imm[0] == '1'){
        signe = 1;
    }
    rs_d = (int)bit_to_decimal(rs,0,0);
    rt_d = (int)bit_to_decimal(rt,0,0);
    imm_d = (int)bit_to_decimal(imm,signe,0);
    if(rt_d ==0){
        printf("->ADDI $%d, $%d, %d\n", rt_d,rs_d,imm_d);
        fatal("Ne modiffiez pas le registre 0");
    }

    if((init_registre[rs_d] == 0)){
        printf("->ADDI $%d, $%d, %d\n", rt_d,rs_d,imm_d);
        printf("Le registre %d est vide\n",rs_d);
        fatal("registre vide");
    }else{
        registre[rt_d] = registre[rs_d] + imm_d; 
        init_registre[rt_d] =1;  
    }
    if((registre[rt_d]>2147483647) ||(registre[rt_d]<-2147483648)){
        printf("->ADDI $%d, $%d, %d\n", rt_d,rs_d,imm_d);
        printf("Débordement dans le registre %d\n",rt_d);
        fatal("Débordement de tampon");
    }
    printf("%ld\n",registre[rt_d]);
}
void add(char *rs,char *rt, char *rd,long int* registre,int *init_registre){
    int rs_d;
    int rt_d;
    int rd_d;

    rs_d = (int)bit_to_decimal(rs,0,0);
    rt_d = (int)bit_to_decimal(rt,0,0);
    rd_d = (int)bit_to_decimal(rd,0,0);
    if(rd_d ==0){
        printf("->ADD $%d, $%d, $%d\n", rd_d,rs_d,rt_d);
        fatal("Ne modiffiez pas le registre 0");
    }
    if(init_registre[rs_d] == 0){
        printf("->ADD $%d, $%d, $%d\n", rd_d,rs_d,rt_d);
        printf("Le registre %d est vide\n",rs_d);
        fatal("registre vide");
    }else if(init_registre[rt_d] == 0){
        printf("->ADD $%d, $%d, $%d\n", rd_d,rs_d,rt_d);
        printf("Le registre %d est vide\n",rt_d);
        fatal("registre vide");
    }
    else{
        registre[rd_d] = registre[rs_d] + registre[rt_d]; 
        init_registre[rd_d] =1;  
    }
    if((registre[rd_d]>2147483647) ||(registre[rd_d]<-2147483648)){
        printf("->ADD $%d, $%d, $%d\n", rd_d,rs_d,rt_d);
        printf("Débordement dans le registre %d\n",rd_d);
        fatal("Débordement de tampon");
    }
    printf("%ld\n",registre[rd_d]);
}
void sub(char *rs,char *rt, char *rd,long int* registre,int *init_registre){
    int rs_d;
    int rt_d;
    int rd_d;

    rs_d = (int)bit_to_decimal(rs,0,0);
    rt_d = (int)bit_to_decimal(rt,0,0);
    rd_d = (int)bit_to_decimal(rd,0,0);
    if(rd_d ==0){
        printf("->SUB $%d, $%d, $%d\n", rd_d,rs_d,rt_d);
        fatal("Ne modiffiez pas le registre 0");
    }
    if(init_registre[rs_d] == 0){
        printf("->SUB $%d, $%d, $%d\n", rd_d,rs_d,rt_d);
        printf("Le registre %d est vide\n",rs_d);
        fatal("registre vide");
    }else if(init_registre[rt_d] == 0){
        printf("->SUB $%d, $%d, $%d\n", rd_d,rs_d,rt_d);
        printf("Le registre %d est vide\n",rt_d);
        fatal("registre vide");
    }
    else{
        registre[rd_d] = registre[rs_d] - registre[rt_d]; 
        init_registre[rd_d] =1;  
    }
    if((registre[rd_d]>2147483647) ||(registre[rd_d]<-2147483648)){
        printf("->SUB $%d, $%d, $%d\n", rd_d,rs_d,rt_d);
        printf("Débordement dans le registre %d\n",rd_d);
        fatal("Débordement de tampon");
    }
    printf("%ld\n",registre[rd_d]);
}
void mult_(char *rs, char*rt, long int* registre,int *init_registre){
    int rs_d;
    int rt_d;
    int signe = 0;
    long long resultat =0;
    long long min = -9223372036854775807;
    long long max = 9223372036854775807;
    char * value = (char *)malloc(sizeof(char)*65);
    char * HI = (char *)malloc(sizeof(char)*33);
    char * HL = (char *)malloc(sizeof(char)*33);
    strcpy(value,"0000000000000000000000000000000000000000000000000000000000000000");

    rs_d = (int)bit_to_decimal(rs,0,0);
    rt_d = (int)bit_to_decimal(rt,0,0);
    if(init_registre[rs_d] == 0){
        printf("->MULT $%d, $%d\n",rs_d,rt_d);
        printf("Le registre %d est vide\n",rs_d);
        fatal("registre vide");
    }else if(init_registre[rt_d] == 0){
        printf("->MULT $%d, $%d\n",rs_d,rt_d);
        printf("Le registre %d est vide\n",rt_d);
        fatal("registre vide");
    }else{
        resultat = (long long)registre[rs_d] * (long long)registre[rt_d];
        if((resultat>max) || (resultat<min)){
            printf("->MULT $%d, $%d\n",rs_d,rt_d);
            fatal("Resultat de la multiplication trop grand");
        }else{
            longbit(resultat,value);
            copy_value(value,HL,32);
            copy_value(value,HI,0);
            printf("%lld\n", resultat);
            if(value[0] == '1'){
                signe = 1;
            }
            if(signe == 0){
                registre[33] = (long)bit_to_decimal(HL,0,0);
                init_registre[33] = 1;
                registre[34] = (long)bit_to_decimal(HI,0,0);
                init_registre[34] = 1;
            }else{
                registre[33] = (long)bit_to_decimal(HL,1,0);
                init_registre[33] = 1;
                registre[34] = (long)bit_to_decimal(HI,1,1);
                init_registre[34] = 1;
            }
        }
    }
    free(HI);
    free(HL);
    free(value);
}
void div_(char *rs, char*rt, long int* registre,int *init_registre){
    int rs_d;
    int rt_d;

    rs_d = (int)bit_to_decimal(rs,0,0);
    rt_d = (int)bit_to_decimal(rt,0,0);
    if(init_registre[rs_d] == 0){
        printf("->DIV $%d, $%d\n",rs_d,rt_d);
        printf("Le registre %d est vide\n",rs_d);
        fatal("registre vide");
    }else if(init_registre[rt_d] == 0){
        printf("->DIV $%d, $%d\n",rs_d,rt_d);
        printf("Le registre %d est vide\n",rt_d);
        fatal("registre vide");
    }else if(registre[rt_d] == 0){
        printf("->DIV $%d, $%d\n",rs_d,rt_d);
        fatal("Division par 0");
    }else{
        registre[33] = (long long)registre[rs_d] / (long long)registre[rt_d];
        init_registre[33] = 1;
        registre[34] = (long long)registre[rs_d] % (long long)registre[rt_d];
        init_registre[34] = 1;
    }
}
void mflo(char *rd, long int* registre,int *init_registre){
    int rd_d;
    rd_d = (int)bit_to_decimal(rd,0,0);
    if(rd_d ==0){
        printf("->MFLO $%d\n", rd_d);
        fatal("Ne modiffiez pas le registre 0");
    }
    if(init_registre[33] == 0){
        fatal("MFLO est vide");
    }else{
        registre[rd_d] = registre[33];
        init_registre[rd_d] = 1;
    }
    printf("%ld\n",registre[rd_d]);
}
void mfhi(char *rd, long int* registre,int *init_registre){
    int rd_d;
    rd_d = (int)bit_to_decimal(rd,0,0);
    if(rd_d ==0){
        printf("->MFHI $%d\n", rd_d);
        fatal("Ne modiffiez pas le registre 0");
    }
    if(init_registre[34] == 0){
        fatal("MFHI est vide");
    }else{
        registre[rd_d] = registre[34];
        init_registre[rd_d] = 1;
    }
    printf("%ld\n",registre[rd_d]);
}
void and_(char *rs,char *rt, char *rd,long int* registre,int *init_registre){
    int rs_d;
    int rt_d;
    int rd_d;

    rs_d = (int)bit_to_decimal(rs,0,0);
    rt_d = (int)bit_to_decimal(rt,0,0);
    rd_d = (int)bit_to_decimal(rd,0,0);
    if(rd_d ==0){
        printf("->AND $%d, $%d, $%d\n", rd_d,rs_d,rt_d);
        fatal("Ne modiffiez pas le registre 0");
    }
    if(init_registre[rs_d] == 0){
        printf("->AND $%d, $%d, $%d\n", rd_d,rs_d,rt_d);
        printf("Le registre %d est vide\n",rs_d);
        fatal("registre vide");
    }else if(init_registre[rt_d] == 0){
        printf("->AND $%d, $%d, $%d\n", rd_d,rs_d,rt_d);
        printf("Le registre %d est vide\n",rt_d);
        fatal("registre vide");
    }else{
        registre[rd_d] = registre[rs_d] & registre[rt_d];
        init_registre[rd_d] = 1;
        printf("%ld\n",registre[rd_d]);
    }
}
void or_(char *rs,char *rt, char *rd,long int* registre,int *init_registre){
    int rs_d;
    int rt_d;
    int rd_d;

    rs_d = (int)bit_to_decimal(rs,0,0);
    rt_d = (int)bit_to_decimal(rt,0,0);
    rd_d = (int)bit_to_decimal(rd,0,0);
    if(rd_d ==0){
        printf("->OR $%d, $%d, $%d\n", rd_d,rs_d,rt_d);
        fatal("Ne modiffiez pas le registre 0");
    }
    if(init_registre[rs_d] == 0){
        printf("->OR $%d, $%d, $%d\n", rd_d,rs_d,rt_d);
        printf("Le registre %d est vide\n",rs_d);
        fatal("registre vide");
    }else if(init_registre[rt_d] == 0){
        printf("->OR $%d, $%d, $%d\n", rd_d,rs_d,rt_d);
        printf("Le registre %d est vide\n",rt_d);
        fatal("registre vide");
    }else{
        registre[rd_d] = registre[rs_d] | registre[rt_d];
        init_registre[rd_d] = 1;
        printf("%ld\n",registre[rd_d]);
    }
}
void xor_(char *rs,char *rt, char *rd,long int* registre,int *init_registre){
    int rs_d;
    int rt_d;
    int rd_d;

    rs_d = (int)bit_to_decimal(rs,0,0);
    rt_d = (int)bit_to_decimal(rt,0,0);
    rd_d = (int)bit_to_decimal(rd,0,0);
    if(rd_d ==0){
        printf("->OR $%d, $%d, $%d\n", rd_d,rs_d,rt_d);
        fatal("Ne modiffiez pas le registre 0");
    }
    if(init_registre[rs_d] == 0){
        printf("->OR $%d, $%d, $%d\n", rd_d,rs_d,rt_d);
        printf("Le registre %d est vide\n",rs_d);
        fatal("registre vide");
    }else if(init_registre[rt_d] == 0){
        printf("->OR $%d, $%d, $%d\n", rd_d,rs_d,rt_d);
        printf("Le registre %d est vide\n",rt_d);
        fatal("registre vide");
    }else{
        registre[rd_d] = registre[rs_d] ^ registre[rt_d];
        init_registre[rd_d] = 1;
        printf("%ld\n",registre[rd_d]);
    }
}
void slt(char *rs,char *rt, char *rd,long int* registre,int *init_registre){
    int rs_d;
    int rt_d;
    int rd_d;

    rs_d = (int)bit_to_decimal(rs,0,0);
    rt_d = (int)bit_to_decimal(rt,0,0);
    rd_d = (int)bit_to_decimal(rd,0,0);
    if(rd_d ==0){
        printf("->SLT $%d, $%d, $%d\n", rd_d,rs_d,rt_d);
        fatal("Ne modiffiez pas le registre 0");
    }
    if(init_registre[rs_d] == 0){
        printf("->SLT $%d, $%d, $%d\n", rd_d,rs_d,rt_d);
        printf("Le registre %d est vide\n",rs_d);
        fatal("registre vide");
    }else if(init_registre[rt_d] == 0){
        printf("->SLT $%d, $%d, $%d\n", rd_d,rs_d,rt_d);
        printf("Le registre %d est vide\n",rt_d);
        fatal("registre vide");
    }else{
        init_registre[rd_d] =1;
        if(registre[rs_d]<registre[rt_d]){
            registre[rd_d] =1;
        }else{
            registre[rd_d] =0;
        }
        printf("%ld\n",registre[rd_d]);
    }
}
void sll(char *sa,char *rt, char *rd,long int* registre,int *init_registre){
    int rt_d;
    int rd_d;
    int sa_d;
    
    sa_d = (int)bit_to_decimal(sa,0,0);
    rt_d = (int)bit_to_decimal(rt,0,0);
    rd_d = (int)bit_to_decimal(rd,0,0);
    if(rd_d ==0){
        printf("->SLL $%d, $%d, %d\n", rd_d,rt_d,sa_d);
        fatal("Ne modiffiez pas le registre 0");
    }
    if(init_registre[rt_d] == 0){
        printf("->SLL $%d, $%d, %d\n", rd_d,rt_d,sa_d);
        printf("Le registre %d est vide\n",rt_d);
        fatal("registre vide");
    }else{
        
        registre[rd_d] = (long)registre[rt_d]<<(long)sa_d;
        init_registre[rd_d] = 1;
    }
    printf("%ld\n", registre[rd_d]);
}
void srl(char *sa,char *rt, char *rd,long int* registre,int *init_registre){
    int rt_d;
    int rd_d;
    int sa_d;
    
    sa_d = (int)bit_to_decimal(sa,0,0);
    rt_d = (int)bit_to_decimal(rt,0,0);
    rd_d = (int)bit_to_decimal(rd,0,0);
    if(rd_d ==0){
        printf("->SRL $%d, $%d, %d\n", rd_d,rt_d,sa_d);
        fatal("Ne modiffiez pas le registre 0");
    }
    if(init_registre[rt_d] == 0){
        printf("->SRL $%d, $%d, %d\n", rd_d,rt_d,sa_d);
        printf("Le registre %d est vide\n",rt_d);
        fatal("registre vide");
    }else{
        
        registre[rd_d] = (long)registre[rt_d]>>(long)sa_d;
        init_registre[rd_d] = 1;
    }
    printf("%ld\n", registre[rd_d]);
}
void rotr(char *sa,char *rt, char *rd,long int* registre,int *init_registre){
    int rt_d;
    int rd_d;
    int sa_d;
    long tamp;
    int signe=0;
    char *tampon = (char*)malloc(sizeof(char)*33);

    sa_d = (int)bit_to_decimal(sa,0,0);
    rt_d = (int)bit_to_decimal(rt,0,0);
    rd_d = (int)bit_to_decimal(rd,0,0);
    if(rd_d ==0){
        printf("->ROTR $%d, $%d, %d\n", rd_d,rt_d,sa_d);
        fatal("Ne modiffiez pas le registre 0");
    }
    if(init_registre[rt_d] == 0){
        printf("->ROTR $%d, $%d, %d\n", rd_d,rt_d,sa_d);
        printf("Le registre %d est vide\n",rt_d);
        fatal("registre vide");
    }else{
        tamp = ((registre[rt_d]>>sa_d)|(registre[rt_d]<<(32-sa_d)))& 0xFFFFFFFF;
        bit(tamp,32,tampon);
        if(tampon[0]=='1'){
            signe =1;
        }
        registre[rd_d] = bit_to_decimal(tampon,signe,0);
        init_registre[rd_d] =1;
        printf("%ld\n", registre[rd_d]);
    }   

    free(tampon);
}
void bgtz(char *rs,char *offset,long int* registre,int *init_registre,Adresse **tete_index, Adresse *tete){
    int rs_d;
    int offset_d;
    int signe =0;
    long add_tamp =0;
    rs_d = (int)bit_to_decimal(rs,0,0);
    if(offset[0] == '1'){
        signe =1;
    }
    offset_d = (int)bit_to_decimal(offset,signe,0);
    if((init_registre[rs_d] == 0)){
        printf("->BGTZ $%d, %d\n",rs_d,offset_d);
        printf("Le registre %d est vide\n",rs_d);
        fatal("registre vide");
    }else if(offset_d%4 !=0){
        printf("->BGTZ $%d, %d\n",rs_d,offset_d);
        fatal("L'adresse n'est pas un multiple de 4");
    }else{
        add_tamp = offset_d + (*tete_index)->adresse;
        if(add_tamp<0){
            printf("->BGTZ $%d, %d\n",rs_d,offset_d);
            fatal("L'adresse ciblée est incorecte");
        }else{
            if(registre[rs_d]>0){
                parcourirListe(tete_index,tete,add_tamp);
            }else{
                (*tete_index) = (*tete_index)->link;
            }
        }
    }
}


void application(char *mot_bit, long int *registre, int *init_registre,int mode, Adresse **tete_index, Adresse *tete){
    char *commande = (char *)malloc(sizeof(char)*5);
    char *rs = (char *)malloc(sizeof(char)*6);
    //int rs;
    char *rt = (char *)malloc(sizeof(char)*6);
    //int rt_d;
    char *rd = (char *)malloc(sizeof(char)*6);
    //int rd_d;
    char *sa = (char *)malloc(sizeof(char)*6);
    //int sa_d;
    char *imm = (char *)malloc(sizeof(char)*17);
    //int imm_d;
    char *adresse = (char *)malloc(sizeof(char)*27);
    //int adresse_d;  
    
    if(!strcmp(mot_bit,"00000000000000000000000000000000")){
        strcpy(commande,"NOP");
    }else{
        get_commande(mot_bit,commande);
    }
    if(!strcmp(commande,"ADDI")){
        for(int i =6; i<11;i++){
            rs[i-6] = mot_bit[i];
        }
        rs[5]='\0';
        for(int i =11; i<16;i++){
            rt[i-11] = mot_bit[i];
        }
        rt[5]='\0';
        for(int i =16; i<32; i++){
            imm[i-16] = mot_bit[i];
        }
        imm[16]='\0';
        addi(rs,rt,imm, registre,init_registre);
        (*tete_index) = (*tete_index)->link;
    }else if(!strcmp(commande,"ADD")){
        for(int i =6; i<11;i++){
            rs[i-6] = mot_bit[i];
        }
        rs[5]='\0';
        for(int i =11; i<16;i++){
            rt[i-11] = mot_bit[i];
        }
        rt[5]='\0';
        for(int i =16; i<21;i++){
            rd[i-16] = mot_bit[i];
        }
        rd[5]='\0';
        add(rs,rt,rd, registre,init_registre);
        (*tete_index) = (*tete_index)->link;
    }else if(!strcmp(commande,"SUB")){
        for(int i =6; i<11;i++){
            rs[i-6] = mot_bit[i];
        }
        rs[5]='\0';
        for(int i =11; i<16;i++){
            rt[i-11] = mot_bit[i];
        }
        rt[5]='\0';
        for(int i =16; i<21;i++){
            rd[i-16] = mot_bit[i];
        }
        rd[5]='\0';
        sub(rs,rt,rd, registre,init_registre);
        (*tete_index) = (*tete_index)->link;
    }else if(!strcmp(commande,"MULT")){
         for(int i =6; i<11;i++){
            rs[i-6] = mot_bit[i];
        }
        rs[5]='\0';
        for(int i =11; i<16;i++){
            rt[i-11] = mot_bit[i];
        }
        rt[5]='\0';
        mult_(rs,rt,registre,init_registre);
        (*tete_index) = (*tete_index)->link;
    }else if(!strcmp(commande,"DIV")){
        for(int i =6; i<11;i++){
            rs[i-6] = mot_bit[i];
        }
        rs[5]='\0';
        for(int i =11; i<16;i++){
            rt[i-11] = mot_bit[i];
        }
        rt[5]='\0';
        div_(rs,rt,registre,init_registre);
        (*tete_index) = (*tete_index)->link;
    }else if(!strcmp(commande,"MFHI")){
        for(int i =16; i<21;i++){
            rd[i-16] = mot_bit[i];
        }
        rd[5]='\0';
        mfhi(rd,registre,init_registre);
        (*tete_index) = (*tete_index)->link;
    }else if(!strcmp(commande,"MFLO")){
        for(int i =16; i<21;i++){
            rd[i-16] = mot_bit[i];
        }
        rd[5]='\0';
        mflo(rd,registre,init_registre);
        (*tete_index) = (*tete_index)->link;
    }else if(!strcmp(commande,"AND")){
        for(int i =6; i<11;i++){
            rs[i-6] = mot_bit[i];
        }
        rs[5]='\0';
        for(int i =11; i<16;i++){
            rt[i-11] = mot_bit[i];
        }
        rt[5]='\0';
        for(int i =16; i<21;i++){
            rd[i-16] = mot_bit[i];
        }
        rd[5]='\0';
        and_(rs,rt,rd, registre,init_registre);
        (*tete_index) = (*tete_index)->link;
    }else if(!strcmp(commande,"OR")){
        for(int i =6; i<11;i++){
            rs[i-6] = mot_bit[i];
        }
        rs[5]='\0';
        for(int i =11; i<16;i++){
            rt[i-11] = mot_bit[i];
        }
        rt[5]='\0';
        for(int i =16; i<21;i++){
            rd[i-16] = mot_bit[i];
        }
        rd[5]='\0';
        or_(rs,rt,rd, registre,init_registre);
        (*tete_index) = (*tete_index)->link;
    }else if(!strcmp(commande,"XOR")){
        for(int i =6; i<11;i++){
            rs[i-6] = mot_bit[i];
        }
        rs[5]='\0';
        for(int i =11; i<16;i++){
            rt[i-11] = mot_bit[i];
        }
        rt[5]='\0';
        for(int i =16; i<21;i++){
            rd[i-16] = mot_bit[i];
        }
        rd[5]='\0';
        xor_(rs,rt,rd, registre,init_registre);
        (*tete_index) = (*tete_index)->link;
    }else if(!strcmp(commande,"SLT")){
        for(int i =6; i<11;i++){
            rs[i-6] = mot_bit[i];
        }
        rs[5]='\0';
        for(int i =11; i<16;i++){
            rt[i-11] = mot_bit[i];
        }
        rt[5]='\0';
        for(int i =16; i<21;i++){
            rd[i-16] = mot_bit[i];
        }
        rd[5]='\0';
        slt(rs,rt,rd, registre,init_registre);
        (*tete_index) = (*tete_index)->link;
    }else if(!strcmp(commande,"SLL")){
        for(int i =11; i<16;i++){
            rt[i-11] = mot_bit[i];
        }
        rt[5]='\0';
        for(int i =16; i<21;i++){
            rd[i-16] = mot_bit[i];
        }
        rd[5]='\0';
        for(int i =21; i<26;i++){
            sa[i-21] = mot_bit[i];
        }
        sa[5]='\0';
        sll(sa,rt,rd, registre,init_registre);
        (*tete_index) = (*tete_index)->link;
    }else if(!strcmp(commande,"SRL")){
        for(int i =11; i<16;i++){
            rt[i-11] = mot_bit[i];
        }
        rt[5]='\0';
        for(int i =16; i<21;i++){
            rd[i-16] = mot_bit[i];
        }
        rd[5]='\0';
        for(int i =21; i<26;i++){
            sa[i-21] = mot_bit[i];
        }
        sa[5]='\0';
        srl(sa,rt,rd, registre,init_registre);
        (*tete_index) = (*tete_index)->link;
    }else if(!strcmp(commande,"ROTR")){
        for(int i =11; i<16;i++){
            rt[i-11] = mot_bit[i];
        }
        rt[5]='\0';
        for(int i =16; i<21;i++){
            rd[i-16] = mot_bit[i];
        }
        rd[5]='\0';
        for(int i =21; i<26;i++){
            sa[i-21] = mot_bit[i];
        }
        sa[5]='\0';
        rotr(sa,rt,rd, registre,init_registre);
        (*tete_index) = (*tete_index)->link;
    }else if(!strcmp(commande,"BGTZ")){
        for(int i =6; i<11;i++){
            rs[i-6] = mot_bit[i];
        }
        rs[5]='\0';
        for(int i =16; i<32; i++){
            imm[i-16] = mot_bit[i];
        }
        imm[16]='\0';
        bgtz(rs,imm, registre,init_registre,tete_index,tete);
    }

    free(adresse);
    free(imm);
    free(sa);
    free(rd);
    free(rt);
    free(rs);
    free(commande);
}