#ifndef _AFFICHAGE_
#define _AFFICHAGE_
#include "Game.h"

// Affichage bonus
#define DETECTEUR 0
#define CASE_SUR 1
#define ESQUIVE 2


// Messages de déminage
#define MAX_MESSAGE 5
#define TAILLE_MESSAGE 60
char cases_vide[MAX_MESSAGE][TAILLE_MESSAGE];

char cases_bombe[MAX_MESSAGE][TAILLE_MESSAGE];

char cases_proche[MAX_MESSAGE][TAILLE_MESSAGE];

char cases_bonus[MAX_MESSAGE][TAILLE_MESSAGE];


// Explication
void explication_jeu();


// Affichage du jeux
void afficher_grille(struct Grille grille);

void afficher_difficulte(struct Difficulte diff);

void afficher_recap(struct Partie partie);

void afficher_val_cases(struct Case c);

void afficher_case(struct Case c);

void afficher_all_case(struct Grille grille);

void afficher_score(struct Partie partie);

void afficher_bombes(struct Grille grille);

void fin_partie(struct Partie partie);


// Statistique
void recapitulatif_partie(struct Partie partie);

#endif