#include <stdio.h>
#include "Affichage.h"
#include "Game.h"

void afficher_val_case(struct Case c){
  printf("%c", c.val == 0 ? '#' : '_');
}

void afficher_grille(struct Grille g)
{
  for (int i = 0; i < g.diff.taille; i++)
  {
    for (int j = 0; j < g.diff.taille; j++)
    {
      afficher_val_cases(g.visible[i + j]);
    }
    printf("\n");
  }
}
