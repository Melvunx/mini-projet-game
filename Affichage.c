#include <stdio.h>
#include "Grille.h"
#include "Affichage.h"

void afficher_grille(struct Grille g)
{
  for (int i = 0; i < g.d.taille; i++)
  {
    for (int j = 0; j < g.d.taille; j++)
    {
      printf("%c", g.visible[i][j] == 0 ? '#' : 'H');
    }
    printf("\n");
  }
}
