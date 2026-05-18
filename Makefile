CC = gcc
CFLAGS = -Wall -Wextra -g

OBJ = principal.o pioche.o mecanique.o affichage.o joueur.o fichier.o

jeu: $(OBJ)
	$(CC) $(OBJ) -o jeu

principal.o: principal.c pioche.h mecanique.h affichage.h joueur.h fichier.h
pioche.o: pioche.c pioche.h
mecanique.o: mecanique.c mecanique.h joueur.h pioche.h
affichage.o: affichage.c affichage.h joueur.h pioche.h mecanique.h
joueur.o: joueur.c joueur.h
fichier.o: fichier.c fichier.h joueur.h

clean:
	rm -f *.o jeu
