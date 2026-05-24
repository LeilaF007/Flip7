#ifndef MECANIQUE_H
#define MECANIQUE_H

#include "joueur.h"
#include "pioche.h"

//Calculates points based on the card drawn, manages bonuses (x2, +2, +4, +6, +8, +10)
void appliquer_carte(Joueur *j, int carte);

//Checks if the player drew a duplicate, returns 1 if duplicate (lost), 0 otherwise
int verifier_doublon(Joueur *j, int carte);

//Count the number of different cards held during the round
int compter_differentes(Joueur *j);

//Manages a player's complete turn
void jouer_tour(Joueur *j, Pioche *p);

#endif
