#include <stdio.h>
#include "Affichage.h"
#include "Grille.h"

int main() {
  struct Difficulte d;
  struct Grille g;

  d = initialiser_difficulte();

  g = initialiser_grille();

  afficher_grille(g);
  return 0;
}
