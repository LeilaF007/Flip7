#include "mecanique.h"
#include "affichage.h"

void appliquer_carte(Joueur *j, int carte) {
    j->cartesMain[carte]++;

    // Cartes bonus (13=x2, 14=+2, 15=+4, 16=+6, 17=+8, 18=+10)
    switch(carte){
        case 13:
            j->scoreManche*=2;
            break;
        case 14:
            j->scoreManche +=2;
            break;   
        case 15:
            j->scoreManche +=4;
            break;
        case 16:
            j->scoreManche +=6;
            break;
        case 17:
            j->scoreManche +=8;
            break;
        case 18:
            j->scoreManche +=10;
            break;
        default:
            j->scoreManche += carte;
            break; 
    }
}

int verifier_doublon(Joueur *j, int carte) {
    if(carte>12){
        return 0;
    }

    if(j->cartesMain[carte]>=2){
        return 1;
    }

    return 0;
}

int compter_differentes(Joueur *j) {
    int total = 0;
    for (int carte = 0; carte <= 12; carte++) {

        if (j->cartesMain[carte] > 0) {
            total++;
        }
    }
    
    return total;
}

void jouer_tour(Joueur *j, Pioche *p) {
    int choix;

    printf("\n--- Tour de %s (Score total : %d) ---\n", j->nom, j->scoreTotal);

    //principal player's round loop
    while(!j->aPerduManche && !j->aFiniManche){

        afficher_plateau(j, p);

        //asking for the player's choice
        printf("(1) Piocher | (0) S'arreter : ");
        scanf("%d", &choix);
        while(getchar() != '\n'); //emptying the buffer

        if(choix != 0 && choix != 1){
            printf("Choix invalide ! Tapez 0 ou 1.\n");
            continue;
        }
        if (choix == 0) {
           j->aFiniManche = 1;
           continue;
        } 

        int carte = tirer_carte(p);
        if (carte == -1) {
                printf("La pioche est vide !\n");
                j->aFiniManche = 1;
                break;
            }
        
        printf("\n>>> Vous avez tire la carte : \n");
            char lignes[5][20];
            generer_lignes_carte(carte, lignes);

            for (int i = 0; i < 5; i++) {
                printf("%s\n", lignes[i]);
            }


            appliquer_carte(j, carte);

        //checking if there is doubles
        if (verifier_doublon(j, carte)) {
                printf("DOUBLON ! Vous perdez vos points de cette manche\n");
                j->scoreManche = 0;
                j->aPerduManche = 1;
                attendre_entree();
        }
        
        //Flip7
        else if (compter_differentes(j) == 7) {
                printf("FLIP 7 ! Bonus de +15 points et fin de manche !\n");
                j->scoreManche += 15;
                j->aFiniManche = 1;
                attendre_entree();
        }

    }
}
