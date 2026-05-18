#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "joueur.h"
#include "pioche.h"
//ANSI colors 
#define COLOR_RESET  "\033[0m"
#define RED    "\033[1;31m"
#define GREEN  "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE   "\033[1;34m"
#define CYAN   "\033[1;36m"

void generer_lignes_carte(int carte, char lignes[5][20]); //Translates the card's numeric code into text (example : 16 -> "+6")

void afficher_plateau(Joueur *j, Pioche *p); //Displays the current state of the player and the pickaxe

void attendre_entree(); //Pauses the game until the user presses Enter

#endif