#ifndef FICHIER_H
#define FICHIER_H
#include "joueur.h"
#include <stdio.h>
#include <stdlib.h>

//If the players wish, a file is created with their names and scores

//checks if the characters we put in the file are compatible with a filename
int verif_carac(char tab[]);

//Create the file with the name you choose
void fichier_score(Joueur *j, int nbj);

#endif