#include <stdio.h>
#define MAX_CHAR 10
// #define SIZE 8



struct Grille
{
  int taille;
  int nb_bombe;
  struct Difficulte d;
};

struct Difficulte
{
  char niveau[MAX_CHAR]; // facile moyen difficile 
  int esquive; // Niveau d'esquive en % 
};
