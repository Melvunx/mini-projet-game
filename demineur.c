#include <stdio.h>
#include "Affichage.h"
#include "Game.h"

int main() {
  struct Grille g;

  g = initialiser_grille();

  afficher_grille(g);
  return 0;
}
