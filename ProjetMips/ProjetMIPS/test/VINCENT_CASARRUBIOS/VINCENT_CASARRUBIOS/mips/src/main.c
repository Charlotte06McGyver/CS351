// Projet MIPS 2022-2023
// Auteurs: CASARRUBIOS_VINCENT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../include/header.h"
#include "../include/convert_hexa.h"
#include "../include/lecture_instructions.h"
#include "../include/beta.h"


int main(int argc, char **argv)
{
   int mode =0;
   FILE * prog_file; //fichier qui contiendra le programme assembleur a lire
   FILE * sortie_assemblage; //fichier qui contiendra les instructions assembleur traduites en hexadecimal (code assemblé)
   FILE * sortie_terminal; //fichier qui contiendra l'état final du programme à la fin de l'exécution
   char *commande = (char*)malloc(sizeof(char)*20);
   int leave = 0;
   char c;

   char *cont = (char *)malloc(sizeof(char)*100);
   commande[0] = '\0';
   cont[0] = '\0';
   
   /*on definit les valeurs de mode (0,1,2)*/
    /* S'il n'y a pas d'arguments (argc==1), lancer le mode interactif. */
    if(argc == 1){
     mode = 0;
    }
    else if(argc == 2){//Pb s'il y a 1 seul argument 
      printf("Error need more than 1 argument or no argument\n");
      exit(EXIT_FAILURE); //comme un return mais arrete le programme immediatement
    }
   else if(argc == 3){ //S'il y a 2 arguments on lance le mode automatique pas-a-pas
      mode = 1;
      prog_file = fopen( argv[1], "r" );
      fclose(prog_file);
      
   }
    /* S'il y a 2 arguments (argc==3), lancer le mode automatique pas-à-pas.
       Le premier argument (argv[1]) est le nom du programme assembleur.
     Le second argument (argv[2]) est forcément "-pas". */
     
   else if(argc == 4){ //S'il y a 3 arguments on lance le mode automatique
      mode = 2;
      prog_file = fopen( argv[1], "r" );
      sortie_assemblage = fopen( argv[2], "w" );
      sortie_terminal = fopen( argv[3], "w" );
      fclose(prog_file);
      fclose(sortie_assemblage);
      fclose(sortie_terminal);
   }
    /* S'il y a 3 arguments (argc==4), lancer le mode automatique.
       Le premier argument (argv[1]) est le nom du programme assembleur.
       Le second argument (argv[2]) est le nom du fichier où il faut
       enregistrer le code assemblé.
       Le troisième argument (argv[3]) est le nom du fichier où il faut
       enregistrer l'état final du programme à la fin de l'exécution. */

    /* Les rendus seront testés par le mode automatique, il est donc important
       que ce mode fasse les choses suivantes :
       - Lire le programme assembleur. Ouvrez-le avec le mode "r" de fopen().
       - Produire les deux fichiers de sortie. Ouvrez-les avec le mode "w" de
         fopen() pour qu'ils soient créés s'ils n'existent pas encore.
       Pour commencer vous n'avez pas besoin d'utiliser les fichiers, il suffit
       de les ouvrir et de les fermer immédiatement. */

    /* Le Makefile fourni contient une commande "test-cli" qui vérifie que le
       mode automatique fonctionne et crée bien les deux fichiers de sortie.
       Tapez "make test-cli" pour effectuer le test. S'il n'y a pas d'erreur,
       c'est bon. */

    /* Supprimez ces commentaires une fois que c'est fait. */
   if(mode ==0){
      printf("Hello émulateur MIPS!, tapez EXIT pour quitter le mode intéractif\n");
      while(leave == 0){
         scanf("%[^\n]%*c", commande);//Lit la commande
         if(strcmp(commande, "\0")==0){//On test qu'on ait pas appuyé plusieurs fois sur entrée
            fatal("Ne pas apuyer 2 fois sur entré");
         }else if((strcmp(commande, "EXIT")==0)){//Test si on veut quitter le mode intéractif
            leave = 1;
         }else{
            fonctions(commande,mode,argv[2]);// appelle la commande qui convertit notre commande en hexa    
         }
      }
   }else if(mode == 1 || mode ==2){
      printf("Hello émulateur MIPS!\n");
      prog_file = fopen( argv[1], "r" );
      while (fscanf(prog_file, "%[^\n]%*c", commande)!=EOF)// On lit notre fichier jusqu'à ce qu'i soit vide
      {
         if((c = fgetc(prog_file))!='\n'){// Permet de savoir si la ligne qui suit en une ligne vide car fscanf ne peut pas lire de ligne vide
            if(c != EOF){  
               fseek(prog_file,-1,SEEK_CUR);// Si ce n'est pas une ligne vide on doit redécaler le pointeur de fichier, pour qu'il prenne bien toute la ligne 
            }            
         }
         if(commande[0] != '#'){// Teste si ce n'est pas un commentire
            fonctions(commande,mode,argv[2]);// Appel de la fonction qui convertit notre commande en hexa
            if(mode == 1){
               printf("Appuyez sur une touche pour continuer et entrée pour continuer\n");
               scanf("%[^\n]%*c",cont);// On attend qu'une touche soit pressée
            }
         }
      }  
      fclose(prog_file);
   }
   free(cont);
   free(commande);
   return EXIT_SUCCESS;
}
