#include <stdio.h>
#include "Affichage.h"
#include "Game.h"

void afficher_val_cases(int val){
  printf("%c", val == 0 ? '#' : '_');
}

void afficher_grille(struct Grille g)
{
  for (int i = 0; i < g.diff.taille; i++)
  {

    for (int j = 0; j < g.diff.taille; j++)
    {
      if ((g.visible[i].y == i + 1) && (g.visible[j].x == j + 1)) 
      afficher_val_cases(g.visible[i + j].val);
    }
    printf("\n");
  }
}
