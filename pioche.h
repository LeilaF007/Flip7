#ifndef PIOCHE_H
#define PIOCHE_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAILLE_PIOCHE 94

typedef struct {
    int *cartes;
    int prochain_indice;        // indice de la prochaine carte à tirer
    int taille;
} Pioche;

void initialiser_pioche(Pioche *tab);
void piocheSpecial(Pioche *tab);
void melange_pioche(Pioche *tab);
int tirer_carte(Pioche *tab);

#endif