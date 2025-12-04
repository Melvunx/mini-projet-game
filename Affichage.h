#ifndef _AFFICHAGE_
#define _AFFICHAGE_
#include "Game.h"

void afficher_grille(struct Grille grille);

void afficher_difficulte(struct Difficulte diff);

void fin_partie(struct Partie partie);

void afficher_recap(struct Partie partie);

void afficher_val_cases(int val);

void afficher_case(struct Case c);

void afficher_all_case(struct Grille grille);


#endif