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
  int visible; // 0 pour invisible et 1 pour visible
};

struct Grille {
  struct Difficulte diff;
  struct Case plateau[MAX_CASE]; 
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

struct Partie deminer_case(struct Partie partie);

// incrémenter le score
// int deminer(struct Case c);

int commencer_partie(struct Partie partie);


#endif