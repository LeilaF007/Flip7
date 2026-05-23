CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude

ifeq ($(OS),Windows_NT)
    MKDIR = if not exist obj mkdir obj
    RMDIR = rmdir /s /q obj
    RM = del /q
    EXEC = jeu.exe
else
    MKDIR = mkdir -p obj
    RMDIR = rm -rf obj
    RM = rm -f
    EXEC = jeu
endif

OBJ = obj/main.o obj/pioche.o obj/mecanique.o obj/affichage.o obj/joueur.o obj/fichier.o

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

obj/%.o: src/%.c
	@$(MKDIR)
	$(CC) $(CFLAGS) -c $< -o $@

obj/main.o: src/main.c include/pioche.h include/mecanique.h include/affichage.h include/joueur.h include/fichier.h
obj/pioche.o: src/pioche.c include/pioche.h
obj/mecanique.o: src/mecanique.c include/mecanique.h include/joueur.h include/pioche.h
obj/affichage.o: src/affichage.c include/affichage.h include/joueur.h include/pioche.h include/mecanique.h
obj/joueur.o: src/joueur.c include/joueur.h
obj/fichier.o: src/fichier.c include/fichier.h include/joueur.h

clean:
	-@$(RMDIR)
	-@$(RM) $(EXEC)
