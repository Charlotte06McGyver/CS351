/*********************************************************************/
/* Biblioth�que graphique graphlib pour l'enseignement universitaire */
/* D'apr�s les id�es de Fran�oise et Jean-Paul Bertrandias sur Atari */
/* Impl�mentation sous X Windows: Michel Bonin et Xavier Girod       */
/* UFR IMA - Universit� Joseph Fourier (Grenoble)                    */
/* Centre Joseph Fourier Dr�me-Ard�che (Valence)                     */
/* email: Michel.Bonin@ujf-grenoble.fr                               */
/* modifi� par Christophe Deleuze                                    */
/*********************************************************************/

/* Fichiers X inclus */

#include <X11/Xlib.h>
#include <X11/Xutil.h>

/* Fichier d'en-t�te */

#ifndef _GRAPHLIB_H
#define _GRAPHLIB_H

Display *Moniteur;
int Ecran;
Window FenetreParDefaut;
GC Zone;


/* gr_inits(larg,haut,titre) : initialisation de l'�cran graphique 
  cr�e une fenetre X-Window de taille larg X haut avec un titre */
void gr_inits_w(int larg, int haut, char titre[]);

/* Ouverture d'une fen�tre */
void open_w(Window *W, int abs, int ord, int larg, int haut, char titre[]);

/* S�lection d'une fen�tre */
void set_w(Window W);

/* Fermeture d'une fen�tre */
void close_w(Window W);

/* gr_close : fermeture de l'�cran graphique */
void gr_close(void);

/* set_blue: changement de couleur */
void set_blue(void);

/* set_red: changement de couleur */
void set_red(void);

/* set_green: changement de couleur */
void set_green(void);

/* set_yellow: changement de couleur */
void set_yellow(void);

/* set_black: changement de couleur */
void set_black(void);

/*�criture de texte en blanc sur fond noir*/
void video_inv(void);

/*dessin en blanc sur fond noir*/
void graph_inv(void);

/*ecriture de texte en noir sur fond blanc*/
void video_nor(void);

/*dessin en noir sur fond blanc*/
void graph_nor(void);

/* clear_screen : effacement de l'�cran */
void clear_screen(void);

/* line : trace une ligne */
void line(int x1,int y1,int x2,int y2);

/* line_off : efface une ligne */
void line_off(int x1,int y1,int x2,int y2);

/* point :  affichage du point (x,y) */
void point(int x,int y);

/* point_off : effacement du point (x,y) */
void point_off(int x,int y);

/*fill_triangle: remplit un triangle*/
void fill_triangle(int x1,int y1,int x2,int y2,int x3,int y3);

/* circle : trace un cercle */
void circle (int x,int y,int R);

/* fill_circle : remplit un cercle */
void fill_circle (int x,int y,int R);

/* circle_off : efface un cercle */
void circle_off (int x,int y,int R);

/* write_gr : �criture sur l'�cran graphique en superposition */
void write_gr(int x,int y, char str[]);

/* overwrite_gr : �criture sur l'�cran graphique avec effacement */
void overwrite_gr(int x,int y, char str[]);

/* attente d'un clic de souris */
void cliquer(void);

/* attente d'un clic de souris et r�cup�ration des coordonn�es */
void cliquer_xy(int *x, int *y);

/*pour la compatibilit� avec Atari*/
void wait_kbd(void);

/*cstat teste l'enfoncement d'une touche du clavier*/
int cstat(void);

/*consilent fournit le caract�re pr�sent s'il y en a un, 
  le caract�re nul sinon*/
char consilent(void);

/*bouton fournit le num�ro de bouton si un bouton de la souris a �t� enfonc�,
  0 sinon*/
int bouton(void);

#endif

