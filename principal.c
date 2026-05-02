#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "pioche.h"
#define COLOR_RESET  "\033[0m"
#define COLOR_RED    "\033[1;31m"
#define COLOR_GREEN  "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_BLUE   "\033[1;34m"
#define COLOR_CYAN   "\033[1;36m"
#define SIZE 85

typedef struct{
    char nom[SIZE];
    int carte[SIZE];
    int id;
    int score;
        }Joueur;

Joueur *connexion(int nbj){
    Joueur *j = malloc(nbj*sizeof(Joueur));
    if(j == NULL){
        printf("Erreur d'allocation 1");
    }
    for(int i=0; i<nbj; i++){
        printf("Veuillez choisir votre nom:\n");
        scanf("%s", j[i].nom);
        j[i].id = i+1;
        j->score = 0;
    }
    return j;
}


int gains(Joueur j, int carte){
    if(carte == 13){
        j.score *= 2;
    }
    else if(carte == 14){
        j.score += 2;
    }
    else if(carte == 15){
        j.score += 4;
    }
    else if(carte == 16){
        j.score += 6;
    }
    else if(carte == 17){
        j.score += 8;
    }
    else if(carte == 18){
        j.score += 10;
    }
    else{
        j.score += carte;
    }
}


void afficher_nom_carte(int carte) {
    if (carte == 13) printf("%sx2%s", COLOR_YELLOW, COLOR_RESET);
    else if (carte == 14) printf("%s+2%s", COLOR_YELLOW, COLOR_RESET);
    else if (carte == 15) printf("%s+4%s", COLOR_YELLOW, COLOR_RESET);
    else if (carte == 16) printf("%s+6%s", COLOR_YELLOW, COLOR_RESET);
    else if (carte == 17) printf("%s+8%s", COLOR_YELLOW, COLOR_RESET);
    else if (carte == 18) printf("%s+10%s", COLOR_YELLOW, COLOR_RESET);
    else printf("%s%d%s", COLOR_BLUE, carte, COLOR_RESET); 
}

void fichier_score(Joueur *tab, int *nbj){
    char nom[SIZE];
    printf("Veuillez saisir un nom de fichier :\n");
    scanf("%s", nom);
    FILE *f = fopen(nom, "w");
    if(f == NULL){
        printf("Ouverture impossible\n");
        exit(4);
    }
    for(int i=0; i<(*nbj); i++){
        fprintf(f, "Nom du joueur : %s  son score final : %d\n", tab[i].nom, tab[i].score);
    }
    fclose(f);
    

}

int main(){
    srand(time(NULL));
    Joueur *partie = NULL;
    int nbj =0;
    printf("Veuillez saisir un nombre de joueurs supérieur à 1\n");
    do{
        scanf("%d", &nbj);
            }while(nbj<2);
    partie = connexion(nbj);
    Pioche *pioche_carte = malloc(SIZE*sizeof(int));
    if(pioche_carte == NULL){
        printf("Erreur d'allocation 2");
    }
    initialiser_pioche(pioche_carte); //pour avoir la pioche
    free(partie);
    free(pioche_carte);
    return 0;
}