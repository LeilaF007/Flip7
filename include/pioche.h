#ifndef PIOCHE_H
#define PIOCHE_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int *cartes;
    int prochain_indice;        //index to the next card to be drawn
    int taille;
} Pioche;

//Initializes a standard draw pile with 1 card of value 0, 1 card of value 1, 2 cards of value 2, etc...
// + 6 bonus cards (+2, *2, +4, +6, +8, +10)
void initialiser_pioche(Pioche *tab);

//initializes a custom draw pile where you choose the quantity of each number card
//always with the 6 bonus cards
void piocheSpecial(Pioche *tab);

//to shuffle the draw pile
void melange_pioche(Pioche *tab);

//To draw a card from the deck, if the deck is empty, this returns -1
int tirer_carte(Pioche *tab);

#endif