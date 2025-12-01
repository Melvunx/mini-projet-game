#include <stdio.h>
#include "Grille.h"

struct Difficulte initialiser_difficulte(struct Difficulte d)
{

}

struct Grille initialiser_grille(struct Grille g, int difficulte)
{
  struct Grille g;

  // Initialisation de la difficulté
  g.d = initialiser_difficulte(g.d);

  switch (difficulte)
  {
  case DIFF_EASY:
    // g.nb_bombe;
    return g;
  
  default:
    break;
  }
}