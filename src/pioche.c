#include "pioche.h"

void initialiser_pioche(Pioche *tab){
    int i=1, l=0, cmp=1;
    tab->cartes = malloc(85*sizeof(int));
    if(tab->cartes == NULL){
    	printf("Erreur d'allocation dynamique\n");
        exit(3);
    }   

    tab->cartes[0] = 0; //the card 0
    while(cmp<13){ //normal cards range from 1 to 12
        if(i>78){ //we fill in 79 boxes, the rest are for bonus cards
            break;
        }
        l=0;
        while(l<cmp){ //if cmp = 3, then we put 3 cards with the number 3 in our array
            tab->cartes[i] = cmp;
            i++; //we are making progress in our array
            l++;
        }
        cmp++; //cmp is incremented at each iteration
    }

    i=79;
    while(i<85){
        tab->cartes[i] = cmp;
        cmp++; //the bonus cards have values ​​of 13,14,15,16,17,18
        i++;
    }
    tab->prochain_indice = 0;
    tab->taille =85;
    }

void piocheSpecial(Pioche *tab){
	int indice =0, nbrCarte=0, i=0, nv_taille=0;
    tab->cartes = NULL;
    tab->taille=0;

	for(i=0; i<13; i++){ //we process each card number one by one
    	do{
            printf("Combien de %d voulez vous (saisissez un nombre positif)\n", i);
    		int verif_nbr = scanf("%d", &nbrCarte); //returns 1 if an integer was read correctly
            while(getchar() != '\n'); //buffer clearing -> if there is a \n remove it
            if(verif_nbr != 1){
                nbrCarte = -1; 
            }
            if(nbrCarte<0){
                printf("Saisissez un nombre positif !\n"); 
            }
        }while(nbrCarte<0);

    	nv_taille = tab->taille + nbrCarte;
        if(nbrCarte != 0){
            int *tmp = realloc(tab->cartes, nv_taille*sizeof(int)); 
            //a temporary pointer is used in case of failure tab->cartes still point to the old table
            if(tmp == NULL){
                printf("Erreur d'allocation\n");
                exit(1);
            }
            tab->cartes = tmp; //if it's okay
        }

        for(int j=0; j<nbrCarte; j++){
            tab->cartes[indice] = i;
            indice++;
        }
        tab->taille = nv_taille;
    }
    nv_taille = tab->taille + 6; //bonus
    int *tmp = realloc(tab->cartes, nv_taille*sizeof(int));
    if(tmp == NULL){
        printf("Erreur d'allocation\n");
        exit(2);
    }
    tab->cartes = tmp;
    for(i = 13; i<19; i++){
        tab->cartes[indice] = i;
        indice++;
    }
    tab->taille = nv_taille;
    tab->prochain_indice = 0;
}


void melange_pioche(Pioche *tab){
    int i, nb1=0, nb2=0, tmp=0;
    for(i=0; i<(tab->taille); i++){
        do{
            nb1 = rand()%(tab->taille);
            nb2 = rand()%(tab->taille);
            }while(nb1==nb2); //the two locations must be different in order to switch places
        tmp = tab->cartes[nb1];
        tab->cartes[nb1] = tab->cartes[nb2];
        tab->cartes[nb2] = tmp; //we change the positions of the numbers stored in the array
        }
}

int tirer_carte(Pioche *tab){
    if(tab->prochain_indice >= tab->taille){
        return -1; //if we exceed the array size -> draw ends -> we return -1
    }
    else{
        int carte = tab->cartes[tab->prochain_indice];
        tab->prochain_indice++; //When you draw a card, you advance in the tableau
        return carte;} //the card drawn
}
