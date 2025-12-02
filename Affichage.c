#include <stdio.h>
#include "Affichage.h"
#include "Game.h"

void afficher_grille(struct Grille g)
{
  for (int i = 0; i < g.diff.taille; i++)
  {
    for (int j = 0; j < g.diff.taille; j++)
    {
      printf("%c", g.visible[i][j] == 0 ? '#' : 'H');
    }
    printf("\n");
  }
}
