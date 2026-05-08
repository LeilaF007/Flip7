#include<stdio.h>
#include<stdlib.h>
#include "affichage.h"

void afficher_nom_carte(int carte){
    if(carte >= 13){
        printf(YELLOW);
    }
    else{
        printf(BLUE);
    }
    printf("--------\n");
    if(carte == 13){
        printf("|  x2  |\n");}
    else if(carte == 14){
        printf("|  +2  |\n");}
    else if(carte == 15){
        printf("|  +4  |\n");}
    else if(carte == 16){
        printf("|  +6  |\n");}
    else if(carte == 17){
        printf("|  +8  |\n");}
    else if(carte == 18){
        printf("| +10  |\n");}
    else{
        if(carte>9){ //pour que les bords de la carte soit bien alignés
            printf("|  %d  |\n", carte);
        }
        else{
            printf("|   %d  |\n", carte);
        }
    }
    printf("--------\n");
    printf(COLOR_RESET);
}

void afficher_plateau(Joueur *j, Pioche *p){
    int vide = 1;
    printf("\n");
    printf("%s--------------------------------------------------------%s\n", CYAN, COLOR_RESET);
    printf("  JOUEUR : %s%s%s | SCORE TOTAL : %s%d%s | SCORE MANCHE : %s%d%s\n", 
    YELLOW, j->nom, COLOR_RESET, GREEN, j->scoreTotal, COLOR_RESET, RED, j->scoreManche, COLOR_RESET);
    printf("  VOTRE MAIN : \n");
    for(int i=0;i <= 18; i++){
        if(j->cartesMain[i]>0){
            afficher_nom_carte(i);
            vide = 0;
        }
    }
    if(vide==1){
        printf("  (vide)");
    }
    printf("\n");
    printf("  PIOCHE : [");
    int progression = (p->prochain_indice * 40)/TAILLE_PIOCHE; //echelle pour la pioche
    for(int i=0; i<40; i++){
        if(i<progression){
            printf("X");}
        else{
            printf(".");}
    }
    printf("] (%d/%d cartes tirées)\n", p->prochain_indice, TAILLE_PIOCHE);
    printf("%s--------------------------------------------------------%s\n", CYAN, COLOR_RESET);
}

void attendre_entree(){
    printf("\n");
    printf("%sAppuyez sur ENTREE pour continuer%s\n", CYAN, COLOR_RESET);
    while(getchar() != '\n'){}
}