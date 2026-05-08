#include "joueur.h"
#include <string.h>

void init_joueur_manche(Joueur *j){
    j->scoreManche = 0;
    j->aPerduManche = 0;
    j->aFiniManche = 0;
    for(int i=0; i < 19; i++){
        j->cartesMain[i] = 0;
    }
}

Joueur* connexion(int *nbj){
    int n = 0;
    printf("--- BIENVENUE DANS FLIPTEK ---\n");
    do{
        printf("Combien de joueurs participent ? (Minimum 2) : ");
        if(scanf("%d", &n) != 1){ //si la fonction scanf ne renvoie pas 1 alors il y a une erreur sur le champ entrer par l'utlisateur
            printf("Erreur : veuillez saisir un nombre entier\n");
            while(getchar() != '\n'){};
        }
    }while(n<2);
    (*nbj) = n;
    Joueur *tab = malloc(n*sizeof(Joueur));
    if(tab == NULL){
        printf("Erreur d'allocation des joueurs\n");
        exit(1);
    }
    for(int i=0; i < n; i++){
        printf("\n");
        printf("Joueur %d, saisissez votre pseudo :", i+1);
        scanf("%s", tab[i].nom);
        tab[i].id = i+1;
        tab[i].scoreTotal =0; //les scores à 0 en début de partie
        init_joueur_manche(&tab[i]);
    }
    printf("\n");
    printf("Tous les joueurs sont enregistrés !\n");
    printf("\n");
    return tab;
}