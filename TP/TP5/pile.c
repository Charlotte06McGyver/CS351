#include "pile.h"

/* Realisation TRES SIMPLE d'une pile d'entiers
   Ne verifie pas les debordements
*/

pileInt creerPile(){
    pileInt p = (pileInt) malloc(sizeof(sPileInt));
    p->pp = 0;
    return p;

}

int estPileVide(pileInt p){
    return (p->pp == 0);
}
void empiler(pileInt p, int x){
    p->pp++;
    p->pile[p->pp] = x;
}
int depiler(pileInt p){
    return(p->pile[p->pp--]);
}
