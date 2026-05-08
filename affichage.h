#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "joueur.h"
#include "pioche.h"
//ANSI colors 
#define COLOR_RESET  "\033[0m"
#define COLOR_RED    "\033[1;31m"
#define COLOR_GREEN  "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_BLUE   "\033[1;34m"
#define COLOR_CYAN   "\033[1;36m"

void afficher_nom_carte(int carte); //Translates the card's numeric code into text (example : 16 -> "+6")

void afficher_plateau(Joueur *j, Pioche *p); //Displays the current state of the player and the pickaxe

//void effacer_terminal(); //Erases all terminal contents

void attendre_entree(); //Pauses the game until the user presses Enter

#endif