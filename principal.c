#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "joueur.h"
#include "pioche.h"
#include "mecanique.h"
#include "fichier.h"


int main(){
    srand(time(NULL));
    int *nbj= malloc(sizeof(int));
    if(nbj == NULL){
        printf("Erreur d'allocation dynamique\n");
        exit(2);
    }
    *nbj = 0;
    int partieEnCours = 1;
    int val=0;
    Joueur *tabJoueurs = connexion(nbj);
    Pioche deck;
    initialiser_pioche(&deck);
    melange_pioche(&deck); 
    while(partieEnCours==1){
        printf("\n---------- NOUVELLE MANCHE ----------\n");
        for(int i = 0; i<(*nbj); i++){
            init_joueur_manche(&tabJoueurs[i]);
            jouer_tour(&tabJoueurs[i], &deck);

            tabJoueurs[i].scoreTotal += tabJoueurs[i].scoreManche;
            printf("Fin du tour, score total de %s : %d\n", tabJoueurs[i].nom, tabJoueurs[i].scoreTotal);

            if(tabJoueurs[i].scoreTotal >= 200){
                printf("\n");
                printf("!!! %s A ATTEINT 200 POINTS ET GAGNE LA PARTIE !!!\n", tabJoueurs[i].nom);
                partieEnCours = 0;
                break;
            }
            if(deck.prochain_indice >= TAILLE_PIOCHE){
                printf("\n");
                printf("--- PLUS DE CARTES DANS LA PIOCHE ---\n");
                printf("---       FIN DE LA PARTIE        ---\n");
                partieEnCours = 0;
                break;
            }
        }
    }
    printf("\n");
    printf("---       CLASSEMENT FINAL        ---\n");
    for(int i = 0; i<(*nbj); i++){
        printf("%d. %s : %d points\n", i + 1, tabJoueurs[i].nom, tabJoueurs[i].scoreTotal);
    }
    printf("Voulez-vous créez un fichier avec le score et le pseudo de chaque joueurs ?\n");
    printf("Oui : 1 Non : 0\n");
    do{
        scanf("%d", &val);
    }while((val!=1) && (val!=0));
    if(val ==1){
        fichier_score(tabJoueurs, (*nbj));
    }
    free(tabJoueurs);
    printf("\n");
    printf("Merci d'avoir joue a FlipTek !\n");
    return 0;
}