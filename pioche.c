#include "pioche.h"

void initialiser_pioche(Pioche *tab){
    int i=1, j=1, l=0, cmp=1;
    tab->cartes[0] = 0;
    while(cmp<13){ // normal cards range from 0 to 12
        if(i>78){ //We fill in 79 boxes, the rest are for bonus cards
            break;
        } 
        j = cmp;
        l=0;
        while(l<j){ //If cmp = 3, then we put 3 cards with the number 3 in our array
            tab->cartes[i] = cmp;
            i++; //we are making progress in our array
            l++;
        }
        cmp++; //cmp is incremented at each iteration
    }
    i=79;
    j=13;
    while(i<85){
        tab->cartes[i] = j;
        j++; //the bonus cards have values ​​of 13,14,15,16,17,18
        i++;
    }
    tab->prochain_indice = 0;
    }

void melange_pioche(Pioche *tab){
    int i, nb1=0, nb2=0, tmp=0;
    for(i=0; i<TAILLE_PIOCHE; i++){
        do{
            nb1 = rand()%85;
            nb2 = rand()%85;
            }while(nb1==nb2);
        tmp = tab->cartes[nb1];
        tab->cartes[nb1] = tab->cartes[nb2];
        tab->cartes[nb2] = tmp; //we change the positions of the numbers stored in the array
        }
    for(i=0; i<TAILLE_PIOCHE; i++){
        printf("%d\n", tab[i]);
    }
}

int tirer_carte(Pioche *tab){
    if(tab->prochain_indice >= TAILLE_PIOCHE){
        return -1;
    }
    else{
        int carte = tab->cartes[tab->prochain_indice];
        tab->prochain_indice++; //When you draw a card, you advance in the tableau
        return carte;} //the card drawn
}