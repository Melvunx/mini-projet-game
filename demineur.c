#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Affichage.h"
#include "Game.h"

int main() {

  srand(time(NULL)); //Initialisation du rand
  struct Grille g;

  g = initialiser_grille();

  g = generer_bombe(g);

  printf("\n");
  afficher_grille(g);
  printf("\n");


  return 0;
}
