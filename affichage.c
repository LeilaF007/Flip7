#include<stdio.h>
#include<stdlib.h>
#include "affichage.h"

void generer_lignes_carte(int carte, char lignes[5][20]){
    const char *couleur;
<<<<<<< HEAD
    if(carte >= 13){
        couleur = YELLOW; //for bonus card
    } 
    else{
        couleur = BLUE; //for normal card
    }
    sprintf(lignes[0], "%s--------%s", couleur, COLOR_RESET); //first line, color reset for stopped the color
=======

    if (carte >= 13) {
        couleur = YELLOW;
    } 
    else {
        couleur = BLUE;
    }


    sprintf(lignes[0], "%s--------%s", couleur, COLOR_RESET);

>>>>>>> 66868323fe23527346b415ff410dd1bfe12b10d9
    switch(carte){ 
        case 13:
            sprintf(lignes[1], "%s|  x2  |%s", couleur, COLOR_RESET); //second line with the number
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
            if(carte > 9){
                sprintf(lignes[1], "%s|  %d  |%s",couleur, carte, COLOR_RESET); //for normal card
            }
            else{ 
                sprintf(lignes[1], "%s|   %d  |%s",couleur, carte, COLOR_RESET);
            }
    }

    sprintf(lignes[2], "%s--------%s", couleur, COLOR_RESET);
    
    // lignes 3 et 4 vides pour compatibilité
    sprintf(lignes[3], " "); //space
    sprintf(lignes[4], " ");
}



void afficher_plateau(Joueur *j, Pioche *p){
    printf("\n");
    printf("%s╭──────────────────────────────── PLATEAU ─────────────────────────────────╮%s\n", CYAN, COLOR_RESET);
    printf("  JOUEUR : %s%s%s | SCORE TOTAL : %s%d%s | SCORE MANCHE : %s%d%s\n", 
    YELLOW, j->nom, COLOR_RESET, GREEN, j->scoreTotal, COLOR_RESET, RED, j->scoreManche, COLOR_RESET);
    printf("  VOTRE MAIN : \n");
<<<<<<< HEAD
    int cartes[CARTES_MAX];
    int nb=0;
    for(int i=0; i<=18; i++){  //recovering present cards
=======
    
    int cartes[50];
    int nb=0;

    //recovering present cards
    for(int i = 0; i<= 18; i++){
>>>>>>> 66868323fe23527346b415ff410dd1bfe12b10d9
        if(j->cartesMain[i]>0){
            cartes[nb++]=i;
        }
    }

    //player has no cards
    if(nb==0){
        printf("  (vide)\n");
    }
    else{
<<<<<<< HEAD
        char lignes[CARTES_MAX][5][20]; // constante de 19 cartes différentes max, 5 lignes, 20 chars
        // Génération
        for(int k = 0; k<nb; k++){
            generer_lignes_carte(cartes[k], lignes[k]); //
=======
        char lignes[50][5][20]; // 50 cartes max, 5 lignes, 20 chars

        // Génération
        for (int k = 0; k < nb; k++) {
            generer_lignes_carte(cartes[k], lignes[k]);
>>>>>>> 66868323fe23527346b415ff410dd1bfe12b10d9
        }

        // Affichage ligne par ligne
<<<<<<< HEAD
        for(int ligne = 0; ligne<3; ligne++){
=======
        for (int ligne = 0; ligne < 3; ligne++) {
>>>>>>> 66868323fe23527346b415ff410dd1bfe12b10d9
            for (int k = 0; k < nb; k++) {
                printf("%s   ", lignes[k][ligne]);
            }
            printf("\n");
        }
    }
    printf("\n");
    //progression bar
    printf("  PIOCHE : [");
<<<<<<< HEAD
    int progression = (p->prochain_indice * 40)/p->taille; //scale for the stack
=======
    int progression = (p->prochain_indice * 40)/TAILLE_PIOCHE; //echelle pour la pioche
>>>>>>> 66868323fe23527346b415ff410dd1bfe12b10d9
    for(int i=0; i<40; i++){
        if(i<progression){
            printf("X");}
        else{
            printf(".");}
    }
    printf("] (%d/%d cartes tirées)\n", p->prochain_indice, TAILLE_PIOCHE);
    printf("%s╰──────────────────────────────────────────────────────────────────────────╯%s\n", CYAN, COLOR_RESET);
}

void attendre_entree(){
    printf("\n");
    printf("%sAppuyez sur ENTREE pour continuer%s\n", CYAN, COLOR_RESET);
    while(getchar() != '\n'){};
}
