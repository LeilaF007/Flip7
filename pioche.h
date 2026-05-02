#ifndef PIOCHE_H
#define PIOCHE_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAILLE_PIOCHE 85

typedef struct {
    int cartes[TAILLE_PIOCHE]; // tab des 85 carte
    int prochain_indice;        // indice de la prochaine carte à tirer
} Pioche;

void initialiser_pioche(Pioche *tab);
void melange_pioche(Pioche *tab);
int tirer_carte(Pioche *tab);

#endif