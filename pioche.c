#include "pioche.h"

void initialiser_pioche(Pioche *tab){
    int i=1, j=1, l=0, cmp=1;
    tab->cartes = malloc(85*sizeof(int));
    if(tab->cartes == NULL){
    	printf("Erreur d'allocation dynamique\n");
        exit(3);
    }
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
    tab->taille =85;
    }

void piocheSpecial(Pioche *tab){
	int indice =0, nbrCarte, i;
    tab->cartes = NULL;
    tab->taille=0;
	for(i =0; i<13; i++){ //on traîte chaque carte numéro un par un
    		do{
                printf("Combien de %d voulez vous (saissiez un nombre positif)\n", i);
    		    scanf("%d", &nbrCarte);}while(nbrCarte<0);
    		tab->taille+=nbrCarte; //la taille du tableau de la pioche augmente en fonction du nombre de carte demandé
            if(nbrCarte!=0){
                int *tmp = realloc(tab->cartes, tab->taille*sizeof(int)); 
    		    if(tmp == NULL){
                    printf("Erreur d'allocation\n");
                    free(tab->cartes);
                    exit(1);
                }
                tab->cartes = tmp;
            }
            for(int j=0; j<nbrCarte; j++){ //on rajoute la carte nbrCarte fois
    			tab->cartes[indice] = i; 
    			indice++; //on avance dans le tableau pour le remplir
    		}
        }
    for(i = 13;i<19; i++){ //pour les cartes bonus
        tab->taille++; //on augmente de 1 la taille du tableau a chaque tour qu'il y a qu'une carte par type de bonus
        int *tmp = realloc(tab->cartes, tab->taille * sizeof(int));
        if(tmp == NULL){
            printf("Erreur d'allocation\n");
            free(tab->cartes);
            exit(2);
        }
        tab->cartes = tmp;
        tab->cartes[indice] = i; //i correspond à la valeur de la carte bonus
        indice++; //on avance dans le tableau pour le remplir
    }
    tab->prochain_indice = 0; //on met l'indice de la pioche à zéro pour pouvoir commencer une nouvelle partie
}


void melange_pioche(Pioche *tab){
    int i, nb1=0, nb2=0, tmp=0;
    for(i=0; i<(tab->taille); i++){
        do{
            nb1 = rand()%(tab->taille);
            nb2 = rand()%(tab->taille);
            }while(nb1==nb2); //il faut que les deux emplacements soit différents pour pouvoir les échanger de place
        tmp = tab->cartes[nb1];
        tab->cartes[nb1] = tab->cartes[nb2];
        tab->cartes[nb2] = tmp; //we change the positions of the numbers stored in the array
        }
}

int tirer_carte(Pioche *tab){
    if(tab->prochain_indice >= tab->taille){
        return -1; //si on dépasse la taille du tableau ->pioche finit
    }
    else{
        int carte = tab->cartes[tab->prochain_indice];
        tab->prochain_indice++; //When you draw a card, you advance in the tableau
        return carte;} //the card drawn
}
