# FlipTech - MI2 A

## Présentation du jeu

**FlipTech** est un jeu de cartes où le joueur pioche des cartes pour accumuler un maximum de points. Cependant, chaque tirage comporte des risques :

* **Les Doublons :** Si le joueur pioche **deux fois la même carte normale (de 0 à 12)**, il perd instantanément tous les points accumulés durant la manche actuelle et son tour s'arrête.
* **Le FLIP 7 :** Si un joueur réussit d'obtenir **7 cartes différentes (de 0 à 12)**, il réalise un **Flip7** et met fin à la manche avec succès et empoche un **bonus de +15 points**.
* **Les Cartes Bonus :** Le jeu intègre également **6 cartes spéciales** (`x2`, `+2`, `+4`, `+6`, `+8`, `+10`) qui n'appliquent pas la règle des doublons et permettent d'augmenter le score.

---

## Compilation et Lancement

### 1. Naviguer vers le projet
Ouvrez votre terminal et déplacez-vous dans le dossier du projet :
```bash
cd chemin/FlipTech
```

### 2. Compiler le projet
Le projet intègre un système de détection automatique de votre système d'exploitation. 
* Sous **Linux / Mac**, tapez simplement :  
  ```bash
  make
  ```
* Sous **Windows**, tapez :  
  ```bash
  mingw32-make
  ```
*(Cette commande va automatiquement créer le dossier `obj/`, compiler tous les fichiers `.c` et générer l'exécutable).*

### 3. Lancer le jeu
Une fois la compilation terminée avec succès :
* **Sous Linux / Mac :**
```bash
  ./jeu
  ```
* **Sous Windows :**
```bash
  ./jeu.exe
  ```

### 4. Nettoyer les fichiers temporaires
Pour supprimer proprement les fichiers objets `.o` générés ainsi que l'exécutable :
* Sous **Linux / Mac** : `make clean`
* Sous **Windows** : `mingw32-make clean`

---

## Commandes et Interface du Jeu

Pendant son tour de jeu, le joueur fait face à un choix binaire :
* **`1`** -> Piocher une carte.
* **`0`** -> Arrêter la manche.

À chaque étape l'interface du terminal affiche :
* Le score total.
* Le score temporaire de la manche actuelle.
* La main du joueur sous forme de cartes en ASCII.
* La jauge et la progression de la pioche.

---

## Les Règles de Jeu

* **Cartes Normales (0 à 12) :** Ajoutent directement leur valeur nominale au score de la manche en cours.
* **Cartes Bonus (13 à 18) :**
  * **13** ➔ Multiplicateur `x2` sur le score de la manche.
  * **14** ➔ Bonus de `+2` points.
  * **15** ➔ Bonus de `+4` points.
  * **16** ➔ Bonus de `+6` points.
  * **17** ➔ Bonus de `+8` points.
  * **18** ➔ Bonus de `+10` points.
* **Fin de manche par Doublon :** Arrêt immédiat de la manche, le score de la manche tombe à `0`.
* **Fin de manche par FLIP 7 :** Arrêt immédiat de la manche, encaissement des points + bonus de `+15`.

---

## Organisation du Projet

L'architecture des dossiers respecte les conventions de développement en C :

```text
FlipTech/
├── include/           # Contient tous les fichiers (.h)
│   ├── affichage.h
│   ├── fichier.h
│   ├── joueur.h
│   ├── mecanique.h
│   └── pioche.h
├── src/               # Contient tous les fichiers (.c)
│   ├── main.c         # Programme principale
│   ├── pioche.c       # Gestion de la pioche
│   ├── mecanique.c    # Déroulement du jeu
│   ├── affichage.c    # Dessin ASCII et couleurs de la console
│   ├── joueur.c       # Structures des joueurs
│   └── fichier.c      # Sauvegarde des scores (.txt)
├── obj/               # Fichiers d'objets intermédiaires (Généré automatiquement)
└── Makefile           # Script de configuration multiplateforme (Windows / Linux)
```

---

## Prérequis & Dépendances

* **Compilateur :** GCC
* **Outil de build :** Make (`make` ou `mingw32-make`)
* **Environnement :** Un terminal prenant en charge les codes de couleurs ANSI.
