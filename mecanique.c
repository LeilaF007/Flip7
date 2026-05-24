#include "mecanique.h"
#include "affichage.h"

void appliquer_carte(Joueur *j, int carte) {
    j->cartesMain[carte]++;

    //Bonus cards (13=x2, 14=+2, 15=+4, 16=+6, 17=+8, 18=+10)
    switch(carte){
        //adding the bonus cards into the score
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
            //normal cards into score
            j->scoreManche += carte;
            break; 
    }
}

int verifier_doublon(Joueur *j, int carte) {
    //cards from 13 to 18 are bonuses, can't be doubles
    if(carte>12){
        return 0;
    }
    //if the remaining cards are more than 1 then they are doubles
    if(j->cartesMain[carte]>1){
        return 1;
    }
    //return 0 for the rest
    return 0;
}

int compter_differentes(Joueur *j) {
    int total = 0;

    //counting cards
    for (int carte = 0; carte <= 12; carte++) {

        if (j->cartesMain[carte] > 0){ //if there is at least 1 card we add 1 to the total 
            total++;
        }
    }
    
    return total; //retrieve the total
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

        //the case where the player presses something other than 1 or 0
        if(choix != 0 && choix != 1){
            printf("Choix invalide ! Tapez 0 ou 1.\n");
        }
        else{
            //case where the player chooses to stop
            if (choix == 0) {
                j->aFiniManche = 1;
            }
            
            else{
                //the case where the player picks

                int carte = tirer_carte(p);
                if (carte == -1) {
                    printf("La pioche est vide !\n");
                    j->aFiniManche = 1;
                }
                else{
        
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
        }   
    }
}
