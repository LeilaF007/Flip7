#include "mecanique.h"
#include "affichage.h"

void appliquer_carte(Joueur *j, int carte) {
    j->cartesMain[carte]++;

    // Cartes bonus (13=x2 / 14=+2 / 15=+4 / 16=+6 / 17=+8 / 18=+10)
    if (carte == 13) {
        j->scoreManche *= 2;
    }
    else if (carte == 14) {
        j->scoreManche += 2;
    }
    else if (carte == 15) {
        j->scoreManche += 4;
    }
    else if (carte == 16) {
        j->scoreManche += 6;
    }
    else if (carte == 17) {
        j->scoreManche += 8;
    }
    else if (carte == 18) {
        j->scoreManche += 10;
    }
    else {
        // Cartes normales
        j->scoreManche += carte;
    }
}

int verifier_doublon(Joueur *j, int carte) {
    if (carte >= 0 && carte <= 12) {
        if (j->cartesMain[carte] > 1) {
            return 1;
        }
    }
    return 0;
}

int compter_differentes(Joueur *j) {
    int total = 0;
    for (int i = 0; i <= 12; i++) {
        if (j->cartesMain[i] > 0) {
            total++;
        }
    }
    return total;
}

void jouer_tour(Joueur *j, Pioche *p) {
    int choix;
    int continuer = 1;

    printf("\n--- Tour de %s (Score total : %d) ---\n", j->nom, j->scoreTotal);

    while (continuer && !j->aPerduManche && !j->aFiniManche) {
        effacer_terminal();
        afficher_plateau(j, p);

        printf("[1] Piocher | [0] S'arreter : ");
        scanf("%d", &choix);

        if (choix == 1) {
            int carte = tirer_carte(p);
            if (carte == -1) {
                printf("La pioche est vide !\n");
                j->aFiniManche = 1;
                break;
            }

            printf("\n>>> Vous avez tire la carte : ");
            afficher_nom_carte(carte);
            printf("\n");
            appliquer_carte(j, carte);

            if (verifier_doublon(j, carte)) {
                printf("DOUBLON ! Vous perdez vos points de cette manche.\n");
                j->scoreManche = 0;
                j->aPerduManche = 1;
                attendre_entree();
            } 
            else if (compter_differentes(j) == 7) {
                printf("FLIP 7 ! Bonus de +15 points et fin de manche !\n");
                j->scoreManche += 15;
                j->aFiniManche = 1;
                attendre_entree();
            }
        } else {
            j->aFiniManche = 1;
        }
    }
}