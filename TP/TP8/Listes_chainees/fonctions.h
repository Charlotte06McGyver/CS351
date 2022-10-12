
typedef struct element {
    int valeur; /*valeur de l'element*/
    struct element* suivant;
}liste;


void afficherListe(liste *l);
void InsertionTete (liste **l, int x);
void InsertionQueue (liste **l, int x);
void suppressionTete(liste **l);
void suppressionQueue(liste **l);
int Taille_liste(liste *l);
void InsertionMilieu(liste **l, int x);
void insererElement(int x, liste *l);
void supprimerElement(int i, liste *l);