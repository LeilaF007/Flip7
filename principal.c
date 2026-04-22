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

int *pioche(int *tab){
    int i, j, nb1 = 0, nb2 = 0, tmp = 0;
    for(i=0; i<SIZE; i++){
        tab[i] = i+1; //an array with numbers from 1 to 85 in ascending order
        }
    for(i=0; i<SIZE; i++){
        do{
            nb1 = rand()%85 +1;
            nb2 = rand()%85 +1;
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

int main(){
    srand(time(NULL));
    int *pioche_carte = malloc(SIZE*sizeof(int));
    if(pioche == NULL){
        printf("Erreur d'allocation");
    }
    pioche(pioche_carte);
    return 0;
}