#ifndef JOUEUR_H
#define JOUEUR_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_NOM 50
#define NB_CARTES_MAX 85


typedef struct {
    char nom[MAX_NOM];       // Pseudo
    int id;                  // Identifiant 
    int scoreTotal;          // Score 
    int scoreManche;         // Points accumulés dans une manche
    int cartesMain[19];      // Main
    int aPerduManche;        // 1 si le joueur pioche un double
    int aFiniManche;         // 1 si le joueur arrete
} Joueur;

/* --- Prototypes des fonctions --- */

/**
 * Initialise le tableau de joueurs en demandant le nombre et les pseudos[cite: 1]
 * @param nbj Pointeur pour retourner le nombre de joueurs saisis
 * @return Un pointeur vers le tableau de joueurs alloué dynamiquement
 */
Joueur* connexion(int *nbj);

/**
 * Réinitialise les données temporaires du joueur avant une nouvelle manche[cite: 1]
 * @param j Pointeur vers le joueur à réinitialiser
 */
void reset_joueur_manche(Joueur *j);

#endif