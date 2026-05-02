#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "joueur.h"
#include "pioche.h"

// Couleurs ANSI 
#define COLOR_RESET  "\033[0m"
#define COLOR_RED    "\033[1;31m"
#define COLOR_GREEN  "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_BLUE   "\033[1;34m"
#define COLOR_CYAN   "\033[1;36m"

/* --- Prototypes --- */

/**
 * Traduit le code numérique de la carte en texte (ex: 16 -> "+6")
 */
void afficher_nom_carte(int carte);

/**
 * Affiche l'état actuel du joueur et de la pioche
 */
void afficher_plateau(Joueur *j, Pioche *p);

/**
 * Efface tout le contenu du terminal
 */
void effacer_terminal();

/**
 * Met le jeu en pause jusqu'à ce que l'utilisateur appuie sur Entrée
 */
void attendre_entree();

#endif