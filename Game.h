#ifndef _GAME_
#define _GAME_

// Constantes pour la grille
#define MAX_CHAR 10
#define DIFF_EASY 1
#define DIFF_MID 2
#define DIFF_HARD 3
#define POURCENT 100

// Constantes pour le jeu
#define MAX_TAILLE 6
#define MAX_CASE 36
#define MAX_NOM_BONUS 30
#define MAX_EFFET_BONUS 60
#define NB_TYPES_BONUS 3



enum CaseType {
  VIDE,
  BOMBE,
  PROCHE,
  BONUS,
};

enum Statut {
  INDETERMINE,
  DEFAITE,
  VICTOIRE
};

enum ActionBonus {
  AFFICHE_BOMBE,
  AFFICHE_CASE,
  BOUCLIER,
};

struct Bonus {
  char nom[MAX_NOM_BONUS];
  char effet[MAX_EFFET_BONUS];
  enum ActionBonus action;
};

struct Difficulte {
  int taille;
  char niveau[MAX_CHAR + 1]; // facile moyen difficile
  int nb_bombe;
  int nb_bonus;
  int esquive; // Niveau d'esquive en % 
};

struct Case {
  int x;
  int y;
  enum CaseType val;
  int index_bonus;
  int visible; // 0 pour invisible et 1 pour visible
};

struct Grille {
  struct Difficulte diff;
  struct Case plateau[MAX_CASE];
};

struct Partie {
  int score;
  int bonus_trouve;
  struct Grille grille;
  int terminer;
  enum Statut stat;
};

struct Bonus BONUS_DISPONIBLES[NB_TYPES_BONUS];

// Initialisation de la difficulté
struct Difficulte initialiser_difficulte();

struct Grille initialiser_cases(struct Grille grille);

// Initialisation de la grille
struct Grille initialiser_grille();

struct Grille generer_bombes(struct Grille grille);

struct Grille generer_bonus(struct Grille grille);

struct Case coordonnee_case(int taille);

int rechercher_case(struct Grille grille, struct Case c);

struct Grille reveler_bombe(struct Grille grille);

struct Grille reveler_case_sure(struct Grille grille);

struct Grille activer_bonus(struct Partie partie, struct Bonus bonus);

struct Partie action_case(struct Partie partie, int position);

struct Partie deminer_case(struct Partie partie);

struct Grille detecter_bombe_proche(struct Grille grille, int position);

void commencer_partie();

#endif