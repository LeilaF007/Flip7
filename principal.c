#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 85

typedef struct{
    char nom[SIZE];
    int carte[SIZE];
    int id;
    int score;
        }Joueur;

Joueur *connexion(){
    int nbj;
    printf("Veuillez saisir le nombre de joueurs\n");
    do{
        scanf("%d", &nbj);
            }while(nbj<2);
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

int *pioche(int *tab){
    int i=1, j=1, l=0, nb1 = 0, nb2 = 0, tmp = 0, cmp=1;
    tab[0] = 0;
    while(cmp<13){ // normal cards range from 0 to 12
        if(i>78){
            break;
        } //We fill in 79 boxes, the rest are for bonus cards
        j = cmp;
        l=0;
        while(l<j){ //If cmp = 3, then we put 3 cards with the number 3 in our array
            tab[i] = cmp;
            i++; //we are making progress in our array
            l++;
        }
        cmp++; //cmp is incremented at each iteration
    }
    i=79;
    j=13;
    while(i<85){
        tab[i] = j;
        j++; //the bonus cards have values ​​of 13,14,15,16,17,18
        i++;
    }
    for(i=0; i<SIZE; i++){
        do{
            nb1 = rand()%85;
            nb2 = rand()%85;
        }while(nb1==nb2);
        tmp = tab[nb1];
        tab[nb1] = tab[nb2];
        tab[nb2] = tmp; //we change the positions of the numbers stored in the array
    }
    for(i=0; i<SIZE; i++){
        printf("%d\n", tab[i]);
    }
    return tab;        
    }

int tirer_carte(int *tab, int *indice_act){
    int carte = tab[*indice_act];
    (*indice_act)++; //When you draw a card, you advance in the tableau
    return carte; //the card drawn
}



void jeu(){

}

int main(){
    srand(time(NULL));
    Joueur *partie = NULL;
    partie = connexion();
    int *pioche_carte = malloc(SIZE*sizeof(int));
    int *indice_pioche = malloc(sizeof(int));
    if(pioche == NULL){
        printf("Erreur d'allocation 2");
    }
    if(indice_pioche == NULL){
        printf("Erreur d'allocation 3");
    }
    pioche(pioche_carte);
    *indice_pioche = 0;
    int c = tirer_carte(pioche_carte, indice_pioche);
    free(partie);
    free(pioche_carte);
    free(indice_pioche);
    return 0;
}