#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "joueur.h"
#include "pioche.h"
#include "mecanique.h"
#include "fichier.h"

int main(){

    srand(time(NULL));

    int nbj = 0;

    int partieEnCours = 1;

    int val = 0;

    int choixPioche = 0;

    Joueur *tabJoueurs = connexion(&nbj);

    Pioche deck;

    /* ---------- CHOIX DE LA PIOCHE ---------- */

    printf("\n");
    printf("---------- CHOIX DE LA PIOCHE ----------\n");
    printf("[1] Pioche classique\n");
    printf("[2] Pioche personnalisee\n");
    printf("Votre choix : ");

    do{

        scanf("%d", &choixPioche);

    }while(choixPioche != 1 &&
           choixPioche != 2);

    /* ---------- INITIALISATION ---------- */

    if(choixPioche == 1){

        initialiser_pioche(&deck);

    }
    else{

        piocheSpecial(&deck);
    }

    melange_pioche(&deck);

    /* ---------- BOUCLE PRINCIPALE ---------- */

    while(partieEnCours == 1){

        printf("\n");
        printf("---------- NOUVELLE MANCHE ----------\n");

        for(int i = 0; i < nbj; i++){

            init_joueur_manche(&tabJoueurs[i]);

            jouer_tour(&tabJoueurs[i], &deck);

            tabJoueurs[i].scoreTotal +=
            tabJoueurs[i].scoreManche;

            printf("\n");

            printf("Fin du tour, score total de %s : %d\n",
            tabJoueurs[i].nom,
            tabJoueurs[i].scoreTotal);

            /* ---------- VICTOIRE ---------- */

            if(tabJoueurs[i].scoreTotal >= 200){

                printf("\n");

                printf("!!! %s A ATTEINT 200 POINTS ET GAGNE LA PARTIE !!!\n",
                tabJoueurs[i].nom);

                partieEnCours = 0;

                break;
            }

            /* ---------- FIN DE PIOCHE ---------- */

            if(deck.prochain_indice >= deck.taille){

                printf("\n");

                printf("--- PLUS DE CARTES DANS LA PIOCHE ---\n");

                printf("---       FIN DE LA PARTIE        ---\n");

                partieEnCours = 0;

                break;
            }
        }
    }

    /* ---------- CLASSEMENT ---------- */

    printf("\n");
    printf("---       CLASSEMENT FINAL        ---\n");

    for(int i = 0; i < nbj; i++){

        printf("%d. %s : %d points\n",
        i + 1,
        tabJoueurs[i].nom,
        tabJoueurs[i].scoreTotal);
    }

    /* ---------- SAUVEGARDE ---------- */

    printf("\n");

    printf("Voulez-vous creer un fichier avec les scores ?\n");

    printf("Oui : 1 | Non : 0\n");

    do{

        scanf("%d", &val);

    }while(val != 0 &&
           val != 1);

    if(val == 1){

        fichier_score(tabJoueurs, nbj);
    }

    /* ---------- LIBERATION MEMOIRE ---------- */

    free(tabJoueurs);

    free(deck.cartes);

    printf("\n");

    printf("Merci d'avoir joue a FlipTek !\n");

    return 0;
}