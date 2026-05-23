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
    int choixPioche = 0; //si on veut une pioche classique ou personnalisée
    Joueur *tabJoueurs = connexion(&nbj); // on enregistre tous les joueurs
    Pioche deck; //tableau de la pioche
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
        initialiser_pioche(&deck); //pioche classique
    }
    else{
        piocheSpecial(&deck); //pioche speciale
    }
    melange_pioche(&deck); //on melange la pioche
    while(partieEnCours == 1){ //tant que la partie doit continuer -> boucle principale
        printf("\n");
        printf("---------- NOUVELLE MANCHE ----------\n");
        for(i = 0; i<nbj; i++){
            init_joueur_manche(&tabJoueurs[i]); //on inititialise tous les joueurs (score, main et partie à 0)
            jouer_tour(&tabJoueurs[i], &deck);
            tabJoueurs[i].scoreTotal += tabJoueurs[i].scoreManche; //on incrémente le score total
            printf("\n");
            printf("Fin du tour, score total de %s : %d\n", tabJoueurs[i].nom, tabJoueurs[i].scoreTotal);
            if(tabJoueurs[i].scoreTotal >= 200){ //si le joueur a plus de 200 points
                printf("\n");
                printf("!!! %s A ATTEINT 200 POINTS ET GAGNE LA PARTIE !!!\n",tabJoueurs[i].nom);
                partieEnCours = 0; //on finit la partie
                break; //on sort de la partie
            }

            /* ---------- FIN DE PIOCHE ---------- */

            if(deck.prochain_indice >= deck.taille){
                printf("---       FIN DE LA PARTIE         ---\n");
                partieEnCours = 0;
                break;
            }
        }
    }

    /* ---------- CLASSEMENT ---------- */

    printf("\n");
    printf("---       CLASSEMENT FINAL        ---\n");

    for(int i = 0; i < nbj; i++){

        printf("%d. %s : %d points\n",
        i + 1,
        tabJoueurs[i].nom,
        tabJoueurs[i].scoreTotal);
    }

    /* ---------- SAUVEGARDE ---------- */

    printf("\n");

    printf("Voulez-vous creer un fichier avec les scores ?\n");

    printf("Oui : 1 | Non : 0\n");

    do{

        scanf("%d", &val);

    }while(val != 0 &&
           val != 1);

    if(val == 1){

        fichier_score(tabJoueurs, nbj);
    }

    /* ---------- LIBERATION MEMOIRE ---------- */

    free(tabJoueurs);

    free(deck.cartes);

    printf("\n");

    printf("Merci d'avoir joue a FlipTek !\n");

    return 0;
}