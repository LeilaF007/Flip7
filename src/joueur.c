#include "joueur.h"
#include <string.h>

void init_joueur_manche(Joueur *j){
    j->scoreManche = 0;
    j->perduManche = 0;
    j->finiManche = 0;

    //There are 19 different cards in the game
    for(int i=0; i<19; i++){
        j->cartesMain[i] = 0;
    }
}

Joueur* connexion(int *nbj){

    //initialization of the number of players
    int n = 0; 
    printf("--- BIENVENUE DANS FLIPTEK ---\n");
    do{
        printf("Combien de joueurs participent ? (Minimum 2) : ");
        if(scanf("%d", &n) != 1){ //If the scanf function does not return 1, then there is an error in the field entered by the user
            printf("Erreur : veuillez saisir un nombre entier\n");
            while(getchar() != '\n'); //The buffer contains something other than an integer, so the while loop allows us to remove what it contains because it's false
        }
    }while(n<2);

    //the number of players
    (*nbj) = n; 

    //players' table
    Joueur *tab = malloc(n*sizeof(Joueur));
    if(tab == NULL){
        printf("Erreur d'allocation des joueurs\n");
        exit(1);
    }
    for(int i=0; i<n; i++){
        printf("\n");
        printf("Joueur %d, saisissez votre pseudo : ", i+1);
        scanf("%s", tab[i].nom);
        while(getchar() != '\n'); //to remove the \n present in the buffer because scanf only retrieves the name
        tab[i].id = i+1;
        tab[i].scoreTotal =0; //scores at 0 at the start of the game
        init_joueur_manche(&tab[i]);
    }
    printf("\n");
    printf("[Tous les joueurs sont enregistrés !]\n");
    printf("\n");
    return tab;
}
