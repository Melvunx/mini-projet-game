#ifndef _GAME_
#define _GAME_

// Constantes pour la grille
#define MAX_CHAR 10
#define DIFF_EASY 1
#define DIFF_MID 2
#define DIFF_HARD 3

// Constantes pour le jeu
#define MAX_TAILLE 6
#define MAX_CASE 36
#define BOMBE -2
#define PROCHE -1 // Case a proximité d'une bombe
#define VIDE 0
#define BONUS 1

struct Difficulte {
  int taille;
  char niveau[MAX_CHAR + 1]; // facile moyen difficile
  int nb_bombe; 
  int esquive; // Niveau d'esquive en % 
};

struct Case {
  int x;
  int y;
  int val;
};

struct Grille {
  struct Difficulte diff;
  struct Case visible[MAX_CASE]; // Case visible par le joueur (1) case invisible pour le joueur (0)
  struct Case drapeaux[MAX_CASE]; // Drapeaux posés par le joueur
};

struct Partie {
  int score;
  struct Grille grille;
  int terminer;
};

// Initialisation de la difficulté
struct Difficulte initialiser_difficulte();

struct Grille initialiser_cases(struct Grille grille);

// Initialisation de la grille
struct Grille initialiser_grille();

struct Grille generer_bombe(struct Grille grille);

// struct Grille generer_bonus(struct Grille grille);

struct Case coordonnee_case(int taille);

struct Partie deminer_case(struct Grille grille, struct Case c);

// incrémenter le score
// int deminer(struct Case c);

void commencer_partie(struct Partie partie);


#endif