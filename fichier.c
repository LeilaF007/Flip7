#include "fichier.h"
#include <string.h>

int taille_chaine(char tab[]){
    int taille=0;
    for(int i=0; tab[i]!='\0'; i++){
        taille++;
    }
    return taille;
}

int verif_carac(char tab[]){
    int valeur=0;
    for(int i=0; tab[i]!='.'; i++){
        char c = tab[i];
        if((c == '/')||(c == '\\')||(c == ':')||(c == '*')||(c == '?')||
        (c == '"')||(c == '<')||(c == '>')||
        (c == '|')||(c == ' ')){
            valeur = 1;
        }
    }
    return valeur;
}

void fichier_score(Joueur *j, int nbj){
    FILE* fichier = NULL;
    char nom[MAX_NOM];
    int size=0;
    do{
        printf("Quel nom voulez-vous donné au fichier ? (au minimum commencer avec une lettre et finir avec .txt) \n");
        scanf("%s", nom);
        size = taille_chaine(nom);
        }while((size<5)||(verif_carac(nom)==0)||(nom[size - 4]!='.')||(nom[size-3]!='t')||(nom[size-2]!='x')||(nom[size-1]!='t'));
	fichier = fopen(nom, "w+"); 
	if(fichier == NULL){
		printf("Ouverture du fichier impossible\n");
		exit(1);
	}
    for(int i =0; i<nbj; i++){
        fprintf(fichier, "%s %d\n", j[i].nom, j[i].scoreTotal);
    }
    fclose(fichier);
}