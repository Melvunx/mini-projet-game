#ifndef _GRILLE_
#define _GRILLE_

#include <stdio.h>

// Constantes pour la grille
#define MAX_CHAR 10
#define MAX_TAILLE 6
#define DIFF_EASY 1
#define DIFF_MID 2
#define DIFF_HARD 3

// Constantes pour le jeu
#define BOMBE -1
#define VIDE 0

struct Grille
{
  int taille;
  struct Difficulte d;
  int plateau[MAX_TAILLE][MAX_TAILLE]; // Base de la grille
  int visible[MAX_TAILLE][MAX_TAILLE]; // Case visible par le joueur (1) case invisible pour le joueur (0)
  int drapeaux[MAX_TAILLE][MAX_TAILLE]; // Drapeaux posés par le joueur
};

struct Difficulte
{
  char niveau[MAX_CHAR]; // facile moyen difficile
  int nb_bombe; 
  int esquive; // Niveau d'esquive en % 
};

struct Difficulte initialiser_difficulte(struct Difficulte d);

struct Grille initialiser_grille(struct Grille g, struct Difficulte d);

#endif