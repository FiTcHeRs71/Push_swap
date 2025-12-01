# 🔄 Push_swap

> Projet 42 - Algorithme de tri avec un ensemble limité d'instructions


## 📋 Table des matières

- [À propos](#-à-propos)
- [Règles du jeu](#-règles-du-jeu)
- [Algorithme](#-algorithme)
- [Installation](#-installation)
- [Utilisation](#-utilisation)
- [Bonus - Checker](#-bonus---checker)
- [Performances](#-performances)
- [Structure du projet](#-structure-du-projet)

## 📖 À propos

**Push_swap** est un projet de l'école 42 qui consiste à trier une pile de nombres entiers en utilisant un ensemble limité d'opérations, tout en minimisant le nombre d'actions effectuées.

Le défi : trier des données avec seulement deux piles (A et B) et 11 opérations possibles.

## 🎮 Règles du jeu

### Les piles

- **Pile A** : Contient initialement les nombres à trier
- **Pile B** : Vide au départ, utilisée comme espace de travail temporaire

### Les opérations disponibles

| Opération | Description |
|-----------|-------------|
| `sa` | Swap A - Échange les 2 premiers éléments de la pile A |
| `sb` | Swap B - Échange les 2 premiers éléments de la pile B |
| `ss` | Swap A et B simultanément |
| `pa` | Push A - Déplace le premier élément de B vers A |
| `pb` | Push B - Déplace le premier élément de A vers B |
| `ra` | Rotate A - Décale tous les éléments de A vers le haut |
| `rb` | Rotate B - Décale tous les éléments de B vers le haut |
| `rr` | Rotate A et B simultanément |
| `rra` | Reverse Rotate A - Décale tous les éléments de A vers le bas |
| `rrb` | Reverse Rotate B - Décale tous les éléments de B vers le bas |
| `rrr` | Reverse Rotate A et B simultanément |

## 🧠 Algorithme

### Vue d'ensemble

L'implémentation utilise un **algorithme de tri par chunks** inspiré du quicksort, avec plusieurs optimisations :

### 1. Normalisation des données (Ranking)

Les valeurs d'entrée sont converties en rangs (1 à N) pour simplifier les comparaisons :
```
Entrée:  [42, -5, 100, 0]
Rangs:   [3,   1,   4,  2]
```

### 2. Cas particuliers optimisés

- **3 éléments** : Tri direct avec maximum 2 opérations
- **5 éléments** : Pousse les 2 plus petits vers B, trie 3, puis récupère

### 3. Tri par chunks (cas général)

L'algorithme divise récursivement la pile en 3 parties :
- **High** : Les plus grandes valeurs (1/3 supérieur)
- **Mid** : Les valeurs moyennes
- **Low** : Les plus petites valeurs (1/3 inférieur)

```
┌─────────────────────────────────────────┐
│           SPLIT CHUNK                   │
│                                         │
│   TOP_A ──► High → BOT_A                │
│           │ Mid  → TOP_B                │
│           └ Low  → BOT_B                │
│                                         │
│   Puis récursion sur chaque partie      │
└─────────────────────────────────────────┘
```

### 4. Structure de pile circulaire

Les piles sont implémentées comme des tableaux circulaires avec pointeurs `top` et `bot`, permettant des opérations O(1) pour rotate et reverse_rotate.

### 5. Optimisations Quick Sort

Pendant le tri, l'algorithme vérifie si des éléments peuvent être placés directement à leur position finale, réduisant ainsi le nombre d'opérations.

## 🔧 Installation

```bash
# Cloner le repository
git clone https://github.com/votre-username/push_swap.git

# Se déplacer dans le dossier
cd push_swap

# Compiler le projet
make

# Compiler avec le bonus (checker)
make bonus
```

## 🚀 Utilisation

### Programme principal

```bash
# Avec des arguments séparés
./push_swap 4 67 3 87 23

# Avec une chaîne de caractères
./push_swap "4 67 3 87 23"

# Avec des nombres générés aléatoirement
ARG=$(shuf -i 1-100 | tr '\n' ' '); ./push_swap $ARG

# Compter le nombre d'opérations
./push_swap 4 67 3 87 23 | wc -l
```

### Vérification avec checker

```bash
# Vérifier si le tri est correct
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
# Résultat attendu : OK

# Test interactif
./checker 3 2 1
sa
rra
# Ctrl+D pour terminer
```

### Exemples de sortie

```bash
$ ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
ra
pa
pa
pa
```

## 🎁 Bonus - Checker

Le programme `checker` permet de vérifier si une séquence d'instructions trie correctement la pile.

### Fonctionnement

1. Lit les instructions depuis l'entrée standard
2. Exécute chaque instruction sur les piles
3. Affiche `OK` si la pile A est triée et B est vide
4. Affiche `KO` sinon
5. Affiche `Error` en cas d'instruction invalide

### Instructions reconnues

```
sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr
```

## 📊 Performances

### Objectifs de l'école 42

| Taille | Maximum pour note max | Mon implémentation |
|--------|----------------------|-------------------|
| 3      | 3 opérations        | ≤ 2               |
| 5      | 12 opérations       | ≤ 8               |
| 100    | 700 opérations      | ~550 en moyenne   |
| 500    | 5500 opérations     | ~4500 en moyenne  |

### Script de test

```bash
# Lancer les tests de performance
chmod +x test.sh
./test.sh
```

## 📁 Structure du projet

```
push_swap/
├── Makefile
├── include/
│   ├── push_swap.h          # Header principal
│   ├── stack.h              # Structures de données
│   ├── operations.h         # Prototypes des opérations
│   └── checker_bonus.h      # Header du checker
├── srcs/
│   ├── main.c               # Point d'entrée
│   ├── ft_parsing.c         # Parsing des arguments
│   ├── input_validation.c   # Validation des entrées
│   ├── stack_initz.c        # Initialisation des piles
│   ├── ft_execute.c         # Orchestration du tri
│   ├── sort_chunk.c         # Tri par chunks
│   ├── chunk_split.c        # Division des chunks
│   ├── chunk_utils.c        # Utilitaires chunks
│   ├── sort_three.c         # Tri de 3 éléments
│   ├── sort_optimize.c      # Optimisations
│   ├── split_utils.c        # Utilitaires de division
│   ├── change_stack.c       # Mouvements entre piles
│   ├── swap_op.c            # Opérations swap
│   ├── push_op.c            # Opérations push
│   ├── rotate_op.c          # Opérations rotate
│   ├── reverse_rotate_op.c  # Opérations reverse rotate
│   ├── op_utils.c           # Utilitaires opérations
│   ├── error.c              # Gestion des erreurs
│   └── print_stack.c        # Debug (affichage pile)
├── checker_bonus/
│   ├── checker_bonus.c      # Main du checker
│   └── checker_utils_bonus.c # Exécution des instructions
├── libft/                   # Bibliothèque personnelle
└── test.sh                  # Script de tests
```

## 🏗️ Structures de données

### t_stack - Pile circulaire
```c
typedef struct s_stack
{
    int    *array;    // Tableau des valeurs
    int    size;      // Taille totale allouée
    int    top;       // Index du sommet
    int    bot;       // Index du fond
}    t_stack;
```

### t_build - Données globales
```c
typedef struct s_build
{
    t_stack    a;      // Pile A
    t_stack    b;      // Pile B
    int        flag;   // Flag pour push_swap vs checker
}    t_build;
```

### t_chunck - Définition d'un chunk
```c
typedef struct s_chunck
{
    t_loc    loc;     // Position (TOP_A, BOT_A, TOP_B, BOT_B)
    int      size;    // Nombre d'éléments
}    t_chunck;
```

## 📝 Commandes Makefile

| Commande | Description |
|----------|-------------|
| `make` | Compile le programme push_swap |
| `make bonus` | Compile le checker |
| `make clean` | Supprime les fichiers objets |
| `make fclean` | Supprime les fichiers objets et les exécutables |
| `make re` | Recompile tout le projet |

## ⚠️ Gestion des erreurs

Le programme affiche `Error` sur stderr dans les cas suivants :
- Argument non numérique
- Nombre en dehors de la plage des int
- Nombres en double
- Argument vide

## 👤 Auteur

**fducrot** - École 42 Lausanne

---

*Projet réalisé dans le cadre du cursus de l'école 42*
