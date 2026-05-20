#include "joueur.h"
#include <string.h>

void init_joueur_manche(Joueur *j){
    j->scoreManche = 0;
    j->perduManche = 0;
    j->finiManche = 0;
    for(int i=0; i<19; i++){ //il y a 19 cartes différentes dans le jeu
        j->cartesMain[i] = 0;
    }
}

Joueur* connexion(int *nbj){
    int n = 0; //initialisation des nombres de joueurs
    printf("--- BIENVENUE DANS FLIPTEK ---\n");
    do{
        printf("Combien de joueurs participent ? (Minimum 2) : ");
        if(scanf("%d", &n) != 1){ //si la fonction scanf ne renvoie pas 1 alors il y a une erreur sur le champ entrer par l'utlisateur
            printf("Erreur : veuillez saisir un nombre entier\n");
            while(getchar() != '\n'){}; //le buffer contient autre chose que un entier donc le while permet d'enlever ce qui y contient car c'est faux
        }
    }while(n<2);
    (*nbj) = n; //le nbr de joueurs
    Joueur *tab = malloc(n*sizeof(Joueur)); //tableau de joueurs
    if(tab == NULL){
        printf("Erreur d'allocation des joueurs\n");
        exit(1);
    }
    for(int i=0; i<n; i++){
        printf("\n");
        printf("Joueur %d, saisissez votre pseudo :", i+1);
        scanf("%s", tab[i].nom);
        while(getchar() != '\n'); //pour enlever le \n present dans le buffer parce que le scanf recupère que le nom
        tab[i].id = i+1;
        tab[i].scoreTotal =0; //les scores à 0 en début de partie
        init_joueur_manche(&tab[i]);
    }
    printf("\n");
    printf("[Tous les joueurs sont enregistrés !]\n");
    printf("\n");
    return tab;
}