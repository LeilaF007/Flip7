#ifndef JOUEUR_H
#define JOUEUR_H
#include <stdio.h>
#include <stdlib.h>
#define MAX_NOM 50


typedef struct {
    char nom[MAX_NOM];       //Username
    int id;                  //User ID
    int scoreTotal;          //Score 
    int scoreManche;         //Points accumulated in a round
    int cartesMain[19];      //Hand
    int aPerduManche;        //1 if the player draw a double
    int aFiniManche;         //1 if the player stops
} Joueur;


//Initializes the player's temporary data before a new round
void init_joueur_manche(Joueur *j);

//Initializes the player array by requesting the ID and usernames
//gives the number of players entered
//returns a pointer to the player array
Joueur* connexion(int *nbj);

#endif