#ifndef _AFFICHAGE_
#define _AFFICHAGE_
#include "Game.h"

#define MAX_MESSAGE 5
#define TAILLE_MESSAGE 50


void afficher_grille(struct Grille grille);

void afficher_difficulte(struct Difficulte diff);

void afficher_recap(struct Partie partie);

void afficher_val_cases(struct Case c);

void afficher_case(struct Case c);

void afficher_all_case(struct Grille grille);

void afficher_deminage(int val);

void afficher_score(struct Partie partie);

void afficher_bombes(struct Grille grille);

void fin_partie(struct Partie partie);

#endif