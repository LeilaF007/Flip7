#include "joueur.h"
#include <string.h>


Joueur* connexion(int *nbj) {
    int n = 0;

    printf("--- BIENVENUE DANS FLIPTEK ---\n");
    do {
        printf("Combien de joueurs participent ? (Minimum 2) : ");
        if (scanf("%d", &n) != 1) {
            printf("Erreur : veuillez saisir un nombre entier.\n");
            while(getchar() != '\n');
        }
    } while (n < 2);

    *nbj = n;

    Joueur *tab = malloc(n * sizeof(Joueur));
    if (tab == NULL) {
        printf("Erreur : Problème de l'allocation des joueurs.\n");
        exit(1); 
    }

    for (int i = 0; i < n; i++) {
        printf("\nJoueur %d, quel est votre pseudo ? ", i + 1);
        scanf("%49s", tab[i].nom);
        
        tab[i].id = i + 1;
        tab[i].scoreTotal = 0;
        
        reset_joueur_manche(&tab[i]);
    }

    printf("\nTous les joueurs sont prets !\n\n");
    return tab;
}


void reset_joueur_manche(Joueur *j) {
    j->scoreManche = 0;
    j->aPerduManche = 0;
    j->aFiniManche = 0;
    
    for (int i = 0; i < 19; i++) {
        j->cartesMain[i] = 0;
    }
}