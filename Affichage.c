#include <stdio.h>
#include "Affichage.h"
#include "Game.h"

// Faire un switch pour séparer les cas
void afficher_val_cases(int val){
  switch (val)
  {
  case VIDE:
    printf("#");
    break;

  case BOMBE:
    printf("o");
    break;

  default:
    printf("#");
    break;
  }
}

void afficher_grille(struct Grille g)
{
  int i = 0;
  for (int y = 1; y <= g.diff.taille; y++)
  {
    for (int x = 1; x <= g.diff.taille; x++)
    {
      if ((g.visible[i].y == y) && (g.visible[i].x == x))
      {
        afficher_val_cases(g.visible[i].val);
        i++;
      }
    }
    printf("\n");
  }
}

void afficher_case(struct Case c)
{
  printf("(x:%d ; y:%d)\n", c.x, c.y);
}

void afficher_all_case(struct Grille g)
{
  int nbcases = g.diff.taille * g.diff.taille;
  for (int i = 0; i < nbcases; i++)
  {
    printf("Case n° = %2d | x:%d y:%d val:%2d |\n", 
      i + 1, g.visible[i].x, g.visible[i].y, g.visible[i].val);
  }
}
