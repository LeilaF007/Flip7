#include "affichage.h"
#include <stdio.h>

void afficher_nom_carte(int carte) {
    if (carte == 13) printf("%sx2%s", COLOR_YELLOW, COLOR_RESET);
    else if (carte == 14) printf("%s+2%s", COLOR_YELLOW, COLOR_RESET);
    else if (carte == 15) printf("%s+4%s", COLOR_YELLOW, COLOR_RESET);
    else if (carte == 16) printf("%s+6%s", COLOR_YELLOW, COLOR_RESET);
    else if (carte == 17) printf("%s+8%s", COLOR_YELLOW, COLOR_RESET);
    else if (carte == 18) printf("%s+10%s", COLOR_YELLOW, COLOR_RESET);
    else printf("%s%d%s", COLOR_BLUE, carte, COLOR_RESET); 
}

void afficher_plateau(Joueur *j, Pioche *p) {
    printf("\n%s==========================================%s\n", COLOR_CYAN, COLOR_RESET);
    printf("  JOUEUR : %s%s%s | SCORE TOTAL : %s%d%s | SCORE MANCHE : %s%d%s\n", 
            COLOR_YELLOW, j->nom, COLOR_RESET, COLOR_GREEN, j->scoreTotal, COLOR_RESET, COLOR_RED, j->scoreManche, COLOR_RESET);
    
    printf("  VOTRE MAIN : ");
    int vide = 1;
    for (int i = 0; i <= 18; i++) {
        if (j->cartesMain[i] > 0) {
            printf("[");
            afficher_nom_carte(i);
            printf("] ");
            vide = 0;
        }
    }
    if(vide) {
    printf("(vide)");
    }

    printf("\n  PIOCHE : [");
    int progression = (p->indexProchaine * 20) / TAILLE_PIOCHE;
    for (int i = 0; i < 20; i++) {
        if (i < progression) printf("#");
        else printf(".");
    }
    printf("] (%d/%d cartes tirees)\n", p->indexProchaine, TAILLE_PIOCHE);
    printf("%s==========================================%s\n", COLOR_CYAN, COLOR_RESET);
}

void effacer_terminal() {
    printf("\033[H\033[J");
}

void attendre_entree() {
    printf("\n%sAppuyez sur [ENTREE] pour continuer...%s", COLOR_CYAN, COLOR_RESET);
    while (getchar() != '\n'); 
    getchar(); 
}