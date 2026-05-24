#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "joueur.h"
#include "pioche.h"
#include "mecanique.h"
#include "fichier.h"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <locale.h>
#endif

void init_console() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#else
    setlocale(LC_ALL, "");
#endif
}

int main(){
    init_console();
    srand(time(NULL));
    int nbj = 0, i=0;
    int partieEnCours = 1;
    int val = 0;
    int choixPioche = 0; //whether you want a classic or special pickaxe
    Joueur *tabJoueurs = connexion(&nbj); //we register all the players
    Pioche deck; //array pickaxe
    printf("\n");
    printf("---------- CHOIX DE LA PIOCHE ----------\n");
    printf("[1] Pioche classique\n");
    printf("[2] Pioche personnalisee\n");
    do{
        printf("Votre choix : ");
        scanf("%d", &choixPioche);
        while(getchar() != '\n');
        if ((choixPioche!=1) && (choixPioche!=2)) {
            printf("Choix invalide ! Tapez 1 ou 2.\n"); 
        }
    } while((choixPioche != 1) && (choixPioche != 2));
    if(choixPioche == 1){
        initialiser_pioche(&deck); //normal pickaxe
    }
    else{
        piocheSpecial(&deck); //special pickaxe
    }
    melange_pioche(&deck); //we shuffle the pickaxe
    while(partieEnCours == 1){ //as long as the part needs to continue -> main loop
        printf("\n");
        printf("---------- NOUVELLE MANCHE ----------\n");
        for(i=0; i<nbj; i++){
            init_joueur_manche(&tabJoueurs[i]); //all players are initialized (score, hand and game to 0)
            jouer_tour(&tabJoueurs[i], &deck);
            tabJoueurs[i].scoreTotal += tabJoueurs[i].scoreManche;
            printf("\n");
            printf("Fin du tour, score total de %s : %d\n", tabJoueurs[i].nom, tabJoueurs[i].scoreTotal);
            if(tabJoueurs[i].scoreTotal >= 200){ //if the player has more than 200 points
                printf("\n");
                printf("!!! %s A ATTEINT 200 POINTS ET GAGNE LA PARTIE !!!\n",tabJoueurs[i].nom);
                partieEnCours = 0; //we finish the game
                break; //we're leaving the game
            }
            if(deck.prochain_indice >= deck.taille){ //end of the draw pile
                printf("---       FIN DE LA PARTIE         ---\n");
                partieEnCours = 0;
                break;
            }
        }
    }
    printf("\n");
    printf("---       CLASSEMENT FINAL        ---\n");
    for(i=0; i<nbj; i++){
        printf("%d. %s : %d points\n", i+1, tabJoueurs[i].nom, tabJoueurs[i].scoreTotal);
    }
    printf("\n");
    printf("Voulez-vous creer un fichier avec les scores ?\n");
    printf("[1] Oui | [2] Non\n");
    do{
        scanf("%d", &val);
    }while((val != 1) && (val != 2));
    if(val == 1){
        fichier_score(tabJoueurs, nbj);
    }
    printf("\n");
    printf("Merci d'avoir joue a FlipTek !\n");

    //release the memory
    free(tabJoueurs);
    free(deck.cartes);
    return 0;
}