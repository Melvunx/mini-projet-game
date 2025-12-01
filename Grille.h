#ifndef _GRILLE_
#define _GRILLE_

#include <stdio.h>
#define MAX_CHAR 10

struct Grille
{
  int taille;
  int nb_bombe;
  struct Difficulte d;
};

struct Difficulte
{
  char niveau[MAX_CHAR]; // facile moyen difficile 
  int facteur; // Niveau de difficulté en plus (ou en moins) de la grille
  int esquive; // Niveau d'esquive en % 
};

#endif