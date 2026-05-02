#ifndef MECANIQUE_H
#define MECANIQUE_H

#include "joueur.h"
#include "pioche.h"

/* --- Prototypes des fonctions --- */

/**
 * Calcule les gains selon la carte tirée
 * Gère les bonus (x2, +2, +4, +6, +8, +10)
 */
void appliquer_carte(Joueur *j, int carte);

/**
 * Vérifie si le joueur a pioché un doublon
 * @return 1 si doublon (perdu), 0 sinon
 */
int verifier_doublon(Joueur *j, int carte);

/**
 * Compte le nombre de cartes différentes possédées durant la manche
 */
int compter_differentes(Joueur *j);

/**
 * Gère le tour complet d'un joueur
 */
void jouer_tour(Joueur *j, Pioche *p);

#endif