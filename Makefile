CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude

# 1. OS and terminal type detection
ifeq ($(OS),Windows_NT)
    EXEC = jeu.exe
    # Specific detection for Git Bash / MSYS64
    ifdef MSYSTEM
        MKDIR = mkdir -p obj
        RMDIR = rm -rf obj
        RM = rm -f
    else
        # Standard PowerShell / CMD detection
        MKDIR = if not exist obj mkdir obj
        RMDIR = rmdir /s /q obj
        RM = del /q
    endif
else
    # Pure Linux / Mac
    EXEC = jeu
    MKDIR = mkdir -p obj
    RMDIR = rm -rf obj
    RM = rm -f
endif

# 2. List of compiled files
OBJ = obj/main.o obj/pioche.o obj/mecanique.o obj/affichage.o obj/joueur.o obj/fichier.o

# 3. Executable creation
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# 4. Compilation of .c files
obj/%.o: src/%.c
	@$(MKDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# 5. Exact dependencies
obj/main.o: src/main.c include/pioche.h include/mecanique.h include/affichage.h include/joueur.h include/fichier.h
obj/pioche.o: src/pioche.c include/pioche.h
obj/mecanique.o: src/mecanique.c include/mecanique.h include/joueur.h include/pioche.h
obj/affichage.o: src/affichage.c include/affichage.h include/joueur.h include/pioche.h include/mecanique.h
obj/joueur.o: src/joueur.c include/joueur.h
obj/fichier.o: src/fichier.c include/fichier.h include/joueur.h

# 6. Clean rules
clean:
	-@$(RMDIR)
	-@$(RM) $(EXEC)
