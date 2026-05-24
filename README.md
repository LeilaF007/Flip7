Présentation du jeu:

FlipTech consiste en un jeu où le joueur pioche des cartes pour accumuler des points, cependant si celui-ci pioche deux fois la même carte (0 à 12), il perd toute la manche.
Et si il obtient 7 cartes différentes il fait un Flip 7 et gagnes un bonus de +15 points.
Le jeu compte aussi 6 cartes bonus (+2 x2 +6 +10 +8 +4) qui ne comptent pas de doublons.

Compilation:

2)Dans le terminal il faudra se placer dans le dossier du projet : cd chemin/vers/notre/FlipTech

2)Compiler avec "make".
celui-ci va créer le dossier obj/, compiler tous les .c, générer l'éxécutable jeu (ou jeu.exe sous Windows)

3)Lancer le jeu:
	Sous Linux/Mac: ./jeu
	Sous Windows: jeu.exe

4)Pour nettoyer les fichiers compilés.
	Si on veut supprimer les .o et l'exécutable: make clean

Commandes dans le jeu:

-Pendant le tour, le joeur aura 2 choix:
	- 1->piocher une carte
	- 2-> arrêter la manche

-Le jeu affiche:
	- Le score total
	- le score de la manche actuelle
	- la main sous forme de cartes ASCII
	- la progression de la pioche

Les régles de jeu:

-Cartes normales(0 à 12): ajoutent leur valeur au score de manche
-Cartes bonus (13 à 18):
	- 13 -> x2
	- 14 -> +2
	- 15 -> +4
	- 16 -> +6
	- 17 -> +8
	- 18 -> +10	
-Doublons: Si le joueur pioche la même carte entre 0 et 12, il perd tous les points de la manche et celle-ci s'arrête.
 FLIP7: Si le joueur obtient 7 cartes différentes (0 à 12), il gagne +15 points et la manche s'arrête.
-Organisation du Projet:
/src
    main.c
    pioche.c
    mecanique.c
    affichage.c
    joueur.c
    fichier.c

/include
    *.h

/obj
    (généré automatiquement)

/Makefile

-Dépendances: GCC, Make, Un terminal
-Notes: Le jeu utilise des couleurs ANSI, le Makefile utilise automatiquement Windoaws ou Linux
