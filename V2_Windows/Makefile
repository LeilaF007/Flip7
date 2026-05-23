CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude

OBJ = obj/main.o obj/pioche.o obj/mecanique.o obj/affichage.o obj/joueur.o obj/fichier.o

jeu: $(OBJ)
	$(CC) $(OBJ) -o jeu

obj/%.o: src/%.c
	@if not exist obj mkdir obj
	$(CC) $(CFLAGS) -c $< -o $@

obj/main.o: src/main.c include/pioche.h include/mecanique.h include/affichage.h include/joueur.h include/fichier.h
obj/pioche.o: src/pioche.c include/pioche.h
obj/mecanique.o: src/mecanique.c include/mecanique.h include/joueur.h include/pioche.h
obj/affichage.o: src/affichage.c include/affichage.h include/joueur.h include/pioche.h include/mecanique.h
obj/joueur.o: src/joueur.c include/joueur.h
obj/fichier.o: src/fichier.c include/fichier.h include/joueur.h

clean:
	@if exist obj rmdir /s /q obj
	@if exist jeu.exe del /q jeu.exe
	@if exist jeu del /q jeu
