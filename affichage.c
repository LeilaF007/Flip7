#include<stdio.h>
#include<stdlib.h>
#include "affichage.h"

void generer_lignes_carte(int carte, char lignes[5][20]){
    const char *couleur;

    if (carte >= 13) {
        couleur = YELLOW; //bonus cards
    } 
    else {
        couleur = BLUE; //normal cards
    }

    //top of the cards
    sprintf(lignes[0], "%s--------%s", couleur, COLOR_RESET);

    //content of the card, according to teh card
    switch(carte){ 
        case 13:
            sprintf(lignes[1], "%s|  x2  |%s", couleur, COLOR_RESET);
            break;
        case 14:
            sprintf(lignes[1], "%s|  +2  |%s", couleur, COLOR_RESET);
            break;
        case 15:
            sprintf(lignes[1], "%s|  +4  |%s", couleur, COLOR_RESET);
            break;
        case 16:
            sprintf(lignes[1], "%s|  +6  |%s", couleur, COLOR_RESET);
            break;
        case 17:
            sprintf(lignes[1], "%s|  +8  |%s", couleur, COLOR_RESET);
            break;
        case 18: 
            sprintf(lignes[1], "%s| +10  |%s", couleur, COLOR_RESET);
            break;
    
        default:
            //different alignments according to if the content is at 1 or 2 numbers
            if(carte > 9){
                sprintf(lignes[1], "%s|  %d  |%s",couleur, carte, COLOR_RESET);
            }
            else{ 
                sprintf(lignes[1], "%s|   %d  |%s",couleur, carte, COLOR_RESET);
            }
    }

    //bottom of the card
    sprintf(lignes[2], "%s--------%s", couleur, COLOR_RESET);
    
    
    // lines 3 and 4 empty for comptability with the horizontal display
    sprintf(lignes[3], " ");
    sprintf(lignes[4], " ");
}



void afficher_plateau(Joueur *j, Pioche *p){
    printf("\n");

    //top of the playing board
    printf("%s╭──────────────────────────────── PLATEAU ─────────────────────────────────╮%s\n", CYAN, COLOR_RESET);

    //player's info
    printf("  JOUEUR : %s%s%s | SCORE TOTAL : %s%d%s | SCORE MANCHE : %s%d%s\n", 
    YELLOW, j->nom, COLOR_RESET, GREEN, j->scoreTotal, COLOR_RESET, RED, j->scoreManche, COLOR_RESET);
    
    printf("  VOTRE MAIN : \n");
    
    int cartes[50];
    int nb=0;

    //recovering present cards
    for(int i = 0; i<= 18; i++){
        if(j->cartesMain[i]>0){
            cartes[nb++]=i;
        }
    }

    //player has no cards
    if(nb==0){
        printf("  (vide)\n");
    }
    else{
        //temporary table for one card
        char lignes[5][20]; // 5 lines, 20 chars

        // Horizontal display: displaying the card line by line for every card
        for (int ligne = 0; ligne < 3; ligne++) {
            for(int k=0; k<nb; k++){

                //generate the line for the card k
                generer_lignes_carte(cartes[k], lignes);
                
                //only displaying the asked line
                print("%s   ", lignes[ligne]);
            }
            print("\n");
        }
    }

    printf("\n");

    //progression bar
    printf("  PIOCHE : [");

    //Conversion of the number of cards drawn into a 40 character bar
    int progression = (p->prochain_indice * 40)/TAILLE_PIOCHE; //pick's scale

    //displaying the progression
    for(int i=0; i<40; i++){
        if(i<progression){
            printf("X");}
        else{
            printf(".");}
    }
    printf("] (%d/%d cartes tirées)\n", p->prochain_indice, TAILLE_PIOCHE);

    //closing the playing board
    printf("%s╰──────────────────────────────────────────────────────────────────────────╯%s\n", CYAN, COLOR_RESET);
}

void attendre_entree(){
    printf("\n");
    printf("%sAppuyez sur ENTREE pour continuer%s\n", CYAN, COLOR_RESET);
    while(getchar() != '\n'){};
}
